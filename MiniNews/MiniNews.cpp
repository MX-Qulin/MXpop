// MiniNews.cpp : 定义应用程序的入口点。
// Download by http://www.codefans.net
#include "stdafx.h"
#include "MiniNews.h"
#include "NewsWindow.h"
CNewsWindow NewsWindow;
BOOL InitNews();
int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine,int nCmdShow){
	if(!InitNews())return 0;
	// 主消息循环:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){
	TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}
BOOL InitNews(){
	LPCTSTR lpNewsTitle		= _T("下载已完成!");
	LPCTSTR lpNewsContent	= _T("   恭喜!文件下载完成了!您可以关闭客户端而'毫bit无伤'(仿'吞下玻璃...').\n\n  (点击弹窗内任何区域就可以闭关本弹窗)\n\n       Powered By MX-Codingland.\n       由MX-Codingland'强力驱动'");
	LPCTSTR lpNewsURL		= _T("https://www.baidu.com");
	NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_QQ));
	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_WANGWANG));
	//NewsWindow.SetSkin(MAKEINTRESOURCE(IDB_SKIN_XUNLEI),0xFFFFFF);
	if(!NewsWindow.Create(_T("MX-Codingland下载"))) return FALSE;
	NewsWindow.SetNews(lpNewsTitle,lpNewsContent,lpNewsURL);
	NewsWindow.Show();
	NewsWindow.SetMainWindow();
	return TRUE;
}