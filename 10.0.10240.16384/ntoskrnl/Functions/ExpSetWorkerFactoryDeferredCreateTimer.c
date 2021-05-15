// ExpSetWorkerFactoryDeferredCreateTimer 
 
int __fastcall ExpSetWorkerFactoryDeferredCreateTimer(signed int a1)
{
  __int64 v1; // r2
  unsigned int v2; // r4
  __int64 v3; // r0
  int v4; // r5
  signed int v5; // r6

  if ( a1 == 3 )
  {
    HIDWORD(v1) = &ExpWorkerFactoryDeferredShortTimeout;
    v2 = 30;
  }
  else
  {
    if ( a1 != 2 )
      return sub_7E9B80();
    HIDWORD(v1) = &ExpWorkerFactoryDeferredMediumTimeout;
    v2 = 120;
  }
  HIDWORD(v3) = *(_DWORD *)(HIDWORD(v1) + 4);
  LODWORD(v1) = *(_DWORD *)HIDWORD(v1);
  v4 = ExpWorkerFactoryThreadCreationState;
  __dmb(0xBu);
  if ( a1 > v4 )
  {
    while ( 1 )
    {
      __dmb(0xBu);
      do
        v5 = __ldrex((unsigned int *)&ExpWorkerFactoryThreadCreationState);
      while ( v5 == v4 && __strex(a1, (unsigned int *)&ExpWorkerFactoryThreadCreationState) );
      __dmb(0xBu);
      if ( v4 == v5 )
        break;
      v4 = v5;
      if ( a1 <= v5 )
        return a1;
    }
    LODWORD(v3) = &ExpWorkerFactoryThreadCreationTimer;
    HIDWORD(v1) = HIDWORD(v3);
    KeSetCoalescableTimer(v3, v1, 0, v2, 0);
  }
  return a1;
}
