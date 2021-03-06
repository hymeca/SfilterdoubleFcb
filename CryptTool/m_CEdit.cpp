// m_CEdit.cpp: 实现文件
//

#include "stdafx.h"
#include "CryptTool.h"
#include "m_CEdit.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

// m_CEdit

IMPLEMENT_DYNAMIC(m_CEdit, CEdit)

m_CEdit::m_CEdit()
{

}

m_CEdit::~m_CEdit()
{
}


void m_CEdit::DoDataExchange(CDataExchange* pDX)
{
	CEdit::DoDataExchange(pDX);
}





BEGIN_MESSAGE_MAP(m_CEdit, CEdit)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()



// m_CEdit 消息处理程序

VOID m_CEdit::OnDropFiles(HDROP hDropInfo) {
	UINT  nNumOfFiles = DragQueryFileA(hDropInfo, 0xFFFFFFFF, NULL, 0); //文件的个数
	

	//GetTempPathA(261, Filepullpath);
	for (UINT nIndex = 0; nIndex < nNumOfFiles; ++nIndex)
	{
		DragQueryFileA(hDropInfo, nIndex, cFilePathName, _MAX_PATH);  //得到文件名
		//LPARAM lParam = (LPARAM)cFilePathName;
		//SetFileAttributesA(cFilePathName, FILE_ATTRIBUTE_NORMAL);
		//USES_CONVERSION;
		SetText((LPCTSTR)cFilePathName);
	}
	DragFinish(hDropInfo);
}


void m_CEdit::SetText(LPCTSTR str)
{
	SetSel(0, -1, true);  
	ReplaceSel(str);      
	SetSel(0);           
}