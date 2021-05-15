// PopRtcWakeSettingCallback 
 
int __fastcall PopRtcWakeSettingCallback(unsigned int a1, _DWORD *a2, int a3)
{
  int v5; // r4

  v5 = -1073741811;
  if ( !memcmp((unsigned int)&GUID_ALLOW_RTC_WAKE, a1, 16) && a3 == 4 && a2 )
  {
    PopAcquirePolicyLock();
    PoRtcWakeAllowed = *a2 != 0;
    PopReleasePolicyLock();
    v5 = 0;
  }
  return v5;
}
