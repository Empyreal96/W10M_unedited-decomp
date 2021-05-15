// ResFwFreeContext 
 
void __fastcall ResFwFreeContext(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r0
  void **v5; // r5
  __int64 v6; // r2
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v3 = a1;
  if ( (dword_619018 & 0x100000) != 0 )
  {
    v5 = (void **)TxtpTextCache;
    v6 = *(_QWORD *)TxtpTextCache;
    if ( *((void ***)TxtpTextCache + 1) != &TxtpTextCache || *(void **)(v6 + 4) != TxtpTextCache )
      __fastfail(3u);
    while ( 1 )
    {
      TxtpTextCache = (void *)v6;
      *(_DWORD *)(v6 + 4) = &TxtpTextCache;
      if ( v5 == &TxtpTextCache )
        break;
      BgpGxRectangleDestroy((int)v5[8]);
      a1 = BgpFwFreeMemory((int)v5);
      v5 = (void **)TxtpTextCache;
      v6 = *(_QWORD *)TxtpTextCache;
      if ( *((void ***)TxtpTextCache + 1) != &TxtpTextCache || *(void **)(v6 + 4) != TxtpTextCache )
        __fastfail(3u);
    }
    dword_6174D4 = 0;
    if ( RasterizerInitialized )
      RaspClearCache(a1, a2);
    AnFwDisableBackgroundUpdateTimer();
    AnFwFadeCompletion();
    LogFwReport(v7, v8, v9);
    if ( *(_DWORD *)(v3 + 8) )
    {
      BgpFwReservePoolSwap(1, 0, 0);
      MmFreePagesFromMdl(*(_DWORD *)(v3 + 4), v10, v11, v12);
      ExFreePoolWithTag(*(_DWORD *)(v3 + 4));
    }
    dword_619094 = BgpAnimationRegionSave;
    dword_619098 = BgpTextRegionSave;
    dword_619018 &= 0xFFEFF7FD;
    memset(&BgInternal, 0, 28);
    ResFwpPageOutBackground();
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 4);
    if ( v4 )
    {
      MmFreePagesFromMdl(v4, a2, a3, dword_619018);
      ExFreePoolWithTag(*(_DWORD *)(v3 + 4));
    }
  }
}
