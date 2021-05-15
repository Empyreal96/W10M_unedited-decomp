// MiStoreLogWriteIssueFailure 
 
int __fastcall MiStoreLogWriteIssueFailure(int result, int *a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // r5
  int v10; // r9
  int v11; // r2
  int v12; // r3
  int v13; // [sp+8h] [bp-D0h] BYREF
  int v14; // [sp+Ch] [bp-CCh] BYREF
  int v15; // [sp+10h] [bp-C8h] BYREF
  int v16; // [sp+14h] [bp-C4h] BYREF
  int v17; // [sp+18h] [bp-C0h] BYREF
  int v18; // [sp+1Ch] [bp-BCh] BYREF
  int v19[2]; // [sp+20h] [bp-B8h] BYREF
  _DWORD v20[44]; // [sp+28h] [bp-B0h] BYREF

  v7 = (_DWORD *)dword_634CA0;
  v10 = result;
  if ( dword_634CA0 && *(_DWORD *)dword_634CA0 > 5u )
  {
    result = TlgKeywordOn(dword_634CA0, 2i64);
    if ( result )
    {
      v12 = *a2;
      v17 = v10;
      v18 = a3;
      v13 = a4;
      v19[0] = v12;
      v19[1] = 0;
      v15 = a2[1];
      v14 = a5;
      v16 = a6;
      v20[8] = &v17;
      v20[9] = 0;
      v20[10] = 4;
      v20[11] = 0;
      v20[12] = v19;
      v20[13] = 0;
      v20[14] = 8;
      v20[15] = 0;
      v20[16] = &v15;
      v20[17] = 0;
      v20[18] = 4;
      v20[19] = 0;
      v20[20] = &v18;
      v20[21] = 0;
      v20[22] = 4;
      v20[23] = 0;
      v20[24] = &v13;
      v20[25] = 0;
      v20[26] = 4;
      v20[27] = 0;
      v20[28] = &v14;
      v20[29] = 0;
      v20[30] = 4;
      v20[31] = 0;
      v20[32] = &v16;
      v20[33] = 0;
      v20[34] = 4;
      v20[35] = 0;
      result = MmTlgWrite(v7, (unsigned __int8 *)dword_4140F8 + 1, v11, (int)dword_4140F8, 9, v20);
    }
  }
  return result;
}
