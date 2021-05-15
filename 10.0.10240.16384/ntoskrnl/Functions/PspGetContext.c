// PspGetContext 
 
_DWORD *__fastcall PspGetContext(_DWORD *result, int **a2, int *a3)
{
  int v3; // r8
  _DWORD *v6; // r7
  int v7; // r4
  int v8; // r0
  int *v9; // r2
  int *v10; // r2
  int *v11; // r2
  int *v12; // r2
  int *v13; // r2
  int *v14; // r2
  int *v15; // r2
  int *v16; // r2
  int v17; // r3
  unsigned int v18; // r3
  unsigned int v19; // r3
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r1
  int v32; // r2
  int v33; // r3

  v3 = *a3;
  v6 = result;
  if ( (*a3 & 0x200001) == 2097153 )
  {
    a3[14] = result[29];
    a3[15] = result[30];
    a3[16] = result[32];
    a3[17] = result[33];
  }
  if ( (v3 & 0x200002) == 2097154 )
  {
    a3[1] = result[24];
    a3[2] = result[25];
    a3[3] = result[26];
    a3[4] = result[27];
    a3[13] = result[28];
    a3[5] = **a2;
    a3[6] = *a2[1];
    a3[7] = *a2[2];
    a3[8] = *a2[3];
    a3[9] = *a2[4];
    a3[10] = *a2[5];
    a3[11] = *a2[6];
    a3[12] = *a2[7];
  }
  if ( (v3 & 0x200004) == 2097156 )
  {
    v7 = KiGetVfpStatePointer((int)result);
    v8 = (int)(a3 + 20);
    if ( !v7 )
      return (_DWORD *)sub_803578(v8);
    a3[18] = *(_DWORD *)(v7 + 4) & 0xFFC8FFFF;
    memmove(v8, v7 + 16, 0x40u);
    result = (_DWORD *)memmove((int)(a3 + 52), v7 + 144, 0x80u);
    v9 = a2[9];
    a3[36] = *v9;
    a3[37] = v9[1];
    v10 = a2[10];
    a3[38] = *v10;
    a3[39] = v10[1];
    v11 = a2[11];
    a3[40] = *v11;
    a3[41] = v11[1];
    v12 = a2[12];
    a3[42] = *v12;
    a3[43] = v12[1];
    v13 = a2[13];
    a3[44] = *v13;
    a3[45] = v13[1];
    v14 = a2[14];
    a3[46] = *v14;
    a3[47] = v14[1];
    v15 = a2[15];
    a3[48] = *v15;
    a3[49] = v15[1];
    v16 = a2[16];
    a3[50] = *v16;
    a3[51] = v16[1];
  }
  if ( (v3 & 0x200008) == 2097160 )
  {
    if ( *((_BYTE *)v6 + 18) )
    {
      v22 = v6[7];
      v23 = v6[8];
      v24 = v6[9];
      a3[84] = v6[6];
      a3[85] = v22;
      a3[86] = v23;
      a3[87] = v24;
      v25 = v6[11];
      v26 = v6[12];
      v27 = v6[13];
      a3[88] = v6[10];
      a3[89] = v25;
      a3[90] = v26;
      a3[91] = v27;
      v28 = v6[15];
      v29 = v6[16];
      v30 = v6[17];
      a3[92] = v6[14];
      a3[93] = v28;
      a3[94] = v29;
      a3[95] = v30;
      result = (_DWORD *)v6[18];
      v31 = v6[19];
      v32 = v6[20];
      v33 = v6[21];
      a3[96] = (int)result;
      a3[97] = v31;
      a3[98] = v32;
      a3[99] = v33;
      a3[100] = v6[22];
      v17 = v6[23];
    }
    else
    {
      memset((_BYTE *)a3 + 336, 0, 32);
      result = memset((_BYTE *)a3 + 368, 0, 32);
      v17 = 0;
      a3[100] = 0;
    }
    a3[101] = v17;
  }
  if ( (v3 & 0x40000000) != 0 )
  {
    v18 = *a3 & 0xE7FFFFFF;
    *a3 = v18;
    v19 = v18 | 0x80000000;
    *a3 = v19;
    v20 = *((unsigned __int8 *)v6 + 16);
    if ( v20 == 1 )
    {
      v21 = v19 | 0x8000000;
    }
    else
    {
      if ( v20 != 2 )
        return result;
      v21 = v19 | 0x10000000;
    }
    *a3 = v21;
  }
  return result;
}
