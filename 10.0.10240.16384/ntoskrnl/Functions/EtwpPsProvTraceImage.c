// EtwpPsProvTraceImage 
 
unsigned __int16 *__fastcall EtwpPsProvTraceImage(unsigned __int16 *result, int a2, int a3, int a4)
{
  int *v4; // r4
  _DWORD v5[36]; // [sp+20h] [bp-90h] BYREF

  if ( a3 == 5121 )
  {
    v4 = ImageLoad;
  }
  else
  {
    if ( a3 != 5122 )
      return result;
    v4 = ImageUnload;
  }
  v5[0] = a2;
  v5[1] = 0;
  v5[2] = 4;
  v5[3] = 0;
  v5[4] = a2 + 4;
  v5[5] = 0;
  v5[6] = 4;
  v5[7] = 0;
  v5[8] = a2 + 8;
  v5[9] = 0;
  v5[10] = 4;
  v5[11] = 0;
  v5[12] = a2 + 12;
  v5[13] = 0;
  v5[14] = 4;
  v5[15] = 0;
  v5[16] = a2 + 16;
  v5[17] = 0;
  v5[18] = 4;
  v5[19] = 0;
  v5[20] = a2 + 24;
  v5[21] = 0;
  v5[22] = 4;
  v5[23] = 0;
  v5[24] = *((_DWORD *)result + 1);
  v5[25] = 0;
  v5[26] = *result;
  v5[27] = 0;
  v5[28] = &EtwpNull;
  v5[29] = 0;
  v5[30] = 2;
  v5[31] = 0;
  return (unsigned __int16 *)EtwWriteEx(
                               EtwpPsProvRegHandle,
                               dword_61A934,
                               (int)v4,
                               (int)&EtwpPsProvRegHandle,
                               0,
                               0,
                               a4 != 0,
                               0,
                               0,
                               8,
                               (int)v5);
}
