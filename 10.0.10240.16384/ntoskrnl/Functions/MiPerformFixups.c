// MiPerformFixups 
 
int *__fastcall MiPerformFixups(int *result, int a2, unsigned int a3, int a4, int a5, int a6)
{
  int v6; // lr
  int v8; // r8
  int v9; // r7
  unsigned int v10; // r4
  int v11; // r10
  int i; // r2
  int v13; // r0
  int v14; // r1
  unsigned int v15; // r5
  int v16; // r2
  int v17; // r2
  int v19; // [sp+Ch] [bp-24h]

  v6 = a4;
  v8 = (int)result;
  v9 = (int)result;
  if ( (BYTE2(MiFlags) & 3u) >= 2 )
    return (int *)sub_8017AC();
  v10 = **(_DWORD **)(a2 + 56);
  if ( a3 < *(_DWORD *)(v10 + 24) )
  {
    v11 = a3 << 12;
    for ( i = 4 * a3; ; i = v19 + 4 )
    {
      v19 = i;
      v13 = a5;
      v14 = a6;
      while ( 1 )
      {
        v15 = *(_DWORD *)(*(_DWORD *)v10 + i);
        if ( v15 )
          break;
        v9 += 4096;
        if ( (v9 & 0xFFF) == 0 )
          goto LABEL_16;
        i += 4;
        v19 = i;
        v11 += 4096;
      }
      if ( v15 > 1 )
      {
        v16 = *(_DWORD *)(*(_DWORD *)v10 + i);
        if ( *(_BYTE *)(v10 + 32) )
          MiApplyCompressedFixups(a2, v9, v16, v6);
        else
          MiApplyRawFixups(a2, v9, v16, v6);
        v13 = a5;
        v14 = a6;
        v6 = a4;
      }
      if ( (v15 & 1) != 0 )
        MiApplyStraddleFixups(v10, (_BYTE *)v9, v11, v6, v13, v14);
      v17 = *(_DWORD *)(v10 + 28);
      v6 = a4;
      if ( (v17 & 0xFFFFF000) == v11 )
        *(_DWORD *)((v17 & 0xFFF) + v9) += a4;
      v9 += 4096;
      if ( (v9 & 0xFFF) == 0 )
        break;
      v11 += 4096;
    }
LABEL_16:
    result = KeSweepIcacheRange(1, v8, 0x1000u);
  }
  return result;
}
