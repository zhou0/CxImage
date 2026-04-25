#if !defined(__ximadefs_h)
#define __ximadefs_h

#include "ximacfg.h"

#if !defined(WIN32) && !defined(_WIN32_WCE)
  #include <stdint.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  #include <stdio.h>
  #include <math.h>
  #ifdef __cplusplus
    #include <algorithm>
    #include <limits>
    #include <vector>
    #include <string>
    #include <list>
    #include <map>
    #include <set>
    #include <deque>
    #include <stack>
    #include <queue>
  #endif
#endif

#if /*defined(_AFXDLL)||*/defined(_USRDLL)
 #define DLL_EXP __declspec(dllexport)
#elif defined(_MSC_VER)&&(_MSC_VER<1200)
 #define DLL_EXP __declspec(dllimport)
#else
 #define DLL_EXP
#endif

#if CXIMAGE_SUPPORT_EXCEPTION_HANDLING
  #define cx_try try
  #define cx_throw(message) throw(message)
  #define cx_catch catch (const char *message)
#else
  #define cx_try bool cx_error=false;
  #define cx_throw(message) {cx_error=true; if(strcmp(message,"")) strncpy(info.szLastError,message,255); goto cx_error_catch;}
  #define cx_catch cx_error_catch: char message[]=""; if(cx_error)
#endif


#if CXIMAGE_SUPPORT_JP2 || CXIMAGE_SUPPORT_JPC || CXIMAGE_SUPPORT_PGX || CXIMAGE_SUPPORT_PNM || CXIMAGE_SUPPORT_RAS
 #define CXIMAGE_SUPPORT_JASPER 1
#else
 #define CXIMAGE_SUPPORT_JASPER 0
#endif

#if CXIMAGE_SUPPORT_DSP
#undef CXIMAGE_SUPPORT_TRANSFORMATION
 #define CXIMAGE_SUPPORT_TRANSFORMATION 1
#endif

#if CXIMAGE_SUPPORT_TRANSFORMATION || CXIMAGE_SUPPORT_TIF || CXIMAGE_SUPPORT_TGA || CXIMAGE_SUPPORT_BMP || CXIMAGE_SUPPORT_WINDOWS
 #define CXIMAGE_SUPPORT_BASICTRANSFORMATIONS 1
#endif

#if CXIMAGE_SUPPORT_DSP || CXIMAGE_SUPPORT_TRANSFORMATION
#undef CXIMAGE_SUPPORT_INTERPOLATION
 #define CXIMAGE_SUPPORT_INTERPOLATION 1
#endif

#if (CXIMAGE_SUPPORT_DECODE == 0)
#undef CXIMAGE_SUPPORT_EXIF
 #define CXIMAGE_SUPPORT_EXIF 0
#endif

#if defined (_WIN32_WCE)
 #undef CXIMAGE_SUPPORT_WMF
 #define CXIMAGE_SUPPORT_WMF 0
#endif

#if !defined(WIN32) && !defined(_WIN32_WCE)
 #undef CXIMAGE_SUPPORT_WINDOWS
 #define CXIMAGE_SUPPORT_WINDOWS 1
#endif

#ifndef PI
 #define PI 3.141592653589793f
#endif

#if defined(WIN32) || defined(_WIN32_WCE)
#include <windows.h>
#include <tchar.h>
#include "stdint.h"
#endif

#if !defined(WIN32) && !defined(_WIN32_WCE)

typedef uint32_t   COLORREF;
typedef void*      HANDLE;
typedef void*      HRGN;
typedef void*      HDC;
typedef void*      HBITMAP;
typedef void*      HICON;
typedef void*      HPALETTE;
typedef void*      HFONT;
typedef void*      HGDIOBJ;
typedef void*      HENHMETAFILE;
typedef void*      LPVOID;
typedef char*      LPSTR;
typedef uint8_t    BYTE;
typedef uint16_t   WORD;
typedef uint32_t   DWORD;
typedef unsigned long  ULONG;
typedef BYTE*      PBYTE;

#ifndef BOOL
#define	BOOL bool
#endif

#include <math.h>
#ifndef TRUE
#define	TRUE true
#endif

#ifndef FALSE
#define	FALSE false
#endif

#ifndef TCHAR
#define TCHAR char
#define _T(x) x
#endif

typedef struct tagRECT
{
	int32_t    left;
	int32_t    top;
	int32_t    right;
	int32_t    bottom;
} RECT;

typedef struct tagPOINT
{
	int32_t  x;
	int32_t  y;
} POINT;

typedef struct tagRGBQUAD {
	uint8_t    rgbBlue;
	uint8_t    rgbGreen;
	uint8_t    rgbRed;
	uint8_t    rgbReserved;
} RGBQUAD;

typedef struct tagRGBTRIPLE {
	uint8_t    rgbtBlue;
	uint8_t    rgbtGreen;
	uint8_t    rgbtRed;
} RGBTRIPLE;

typedef struct tagPALETTEENTRY {
  uint8_t peRed;
  uint8_t peGreen;
  uint8_t peBlue;
  uint8_t peFlags;
} PALETTEENTRY, *PPALETTEENTRY;

typedef struct tagLOGPALETTE {
  uint16_t palVersion;
  uint16_t palNumEntries;
  PALETTEENTRY palPalEntry[1];
} LOGPALETTE, *PLOGPALETTE;

typedef struct tagLOGFONT {
  long lfHeight;
  long lfWidth;
  long lfEscapement;
  long lfOrientation;
  long lfWeight;
  uint8_t lfItalic;
  uint8_t lfUnderline;
  uint8_t lfStrikeOut;
  uint8_t lfCharSet;
  uint8_t lfOutPrecision;
  uint8_t lfClipPrecision;
  uint8_t lfQuality;
  uint8_t lfPitchAndFamily;
  TCHAR lfFaceName[32];
} LOGFONT;

typedef struct tagBITMAP {
  long bmType;
  long bmWidth;
  long bmHeight;
  long bmWidthBytes;
  uint16_t bmPlanes;
  uint16_t bmBitsPixel;
  void* bmBits;
} BITMAP;

typedef struct tagICONINFO {
  bool fIcon;
  uint32_t xHotspot;
  uint32_t yHotspot;
  HBITMAP hbmMask;
  HBITMAP hbmColor;
} ICONINFO;

typedef struct tagENHMETAHEADER {
  uint32_t iType;
  uint32_t nSize;
  RECT rclBounds;
  RECT rclFrame;
  uint32_t dSignature;
  uint32_t nVersion;
  uint32_t nBytes;
  uint32_t nRecords;
  uint16_t nHandles;
  uint16_t sReserved;
  uint32_t nDescription;
  uint32_t offDescription;
  uint32_t nPalEntries;
  POINT szlDevice;
  POINT szlMillimeters;
} ENHMETAHEADER;

typedef struct tagMETAHEADER {
  uint16_t mtType;
  uint16_t mtHeaderSize;
  uint16_t mtVersion;
  uint32_t mtSize;
  uint16_t mtNoObjects;
  uint32_t mtMaxRecord;
  uint16_t mtNoParameters;
} METAHEADER;

typedef struct tagMETAFILEPICT {
  long mm;
  long xExt;
  long yExt;
  void* hMF;
} METAFILEPICT;

#pragma pack(1)

typedef struct tagBITMAPINFOHEADER{
	uint32_t   biSize;
	int32_t    biWidth;
	int32_t    biHeight;
	uint16_t   biPlanes;
	uint16_t   biBitCount;
	uint32_t   biCompression;
	uint32_t   biSizeImage;
	int32_t    biXPelsPerMeter;
	int32_t    biYPelsPerMeter;
	uint32_t   biClrUsed;
	uint32_t   biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD bmiColors[1];
} BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;

typedef struct tagBITMAPCOREHEADER {
	uint32_t   bcSize;
	uint16_t   bcWidth;
	uint16_t   bcHeight;
	uint16_t   bcPlanes;
	uint16_t   bcBitCount;
} BITMAPCOREHEADER;

typedef struct tagBITMAPCOREINFO {
  BITMAPCOREHEADER bmciHeader;
  RGBTRIPLE bmciColors[1];
} BITMAPCOREINFO, *LPBITMAPCOREINFO;

typedef struct tagDIBSECTION {
  BITMAP dsBm;
  BITMAPINFOHEADER dsBmih;
  uint32_t dsBitfields[3];
  HANDLE dshSection;
  uint32_t dsOffset;
} DIBSECTION;

typedef struct tagBITMAPFILEHEADER {
	uint16_t   bfType;
	uint32_t   bfSize;
	uint16_t   bfReserved1;
	uint16_t   bfReserved2;
	uint32_t   bfOffBits;
} BITMAPFILEHEADER;

#pragma pack()

#define SRCCOPY 0x00CC0020
#define SRCAND 0x008800C6
#define SRCPAINT 0x00EE0086
#define SRCINVERT 0x00660046
#define COLORONCOLOR 3
#define DIB_RGB_COLORS 0
#define OPAQUE 2
#define ETO_OPAQUE 0x0002

#define RGN_OR 2
#define RGN_AND 1
#define DT_CALCRECT 0x00000400
#define DT_NOPREFIX 0x00000800
#define DT_CENTER 1
#define DT_LEFT 0
#define DT_RIGHT 2
#define _tcscpy strcpy
#define _tcsncpy strncpy
#define _tcsclen strlen
#define _tcslen strlen
#define DEFAULT_CHARSET 1
#define EASTEUROPE_CHARSET 238
#define OUT_DEFAULT_PRECIS 0
#define CLIP_DEFAULT_PRECIS 0
#define PROOF_QUALITY 2
#define DEFAULT_PITCH 0
#define FF_DONTCARE 0
#define FW_NORMAL 400
#define DEFAULT_GUI_FONT 17
#define COLOR_WINDOW 5

#define GHND 0x0042
#define PATCOPY 0x00F00021
#define ENHMETA_SIGNATURE 0x464D4520
#define MM_TEXT 1
#define EMR_HEADER 1
#define MM_ANISOTROPIC 8
#define LOGPIXELSX 88
#define LOGPIXELSY 90
#define BITSPIXEL 12

#define GMEM_FIXED 0x0000
#define GMEM_ZEROINIT 0x0040

typedef void*      HBRUSH;

#ifdef __cplusplus
inline int SaveDC(HDC) { return 1; }
inline void RestoreDC(HDC, int) {}
inline HDC CreateCompatibleDC(HDC) { return 0; }
inline void DeleteDC(HDC) {}
inline void DeleteObject(void*) {}
inline void* SelectObject(HDC, void*) { return 0; }
inline void* GetStockObject(int) { return 0; }
inline void BitBlt(HDC,int,int,int,int,HDC,int,int,uint32_t) {}
inline void SetStretchBltMode(HDC,int) {}
inline void StretchDIBits(HDC,int,int,int,int,int,int,int,int,const void*,const void*,uint32_t,uint32_t) {}
inline void SetDIBitsToDevice(HDC,int,int,int,int,int,int,int,int,const void*,const void*,uint32_t) {}
inline void* CreateDIBSection(HDC,const void*,uint32_t,void**,void*,uint32_t) { return 0; }
inline void GetClipBox(HDC,RECT*) {}
inline void* CreateRectRgnIndirect(const RECT*) { return 0; }
inline void ExtSelectClipRgn(HDC,void*,int) {}
inline void* CreateIconIndirect(void*) { return 0; }
inline void DrawText(HDC,const TCHAR*,int,RECT*,uint32_t) {}
inline bool ExtTextOut(HDC,int,int,uint32_t,const RECT*,const TCHAR*,uint32_t,const int*) { return true; }

inline COLORREF SetTextColor(HDC,COLORREF) { return 0; }
inline COLORREF SetBkColor(HDC,COLORREF) { return 0; }
inline int SetBkMode(HDC,int) { return 0; }
inline void* CreateFontIndirect(const LOGFONT*) { return 0; }
inline void* GetDC(void*) { return 0; }
inline void ReleaseDC(void*, void*) {}
inline void StretchBlt(HDC,int,int,int,int,HDC,int,int,int,int,uint32_t) {}
inline void* CreateCompatibleBitmap(HDC,int,int) { return 0; }
inline void* CreateBitmap(int,int,int,int,const void*) { return 0; }
inline bool RectVisible(HDC,const RECT*) { return true; }
inline int GetObject(void*,int,void*) { return 0; }
inline int GetDIBits(HDC,HBITMAP,uint32_t,uint32_t,void*,void*,uint32_t) { return 0; }
inline bool GetIconInfo(HICON,ICONINFO*) { return true; }
inline uint32_t RealizePalette(HDC) { return 0; }
inline void* GlobalLock(void*) { return 0; }
inline bool GlobalUnlock(void*) { return true; }
inline void* GlobalAlloc(uint32_t,uint32_t) { return 0; }
inline void* GlobalFree(void*) { return 0; }
inline uint32_t GlobalSize(void*) { return 0; }
inline void* CreateDIBPatternBrushPt(const void*,uint32_t) { return 0; }
inline bool SetBrushOrgEx(HDC,int,int,POINT*) { return true; }
inline bool PatBlt(HDC,int,int,int,int,uint32_t) { return true; }
inline void* CreateRectRgn(int,int,int,int) { return 0; }
inline int CombineRgn(HRGN,HRGN,HRGN,int) { return 0; }
inline void* SetEnhMetaFileBits(uint32_t,const uint8_t*) { return 0; }
inline uint32_t GetEnhMetaFileHeader(void*,uint32_t,ENHMETAHEADER*) { return 0; }
inline bool DeleteEnhMetaFile(void*) { return true; }
inline void* SetWinMetaFileBits(uint32_t,const uint8_t*,HDC,const METAFILEPICT*) { return 0; }
inline int GetDeviceCaps(HDC,int) { return 96; }
inline uint32_t GetSysColor(int) { return 0xFFFFFF; }

inline void* SelectPalette(HDC,HPALETTE,bool) { return 0; }
inline bool PlayEnhMetaFile(HDC,HENHMETAFILE,const RECT*) { return true; }
inline uint32_t GetEnhMetaFilePaletteEntries(void*,uint32_t,PALETTEENTRY*) { return 0; }
inline void* CreatePalette(const LOGPALETTE*) { return 0; }
#endif

#define BI_RGB        0L
#define BI_RLE8       1L
#define BI_RLE4       2L
#define BI_BITFIELDS  3L

#define GetRValue(rgb)      ((uint8_t)(rgb))
#define GetGValue(rgb)      ((uint8_t)(((uint16_t)(rgb)) >> 8))
#define GetBValue(rgb)      ((uint8_t)((rgb)>>16))
#define RGB(r,g,b)          ((COLORREF)(((uint8_t)(r)|((uint16_t)((uint8_t)(g))<<8))|(((uint32_t)(uint8_t)(b))<<16)))

#ifndef _COMPLEX_DEFINED
typedef struct tagcomplex {
	double x,y;
} _complex;
#endif

#define _cabs(c) sqrt(c.x*c.x+c.y*c.y)

#define _stricmp strcasecmp
#define _strnicmp strncasecmp

#endif

#ifndef min
#define min(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef max
#define max(a,b) (((a)>(b))?(a):(b))
#endif

#endif //__ximadefs
