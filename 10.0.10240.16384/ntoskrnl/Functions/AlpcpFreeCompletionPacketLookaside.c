// AlpcpFreeCompletionPacketLookaside 
 
void __fastcall __spoils<R2,R3,R12> AlpcpFreeCompletionPacketLookaside(unsigned int *a1, int a2, int a3, int a4)
{
  int v5; // r4
  _DWORD v6[6]; // [sp+0h] [bp-18h] BYREF

  v6[2] = a3;
  v6[3] = a4;
  KeAcquireInStackQueuedSpinLock(a1, (unsigned int)v6);
  if ( a1[2] )
  {
    v5 = 0;
    a1[5] = 1;
  }
  else
  {
    v5 = 1;
  }
  KeReleaseInStackQueuedSpinLock((int)v6);
  if ( v5 )
    AlpcpDeferredFreeCompletionPacketLookaside(a1);
}
