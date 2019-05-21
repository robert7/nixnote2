/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_OPTIONAL_H
#define QEVERCLOUD_OPTIONAL_H

#include "EverCloudException.h"
#include <algorithm>

namespace qevercloud {

/**
 * Supports optional values.
 *
 * Most of the fields in the Evernote API structs are optional. But C++ does not support this notion directly.
 *
 * To implement the concept of optional values conventional Thrift C++ wrapper uses a special field of a struct type
 * where each field is of type bool with the same name as a field in the struct. This bool flag indicated was
 * the field with the same name in the outer struct assigned or not.
 *
 * While this method have its advantages (obviousness and simplicity) I found it very inconvenient to work with.
 * You have to check by hand that both values (value itself and its __isset flag) are in sync.
 * There is no checks whatsoever against an error and such an error is too easy to make.
 *
 * So for my library I created a special class that supports the optional value notion explicitly.
 * Basically Optional class just holds a bool value that tracks the fact that a value was assigned. But this tracking
 * is done automatically and attempts to use unissigned values throw exceptions. In this way errors are much harder to
 * make and it's harder for them to slip through testing unnoticed too.
 *
 */
template<typename T>
class Optional
{
public:
    /** Default constructor.
     * Default Optional is not set.
     */
    Optional() :
        m_isSet(false),
        m_value(T())
    {}

    /**
     * Copy constructor.
     */
    Optional(const Optional & o) :
        m_isSet(o.m_isSet),
        m_value(o.m_value)
    {}

    /**
     * Template copy constructor. Allows to be initialized with Optional of any compatible type.
     */
    template<typename X>
    Optional(const Optional<X> & o) :
        m_isSet(o.m_isSet),
        m_value(o.m_value)
    {}

    /**
     * Initialization with a value of the type T. Note: it's implicit.
     */
    Optional(const T & value) :
        m_isSet(true),
        m_value(value)
    {}

    /**
     * Template initialization with a value of any compatible type.
     */
    template<typename X>
    Optional(const X & value) :
        m_isSet(true),
        m_value(value)
    {}

    /**
     * Assignment.
     */
    Optional & operator=(const Optional & o)
    {
        m_value = o.m_value;
        m_isSet = o.m_isSet;
        return *this;
    }

    /**
     * Template assignment with an Optional of any compatible value.
     */
    template<typename X>
    Optional & operator=(const Optional<X> & o)
    {
        m_value = o.m_value;
        m_isSet = o.m_isSet;
        return *this;
    }

    /**
     * Assignment with a value of the type T.
     */
    Optional & operator=(const T & value)
    {
        m_value = value;
        m_isSet = true;
        return *this;
    }

    /**
     * Template assignment with a value of any compatible type.
     */
    template<typename X>
    Optional & operator=(const X & value)
    {
        m_value = value;
        m_isSet = true;
        return *this;
    }

    /**
     * Implicit conversion of Optional<T> to T.
     *
     * const version.
     */
    operator const T&() const
    {
        if (!m_isSet) {
            throw EverCloudException("qevercloud::Optional: nonexistent value access");
        }

        return m_value;
    }

    /**
     * Implicit conversion of Optional<T> to T.
     *
     * Note: a reference is returned, not a copy.
     */
    operator T&()
    {
        if (!m_isSet) {
            throw EverCloudException("qevercloud::Optional: nonexistent value access");
        }

        return m_value;
    }

    /**
     * Returs a reference to the holded value.
     *
     * const version.
     *
     */
    const T & ref() const
    {
        if (!m_isSet) {
            throw EverCloudException("qevercloud::Optional: nonexistent value access");
        }

        return m_value;
    }

    /**
     * Returs reference to the holded value.
     *
     * There are contexts in C++ where impicit type conversions can't help. For example:
     *
     * @code
      Optional<QStringList> l;
      for(auto s : l); // you will hear from your compiler
      @endcode
     *
     * Explicit type conversion can be used...
     *
     * @code
      Optional<QStringList> l;
      for(auto s : static_cast<QStringList&>(l)); // ugh...
      @endcode
     *
     * ... but this is indeed ugly as hell.
     *
     * So I implemented ref() function that returns a reference to the holded value.
     * @code
      Optional<QStringList> l;
      for(auto s : l.ref()); // not ideal but OK
      @endcode
     */
    T & ref()
    {
        if (!m_isSet) {
            throw EverCloudException("qevercloud::Optional: nonexistent value access");
        }

        return m_value;
    }

    /**
     * @brief Checks if value is set.
     * @return true if Optional have been assigned a value and false otherwise.
     *
     * Access to an unassigned ("not set") Optional lead to an exception.
     */
    bool isSet() const
    {
        return m_isSet;
    }

    /**
     * Clears an Optional.
     *
     * @code

      Optional<int> o(1);
      o.clear();
      cout << o; // exception

      @endcode
     */
    void clear()
    {
        m_isSet = false;
        m_value = T();
    }

    /**
     * Fast way to initialize an Optional with a default value.
     *
     * It's very useful for structs.
     *
     * @code

      struct S2 {int f;};
      struct S {int f1; Optional<S2> f2};
      Optional<S> o; // o.isSet() != ture

      // without init() it's cumbersome to access struct fields
      // it's especially true for nested Optionals
      o = S(); // now o is set
      o->f2 = S2(); // and o.f2 is set
      o->f2->f = 1; // so at last it can be used

      // with init() it's simpler
      o.init()->f2.init()->f = 1;

      @endcode
     * @return reference to itself
     */
    Optional & init()
    {
        m_isSet = true;
        m_value = T();
        return *this;
    }

    /**
     * Two syntatic constructs come to mind to use for implementation of access to a struct's/class's field directly from Optional.
     *
     * One is the dereference operator.
     * This is what boost::optional uses. While it's conceptually nice
     * I found it to be not a very convenient way to refer to structs, especially nested ones.
     * So I overloaded the operator-> and use smart pointer semantics.
     *
     * @code
      struct S1 {int f1;};
      struct S2 {Optional<S1> f2;};
      Optional<S2> o;

      *((*o).f2).f1; // boost way, not implemented

      o->f2->f1;     // QEverCloud way

      @endcode
     *
     * I admit, boost::optional is much more elegant overall. It uses pointer semantics quite clearly and
     * in an instantly understandable way. It's universal (* works for any type and not just structs). There is
     * no need for implicit type concersions and so there is no subtleties because of it. And so on.
     *
     * But then referring to struct fields is a chore. And this is the most common use case of Optionals in QEverCloud.
     *
     * So I decided to use non-obvious-on-the-first-sight semantics for my Optional. IMO it's much more convenient when gotten used to.
     *
     */
    T * operator->()
    {
        if (!m_isSet) {
            throw EverCloudException("qevercloud::Optional: nonexistent value access");
        }

        return &m_value;
    }

    /**
     * const version.
     */
    const T * operator->() const
    {
        if (!m_isSet) {
            throw EverCloudException("qevercloud::Optional: nonexistent value access");
        }

        return &m_value;
    }

    /**
     * The function is sometimes useful to simplify checking for the value being set.
     * @param defaultValue
     * The value to return if Optional is not set.
     * @return Optional value if set and defaultValue otherwise.
     */
    T value(T defaultValue = T()) const
    {
        return m_isSet ? m_value : defaultValue;
    }

    /**
     * Two optionals are equal if they are both not set or have
     * equal values.
     *
     * I do not define `operator==` due to not easily resolvable conflicts with `operator T&`.
     *
     * Note that `optional == other_optional` may throw but `optional.isEqual(other_optional)` will not.
     */
    bool isEqual(const Optional<T> & other) const
    {
        if(m_isSet != other.m_isSet) return false;
        return !m_isSet || (m_value == other.m_value);
    }

    template<typename X> friend class Optional;

    friend void swap(Optional & first, Optional & second)
    {
        using std::swap;
        swap(first.m_isSet, second.m_isSet);
        swap(first.m_value, second.m_value);
    }

// Visual C++ does not to generate implicit move constructors so this stuff doesn't work with even recent MSVC compilers
#if defined(Q_COMPILER_RVALUE_REFS) && !defined(_MSC_VER)
    Optional(Optional && other)
    {
        swap(*this, other);
    }

    Optional & operator=(Optional && other)
    {
        swap(*this, other);
        return *this;
    }

    Optional(T && other)
    {
        using std::swap;
        m_isSet = true;
        swap(m_value, other);
    }

    Optional & operator=(T && other)
    {
        using std::swap;
        m_isSet = true;
        swap(m_value, other);
        return *this;
    }
#endif

private:
    bool m_isSet;
    T m_value;
};

} // namespace qevercloud

#endif // QEVERCLOUD_OPTIONAL_H
