// PpmTranslateIdleAccounting 
 
int __fastcall PpmTranslateIdleAccounting(int a1, _DWORD *a2, _QWORD *a3)
{
  _QWORD *v3; // r9
  int v6; // r8
  __int64 v7; // r0
  int v8; // r4
  int *v9; // r6
  _DWORD *v10; // r5
  unsigned int v11; // r9
  int v12; // r1
  int v13; // kr08_4
  __int64 v14; // r0
  int *v15; // r4
  _DWORD *v16; // r7
  int v17; // r10
  __int64 v18; // r0
  int v19; // r3
  int *v20; // r4
  int v21; // r7
  int v22; // r2
  __int64 v23; // r0
  unsigned int v24; // r10
  int *v25; // r7
  int v26; // lr
  int v27; // r3
  int v29; // [sp+4h] [bp-24h]

  v3 = a3;
  PpmUpdateProcessorIdleAccounting((unsigned __int64 *)a1);
  LODWORD(v7) = *(_DWORD *)(a1 + 4);
  v6 = *(_DWORD *)v7;
  *a2 = *(_DWORD *)v7;
  a2[1] = *(_DWORD *)(v7 + 4);
  a2[2] = *(_DWORD *)(v7 + 8);
  a2[3] = *(_DWORD *)(v7 + 12);
  a2[4] = *(_DWORD *)(v7 + 16);
  a2[5] = *(_DWORD *)(v7 + 20);
  HIDWORD(v7) = *(_DWORD *)(v7 + 28);
  v8 = *(_DWORD *)(v7 + 24);
  if ( v6 )
  {
    v9 = (int *)(v7 + 40);
    v10 = a2 + 6;
    v11 = *(_DWORD *)(v7 + 24);
    do
    {
      v13 = v11 + *v9;
      v12 = (__PAIR64__(HIDWORD(v7), v11) + (unsigned int)*v9) >> 32;
      v11 = v13;
      v29 = v9[1] + v12;
      v10[2] = v9[2] + v9[4] + v9[3];
      v10[3] = v9[3];
      v10[7] = v9[2];
      v10[4] = v9[5];
      LODWORD(v14) = PpmConvertTimeTo(*v9, v9[1]);
      *(_QWORD *)v10 = v14;
      v10[5] = PpmConvertTimeTo(v9[6], v9[7]);
      v10[6] = PpmConvertTimeTo(v9[8], v9[9]);
      v15 = v9 + 70;
      v16 = v10 + 8;
      v17 = 16;
      do
      {
        LODWORD(v18) = PpmConvertTimeTo(*v15, v15[1]);
        *(_QWORD *)v16 = v18;
        v16[2] = PpmConvertTimeTo(v15[2], v15[3]);
        LODWORD(v7) = PpmConvertTimeTo(v15[4], v15[5]);
        v16[3] = v7;
        v19 = v15[6];
        v15 += 8;
        v16[4] = v19;
        v16 += 6;
        --v17;
      }
      while ( v17 );
      v20 = v9 + 38;
      v21 = 4;
      do
      {
        v22 = v20[6];
        if ( v22 )
        {
          v10[12] += v22;
          LODWORD(v23) = PpmConvertTimeTo(*v20, v20[1]);
          *((_QWORD *)v10 + 4) += v23;
          v24 = PpmConvertTimeTo(v20[2], v20[3]);
          LODWORD(v7) = PpmConvertTimeTo(v20[4], v20[5]);
          if ( v10[10] > v24 )
            v10[10] = v24;
          if ( v10[11] < (unsigned int)v7 )
            v10[11] = v7;
        }
        v20 += 8;
        --v21;
      }
      while ( v21 );
      v25 = v9 + 160;
      v26 = 6;
      do
      {
        v27 = v25[44];
        v25 += 8;
        v10[4] += v27;
        --v26;
      }
      while ( v26 );
      HIDWORD(v7) = v29;
      v10 += 104;
      v9 += 246;
      --v6;
    }
    while ( v6 );
    v3 = a3;
    v8 = v13;
  }
  if ( v3 )
  {
    LODWORD(v7) = PpmConvertTimeTo(v8, SHIDWORD(v7));
    *v3 = v7;
  }
  return v7;
}
