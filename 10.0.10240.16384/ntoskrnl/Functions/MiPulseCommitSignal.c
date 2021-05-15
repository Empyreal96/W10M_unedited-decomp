// MiPulseCommitSignal 
 
int __fastcall MiPulseCommitSignal(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r0
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[1] = a3;
  v7[2] = a4;
  KeAcquireInStackQueuedSpinLock(a1 + 806, (unsigned int)v7);
  v5 = a1[54];
  if ( !*(_DWORD *)(v5 + 4) )
    KePulseEvent(v5, 0, 0);
  if ( !*(_DWORD *)(a1[55] + 4) && a1[1029] == a1[801] )
    KePulseEvent(a1[55], 0, 0);
  return KeReleaseInStackQueuedSpinLock((int)v7);
}
