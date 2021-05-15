// PnprRecopyMirrorPages 
 
int PnprRecopyMirrorPages()
{
  int v0; // r0
  int v1; // r2
  int v2; // r0
  unsigned int v3; // r6
  unsigned int v4; // r3
  int v5; // r5
  int result; // r0
  int v7; // r3
  int v8; // r2
  int v9; // r2

  v0 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  PnprGetStackLimits(
    (int **)(PnprContext + 4 * (v0 + 40)),
    (unsigned int *)(PnprContext + 4 * (v0 + 72)),
    PnprContext,
    v0 + 40);
  v2 = PnprContext;
  v3 = 0;
  v4 = *(_DWORD *)(PnprContext + 124);
  if ( v4 )
  {
    v5 = 0;
    while ( 1 )
    {
      result = PnprRecopyAddress(
                 *(_DWORD *)(v2 + 4 * v3 + 160),
                 *(_DWORD *)(v2 + 4 * v3 + 288) - *(_DWORD *)(v2 + 4 * v3 + 160),
                 v1,
                 *(_DWORD *)(v2 + 4 * v3 + 288));
      if ( result < 0 )
        break;
      v2 = PnprContext;
      if ( v3 != *(_DWORD *)(PnprContext + 128) )
      {
        result = PnprRecopyMappingReserve((int *)(v5 + *(_DWORD *)(PnprContext + 108)));
        v7 = PnprContext;
        if ( result < 0 )
        {
          v8 = *(_DWORD *)(PnprContext + 608);
          if ( !v8 )
            v8 = 5604;
          goto LABEL_18;
        }
        result = PnprRecopyMappingReserve((int *)(v5 + *(_DWORD *)(PnprContext + 104)));
        if ( result < 0 )
        {
          v7 = PnprContext;
          v8 = *(_DWORD *)(PnprContext + 608);
          if ( !v8 )
            v8 = 5612;
          goto LABEL_18;
        }
        v2 = PnprContext;
      }
      v4 = *(_DWORD *)(v2 + 124);
      ++v3;
      v5 += 12;
      if ( v3 >= v4 )
        goto LABEL_9;
    }
    v7 = PnprContext;
    v8 = *(_DWORD *)(PnprContext + 608);
    if ( !v8 )
      v8 = 5588;
  }
  else
  {
LABEL_9:
    result = PnprRecopyAddress(v2, 672, v1, v4);
    if ( result >= 0 )
    {
      result = PnprCopyReservedMapping();
      if ( result >= 0 )
        return 0;
      v7 = PnprContext;
      v8 = *(_DWORD *)(PnprContext + 608);
      if ( !v8 )
        v8 = 5636;
    }
    else
    {
      v7 = PnprContext;
      v8 = *(_DWORD *)(PnprContext + 608);
      if ( !v8 )
        v8 = 5624;
    }
  }
LABEL_18:
  *(_DWORD *)(v7 + 608) = v8;
  v9 = *(_DWORD *)(v7 + 612);
  if ( !v9 )
    v9 = 1;
  *(_DWORD *)(v7 + 612) = v9;
  return result;
}
