// WdipSemSqmAddToStream 
 
int __fastcall WdipSemSqmAddToStream(int a1, unsigned int a2, int a3, int a4)
{
  char *v4; // r3
  int v6; // [sp+8h] [bp-218h] BYREF
  int v7; // [sp+Ch] [bp-214h] BYREF
  int v8[18]; // [sp+10h] [bp-210h] BYREF
  char v9; // [sp+58h] [bp-1C8h] BYREF
  int varg_r0; // [sp+228h] [bp+8h] BYREF
  int varg_r1[3]; // [sp+22Ch] [bp+Ch] BYREF

  varg_r0 = a1;
  varg_r1[1] = a3;
  varg_r1[2] = a4;
  v6 = 1;
  varg_r1[0] = a2;
  v7 = 48;
  v8[0] = 11;
  if ( !a3 || !a2 || a2 > 9 )
    return -1073741811;
  v8[2] = (int)WinSqmGlobalSession;
  v8[3] = 0;
  v8[4] = 16;
  v8[5] = 0;
  v8[6] = (int)&varg_r0;
  v8[7] = 0;
  v8[8] = 4;
  v8[9] = 0;
  v8[10] = (int)v8;
  v8[11] = 0;
  v8[12] = 4;
  v8[13] = 0;
  v8[14] = (int)varg_r1;
  v8[15] = 0;
  v8[16] = 4;
  v8[17] = 0;
  v4 = &v9;
  do
  {
    *(_DWORD *)v4 = &v6;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = 4;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 4) = a3;
    *((_DWORD *)v4 + 5) = 0;
    *((_DWORD *)v4 + 6) = 4;
    *((_DWORD *)v4 + 7) = 0;
    *((_DWORD *)v4 + 8) = &v7;
    *((_DWORD *)v4 + 9) = 0;
    *((_DWORD *)v4 + 10) = 4;
    *((_DWORD *)v4 + 11) = 0;
    v4 += 48;
    a3 += 4;
    --a2;
  }
  while ( a2 );
  return WdipSemWriteEvent(WdipSemRegHandle, SHIDWORD(WdipSemRegHandle), (int)WDI_SEM_EVENT_SQM_ADD_TO_STREAM, 0);
}
