// AnFwProgressIndicatorTransition 
 
int AnFwProgressIndicatorTransition()
{
  __int64 v0; // r0
  int result; // r0

  if ( byte_64A580 )
  {
    KeInitializeTimerEx(dword_653478, 0);
    KeInitializeDpc((int)&unk_653458, (int)AnFwpProgressIndicatorTimer, 0);
    LODWORD(v0) = dword_653478;
    HIDWORD(v0) = 30;
    result = KeSetCoalescableTimer(v0, 0i64, 0x1Eu, 0, (int)&unk_653458);
  }
  return result;
}
