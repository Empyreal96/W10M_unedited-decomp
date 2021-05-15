// PpmTranslatePlatformIdleAccounting 
 
_DWORD *__fastcall PpmTranslatePlatformIdleAccounting(_DWORD *result, _DWORD *a2)
{
  int v2; // r5
  _DWORD *v3; // r4
  unsigned int v4; // r9
  unsigned int v5; // r10
  int *v6; // r6
  int *v7; // r7
  int v8; // kr00_4
  __int64 v9; // r0
  int *v10; // r8
  _DWORD *v11; // r4
  int v12; // r5
  __int64 v13; // r0
  int v14; // r3
  int v15; // [sp+0h] [bp-28h]

  v2 = result[1];
  v3 = a2;
  v4 = 0;
  *a2 = v2;
  v15 = v2;
  v5 = 0;
  a2[1] = *result;
  a2[4] = result[4];
  a2[5] = result[5];
  if ( v2 )
  {
    v6 = result + 6;
    v7 = a2 + 8;
    do
    {
      v8 = *v6 + v6[2] + v6[1];
      *v7 = v8;
      v5 = (__PAIR64__(v5, v4) + (unsigned int)v8) >> 32;
      v4 += v8;
      v7[1] = v6[1];
      v7[2] = *v6;
      v7[5] = v6[10];
      LODWORD(v9) = PpmConvertTimeTo(v6[8], v6[9]);
      *((_QWORD *)v7 + 3) = v9;
      v7[4] = PpmConvertTimeTo(v6[6], v6[7]);
      v7[3] = PpmConvertTimeTo(v6[4], v6[5]);
      v10 = v6 + 40;
      v11 = v7 + 10;
      v12 = 26;
      do
      {
        LODWORD(v13) = PpmConvertTimeTo(*v10, v10[1]);
        *(_QWORD *)v11 = v13;
        v11[2] = PpmConvertTimeTo(v10[2], v10[3]);
        result = (_DWORD *)PpmConvertTimeTo(v10[4], v10[5]);
        v11[3] = result;
        v14 = v10[6];
        v10 += 8;
        v11[4] = v14;
        v11 += 6;
        --v12;
      }
      while ( v12 );
      v7 += 166;
      v6 += 248;
      --v15;
    }
    while ( v15 );
    v3 = a2;
  }
  v3[2] = v4;
  v3[3] = v5;
  return result;
}
