// BgpFwLibraryDisable 
 
void BgpFwLibraryDisable()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0

  if ( (dword_619018 & 2) != 0 )
  {
    AnFwDisplayBackgroundUpdate(0);
    AnFwFadeCompletion();
    if ( dword_619098 )
    {
      v0 = BgpTxtDestroyRegion(dword_619098);
      if ( BgpTextRegionSave == dword_619098 )
      {
        sub_8DF718(v0);
        return;
      }
      dword_619098 = 0;
    }
    AnFwDisplayProgressIndicator(0);
    if ( dword_619094 )
    {
      BgpTxtDestroyRegion(dword_619094);
      if ( BgpAnimationRegionSave == dword_619094 )
        BgpAnimationRegionSave = 0;
      dword_619094 = 0;
    }
    if ( dword_619088 )
    {
      BgpFoDestroy(dword_619088);
      v1 = dword_619088;
      if ( *(_DWORD *)dword_619088 )
      {
        if ( (*(_DWORD *)(dword_619088 + 8) & 1) == 0 )
        {
          BgpFwFreeMemory(*(_DWORD *)dword_619088);
          v1 = dword_619088;
        }
      }
      BgpFwFreeMemory(v1);
      dword_619088 = 0;
    }
    v2 = LogFwReport();
    ResFwpPageOutBackground(v2);
    memset(&BgInternal, 0, 28);
    dword_619018 &= 0xFFFFFFFD;
  }
}
