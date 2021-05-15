// HvSwapLogFiles 
 
_DWORD *__fastcall HvSwapLogFiles(_DWORD *a1, int a2)
{
  int v3; // r9
  int v4; // r10
  _DWORD *result; // r0
  int v6; // r7
  int v7; // r8
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r3
  char v15; // [sp+8h] [bp-E8h] BYREF
  int v16; // [sp+Ch] [bp-E4h] BYREF
  int v17[2]; // [sp+10h] [bp-E0h] BYREF
  int v18; // [sp+18h] [bp-D8h] BYREF
  int v19; // [sp+1Ch] [bp-D4h] BYREF
  int v20; // [sp+20h] [bp-D0h] BYREF
  int v21; // [sp+24h] [bp-CCh] BYREF
  int v22[2]; // [sp+28h] [bp-C8h] BYREF
  _DWORD v23[48]; // [sp+30h] [bp-C0h] BYREF

  if ( a2 )
    return (_DWORD *)sub_7D1F20();
  v3 = HvGetEffectiveLogSizeCapForHive(a1);
  v4 = a1[2 * HvpLogTypeToLogArrayIndex(a1[24]) + 488];
  v16 = a1[25] - a1[26];
  result = KeQuerySystemTime(v17);
  v7 = v17[0];
  v6 = v17[1];
  if ( (unsigned int)dword_616398 > 5 )
  {
    result = (_DWORD *)TlgKeywordOn((int)&dword_616398, 0x400000000000i64);
    if ( result )
    {
      v8 = a1[238];
      v9 = a1[33];
      v15 = 1;
      v20 = v8;
      v10 = a1[29];
      v18 = v3;
      v19 = v10;
      v11 = a1[27];
      v17[0] = v4;
      v21 = v11;
      v12 = (__PAIR64__(v6, v7) - __PAIR64__(v9, a1[32])) >> 32;
      v22[0] = v7 - a1[32];
      v22[1] = v12;
      v23[8] = &v15;
      v23[9] = 0;
      v23[10] = 1;
      v23[11] = 0;
      v23[12] = &v20;
      v23[13] = 0;
      v23[14] = 4;
      v23[15] = 0;
      v23[16] = &v19;
      v23[17] = 0;
      v23[18] = 4;
      v23[19] = 0;
      v23[20] = &v18;
      v23[21] = 0;
      v23[22] = 4;
      v23[23] = 0;
      v23[24] = &v21;
      v23[25] = 0;
      v23[26] = 4;
      v23[27] = 0;
      v23[28] = v17;
      v23[29] = 0;
      v23[30] = 4;
      v23[31] = 0;
      v23[32] = &v16;
      v23[33] = 0;
      v23[34] = 4;
      v23[35] = 0;
      v23[36] = v22;
      v23[37] = 0;
      v23[38] = 8;
      v23[39] = 0;
      result = (_DWORD *)TlgWrite(&dword_616398, (unsigned __int8 *)&word_4136D6 + 1, 0, 0, 10, v23);
    }
  }
  if ( a1[24] == 4 )
    v13 = 5;
  else
    v13 = 4;
  a1[24] = v13;
  a1[27] = 0;
  v14 = a1[25];
  a1[32] = v7;
  a1[33] = v6;
  a1[26] = v14;
  return result;
}
