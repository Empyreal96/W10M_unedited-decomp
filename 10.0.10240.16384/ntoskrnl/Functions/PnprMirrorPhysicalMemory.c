// PnprMirrorPhysicalMemory 
 
int __fastcall PnprMirrorPhysicalMemory(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  int v5; // r3
  int varg_r0; // [sp+20h] [bp+8h]
  int varg_r1; // [sp+24h] [bp+Ch]
  int varg_r2; // [sp+28h] [bp+10h]
  int varg_r3; // [sp+2Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  varg_r0 = a1;
  varg_r1 = a2;
  if ( *(_BYTE *)(PnprContext + 156) )
  {
    v4 = *(_DWORD *)(PnprContext + 148);
    __dmb(0xBu);
    if ( v4 < 2 )
    {
      v5 = PnprContext;
      __dmb(0xBu);
      *(_DWORD *)(v5 + 148) = 2;
    }
    PnprGetMillisecondCounter(0);
    a3 = varg_r2;
    a4 = varg_r3;
    a1 = varg_r0;
    a2 = varg_r1;
  }
  return PnprMarkOrMirrorPages(a1, a2, a3, a4);
}
