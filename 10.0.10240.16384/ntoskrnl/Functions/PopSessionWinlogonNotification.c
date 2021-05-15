// PopSessionWinlogonNotification 
 
int __fastcall PopSessionWinlogonNotification(unsigned int a1, int a2)
{
  int v2; // r4
  int v3; // r5
  int *v5; // r0
  int result; // r0
  _BYTE *v7; // r0
  int v8; // r1
  int v9; // r0
  int v10; // r2
  int v11[6]; // [sp+8h] [bp-18h] BYREF

  v2 = *(unsigned __int8 *)(a2 + 5);
  v3 = *(unsigned __int8 *)(a2 + 4);
  v11[0] = 0;
  v11[1] = 0;
  if ( v2 )
    v5 = POP_ETW_ADPM_SESSION_LOCKED;
  else
    v5 = POP_ETW_ADPM_SESSION_UNLOCKED;
  PopDiagTraceSessionStates((int)v5, a1, v3, 0);
  result = PopPrintEx(3);
  if ( v3 )
  {
    v7 = PopAcquireAdaptiveLock(0);
    if ( v2 )
    {
      byte_61DE54 = 1;
      v9 = PopGetLockConsoleTimeoutUnsafe(v7);
      v11[0] = v9;
      if ( v9 )
      {
        *(_BYTE *)(v10 + 21) = 1;
        dword_61DE0C = v9;
        byte_61DE11 = 1;
        PopUpdateTimeouts(a1, (int)v11, 0);
      }
    }
    else
    {
      byte_61DE54 = 0;
      if ( byte_61DE55 )
      {
        byte_61DE55 = 0;
        PopLazySensorActiveInput(a1, v8, (int)&PopConsoleContext);
      }
    }
    PopReleaseAdaptiveLock();
    v11[0] = v2 != 0;
    result = PopSetPowerSettingValueAcDc((int *)&GUID_CONSOLE_LOCKED, 4u, (int)v11);
  }
  return result;
}
