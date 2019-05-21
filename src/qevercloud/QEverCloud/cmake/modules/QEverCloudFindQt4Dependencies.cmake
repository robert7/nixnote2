find_package(Qt4 COMPONENTS QTCORE QTGUI QTNETWORK QUIET REQUIRED)

include(${QT_USE_FILE})

# Workaround what seems to be a CMake 3.x bug with Qt4 libraries
list(FIND QT_LIBRARIES "${QT_QTGUI_LIBRARY}" HasGui)
if(HasGui EQUAL -1)
  list(APPEND QT_LIBRARIES ${QT_QTGUI_LIBRARY})
endif()
