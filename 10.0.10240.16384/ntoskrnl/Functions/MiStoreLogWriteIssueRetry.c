// MiStoreLogWriteIssueRetry 
 
__int64 *__fastcall MiStoreLogWriteIssueRetry(__int64 *result, int a2, int a3, int a4, int a5)
{
  _DWORD *v6; // r5
  __int64 *v9; // r6
  int v10; // r2
  __int64 v11; // kr00_8
  int v12; // [sp+8h] [bp-C0h] BYREF
  int v13; // [sp+Ch] [bp-BCh] BYREF
  int v14; // [sp+10h] [bp-B8h] BYREF
  int v15; // [sp+14h] [bp-B4h] BYREF
  int v16; // [sp+18h] [bp-B0h] BYREF
  int v17[2]; // [sp+20h] [bp-A8h] BYREF
  _DWORD v18[40]; // [sp+28h] [bp-A0h] BYREF

  v6 = (_DWORD *)dword_634CA0;
  v9 = result;
  if ( dword_634CA0 && *(_DWORD *)dword_634CA0 > 5u )
  {
    result = (__int64 *)TlgKeywordOn(dword_634CA0, 2i64);
    if ( result )
    {
      v17[1] = 0;
      v11 = *v9;
      v15 = a3;
      v16 = a2;
      v12 = a4;
      v13 = HIDWORD(v11);
      v17[0] = v11;
      v14 = a5;
      v18[8] = v17;
      v18[9] = 0;
      v18[10] = 8;
      v18[11] = 0;
      v18[12] = &v13;
      v18[13] = 0;
      v18[14] = 4;
      v18[15] = 0;
      v18[16] = &v16;
      v18[17] = 0;
      v18[18] = 4;
      v18[19] = 0;
      v18[20] = &v15;
      v18[21] = 0;
      v18[22] = 4;
      v18[23] = 0;
      v18[24] = &v12;
      v18[25] = 0;
      v18[26] = 4;
      v18[27] = 0;
      v18[28] = &v14;
      v18[29] = 0;
      v18[30] = 4;
      v18[31] = 0;
      result = (__int64 *)MmTlgWrite(v6, (unsigned __int8 *)&byte_413FFD[1], v10, (int)byte_413FFD, 8, v18);
    }
  }
  return result;
}
