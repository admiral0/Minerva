#This is a test plugin
#Start searching for Minerva and Qt
cmake_minimum_required( VERSION 2.6 )
project(Minerva-MaemoPlugin)
include(../minerva.cmake)
set(maemoplugin_HDRS maemoplugin.h)
qt4_wrap_cpp( maemoplugin_MOC ${maemoplugin_HDRS})
add_library(maemoplugin SHARED maemoplugin.cpp ${maemoplugin_MOC})
set_target_properties  ( maemoplugin PROPERTIES
			PREFIX "")
target_link_libraries(maemoplugin ${MINERVA_LIBRARY} ${QCODEEDIT_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )
install(TARGETS maemoplugin DESTINATION lib/minerva/plugins)
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Minerva Maemo Plugin")
include(CPack)
