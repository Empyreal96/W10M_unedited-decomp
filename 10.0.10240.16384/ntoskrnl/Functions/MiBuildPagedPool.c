// MiBuildPagedPool 
 
int MiBuildPagedPool()
{
  int v1; // r3
  unsigned int v2; // r6
  int v3; // r8
  unsigned int v4; // r5
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r5
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r0

  if ( (MiFlags & 1) != 0 || MmSpecialPoolTag || MmProtectFreedNonPagedPool == 1 )
  {
    v1 = 0;
  }
  else
  {
    if ( (unsigned int)dword_640508 >= 0x80000 )
      return sub_96A9A8();
    if ( (unsigned int)dword_640508 >= 0x40000 )
      v1 = 2 * dword_632D10;
    else
      v1 = 8;
  }
  dword_632D10 = v1;
  v2 = (unsigned int)(MiLowHalVa - dword_63389C) >> 12;
  dword_634D40 = (((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000;
  v3 = (unsigned int)(MiLowHalVa + 0x40000000) >> 12;
  dword_632D00 = -1070596096;
  v4 = ((v2 + 7) >> 3) + 4095;
  MmSizeOfPagedPoolInBytes = v2 << 12;
  dword_634D54 = v2;
  byte_634EF0 = byte_634EF0 & 0xF8 | 3;
  if ( !MiInitializeSystemWorkingSetList((int)&dword_634E80, v2) )
    return 0;
  v5 = MiReservePtes(&dword_634D58, v4 >> 12);
  if ( !v5 )
    MiIssueNoPtesBugcheck(v4 >> 12, v6, v7, v8);
  MiInitializeDynamicBitmap((unsigned int *)&dword_634D38, v5 << 10, dword_634D54, 3);
  dword_634D44 = dword_634D54;
  dword_634D38 = 0;
  dword_634D34[0] = 0;
  v9 = ((unsigned int)(v3 + 7) >> 3) + 4095;
  v10 = MiReservePtes(&dword_634D58, v9 >> 12);
  if ( !v10 )
    MiIssueNoPtesBugcheck(v9 >> 12, v11, v12, v13);
  v14 = MiInitializeDynamicBitmap((unsigned int *)&dword_632CF8, v10 << 10, v3, 3);
  dword_632D04 = v3;
  dword_632CF8 = 0;
  InitializePagedPool(v14);
  dword_632AE8 = 7680;
  if ( v2 / 5 < 0x1E00 )
    dword_632AE8 = v2 / 5;
  dword_632AEC = 15360;
  if ( 2 * v2 / 5 < 0x3C00 )
    dword_632AEC = 2 * v2 / 5;
  return 1;
}
