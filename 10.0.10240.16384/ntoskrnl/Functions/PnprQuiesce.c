// PnprQuiesce 
 
int PnprQuiesce()
{
  int v0; // r4
  int v1; // r0
  int v2; // r2
  int v3; // r3
  int v4; // r3

  v0 = 0;
  if ( (*(_DWORD *)(PnprContext + 48) & 0x20) != 0 )
  {
    v1 = PnprLockPagesForReplace();
    goto LABEL_9;
  }
  KeSetEvent(PnprContext + 476, 0, 1);
  v1 = KeWaitForSingleObject(PnprContext + 492, 0, 0, 0, 0);
  v2 = PnprContext;
  v0 = *(_DWORD *)(PnprContext + 540);
  if ( v0 >= 0 )
  {
LABEL_9:
    PnprQuiesceProcessors(v1);
    return v0;
  }
  v3 = *(_DWORD *)(PnprContext + 608);
  if ( !v3 )
    v3 = 1903;
  *(_DWORD *)(PnprContext + 608) = v3;
  v4 = *(_DWORD *)(v2 + 612);
  if ( !v4 )
    v4 = 1;
  *(_DWORD *)(v2 + 612) = v4;
  return v0;
}
