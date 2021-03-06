//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   AboutDialog.h
//    Author:      Streamlet
//    Create Time: 2011-05-10
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __ABOUTDIALOG_H_5C48ACE4_A916_4C27_BD2E_F36FF78E656C_INCLUDED__
#define __ABOUTDIALOG_H_5C48ACE4_A916_4C27_BD2E_F36FF78E656C_INCLUDED__


#include <xl/Windows/GUI/xlDialog.h>
#include <xl/Windows/GUI/xlStdStatic.h>
#include <xl/Windows/GUI/xlStdButton.h>
#include <xl/Windows/GUI/xlStdLink.h>

class AboutDialog : public xl::Windows::Dialog
{
public:
    static void ShowDialog(xl::Windows::Window *pParent = nullptr);
    static AboutDialog *ms_pDialog;

private:
    AboutDialog();
    ~AboutDialog();

private:
    void CreateControls();
    void SetTexts();

private:
    virtual bool OnCreate();

private:
    xl::Windows::StdStatic m_staticIcon;
    xl::Windows::StdStatic m_staticProductName;
    xl::Windows::StdStatic m_staticCopyright;
    xl::Windows::StdStatic m_staticThanks;
    xl::Windows::StdStatic m_staticContact;
    xl::Windows::StdLink   m_linkWebsite;
    xl::Windows::StdLink   m_linkEmail;
    xl::Windows::StdButton m_buttonOK;

private:
    bool m_bIconMoving;

private:
    // Message Map Handlers
    // LRESULT OnMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnDestroy(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
    LRESULT OnTimer(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);

private:
    // Command Message Handlers
    // LRESULT OnCommandMessage(HWND hWnd, WORD wID, WORD wCode, HWND hControl, BOOL &bHandled);
    LRESULT OnStaticIconClick(HWND hWnd, WORD wID, WORD wCode, HWND hControl, BOOL &bHandled);

private:
    // Notify Message Handlers
    // LRESULT OnNotifyMessage(HWND hWnd, LPNMHDR lpNMHDR, BOOL &bHandled);
    LRESULT OnLinkWebsiteClick(HWND hWnd, LPNMHDR lpNMHDR, BOOL &bHandled);
    LRESULT OnLinkEmailClick  (HWND hWnd, LPNMHDR lpNMHDR, BOOL &bHandled);


};

__declspec(selectany) AboutDialog *AboutDialog::ms_pDialog = nullptr;

#endif // #ifndef __ABOUTDIALOG_H_5C48ACE4_A916_4C27_BD2E_F36FF78E656C_INCLUDED__
