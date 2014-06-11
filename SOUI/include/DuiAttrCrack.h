//////////////////////////////////////////////////////////////////////////
// Xml Attributes Declaration Map

#ifndef DUIATTRCRACK_H
#define DUIATTRCRACK_H

#pragma  once


// Attribute Declaration
#define SOUI_ATTRS_BEGIN()                            \
public:                                                             \
    virtual HRESULT SetAttribute(                                   \
    const CDuiStringA & strAttribName,                                     \
    const CDuiStringA &  strValue,                                          \
    BOOL     bLoading=FALSE)                                    \
    {                                                               \
    HRESULT hRet = E_FAIL;                                        \
 

#define SOUI_ATTRS_END()                              \
    return __super::SetAttribute(                       \
    strAttribName,         \
    strValue,              \
    bLoading               \
    );                     \
    OnAttributeChanged(strAttribName,bLoading,hRet);        \
    return hRet;                                                \
    }                                                               \
 
#define ATTR_CHAIN(varname)                               \
    if (SUCCEEDED(hRet = varname.SetAttribute(strAttribName, strValue, bLoading)))   \
        {                                                           \
        /*return hRet;*/                                            \
        }                                                           \
        else                                                        \
 
#define ATTR_CUSTOM(attribname, func)                    \
    if (attribname == strAttribName)                            \
        {                                                           \
        hRet = func(strValue, bLoading);                        \
        }                                                           \
        else                                                        \
 
// Int = %d StringA
#define ATTR_INT(attribname, varname, allredraw)         \
    if (attribname == strAttribName)                            \
        {                                                           \
        int nRet=0;                                                \
        ::StrToIntExA(strValue,STIF_SUPPORT_HEX,&nRet);            \
        varname=nRet;                                            \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// Rect = %d,%d,%d,%d StringA
#define ATTR_RECT(attribname, varname, allredraw)         \
    if (attribname == strAttribName)                            \
        {                                                           \
        sscanf(strValue,"%d,%d,%d,%d",&varname.left,&varname.top,&varname.right,&varname.bottom);\
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 

// Size = %d,%d StringA
#define ATTR_SIZE(attribname, varname, allredraw)         \
    if (attribname == strAttribName)                            \
        {                                                           \
        sscanf(strValue,"%d,%d",&varname.cx,&varname.cy);\
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// Point = %d,%d StringA
#define ATTR_POINT(attribname, varname, allredraw)         \
    if (attribname == strAttribName)                            \
        {                                                           \
        sscanf(strValue,"%d,%d",&varname.x,&varname.y);\
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 

// Float = %f StringA
#define ATTR_FLOAT(attribname, varname, allredraw)         \
    if (attribname == strAttribName)                            \
        {                                                           \
        sscanf(strValue,"%f",&varname);                        \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// UInt = %u StringA
#define ATTR_UINT(attribname, varname, allredraw)        \
    if (attribname == strAttribName)                            \
        {                                                           \
        int nRet=0;                                                \
        ::StrToIntExA(strValue,STIF_SUPPORT_HEX,&nRet);            \
        varname = (UINT)nRet;                                    \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// DWORD = %u StringA
#define ATTR_DWORD(attribname, varname, allredraw)       \
    if (attribname == strAttribName)                            \
        {                                                           \
        int nRet=0;                                                \
        ::StrToIntExA(strValue,STIF_SUPPORT_HEX,&nRet);            \
        varname = (DWORD)nRet;                                    \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// WORD = %u StringA
#define ATTR_WORD(attribname, varname, allredraw)       \
    if (attribname == strAttribName)                            \
        {                                                           \
        int nRet=0;                                                \
        ::StrToIntExA(strValue,STIF_SUPPORT_HEX,&nRet);            \
        varname = (WORD)nRet;                                    \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 

// bool = 0 or 1 StringA
#define ATTR_BIT(attribname, varname, maskbit, allredraw) \
    if (attribname == strAttribName)                            \
        {                                                           \
        int nRet=0;                                                \
        ::StrToInt(strValue,&nRet);                                \
        if(nRet) varname|=maskbit;                                \
            else     varname &=~(maskbit);                            \
            hRet = allredraw ? S_OK : S_FALSE;                        \
        }                                                           \
        else                                                        \
 

// StringA = StringA
#define ATTR_STRINGA(attribname, varname, allredraw)      \
    if (attribname == strAttribName)                            \
        {                                                           \
        varname = strValue;                                     \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// StringW = StringA
#define ATTR_STRINGW(attribname, varname, allredraw)      \
    if (attribname == strAttribName)                            \
        {                                                           \
        varname = DUI_CA2W(strValue, CP_UTF8);;                                     \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 

// StringT = StringA
#define ATTR_STRINGT(attribname, varname, allredraw)     \
    if (attribname == strAttribName)                            \
        {                                                           \
        varname = DUI_CA2T(strValue, CP_UTF8);                      \
        BUILDSTRING(varname);                        \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// DWORD = %X StringA
#define ATTR_HEX(attribname, varname, allredraw)         \
    if (attribname == strAttribName)                            \
        {                                                           \
        varname = SObject::HexStringToULong(strValue);        \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// COLORREF = %06X StringA
#define ATTR_COLOR(attribname, varname, allredraw)       \
    if (attribname == strAttribName)                            \
        {                                                           \
        varname = SObject::HexStringToColor(strValue);        \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// font = "1007:����"
#define ATTR_FONT(attribname, varname, allredraw)        \
    if (attribname == strAttribName)                            \
        {                                                           \
        int nPos=strValue.ReverseFind(':');\
        if(nPos!=-1)\
            {\
            DWORD dwValue = SObject::HexStringToULong(strValue,nPos);  \
            CDuiStringA strFace=strValue.Right(strValue.GetLength()-nPos-1);\
            CDuiStringT strFaceT=DUI_CA2T(strFace,CP_UTF8);\
            varname = DuiFontPool::getSingleton().GetFont(LOWORD(dwValue),strFaceT);    \
            }else\
            {\
            DWORD dwValue = SObject::HexStringToULong(strValue);  \
            varname = DuiFontPool::getSingleton().GetFont(LOWORD(dwValue));         \
            }\
            hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \


//fontex="facename:����;bold:1;italic:1;underline:1;adding:10"
#define ATTR_FONTEX(attribname, varname, allredraw)        \
    if (attribname == strAttribName)                                    \
    {                                                                    \
        BOOL bBold=0,bItalic=0,bUnderline=0;                            \
        CDuiStringT strFace;                                            \
        char  nAdding=0;                                                \
        CDuiStringT attr=DUI_CA2T(strValue,CP_UTF8);                    \
        attr.MakeLower();                                                \
        int nPosBegin=attr.Find(_T("facename:"));                        \
        if(nPosBegin!=-1)                                                \
        {                                                                \
            nPosBegin+=9;                                                \
            int nPosEnd=attr.Find(_T(";"),nPosBegin);                    \
            if(nPosEnd==-1) nPosEnd=attr.GetLength();                    \
            strFace=attr.Mid(nPosBegin,nPosEnd-nPosBegin);                \
        }                                                                \
        nPosBegin=attr.Find(_T("bold:"));                                \
        if(nPosBegin!=-1)                                                \
        {                                                                \
            bBold=attr.Mid(nPosBegin+5,1)!=_T("0");                            \
        }                                                                \
        nPosBegin=attr.Find(_T("underline:"));                            \
        if(nPosBegin!=-1)                                                \
        {                                                                \
            bUnderline=attr.Mid(nPosBegin+10,1)!=_T("0");                    \
        }                                                                \
        nPosBegin=attr.Find(_T("italic:"));                                \
        if(nPosBegin!=-1)                                                \
        {                                                                \
            bItalic=attr.Mid(nPosBegin+7,1)!=_T("0");                        \
        }                                                                \
        nPosBegin=attr.Find(_T("adding:"));                                \
        if(nPosBegin!=-1)                                                \
        {                                                                \
            nAdding=(char)_ttoi((LPCTSTR)attr+nPosBegin+7);                        \
        }                                                                \
        varname = DuiFontPool::getSingleton().GetFont(bBold,bUnderline,bItalic,nAdding,strFace); \
        hRet = allredraw ? S_OK : S_FALSE;                                \
    }                                                                    \
    else                                                                \


// Value In {String1 : Value1, String2 : Value2 ...}
#define ATTR_ENUM_BEGIN(attribname, vartype, allredraw)        \
    if (attribname == strAttribName)                            \
        {                                                           \
        vartype varTemp;                                        \
        \
        hRet = allredraw ? S_OK : S_FALSE;                      \
 
#define ATTR_ENUM_VALUE(enumstring, enumvalue)                     \
    if (strValue == enumstring)                             \
    varTemp = enumvalue;                                \
            else                                                    \
 
#define ATTR_ENUM_END(varname)                                     \
    return E_FAIL;                                      \
    \
    varname = varTemp;                                      \
        }                                                           \
        else                                                        \
 
// DuiStyle From StringA Key
#define ATTR_STYLE(attribname, varname, allredraw)       \
    if (attribname == strAttribName)                            \
        {                                                           \
        GETSTYLE(strValue,varname);                  \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 
// DuiSkinPool From StringA Key
#define ATTR_SKIN(attribname, varname, allredraw)        \
    if (attribname == strAttribName)                            \
        {                                                           \
        varname = GETSKIN(strValue);                    \
        hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 

#define ATTR_IMAGE(attribname, varname, allredraw)        \
    if (attribname == strAttribName)                            \
        {                                                       \
        CDuiStringT strValueT=DUI_CA2T(strValue,CP_UTF8);        \
        int nPos=strValueT.ReverseFind(':');\
        if(nPos!=-1)\
        {\
            CDuiStringT strType=strValueT.Right(strValue.GetLength()-nPos-1);\
            varname = DuiImgPool::getSingleton().GetImage(strValueT.Left(nPos),strType);        \
            if(varname) varname->AddRef();    \
            hRet = allredraw ? S_OK : S_FALSE;                      \
        }else\
            varname = DuiImgPool::getSingleton().GetImage(strValueT);        \
            if(varname) varname->AddRef();    \
            hRet = allredraw ? S_OK : S_FALSE;                      \
        }                                                           \
        else                                                        \
 


#endif//DUIATTRCRACK_H