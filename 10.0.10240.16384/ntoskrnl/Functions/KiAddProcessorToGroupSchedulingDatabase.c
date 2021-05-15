// KiAddProcessorToGroupSchedulingDatabase 
 
int __fastcall KiAddProcessorToGroupSchedulingDatabase(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  unsigned int *v6; // r4
  unsigned int v7; // r2
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  KiInitializeProcessorGroupSchedulingData(a1);
  v5 = *(_DWORD *)(a1 + 20);
  KeAcquireInStackQueuedSpinLock(KiSchedulingGroupLock, (unsigned int)v9);
  if ( KiGroupSchedulingEnabled )
  {
    v6 = (unsigned int *)(a1 + 24);
    while ( 1 )
    {
      do
        v7 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( !v7 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v6 );
    }
    KiAddProcessorToGroupSchedulingList(a1, &KiSchedulingGroupList, v5);
    __dmb(0xBu);
    *v6 = 0;
  }
  return KeReleaseInStackQueuedSpinLock((int)v9);
}
