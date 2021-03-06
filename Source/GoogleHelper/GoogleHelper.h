//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   GoogleHelper.h
//    Author:      Streamlet
//    Create Time: 2012-12-02
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __GOOGLEHELPER_H_A71F5CE5_2ED3_47B3_B953_0476732AE6FB_INCLUDED__
#define __GOOGLEHELPER_H_A71F5CE5_2ED3_47B3_B953_0476732AE6FB_INCLUDED__


#include "GoogleHelper_h.h"
#include "../GlobalDef.h"
#include "../GoogleHelperAgent/GoogleHelperAgent_h.h"
#include <xl/Windows/COM/xlComInclude.h>
#include <xl/Windows/COM/InterfaceHelper/xlIObjectWithSiteImpl.h>
#include <xl/Windows/COM/InterfaceHelper/xlDWebBrowserEvents2Impl.h>
#include <tchar.h>

class GoogleHelper : public xl::Windows::ComClass<GoogleHelper>,
                     public xl::Windows::Dispatcher<xl::Windows::IObjectWithSiteImpl<>>,
                     public xl::Windows::DWebBrowserEvents2Impl<>
{
public:
    GoogleHelper();
    ~GoogleHelper();

public: // IObjectWithSite Methods
    STDMETHOD(SetSite)(IUnknown *pUnkSite);
    STDMETHOD(GetSite)(REFIID riid, void **ppvSite);

public: // DWebBrowserEvents Methods
    STDMETHOD(Invoke)(DISPID dispIdMember,
                      REFIID riid,
                      LCID lcid,
                      WORD wFlags,
                      DISPPARAMS *pDispParams,
                      VARIANT *pVarResult,
                      EXCEPINFO *pExcepInfo,
                      UINT *puArgErr);

public:
    XL_COM_INTERFACE_BEGIN(GoogleHelper)
        XL_COM_INTERFACE(IDispatch)
        XL_COM_INTERFACE(IObjectWithSite)
    XL_COM_INTERFACE_END()

protected:
    void ReleaseSiteResources();
    HRESULT OnBeforeNavigate2(DISPPARAMS *pDispParams, VARIANT *pVarResult);

private:
    IUnknown                  *m_pUnkSite;
    IWebBrowser2              *m_pWebBrowser;
    IConnectionPointContainer *m_pCPC;
    IConnectionPoint          *m_pCP;
    DWORD                      m_dwCookie;

private:
    IGoogleHelperAgent        *m_pAgent;
};

XL_DECLARE_COM_CLASS(GoogleHelper,
                     MODULE_NAME_GOOGLEHELPER,
                     _T("Streamlet.GoogleHelper.Class"),
                     _T("1"));


#endif // #ifndef __GOOGLEHELPER_H_A71F5CE5_2ED3_47B3_B953_0476732AE6FB_INCLUDED__
