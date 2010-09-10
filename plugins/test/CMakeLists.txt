#This is a test plugin
#Start searching for Minerva and Qt
cmake_minimum_required( VERSION 2.6 )
project(TestPlugin)
find_package ( Qt4 REQUIRED )
find_path(MINERVA_INCLUDE_DIR minervawindow.h
	  HINTS $ENV{MINERVADIR}
	  PATH_SUFFIXES include/minerva
	  PATHS
	  ~/
	  /usr/local
	  /usr
	  /sw # Fink
	  /opt/local # DarwinPorts
	  /opt/csw # Blastwave
	  /opt )
find_path(QCODEEDIT_INCLUDE_DIR qeditor.h
	  HINTS $ENV{MINERVADIR}
	  PATH_SUFFIXES include/qcodeedit
	  PATHS
	  ~/
	  /usr/local
	  /usr
	  /sw # Fink
	  /opt/local # DarwinPorts
	  /opt/csw # Blastwave
	  /opt )
FIND_LIBRARY(MINERVA_LIBRARY 
  NAMES minerva Minerva
  HINTS
  $ENV{MINERVADIR}
  PATH_SUFFIXES lib64 lib libs64 libs libs/Win32 libs/Win64
  PATHS
  ~/
  /usr/local
  /usr
  /sw
  /opt/local
  /opt/csw
  /opt
)
FIND_LIBRARY(QCODEEDIT_LIBRARY 
  NAMES qcodeedit qCodeEdit QCodeEdit
  HINTS
  $ENV{MINERVADIR}
  PATH_SUFFIXES lib64 lib libs64 libs libs/Win32 libs/Win64
  PATHS
  ~/
  /usr/local
  /usr
  /sw
  /opt/local
  /opt/csw
  /opt
)
include_directories(${testplugin_SOURCE_DIR} ${MINERVA_INCLUDE_DIR} ${QCODEEDIT_INCLUDE_DIR}/document ${QCODEEDIT_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} )
set(testplugin_HDRS testplugin.h)
qt4_wrap_cpp( testplugin_MOC ${testplugin_HDRS})
add_library(testplugin SHARED testplugin.cpp ${testplugin_MOC})
set_target_properties  ( testplugin PROPERTIES
			PREFIX "")
target_link_libraries(testplugin ${MINERVA_LIBRARY} ${QCODEEDIT_LIBRARY} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} )
install(TARGETS testplugin DESTINATION lib/minerva/plugins)