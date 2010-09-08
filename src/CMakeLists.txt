include_directories (
	#${QCodeEdit_SOURCE_DIR}
	#${QCodeEdit_SOURCE_DIR}
	#${QCodeEdit_SOURCE_DIR}
	${libminerva_SOURCE_DIR}
	${libminerva_BINARY_DIR}
	${QCodeEdit_SOURCE_DIR}/document
	${Minerva_SOURCE_DIR}/src
	${Minerva_BINARY_DIR}/src
	${QCodeEdit_SOURCE_DIR})
set ( Minerva_HDRS
	)

set ( Minerva_SRCS
	main.cpp
	minervasettings.cpp
	minervaapplication.cpp
	)



set ( Minerva_MOCS
	minervasettings.h
	minervaapplication.h
	)
QT4_WRAP_CPP(MOCS ${Minerva_MOCS})

link_directories (${QCodeEdit_BINARY_DIR}) 

configure_file (
  "${Minerva_SOURCE_DIR}/minervaconfig.h.in"
  "${Minerva_BINARY_DIR}/minervaconfig.h"
  )


add_executable ( minerva ${Minerva_SRCS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( minerva  libminerva qcodeedit  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} )

install ( TARGETS minerva DESTINATION bin )
install ( FILES ${Minerva_MOCS} ${Minerva_HDRS} DESTINATION include/minerva )
