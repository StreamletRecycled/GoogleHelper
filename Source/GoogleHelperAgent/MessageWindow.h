//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   MessageWindow.h
//    Author:      Streamlet
//    Create Time: 2012-12-03
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __MESSAGEWINDOW_H_F2D9ACF7_E60E_449D_9DB8_225D5B818A91_INCLUDED__
#define __MESSAGEWINDOW_H_F2D9ACF7_E60E_449D_9DB8_225D5B818A91_INCLUDED__


#include <xl/Win32/GUI/xlWindow.h>
#include <xl/Win32/GUI/xlMenu.h>
#include <xl/Win32/Threads/xlThread.h>

class MessageWindow : public xl::Window
{
public:
    MessageWindow();
    ~MessageWindow();

public:
    void ReportUrl(LPCTSTR lpszUrl);

private:
    LRESULT OnCreate  (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnDestroy (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnTrayIcon(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);

private:
    LRESULT OnMenuShowTip(HWND hWnd, WORD wID, WORD wCode, HWND hControl, BOOL &bHandled);
    LRESULT OnMenuUpdate (HWND hWnd, WORD wID, WORD wCode, HWND hControl, BOOL &bHandled);
    LRESULT OnMenuAbout  (HWND hWnd, WORD wID, WORD wCode, HWND hControl, BOOL &bHandled);
    LRESULT OnMenuWebsite(HWND hWnd, WORD wID, WORD wCode, HWND hControl, BOOL &bHandled);

private:
    NOTIFYICONDATA m_nid;
    xl::Menu m_menuTray;

private:
    typedef xl::Thread<DWORD> UpdateThreadType;
    UpdateThreadType m_tUpdateThread;

private:
    DWORD UpdateThread(HANDLE hQuit, DWORD dwDelay);
};

__declspec(selectany) MessageWindow g_wndMessage;

#endif // #ifndef __MESSAGEWINDOW_H_F2D9ACF7_E60E_449D_9DB8_225D5B818A91_INCLUDED__
