// PopSetSystemAwayMode 
 
int __fastcall PopSetSystemAwayMode(int a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r1
  unsigned int v4; // r1
  int v5; // r1

  if ( a1 )
  {
    if ( !byte_61EC11 )
    {
      if ( !byte_61EC10 )
        return -1073741811;
      KeResetEvent((int)&PopUserPresentCompletedEvent);
      __dmb(0xBu);
      do
        v2 = __ldrex((unsigned int *)&algn_61EC13[1]);
      while ( __strex(1u, (unsigned int *)&algn_61EC13[1]) );
      __dmb(0xBu);
      do
        v3 = __ldrex((unsigned int *)&PopUserPresentSetStatus);
      while ( !v3 && __strex(0, (unsigned int *)&PopUserPresentSetStatus) );
      __dmb(0xBu);
      if ( v3 )
        KeWaitForSingleObject((unsigned int)&PopUserPresentCompletedEvent, 0, 0, 0, 0);
      KeInitializeDpc((int)&PopAwayModeUserPresenceDpcObject, (int)PopAwayModeUserPresenceDpc, (int)&algn_61EC13[1]);
      KiSetTimerEx((int)&PopAwayModeUserPresenceTimer, v4, -30000000i64, 0, 0, (int)&PopAwayModeUserPresenceDpcObject);
      PopDiagTraceEventNoPayload((int)POP_ETW_EVENT_AWAYMODE);
      PopSetAwayModeStatus(1);
    }
  }
  else if ( byte_61EC11 )
  {
    PopSetAwayModeStatus(0);
    PopNotifyConsoleUserPresent(0, v5, PopAwaymodeExitReason);
  }
  return 0;
}
