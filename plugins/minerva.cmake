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
SET(CPACK_PACKAGE_VENDOR "admiral0")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
SET(CPACK_PACKAGE_VERSION_MAJOR ${MINERVA_VER_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${MINERVA_VER_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH "${MINERVA_VER_PATCH}${MINERVA_VER_EXT}")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_PACKAGE_CONTACT "Radu Andries <admiral0@tuxfamily.org>")

