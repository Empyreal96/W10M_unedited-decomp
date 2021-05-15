// PiDevCfgSetObjectProperty 
 
int __fastcall PiDevCfgSetObjectProperty(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r5

  v10 = 0;
  if ( a1 == PiPnpRtlCtx && a4 == 1 && a2 && (*a2 & 1) != 0 )
    v10 = 0x20000;
  return PnpSetObjectProperty(a1, a3, a4, a5, 0, a7, a8, a9, a10, v10);
}
