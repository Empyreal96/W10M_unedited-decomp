// PnprSwapFinalize 
 
int PnprSwapFinalize()
{
  int v0; // r5
  int v1; // r2
  unsigned int v2; // r3
  int v3; // r0
  int v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r2

  v0 = 0;
  v1 = PnprContext;
  if ( *(_DWORD *)(*(_DWORD *)(PnprContext + 20) + 4) && (*(_DWORD *)(PnprContext + 48) & 8) == 0 )
  {
    PnprRecopyMirrorPages();
    v1 = PnprContext;
  }
  v2 = *(_DWORD *)(v1 + 48) & 0xFFFFFFFB;
  *(_DWORD *)(v1 + 48) = v2;
  if ( (v2 & 0x20) == 0 )
    KiInvalidateCurrentCache();
  if ( *(_DWORD *)(PnprContext + 588) )
  {
    v3 = PnprGetMillisecondCounter(0);
    v4 = PnprContext;
    *(_DWORD *)(PnprContext + 636) = v3;
    v0 = (*(int (__fastcall **)(_DWORD))(v4 + 588))(*(_DWORD *)(v4 + 552));
    if ( v0 < 0 )
    {
      v5 = PnprContext;
      v6 = *(_DWORD *)(PnprContext + 608);
      if ( !v6 )
        v6 = 2961;
      *(_DWORD *)(PnprContext + 608) = v6;
      v7 = *(_DWORD *)(v5 + 612);
      if ( !v7 )
        v7 = 8;
      *(_DWORD *)(v5 + 612) = v7;
    }
    *(_DWORD *)(PnprContext + 640) = PnprGetMillisecondCounter(0);
  }
  return v0;
}
