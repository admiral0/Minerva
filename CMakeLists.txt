cmake_minimum_required( VERSION 2.6 )
project(Minerva)
include (config.cmake)
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
find_package ( Qt4 REQUIRED )
include ( ${QT_USE_FILE} )
include_directories (
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR} ${QT_QTXML_INCLUDE_DIR}
	)
if( EXISTS "${Minerva_SOURCE_DIR}/.git")
set (MINERVA_VER_EXT "git")
endif( EXISTS "${Minerva_SOURCE_DIR}/.git")

add_subdirectory( qcodeedit )
add_subdirectory( lib )
add_subdirectory( src )
add_subdirectory(plugins)

set ( MINERVA_FILES qxs/cpp.qxf
	qxs/css.qnfa
	qxs/xml.qxf
	qxs/css.qxf
	qxs/dox.qnfa
	qxs/dox.qxf
	qxs/marks.qxm
	qxs/qtscript.qxf
	qxs/python.qnfa
	qxs/snippet.qnfa
	qxs/php.qnfa
	qxs/qtscript.qnfa
	qxs/tex.qnfa
	qxs/tex.qxf
	qxs/formats.qxf
	qxs/python.qxf
	qxs/cpp.qnfa
	qxs/bibtex.qxf
	qxs/csharp.qxf
	qxs/bibtex.qnfa
	qxs/csharp.qnfa
	qxs/pro.qnfa
	qxs/xml.qnfa
	qxs/coldfusion.qnfa
	qxs/php.qxf
	qxs/pro.qxf)

install( FILES $${MINERVA_FILES} DESTINATION share/minerva/qxs )
#Package generation
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Minerva Text Editor")
SET(CPACK_PACKAGE_VENDOR "admiral0")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
SET(CPACK_PACKAGE_VERSION_MAJOR ${MINERVA_VER_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${MINERVA_VER_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH "${MINERVA_VER_PATCH}${MINERVA_VER_EXT}")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_PACKAGE_EXECUTABLES "minerva" "Minerva Editor")
include (CPack)

