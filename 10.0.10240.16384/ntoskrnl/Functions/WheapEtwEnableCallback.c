// WheapEtwEnableCallback 
 
void __fastcall WheapEtwEnableCallback(int a1, int a2)
{
  int *v2; // r4
  __int64 v3; // r2
  unsigned int v4; // r1

  WheapEtwEnabled = a2;
  WheapEventingInitialized = a2;
  if ( a2 == 1 )
  {
    while ( 1 )
    {
      KeWaitForSingleObject((unsigned int)&WheapWaitingETWEventLock, 0, 0, 0, 0);
      v2 = (int *)WheapWaitingETWEvents;
      v3 = *(_QWORD *)WheapWaitingETWEvents;
      if ( *(int **)(WheapWaitingETWEvents + 4) != &WheapWaitingETWEvents
        || *(_DWORD *)(v3 + 4) != WheapWaitingETWEvents )
      {
        __fastfail(3u);
      }
      WheapWaitingETWEvents = *(_DWORD *)WheapWaitingETWEvents;
      *(_DWORD *)(v3 + 4) = &WheapWaitingETWEvents;
      KeSetEvent((int)&WheapWaitingETWEventLock, 0, 0);
      if ( v2 == &WheapWaitingETWEvents )
        break;
      WheapGenerateETWEvents();
      WheapFreeErrorRecord((int)v2);
    }
    __dmb(0xBu);
    do
      v4 = __ldrex(&WheapSqmWaitQueued);
    while ( !v4 && __strex(1u, &WheapSqmWaitQueued) );
    __dmb(0xBu);
    if ( !v4 )
      WheapSqmCollectConfigurationDataPoints(1, 0, &WheapSqmWaitQueued);
  }
}
