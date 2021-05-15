// WdipSemSqmIncrementDword 
 
int __fastcall WdipSemSqmIncrementDword(int a1, int a2)
{
  int v3; // [sp+8h] [bp-60h] BYREF
  int v4[22]; // [sp+Ch] [bp-5Ch] BYREF
  int v5; // [sp+64h] [bp-4h] BYREF

  v4[21] = a1;
  v5 = a2;
  v4[0] = 450;
  v3 = 6;
  v4[1] = (int)WinSqmGlobalSession;
  v4[2] = 0;
  v4[3] = 16;
  v4[4] = 0;
  v4[5] = (int)v4;
  v4[6] = 0;
  v4[7] = 4;
  v4[8] = 0;
  v4[9] = (int)&v3;
  v4[10] = 0;
  v4[11] = 4;
  v4[12] = 0;
  v4[13] = (int)&v5;
  v4[14] = 0;
  v4[15] = 4;
  v4[16] = 0;
  return WdipSemWriteEvent(WdipSemRegHandle, SHIDWORD(WdipSemRegHandle), (int)WDI_SEM_EVENT_SQM_INCREMENT_DWORD, 0);
}
