// AnFwDisplayBackgroundUpdate 
 
int __fastcall AnFwDisplayBackgroundUpdate(int a1)
{
  __int64 v1; // r0
  int result; // r0
  unsigned __int64 v3; // r0
  int v4; // r6
  int v5; // r7
  __int64 v6; // r0
  unsigned __int64 v7; // [sp+10h] [bp-20h] BYREF
  __int64 v8[3]; // [sp+18h] [bp-18h] BYREF

  if ( (dword_619018 & 0x1000000) == 0 )
    return 0;
  if ( !a1 )
  {
    AnFwDisableBackgroundUpdateTimer();
    return 0;
  }
  if ( byte_64194F )
    return -1073741823;
  v1 = off_617AA0(v8);
  result = RtlULongLongMult(v1, HIDWORD(v1), 0x3E8u, 0, &v7);
  if ( result >= 0 )
  {
    if ( !v8[0] )
      __brkdiv0();
    LODWORD(v3) = _rt_udiv64(v8[0], v7);
    v4 = v3;
    result = RtlULongLongAdd(v3, qword_619080, &v7);
    if ( result >= 0 )
    {
      DbgPrintEx(101, 0, (int)"BGFX Display Ready Time (ms): %d\n", v4);
      v5 = v7;
      DbgPrintEx(101, 0, (int)"BGFX Secondary Logo Bitmap Display Time GOAL (ms): %d\n", v7);
      if ( (unsigned __int64)qword_619080 < 0x64 )
      {
        result = sub_8DF57C();
      }
      else
      {
        LODWORD(qword_619080) = v5;
        HIDWORD(qword_619080) = HIDWORD(v7);
        KeInitializeTimerEx(dword_649DF8, 0);
        KeInitializeDpc((int)&unk_649DD8, (int)AnFwpBackgroundUpdateTimer, 0);
        LODWORD(v6) = dword_649DF8;
        HIDWORD(v6) = 100;
        if ( KeSetCoalescableTimer(v6, 0i64, 0x64u, 0, (int)&unk_649DD8) )
        {
          KeCancelTimer((int)dword_649DF8);
          byte_64194F = 0;
          result = BgpClearScreen(-16777216);
        }
        else
        {
          byte_64194F = 1;
          result = 0;
        }
      }
    }
  }
  return result;
}
