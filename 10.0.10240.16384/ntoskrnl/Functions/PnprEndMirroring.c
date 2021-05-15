// PnprEndMirroring 
 
int __fastcall PnprEndMirroring(int a1)
{
  int v1; // r4
  int v2; // r0

  v1 = 0;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v2 = PnprSwap();
      v1 = v2;
      if ( v2 < 0 )
        v2 = off_6179EC(3, *(_DWORD *)(PnprContext + 548));
      PnprWakeProcessors(v2);
      if ( v1 >= 0 )
        v1 = 1073742484;
    }
  }
  else
  {
    *(_BYTE *)(PnprContext + 156) = 1;
    v1 = PnprQuiesce();
  }
  return v1;
}
