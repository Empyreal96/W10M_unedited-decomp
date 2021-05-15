// MiInitializePteInfo 
 
int __fastcall MiInitializePteInfo(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r6
  int v7; // r0
  int result; // r0
  __int64 v9; // r2

  v4 = a4 >> 12;
  v7 = MiReservePtes(&dword_634D58, ((((((a4 >> 12) + 15) >> 4) + 7) >> 3) + 4095) >> 12);
  if ( !v7 )
    sub_96A9A0();
  result = MiInitializeDynamicBitmap((unsigned int *)a1, v7 << 10, v4 >> 4, 3);
  *(_DWORD *)(a1 + 12) = 6;
  *(_DWORD *)(a1 + 16) = 12;
  *(_DWORD *)(a1 + 20) = a1 + 24;
  *(_DWORD *)(a1 + 8) = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
  HIDWORD(v9) = dword_634F00;
  LODWORD(v9) = 0;
  *(_QWORD *)(a1 + 28) = v9;
  *(_DWORD *)a1 = 0;
  return result;
}
