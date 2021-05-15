// WheapProcessWorkQueueItem 
 
int __fastcall WheapProcessWorkQueueItem(int a1, int *a2)
{
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int result; // r0
  int **v7; // r1

  if ( WheapPreviousSessionFailure )
  {
    if ( (a2[33] & 2) != 0 )
    {
      v3 = a2[10];
      if ( v3 == 1 || !v3 )
      {
        v4 = a2[6];
        if ( v4 )
        {
          v5 = *(_DWORD *)(v4 + 32);
          if ( !v5 || v5 == 3 || v5 == 4 || v5 == 7 || v5 == 9 )
            WheapCreateTriageDumpFromPreviousSession(a2);
        }
      }
    }
  }
  if ( WheapEventingInitialized )
  {
    WheapPredictiveFailureAnalysis(a2);
    WheapGenerateETWEvents(a2 + 7);
    result = WheapFreeErrorRecord((int)a2);
  }
  else
  {
    KeWaitForSingleObject((unsigned int)&WheapWaitingETWEventLock, 0, 0, 0, 0);
    v7 = (int **)dword_6197D4;
    *a2 = (int)&WheapWaitingETWEvents;
    a2[1] = (int)v7;
    if ( *v7 != &WheapWaitingETWEvents )
      __fastfail(3u);
    *v7 = a2;
    dword_6197D4 = (int)a2;
    result = KeSetEvent((int)&WheapWaitingETWEventLock, 0, 0);
  }
  return result;
}
