#This is a test plugin
#Start searching for Minerva and Qt
cmake_minimum_required( VERSION 2.6 )
project(TestPlugin)
include(../minerva.cmake)
set(testplugin_HDRS testplugin.h)
qt4_wrap_cpp( testplugin_MOC ${testplugin_HDRS})
add_library(testplugin SHARED testplugin.cpp ${testplugin_MOC})
set_target_properties  ( testplugin PROPERTIES
			PREFIX "")
target_link_libraries(testplugin ${MINERVA_LIBRARY} ${QCODEEDIT_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )
install(TARGETS testplugin DESTINATION lib/minerva/plugins)
