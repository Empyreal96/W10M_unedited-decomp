// RtlpUnwindCustom 
 
int __fastcall RtlpUnwindCustom(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // r4
  unsigned int *v5; // r3
  unsigned int v6; // r2
  unsigned int *v7; // r3
  int v8; // r3
  _DWORD *v9; // r1
  unsigned int v10; // r2
  _DWORD *v11; // r6
  int v12; // r7
  int v13; // r3
  int *v14; // r6
  unsigned int i; // r1
  int v16; // t1
  _DWORD *v17; // r2
  int v18; // r3
  _DWORD *v19; // r2
  unsigned int v21; // r2
  unsigned int *v22; // r3
  unsigned int v23; // r2

  v3 = (_DWORD *)a1[14];
  if ( a2 == 3 )
  {
    if ( a1[16] <= (unsigned int)MmHighestUserAddress )
      JUMPOUT(0x548462);
    v5 = *(unsigned int **)(a3 + 4);
    if ( v5 )
    {
      v21 = a1[14];
      if ( v21 < *v5 || v21 > **(_DWORD **)(a3 + 8) - 136 )
        return -1073741784;
    }
    v6 = v3[5];
    if ( v6 )
    {
      if ( a1[16] <= (unsigned int)MmHighestUserAddress )
        JUMPOUT(0x54847E);
      v7 = *(unsigned int **)(a3 + 4);
      if ( v7 && (v6 < *v7 || v6 > **(_DWORD **)(a3 + 8) - 272) )
        return -1073741784;
      v8 = *(_DWORD *)(v6 + 4);
      if ( v8 != -1 )
      {
        v9 = (_DWORD *)(v6 + 16);
        v10 = 0;
        a1[18] = v8;
        v11 = a1;
        do
        {
          v12 = *(_DWORD *)(a3 + 12);
          if ( v12 && v10 - 8 <= 7 )
            *(_DWORD *)(v12 + 4 * v10 + 4) = v9;
          ++v10;
          v11[20] = *v9;
          v13 = v9[1];
          v9 += 2;
          v11[21] = v13;
          v11 += 2;
        }
        while ( v10 < 0x20 );
      }
    }
    v14 = v3 + 24;
    for ( i = 0; i < 4; ++i )
    {
      v16 = *v14++;
      v17 = &a1[i];
      v17[1] = v16;
    }
    v18 = *(_DWORD *)(a3 + 12);
    v19 = v3 + 31;
    if ( v18 )
      *(_DWORD *)(v18 + 28) = v19;
    a1[12] = *v19;
    a1[13] = v3[28];
    a1[14] = v3[29];
    a1[15] = v3[30];
    a1[16] = v3[32];
    a1[17] = v3[33];
LABEL_16:
    *a1 &= 0xDFFFFFFF;
    return 0;
  }
  if ( a2 == 1 )
  {
    if ( a1[16] <= (unsigned int)MmHighestUserAddress )
      JUMPOUT(0x54856C);
    v22 = *(unsigned int **)(a3 + 4);
    if ( v22 )
    {
      v23 = a1[14];
      if ( v23 < *v22 || v23 > **(_DWORD **)(a3 + 8) - 8 )
        return -1073741784;
    }
    a1[14] = *v3;
    a1[16] = v3[1];
    goto LABEL_16;
  }
  return sub_548440();
}
