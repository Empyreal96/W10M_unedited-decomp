// PopAdaptivePowerSettingCallback 
 
int __fastcall PopAdaptivePowerSettingCallback(unsigned int a1, int *a2, int a3)
{
  int v5; // r4
  BOOL v6; // r6
  int v7; // r2
  int v8; // r0

  if ( a3 != 4 || !a2 )
    return -1073741811;
  v5 = 0;
  v6 = PopConsoleSession != 0;
  PopAcquireAdaptiveLock(PopConsoleSession == 0);
  if ( memcmp((unsigned int)&GUID_NON_ADAPTIVE_INPUT_TIMEOUT, a1, 16) )
  {
    if ( !memcmp((unsigned int)&GUID_VIDEO_POWERDOWN_TIMEOUT, a1, 16) )
    {
      PopDisplayTimeout = *a2;
    }
    else
    {
      if ( memcmp((unsigned int)&GUID_VIDEO_CONSOLE_LOCK_TIMEOUT, a1, 16) )
      {
        v5 = -1073741811;
LABEL_9:
        PopReleaseAdaptiveLock();
        return v5;
      }
      PopAdaptiveLockConsoleTimeout = *a2;
    }
    v7 = PopInputTimeout;
LABEL_7:
    v8 = PopDiagTracePolicyChange(PopDisplayTimeout, PopDisplayTimeout, v7, v7);
    if ( v6 )
      PopCheckConsoleTimeouts(v8);
    goto LABEL_9;
  }
  v7 = *a2;
  PopInputTimeout = *a2;
  if ( !v6 )
    goto LABEL_7;
  byte_61DE13 = 1;
  dword_61DE08 = v7;
  if ( v7 )
    goto LABEL_7;
  return sub_7F15D8();
}
