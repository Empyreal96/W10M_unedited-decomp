// BgpFwDisplayBugCheckProgressUpdate 
 
int __fastcall BgpFwDisplayBugCheckProgressUpdate(unsigned int a1, _DWORD *a2, int a3)
{
  unsigned int v6; // r6
  __int64 v7; // kr18_8
  int v8; // r4
  unsigned int v9; // r5
  __int64 v10; // r0
  int v11; // r2
  unsigned int v12; // r5
  int v13; // r1
  int v14; // r3
  int v15; // r4
  int v16; // r0
  void *v18; // r3
  void *v19; // r3
  unsigned int v20; // [sp+0h] [bp-48h]
  int v21; // [sp+4h] [bp-44h]
  __int64 v22; // [sp+8h] [bp-40h] BYREF
  __int64 v23; // [sp+10h] [bp-38h] BYREF
  __int64 v24; // [sp+18h] [bp-30h] BYREF
  int v25; // [sp+24h] [bp-24h]

  if ( (dword_619018 & 0x400000) != 0 || (dword_619018 & 0x10) == 0 )
    return 0;
  KeQueryPerformanceCounter(&v23, &v24);
  v6 = v23;
  v8 = v24;
  v7 = v23 - BcpStartTicks;
  LODWORD(v23) = v24;
  v21 = (__PAIR64__(HIDWORD(v23), v6) - BcpLastProgressUpdateTicks) >> 32;
  LODWORD(v22) = v6 - BcpLastProgressUpdateTicks;
  v9 = 10 * v24;
  HIDWORD(v10) = (unsigned __int64)(10 * v24) >> 32;
  v11 = v24 >> 31;
  v20 = v11;
  if ( a3 && v7 < __SPAIR64__(HIDWORD(v10), v9) )
  {
    if ( !v9 && is_mul_ok(0xAu, v24) )
      __brkdiv0();
    LODWORD(v10) = 10 * v24;
    v12 = _rt_sdiv64(v10, 100 * v7);
    v25 = v13;
    v11 = v20;
  }
  else
  {
    v12 = 100;
    v25 = 0;
  }
  v14 = BcpLastProgressDisplayed;
  if ( a1 <= v12 )
    v12 = a1;
  if ( v21 < v11 || v21 <= v11 && (unsigned int)v22 < 2 * v8 || v12 < BcpLastProgressDisplayed )
  {
    v12 = BcpLastProgressDisplayed;
  }
  else
  {
    v15 = BcpGetDisplayType(dword_618FC8, dword_618FC4, dword_618FCC, BcpLastProgressDisplayed);
    BcpSetCursorPosition(ProgressOffset, &dword_618F68);
    BcpDisplayProgress(v12, v15);
    KeQueryPerformanceCounter(&v22, 0);
    v8 = v23;
    BcpLastProgressDisplayed = v12;
    BcpLastProgressUpdateTicks = v22;
    v14 = v12;
  }
  if ( a1 != 100 || v14 == 100 )
  {
    if ( a3 )
      v18 = &unk_641620;
    else
      v18 = &unk_641628;
    *a2 = v18;
    BcpConvertProgressToString(v12, (int)(a2 + 3));
    if ( a1 == 1 )
    {
      a2[1] = &unk_641640;
      v19 = &unk_641648;
    }
    else
    {
      a2[1] = &unk_641650;
      v19 = &unk_641658;
    }
    a2[2] = v19;
    return 0;
  }
  KeQueryPerformanceCounter(&v23, 0);
  if ( v23 - BcpLastProgressUpdateTicks < __SPAIR64__(v20, 2 * v8) )
  {
    if ( !v24 )
      __brkdiv0();
    v16 = _rt_sdiv64(v24, 1000000 * (__PAIR64__(v20, 2 * v8) - (v23 - BcpLastProgressUpdateTicks)));
    KeStallExecutionProcessor(v16);
  }
  return BgpFwDisplayBugCheckProgressUpdate(100, a2, a3);
}
