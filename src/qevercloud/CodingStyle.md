This document outlines some coding style rules used in QEverCloud project.

## Use common sense

This is the absolute number one rule which *might* override any of the below mentioned rules should the need for that arise. Follow the rules mentioned below *unless* they don’t seem to play nicely with some specific piece of code. You’d need common sense to identify such a piece of code.

Also note that some of these rules are not applied to some existing places of QEverCloud codebase for various legacy reasons. Some of them are easily fixable, others are not.

## Indentation

QEverCloud uses spaces for indentation, not tabs. Tabs width and shift width should be exactly 4 spaces.

## Curly braces usage

**Always** use curly braces in conditional and loop operators, even if their bodies occupy just the single line of code. The rationale is to avoid the possibility of mistakes when extending the loop or conditional operator body in future: suppose you had `if` operator like this:

    if (a > b)
        a = b;

Then suppose in future some additional action becomes needed. It’s unfortunately quite common to make a mistake like this:

    if (a > b)
        a = b;
        b = c;

See the issue? Even though the code is formatted as if `b = c` is executed inside the conditional operator’s body, in reality it is executed *after* the conditional operator’s body:

    if (a > b)
        a = b;

    b = c;

In order to avoid that, please **always** use curly braces to clearly define the scope of the operator’s body:

    if (a > b) {
        a = b;
    }

    if (a > b) {
        a = b;
        b = c;
    }

Another point about curly braces usage is where to put the opening curly brace: at the end of the first line of the conditional operator or loop operator or at the beginning of the next line. The best approach seems to be using both options as appropriate: for small enough operator bodies it seems better to leave the opening curly brace at the end of the operator' first line. However, if the operator's body involves many lines, say, more than 6 or 7, it looks better with the opening curly brace put at the beginning of the next line.

One exception from this rule is the one for class declarations: please always put the opening curvy brace for the class content on the next line after the class declaration:

    class MyClass
    {
        // < class contents >
    };

Another exception is for function/method implementations: please always put the opening curvy brace for the function/method content on the next line after the function/method definition:

    void MyClass::myFunction
    {
        // < method implementation contents >
    }

Finally, please let the closing curly brace fully occupy its line of code, don’t append anything to it. For example, do this:

    if (a > b) {
        a = b;
    }
    else {
        b = a;
    }

but not this:

    if (a > b) {
        a = b;
    } else {
        b = a;
    }

## Line endings

The «native» line endings for headers and sources of QEverCloud are considered to be Unix-style single LFs. If you are using Windows or OS X / macOS and want to contribute some code changes to QEverCloud, please [configure git](https://help.github.com/articles/dealing-with-line-endings/) to convert the line endings to LF on commit or on push.

## Source file names

The name of a header/source file should reflect the name of the class declared/implemented in the file. In case when the header/source file contains declarations/implementations for more than one class, the file name should be either the most important class’ name or some name encompassing the nature of those multiple classes. If the header/source file doesn’t contain C++ classes at all, the file name should just provide some reasonable hint about the contents of the file.

C++ header files have `.h` extension and source files have `.cpp` extension.

## Namespace

All of the public code of QEverCloud code should reside in `qevercloud` namespace. It’s also a good rule of thumb to keep the library’s private code in the same namespace as well.

## Class names

Class names should be capitalized. If the class name consists of several words, each word should be capitalized and there should be no underscore between the words. Like this:

    class MyClass
    {
        // < class contents >
    };

## Class/struct member variable naming

Private class/struct member variable names should start with `m_` followed by a word in the lower case. If the name of the member variable consists of multiple words, all the words but the first one should be capitalized, without underscores in between. For example:

    class MyClass
    {
    private:
        double   m_averageCounter;
        bool     m_countingEnabled;
    };

Public class/struct member variables may skip this convention.

Also, not a strict rule but a rule of thumb: use tabular indentation to keep the names of several member variables starting at the same column. That makes them slightly more readable.

## Class methods / functions naming

The first word in the name of a class method or a function should start from the lower case. If the name of method/function consists of just one word, the entire word should appear in the lower case. If the name of the method/function consists of several words, all the words but the first one should be capitalized, without underscores in between. For example:

    class MyClass
    {
    public:
        void do();
        void doThis();
        void doThisAndThat();

    };

The obvious exceptions from this rule are constructors and destructor of the class, since their names must match the class names in which the first word is capitalized.

## Doxygen documentation for public class methods and functions

For all public class methods or functions of QEverCloud the Doxygen documentation is required. If you add new classes or class methods or functions, please document them in Doxygen format and ensure the documentation can be built properly: first do `make doc` in your build directory and **then** go to `doc/latex` folder inside it and do `make` there. That would attempt to build a pdf from latex documentation. It can fail if, for example, there is some non-ASCII symbol within the Doxygen comments.

## Comments inside the source code

This paragraph is about non-Doxygen comments inside the source code. A good rule of thumb is to try making the code so explicit that it doesn’t require commenting. However, it is not always possible/feasible due to various reasons: optimization, workarounds for some framework bugs etc. In such cases the tricky code should have a comment nearby explaining what it does and why does it have to be so incomprehensible.

Also, please don’t comment out portions of code «just in case, to have it around should it ever be needed again». Having the unused code around is the task of the version control system.

## Classes layout

Try to stick with the following layout of class contents:

- `Q_OBJECT` macro, if required for the class
- inner classes, if any
- typedefs, if any
- contructors - the default one, if present, comes first, then non-default constructors, if any, then copy-constructor, if present.
- assignment operators, if any
- destructor, if present
- Qt signals, if any
- public methods, including Qt slots
- protected methods, including Qt slots
- private methods, including Qt slots
- member variables

## Preferred method/function implementation layout

- In the beginning of the method/function implementation it is wise to check the validity of input parameters values and possibly any other conditions and return with error if something is wrong and the method cannot do its job. Try to avoid multiple return points from the method/function unless these are the returns with error in the beginning of the method/function body.
- Try to make the bodies of methods/functions as small as possible. Ideally, the body of a method/function should fit a single screen or at least 2-3 screens. If it’s larger, consider refactoring the single method into a series of methods.

## Signal/slot signatures

- Use `Q_SIGNALS` macro instead of `signals` and `Q_SLOTS` instead of `slots`, especially in the public interfaces of QEverCloud. The reason is that there are 3rdparty libraries which use `signals` and `slots` keyword in their own code and interfaces and the name clashing can create problems for library users.
- Pass signal/slot parameters by value, not by const reference, unless you are certain that the objects interacting via the particular signals/slots would live in the same thread. The power and convenience of Qt’s signals/slots comes from their flexibility to the thread affinity of the connected objects but unless you pass parameters by value in signals/slots, it would be your job to provide the proper thread safety guarantees. There’s no reason to do this yourself when Qt can do it for you.

## C++11/14/17 features and Qt4 support

The library does not use any C++11/14/17 features directly but only through macros such as `Q_DECL_OVERRIDE`, `Q_STATIC_ASSERT_X`, `QStringLiteral` and the like. These macros expand to proper C++ features if the compiler supports it or to nothing otherwise.

As long as most of these macros exist only in Qt5 but not in Qt4, QEverCloud defines them on its own when building with Qt4.

Building with Qt4 is still supported by QEverCloud. Yes, Qt4 may be dead and unsupported by the upstream. However, there are still LTS Linux distributions around which use and ship Qt4 and QEverCloud strives to be compatible with them.
