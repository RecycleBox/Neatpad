//
//    MODULE:        TextViewFile.cpp
//
//    PURPOSE:    TextView file input routines
//
//    NOTES:        www.catch22.net
//

#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <tchar.h>
#include "TextView.h"
#include "TextViewInternal.h"

//
//    
//
LONG TextView::OpenFile(LPTSTR szFileName)
{
    ClearFile();

    if (init_TextDocument(m_pTextDoc, szFileName))
    {
        m_nLineCount = linecount_TextDocument(m_pTextDoc);
        m_nLongestLine = longestline_TextDocument(m_pTextDoc, m_nTabWidthChars);

        m_nVScrollPos = 0;
        m_nHScrollPos = 0;

        m_nSelectionStart = 0;
        m_nSelectionEnd = 0;
        m_nCursorOffset = 0;

        UpdateMarginWidth();
        UpdateMetrics();
        ResetLineCache();
        return TRUE;
    }

    return FALSE;
}

//
//
//
LONG TextView::ClearFile()
{
    if (m_pTextDoc)
    {
        clear_TextDocument(m_pTextDoc);
        EmptyDoc_TextDocument(m_pTextDoc);
    }

    ResetLineCache();

    m_nLineCount = linecount_TextDocument(m_pTextDoc);
    m_nLongestLine = longestline_TextDocument(m_pTextDoc, m_nTabWidthChars);

    m_nVScrollPos = 0;
    m_nHScrollPos = 0;

    m_nSelectionStart = 0;
    m_nSelectionEnd = 0;
    m_nCursorOffset = 0;

    m_nCurrentLine = 0;
    m_nCaretPosX = 0;

    UpdateMetrics();



    return TRUE;
}
