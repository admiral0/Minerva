project(QCodeEdit)
include_directories (
        ${QCodeEdit_SOURCE_DIR}
        ${QCodeEdit_BINARY_DIR}
	${QCodeEdit_SOURCE_DIR}/document
	${QCodeEdit_SOURCE_DIR}/language
	${QCodeEdit_SOURCE_DIR}/widgets
	${QCodeEdit_SOURCE_DIR}/qnfa)
set (qcodeedit_document_HDRS 
	document/qdocument_p.h
	document/qdocument.h
	document/qdocumentcommand.h
	document/qdocumentcursor.h
	document/qdocumentline.h
	document/qdocumentsearch.h)

set ( qcodeedit_HDRS
	qeditor.h
	qeditorfactory.h
	qeditsession.h
	qpanellayout.h
	qformatscheme.h
	qlinemarksinfocenter.h
	qreliablefilewatch.h
	document/qdocument.h
	qcodecompletionengine.h
	qlanguagefactory.h
	qce-config.h
	qeditorinputbindinginterface.h
	qeditorinputbinding.h
	qcodeedit.h
	qformatfactory.h	
	qlanguagedefinition.h
	)
set (qcodeedit_widgets_HDRS 
widgets/qcalltip.h
widgets/qpanel.h
	widgets/qlinenumberpanel.h
	widgets/qlinemarkpanel.h
	widgets/qlinechangepanel.h
	widgets/qfoldpanel.h
	widgets/qstatuspanel.h
	widgets/qgotolinepanel.h
	widgets/qsearchreplacepanel.h
	widgets/qgotolinedialog.h
	widgets/qeditconfig.h
	widgets/qformatconfig.h
	widgets/qsimplecolorpicker.h)
set (qcodeedit_qnfa_HDRS
	qnfa/qnfa.h
	qnfa/qnfadefinition.h
	qnfa/light_vector.h )
set (qcodeedit_snippets_HDRS
	snippets/qsnippet.h
	snippets/qsnippet_p.h
	snippets/qsnippetpatternloader.h
	snippets/qsnippetbinding.h
	snippets/qsnippetmanager.h
	snippets/qsnippetedit.h)
set ( qcodeedit_SRCS
	qeditor.cpp
	qeditorfactory.cpp
	qeditorinputbinding.cpp
	qeditsession.cpp
	qcodeedit.cpp
	qpanellayout.cpp
	qformatscheme.cpp
	qlinemarksinfocenter.cpp
	qreliablefilewatch.cpp
	document/qdocument.cpp
	document/qdocumentcommand.cpp
	document/qdocumentcursor.cpp
	document/qdocumentline.cpp
	document/qdocumentsearch.cpp
	qcodecompletionengine.cpp
	qlanguagedefinition.cpp
	qlanguagefactory.cpp
	widgets/qpanel.cpp
	widgets/qlinenumberpanel.cpp
	widgets/qlinemarkpanel.cpp
	widgets/qlinechangepanel.cpp
	widgets/qfoldpanel.cpp
	widgets/qstatuspanel.cpp
	widgets/qgotolinepanel.cpp
	widgets/qsearchreplacepanel.cpp
	widgets/qgotolinedialog.cpp
	widgets/qeditconfig.cpp
	widgets/qformatconfig.cpp
	widgets/qsimplecolorpicker.cpp
	widgets/qcalltip.cpp
	snippets/qsnippet.cpp
	snippets/qsnippetmanager.cpp
	snippets/qsnippetedit.cpp
	snippets/qsnippetbinding.cpp
	qnfa/qnfa.cpp
	qnfa/qnfadefinition.cpp
	qnfa/xml2qnfa.cpp
	)

set ( qcodeedit_UIS
	widgets/searchreplace.ui
	widgets/gotoline.ui
	widgets/gotolinedialog.ui
	widgets/editconfig.ui
	widgets/formatconfig.ui
	snippets/snippetedit.ui
	)
QT4_WRAP_UI(UIS ${qcodeedit_UIS})

set ( qcodeedit_MOCS
	qeditor.h
	qeditorfactory.h
	qeditsession.h
	qpanellayout.h
	qformatscheme.h
	qlinemarksinfocenter.h
	qreliablefilewatch.h
	document/qdocument.h
	qcodecompletionengine.h
	qlanguagefactory.h
	widgets/qpanel.h
	widgets/qlinenumberpanel.h
	widgets/qlinemarkpanel.h
	widgets/qlinechangepanel.h
	widgets/qfoldpanel.h
	widgets/qstatuspanel.h
	widgets/qgotolinepanel.h
	widgets/qsearchreplacepanel.h
	widgets/qgotolinedialog.h
	widgets/qeditconfig.h
	widgets/qformatconfig.h
	widgets/qsimplecolorpicker.h
	snippets/qsnippetmanager.h
	snippets/qsnippetedit.h
	)
QT4_WRAP_CPP(MOCS ${qcodeedit_MOCS})

add_library ( qcodeedit SHARED ${qcodeedit_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( qcodeedit  ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} )
set_target_properties(qcodeedit PROPERTIES
			VERSION ${QCODEEDIT_VER_MAJOR}
			SOVERSION "${QCODEEDIT_VER_MAJOR}.${QCODEEDIT_VER_MINOR}")
install ( TARGETS qcodeedit  DESTINATION lib )
install ( FILES ${qcodeedit_HDRS} DESTINATION include/qcodeedit )
install ( FILES ${qcodeedit_widgets_HDRS} DESTINATION include/qcodeedit/widgets )
install ( FILES ${qcodeedit_snippets_HDRS} DESTINATION include/qcodeedit/snippets )
install ( FILES ${qcodeedit_qnfa_HDRS} DESTINATION include/qcodeedit/qnfa )
install ( FILES ${qcodeedit_document_HDRS} DESTINATION include/qcodeedit/document )