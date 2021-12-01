#include "resource.h"
#include "BForm.h"
#include "mdlOpenSaveDlg.h"

const int GCI_BARHEIGHT = 16;
const int GCI_BARSPACE = 8;
const int GCI_LEFTSPACE = 50;
const int GCI_RIGHTSPACE = 5;
const int GCI_TOPSPACE = 5;
int G_iLegs = 0;


CBForm form1(ID_form1);

void form1_Load();
void chkLeg1_Click();
void chkLeg2_Click();
void chkLeg3_Click();
void chkLeg4_Click();
void chkLeg5_Click();
void chkLeg6_Click();
void cmdSave_Click();
void cmdRefresh_Click();
void pic1_Paint();
BOOL SaveBitmapToFile(HBITMAP hBitmap, LPTSTR szfilename);
bool isDegital(LPTSTR szNumber);


int main()
{
	form1.EventAdd(0, eForm_Load, form1_Load);
	form1.EventAdd(ID_chkLeg1, eCommandButton_Click, chkLeg1_Click);
	form1.EventAdd(ID_chkLeg2, eCommandButton_Click, chkLeg2_Click);
	form1.EventAdd(ID_chkLeg3, eCommandButton_Click, chkLeg3_Click);
	form1.EventAdd(ID_chkLeg4, eCommandButton_Click, chkLeg4_Click);
	form1.EventAdd(ID_chkLeg5, eCommandButton_Click, chkLeg5_Click);
	form1.EventAdd(ID_chkLeg6, eCommandButton_Click, chkLeg6_Click);
	form1.EventAdd(ID_cmdSave, eCommandButton_Click, cmdSave_Click);
	form1.EventAdd(ID_cmdRefresh, eCommandButton_Click, cmdRefresh_Click);
	form1.EventAdd(ID_pic1, ePaint, pic1_Paint);
	form1.IconSet(IDI_ICON1);

	form1.Show();

	return 0;
}

void form1_Load()
{
	chkLeg1_Click();
	chkLeg2_Click();
	chkLeg3_Click();
	chkLeg4_Click();
	chkLeg5_Click();
	chkLeg6_Click();
}

void chkLeg1_Click()
{
	bool fChecked = (bool)form1.Control(ID_chkLeg1).ValueChecked();
	form1.Control(ID_txtInitState1).EnabledSet(fChecked);
	form1.Control(ID_txtFrames1).EnabledSet(fChecked);
	if (fChecked) G_iLegs += 1;
	else if (G_iLegs > 0) G_iLegs -= 1;
}
void chkLeg2_Click()
{
	bool fChecked = (bool)form1.Control(ID_chkLeg2).ValueChecked();
	form1.Control(ID_txtInitState2).EnabledSet(fChecked);
	form1.Control(ID_txtFrames2).EnabledSet(fChecked);
	if (fChecked) G_iLegs += 1;
	else if (G_iLegs > 0) G_iLegs -= 1;
}
void chkLeg3_Click()
{
	bool fChecked = (bool)form1.Control(ID_chkLeg3).ValueChecked();
	form1.Control(ID_txtInitState3).EnabledSet(fChecked);
	form1.Control(ID_txtFrames3).EnabledSet(fChecked);
	if (fChecked) G_iLegs += 1;
	else if (G_iLegs > 0) G_iLegs -= 1;
}
void chkLeg4_Click()
{
	bool fChecked = (bool)form1.Control(ID_chkLeg4).ValueChecked();
	form1.Control(ID_txtInitState4).EnabledSet(fChecked);
	form1.Control(ID_txtFrames4).EnabledSet(fChecked);
	if (fChecked) G_iLegs += 1;
	else if (G_iLegs > 0) G_iLegs -= 1;
}
void chkLeg5_Click()
{
	bool fChecked = (bool)form1.Control(ID_chkLeg5).ValueChecked();
	form1.Control(ID_txtInitState5).EnabledSet(fChecked);
	form1.Control(ID_txtFrames5).EnabledSet(fChecked);
	if (fChecked) G_iLegs += 1;
	else if (G_iLegs > 0) G_iLegs -= 1;
}
void chkLeg6_Click()
{
	bool fChecked = (bool)form1.Control(ID_chkLeg6).ValueChecked();
	form1.Control(ID_txtInitState6).EnabledSet(fChecked);
	form1.Control(ID_txtFrames6).EnabledSet(fChecked);
	if (fChecked) G_iLegs += 1;
	else if (G_iLegs > 0) G_iLegs -= 1;
}

void pic1_Paint()
{
	int i, j, k;
	int iPic1Width = form1.Control(ID_pic1).Width();
	int iPic1Height = form1.Control(ID_pic1).Height();
	int *pFrames;
	bool fLegState;
	int iRectLeft, iRectRight, iRectTop, iRectBottom;
	RECT rc;
	HDC hDC = GetDC(form1.Control(ID_pic1).hWnd());
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hPenOld = (HPEN)SelectObject(hDC, hPen);
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hDC, hBrush);

	// ��ջ�ͼ����
	rc.left = 0;
	rc.top = 0;
	rc.right = iPic1Width;
	rc.bottom = iPic1Height;
	FillRect(hDC, &rc, hBrush);

	// ��������ͼ���
	for (i = 0;i < G_iLegs;i++)
	{
		iRectLeft = GCI_LEFTSPACE;
		iRectTop = GCI_TOPSPACE + i*(GCI_BARHEIGHT + GCI_BARSPACE);
		iRectRight = iPic1Width - GCI_RIGHTSPACE;
		iRectBottom = i*(GCI_BARHEIGHT + GCI_BARSPACE) + GCI_BARHEIGHT + GCI_TOPSPACE;
		Rectangle(hDC, iRectLeft, iRectTop, iRectRight, iRectBottom);
	}

	// �л�Ϊ��ɫˢ��
	SelectObject(hDC, hBrushOld);
	DeleteObject(hBrush);
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hDC, hBrush);

	// ����֡�����Ʋ�̬��λͼ
	k = 0;
	for (i = 0;i < 6;i++)
	{
		int ID_chkLeg = ID_chkLeg1 + i;
		int ID_txtInitState = ID_txtInitState1 + i;
		int ID_txtFrames = ID_txtFrames1 + i;

		// ���ĳ����δѡ�У���������ѭ��
		if (!form1.Control(ID_chkLeg).ValueChecked())
			continue;

		// �����ο�ǰ����������
		rc.left = (GCI_LEFTSPACE - 40) / 2;
		rc.right = GCI_LEFTSPACE - (GCI_LEFTSPACE - 40) / 2;
		rc.top = GCI_TOPSPACE + k * (GCI_BARHEIGHT + GCI_BARSPACE);
		rc.bottom = GCI_TOPSPACE + k * (GCI_BARHEIGHT + GCI_BARSPACE) + GCI_BARHEIGHT;
		//DrawText(hDC, _tcscpy(Str(i+1),TEXT("����")), -1, &rc, DT_SINGLELINE | DT_VCENTER | DT_LEFT);
		DrawText(hDC, _tcscat(Str(i+1), TEXT("����")), -1, &rc, DT_SINGLELINE | DT_VCENTER | DT_LEFT);

		// ��ȡ��ʼ״̬
		LPTSTR szInitState = form1.Control(ID_txtInitState).Text();
		if (_tcscmp(szInitState, TEXT("0")) == 0 ||
			_tcscmp(szInitState, TEXT("��")) == 0 ||
			_tcscmp(szInitState, TEXT("��ɫ")) == 0 || 
			_tcscmp(szInitState, TEXT("֧��")) == 0)
		{
			fLegState = 0;
		}
		else if (_tcscmp(szInitState, TEXT("1")) == 0 ||
				 _tcscmp(szInitState, TEXT("��")) == 0 ||
				 _tcscmp(szInitState, TEXT("��ɫ")) == 0 ||
				 _tcscmp(szInitState, TEXT("�ڶ�")) == 0)
		{
			fLegState = 1;
		}
		else
		{
			MsgBox(TEXT("��������ȷ�ĳ�ʼ״̬��"), TEXT("��ʼ״̬����"), mb_OK, mb_IconError);
			return;
		}

		// ��ȡ��̬�л�֡
		LPTSTR szFramesText = form1.Control(ID_txtFrames).Text();
		TCHAR ** frames = NULL; int iLines, iFrames=0;
		iLines = Split(szFramesText, frames, TEXT("\r\n"));
		pFrames = new int[iLines];
		for (j = 0;j < iLines;j++)
		{
			if (isDegital(frames[j + 1]))
			{
				pFrames[iFrames] = (int)Val(frames[j + 1]);
				iFrames++;
			}
		}

		// ���ݲ�̬�л�֡���Ʋ�̬��λ
		for (j = 1;j < iFrames;j++)
		{
			if (!fLegState)
			{
				iRectLeft = GCI_LEFTSPACE + (iPic1Width - GCI_LEFTSPACE - GCI_RIGHTSPACE) * (pFrames[j - 1] - pFrames[0]) / (pFrames[iFrames - 1] - pFrames[0]);
				iRectRight = GCI_LEFTSPACE + (iPic1Width - GCI_LEFTSPACE - GCI_RIGHTSPACE) * (pFrames[j] - pFrames[0]) / (pFrames[iFrames - 1] - pFrames[0]);
				iRectTop = GCI_TOPSPACE + k * (GCI_BARHEIGHT + GCI_BARSPACE);
				iRectBottom = GCI_TOPSPACE + k * (GCI_BARHEIGHT + GCI_BARSPACE) + GCI_BARHEIGHT;
				Rectangle(hDC, iRectLeft, iRectTop, iRectRight, iRectBottom);
			}
			fLegState = !fLegState;
		}
		k++;
	}

	

	SelectObject(hDC, hBrushOld);
	DeleteObject(hBrush);
	SelectObject(hDC, hPenOld);
	DeleteObject(hPen);

	ReleaseDC(form1.Control(ID_pic1).hWnd(), hDC);
}

void cmdRefresh_Click()
{
	InvalidateRect(form1.Control(ID_pic1).hWnd(), 0, true);
}

void cmdSave_Click()
{
	int iPic1Width = form1.Control(ID_pic1).Width();
	int iPic1Height = form1.Control(ID_pic1).Height();
	
	form1.Control(ID_pic1).SetFocus();

	LPTSTR szFileSave;
	OsdSetFilter(TEXT("λͼ�ļ�(*.bmp)|*.bmp"));
	szFileSave = OsdSaveDlg(form1.hWnd());
	if (!(*szFileSave)) return;

	HDC hDC = GetDC(form1.Control(ID_pic1).hWnd());
	HDC hDCMem = CreateCompatibleDC(hDC);
	HBITMAP hBMP = CreateCompatibleBitmap(hDC, iPic1Width, GCI_TOPSPACE*2 + GCI_BARHEIGHT*G_iLegs + GCI_BARSPACE*(G_iLegs - 1));
	HBITMAP hBMPOld = (HBITMAP)SelectObject(hDCMem, hBMP);

	BitBlt(hDCMem, 0, 0, iPic1Width, GCI_TOPSPACE * 2 + GCI_BARHEIGHT*G_iLegs + GCI_BARSPACE*(G_iLegs - 1), hDC, 0, 0, SRCCOPY);
	SaveBitmapToFile(hBMP, szFileSave);

	SelectObject(hDCMem, hBMPOld);
	DeleteObject(hBMP);
	DeleteDC(hDCMem);
	ReleaseDC(form1.Control(ID_pic1).hWnd(), hDC);
}

BOOL SaveBitmapToFile(HBITMAP hBitmap, LPTSTR szfilename)
{
	HDC  hDC;
	int  iBits;   //��ǰ�ֱ�����ÿ������ռ�ֽ���  
	WORD  wBitCount;   //λͼ��ÿ������ռ�ֽ���  
	DWORD  dwPaletteSize = 0, dwBmBitsSize = 0, dwDIBSize = 0, dwWritten = 0; //�����ɫ���С, λͼ�������ֽڴ�С, λͼ�ļ���С, д���ļ��ֽ���   
	BITMAP  Bitmap;    //λͼ���Խṹ   
	BITMAPFILEHEADER  bmfHdr;    //λͼ�ļ�ͷ�ṹ  
	BITMAPINFOHEADER  bi;    //λͼ��Ϣͷ�ṹ  
	LPBITMAPINFOHEADER  lpbi;    //ָ��λͼ��Ϣͷ�ṹ 
	HANDLE  fh, hDib, hPal, hOldPal = NULL;   //�����ļ��������ڴ�������ɫ����  

											  //����λͼ�ļ�ÿ��������ռ�ֽ���   
	hDC = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
	iBits = GetDeviceCaps(hDC, BITSPIXEL) * GetDeviceCaps(hDC, PLANES);
	DeleteDC(hDC);
	if (iBits <= 1)
		wBitCount = 1;
	else if (iBits <= 4)
		wBitCount = 4;
	else if (iBits <= 8)
		wBitCount = 8;
	else
		wBitCount = 24;

	GetObject(hBitmap, sizeof(Bitmap), (LPSTR)&Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = wBitCount;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrImportant = 0;
	bi.biClrUsed = 0;

	dwBmBitsSize = ((Bitmap.bmWidth *wBitCount + 31) / 32) * 4 * Bitmap.bmHeight;

	//Ϊλͼ���ݷ����ڴ�   
	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	*lpbi = bi;

	// �����ɫ��    
	hPal = GetStockObject(DEFAULT_PALETTE);
	if (hPal)
	{
		hDC = ::GetDC(NULL);
		hOldPal = ::SelectPalette(hDC, (HPALETTE)hPal, FALSE);
		RealizePalette(hDC);
	}

	// ��ȡ�õ�ɫ�����µ�����ֵ   
	GetDIBits(hDC, hBitmap, 0, (UINT)Bitmap.bmHeight,
		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize,
			  (BITMAPINFO *)lpbi, DIB_RGB_COLORS);

	// �ָ���ɫ��    
	if (hOldPal)
	{
		::SelectPalette(hDC, (HPALETTE)hOldPal, TRUE);
		RealizePalette(hDC);
		::ReleaseDC(NULL, hDC);
	}

	//����λͼ�ļ�    
	fh = CreateFile(szfilename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
					FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);

	if (fh == INVALID_HANDLE_VALUE)  return  FALSE;

	//  ����λͼ�ļ�ͷ   
	bmfHdr.bfType = 0x4D42;  //  "BM"   
	dwDIBSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize;
	bmfHdr.bfSize = dwDIBSize;
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER) + dwPaletteSize;
	//  д��λͼ�ļ�ͷ   
	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
	//  д��λͼ�ļ���������   
	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);
	//���    
	GlobalUnlock(hDib);
	GlobalFree(hDib);
	CloseHandle(fh);

	return  TRUE;
}

bool isDegital(LPTSTR szNumber)
{
	int iStrSize = _tcsclen(szNumber);
	if (iStrSize == 0) return false;
	for (int i = 0;i < iStrSize; i++)
	{
		if (i==0 && szNumber[i] == TEXT('-') && iStrSize > 1)
			continue;
		if (szNumber[i] > TEXT('9') || szNumber[i] < TEXT('0'))
			return false;
	}
	return true;
}
