// PopTraceEsState 
 
int __fastcall PopTraceEsState(int result, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, int a8, unsigned __int8 a9)
{
  int v11; // r7
  int v12; // [sp+8h] [bp-C8h] BYREF
  int v13; // [sp+Ch] [bp-C4h] BYREF
  int v14; // [sp+10h] [bp-C0h] BYREF
  int v15; // [sp+14h] [bp-BCh] BYREF
  int v16; // [sp+18h] [bp-B8h] BYREF
  int v17; // [sp+1Ch] [bp-B4h] BYREF
  _DWORD v18[2]; // [sp+20h] [bp-B0h] BYREF
  _DWORD v19[42]; // [sp+28h] [bp-A8h] BYREF

  v11 = result;
  if ( (unsigned int)dword_6163C8 > 5 )
  {
    result = TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64);
    if ( result )
    {
      v16 = v11;
      v18[0] = a3;
      v18[1] = a4;
      v14 = a5;
      v17 = a6;
      v12 = a7;
      v13 = a8;
      v15 = a9;
      v19[8] = &v16;
      v19[9] = 0;
      v19[10] = 4;
      v19[11] = 0;
      v19[12] = v18;
      v19[13] = 0;
      v19[14] = 8;
      v19[15] = 0;
      v19[16] = &v14;
      v19[17] = 0;
      v19[18] = 4;
      v19[19] = 0;
      v19[20] = &v17;
      v19[21] = 0;
      v19[22] = 4;
      v19[23] = 0;
      v19[24] = &v12;
      v19[25] = 0;
      v19[26] = 4;
      v19[27] = 0;
      v19[28] = &v13;
      v19[29] = 0;
      v19[30] = 4;
      v19[31] = 0;
      v19[32] = &v15;
      v19[33] = 0;
      v19[34] = 4;
      v19[35] = 0;
      result = TlgWrite(&dword_6163C8, (unsigned __int8 *)&word_41458E + 1, 0, 0, 9, v19);
    }
  }
  return result;
}
