//////////////////////////////////////////////////////////////////////////
//   File Name: SNamedValue.cpp
//////////////////////////////////////////////////////////////////////////

#include "souistd.h"
#include "res.mgr/SNamedValue.h"

namespace SOUI
{

template<> SNamedID * SSingleton<SNamedID>::ms_Singleton =0;

template<> SNamedColor * SSingleton<SNamedColor>::ms_Singleton =0;

template<> SNamedString * SSingleton<SNamedString>::ms_Singleton =0;

//////////////////////////////////////////////////////////////////////////

const wchar_t KPrefixString[] = L"@string/";
const wchar_t KPrefixColor[] = L"@color/";

SStringW SNamedString::Get(const SStringW & strValue) const
{
    if(strValue.IsEmpty()) return strValue;
    if(strValue.Left(ARRAYSIZE(KPrefixString)-1)==KPrefixString)
    {
        return String2Value(strValue.Mid(ARRAYSIZE(KPrefixString)-1));
    }else
    {
        return strValue;
    }
}

COLORREF SNamedColor::Get(const SStringW & strValue) const
{
    if(strValue.Left(ARRAYSIZE(KPrefixColor)-1)==KPrefixColor)
    {
        return String2Value(strValue.Mid(ARRAYSIZE(KPrefixColor)-1));
    }else
    {
        return SColorParser::ParseValue(strValue);
    }
}

void SNamedID::Init2(const NAMEDVALUE *pValue,int nCount,BOOL bSorted)
{
    m_lstNamedValue.RemoveAll();
    m_lstNamedValue.SetCount(nCount);
    for(int i=0;i<nCount;i++)
    {
        m_lstNamedValue.SetAt(i,pValue[i]);
    }
    if(!bSorted)
    {//自动排序
        qsort(m_lstNamedValue.GetData(),m_lstNamedValue.GetCount(),sizeof(NAMEDVALUE),Compare);
    }
}

}//namespace SOUI