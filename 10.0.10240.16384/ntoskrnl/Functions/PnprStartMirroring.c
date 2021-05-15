// PnprStartMirroring 
 
int PnprStartMirroring()
{
  int result; // r0
  int v1; // r2
  int v2; // r3

  result = 0;
  v1 = PnprContext;
  v2 = *(_DWORD *)(PnprContext + 48);
  *(_BYTE *)(PnprContext + 156) = 0;
  *(_DWORD *)(v1 + 48) = v2 | 4;
  return result;
}
