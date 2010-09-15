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
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_SHARED)
ADD_DEFINITIONS(-DQT_PLUGIN)
