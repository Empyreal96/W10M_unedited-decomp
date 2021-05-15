// MiComputeAgingPercent 
 
unsigned int __fastcall MiComputeAgingPercent(int a1)
{
  unsigned int result; // r0
  int v3; // r5
  unsigned int v4; // r1
  unsigned int v5; // r3
  unsigned int v6; // r1
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r4

  result = MiGetAvailablePagesForTrimPass(a1, 0);
  v3 = *(_DWORD *)(a1 + 3512);
  v4 = *(_DWORD *)(v3 + 1208) >> 3;
  *(_DWORD *)(v3 + 1208) = 7 * v4 + result;
  *(_DWORD *)(v3 + 4 * (*(_DWORD *)(v3 + 88) & 7) + 1176) = result;
  if ( result < v4 )
  {
    v5 = v4 - result;
    v6 = *(_DWORD *)(v3 + 1248);
    if ( result <= v6 )
    {
      v9 = 0;
    }
    else
    {
      if ( v5 < 8 )
        v5 = 8;
      v7 = result - v6;
      if ( !(v5 >> 3) )
        __brkdiv0();
      v8 = v7 / (v5 >> 3);
      v9 = v8;
      if ( v8 >= 2 )
        v9 = v8 - 2;
    }
    if ( v9 )
    {
      result = 0x1B58 / v9;
      if ( 0x1B58 / v9 > 0x3E8 )
        result = 1000;
    }
    else
    {
      result = 1000;
    }
    *(_WORD *)(v3 + 1218) = result;
    *(_DWORD *)(v3 + 1224) = v9;
  }
  else
  {
    *(_WORD *)(v3 + 1218) = 0;
  }
  return result;
}
