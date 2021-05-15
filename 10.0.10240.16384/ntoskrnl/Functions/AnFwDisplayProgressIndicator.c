// AnFwDisplayProgressIndicator 
 
int __fastcall AnFwDisplayProgressIndicator(int a1)
{
  unsigned int i; // r1
  __int64 v3; // r0
  int v4; // r0
  void **v5; // r5
  __int64 v6; // r2
  _QWORD v7[3]; // [sp+10h] [bp-18h] BYREF

  if ( a1 || byte_64A580 )
  {
    if ( (dword_619018 & 0x100000) != 0 )
      return sub_8DF5B8();
    if ( a1 )
    {
      if ( byte_64A580 )
        return -1073741637;
      if ( !dword_619094 )
        return -1073741670;
      if ( (dword_619018 & 0x40000) != 0 )
        return -1073741823;
      byte_64A580 = 1;
      word_618D0C = -8110;
      LogFwStat(v7, 1, 2i64);
      for ( i = (unsigned __int16)word_618D0C; i <= 0xE0CB; i = (unsigned __int16)++word_618D0C )
        BgpTxtDisplayCharacter((__int64 *)dword_619094, i, 1, 0, 0, 0, 0);
      word_618D0C = -7989;
      BgpTxtDisplayCharacter((__int64 *)dword_619094, 0xE0CBu, 0, 0, 0, 0, 0);
      LogFwStat(v7, 0, 2i64);
      qword_653560 = v7[0];
      KeInitializeTimerEx(dword_653478, 0);
      KeInitializeDpc((int)&unk_653458, (int)AnFwpProgressIndicatorTimer, 0);
      LODWORD(v3) = dword_653478;
      HIDWORD(v3) = 30;
      KeSetCoalescableTimer(v3, 0i64, 0x1Eu, 0, (int)&unk_653458);
    }
    else
    {
      if ( (dword_619018 & 0xC00) != 3072 )
        AnFwpDisableProgressTimer();
      word_618D0C = -7989;
      v4 = BgpTxtDisplayCharacter((__int64 *)dword_619094, 0xE0CBu, 0, 0, 0, 0, 0);
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
        BgpGxRectangleDestroy(v5[8]);
        v4 = BgpFwFreeMemory((int)v5);
        v5 = (void **)TxtpTextCache;
        v6 = *(_QWORD *)TxtpTextCache;
        if ( *((void ***)TxtpTextCache + 1) != &TxtpTextCache || *(void **)(v6 + 4) != TxtpTextCache )
          __fastfail(3u);
      }
      dword_6174D4 = 0;
      if ( RasterizerInitialized )
        RaspClearCache(v4);
    }
  }
  return 0;
}
