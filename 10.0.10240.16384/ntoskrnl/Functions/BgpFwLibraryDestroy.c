// BgpFwLibraryDestroy 
 
int BgpFwLibraryDestroy()
{
  int *v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3

  BgpFoDestroy(0);
  if ( dword_619088 )
  {
    BgpFoDestroy(dword_619088);
    if ( *(_DWORD *)dword_619088 && (*(_DWORD *)(dword_619088 + 8) & 1) == 0 )
      return sub_8DF4F8();
    BgpFwFreeMemory(dword_619088);
    dword_619088 = 0;
  }
  v1 = (int *)dword_619048;
  if ( dword_619048 )
  {
    BgpFwFreeMemory(dword_619048);
    dword_619048 = 0;
    v1 = BgpFwInitializeReservePool(0, 0, 0);
    dword_61908C = 0;
    dword_619094 = 0;
    dword_619098 = 0;
  }
  BgpFwLibraryDisable(v1);
  ResFwBackgroundTransition(2, v2, v3, v4);
  dword_619018 = 0;
  return 0;
}
