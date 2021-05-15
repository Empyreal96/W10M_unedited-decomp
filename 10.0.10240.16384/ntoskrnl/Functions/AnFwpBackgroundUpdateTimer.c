// AnFwpBackgroundUpdateTimer 
 
int AnFwpBackgroundUpdateTimer()
{
  __int64 v0; // r0
  int result; // r0
  int v2; // r6
  int v3; // r0
  unsigned int v4; // r1
  unsigned int v5; // r4
  int v6; // r7
  int v7; // r0
  int v8; // r2
  char *v9; // r3
  unsigned __int64 v10; // [sp+8h] [bp-20h] BYREF
  __int64 v11[3]; // [sp+10h] [bp-18h] BYREF

  v0 = off_617AA0(v11);
  result = RtlULongLongMult(v0, HIDWORD(v0), 0x3E8u, 0, &v10);
  v2 = result;
  if ( result >= 0 )
  {
    if ( !v11[0] )
      __brkdiv0();
    v3 = _rt_udiv64(v11[0], v10);
    v5 = v4;
    v6 = v3;
    BgpFwAcquireLock(v3);
    if ( __PAIR64__(v5, v6) >= qword_619080 )
    {
      if ( byte_64194F )
      {
        AnFwpDisableProgressTimer();
        v7 = DbgPrintEx(101, 0, (int)"BGFX Secondary Logo Bitmap Display Time (ms): %d\n", v6);
        if ( dword_61905C )
        {
          BgpClearScreen(-16777216);
          v7 = BgpGxDrawBitmapImage(dword_61905C, (int)&dword_619068, v8, v9);
          v2 = v7;
        }
        if ( v2 < 0 )
          return sub_8DF570(v7);
      }
      AnFwDisableBackgroundUpdateTimer();
    }
    result = BgpFwReleaseLock();
  }
  return result;
}
