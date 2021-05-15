// MiPulseLowAvailableEvent 
 
int __fastcall MiPulseLowAvailableEvent(int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r0
  _DWORD v6[4]; // [sp+0h] [bp-10h] BYREF

  v6[1] = a3;
  v6[2] = a4;
  v4 = result;
  if ( !*(_DWORD *)(*(_DWORD *)(result + 188) + 4) )
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)(result + 2944), (unsigned int)v6);
    v5 = *(_DWORD *)(v4 + 188);
    if ( !*(_DWORD *)(v5 + 4) )
      KePulseEvent(v5, 0, 0);
    result = KeReleaseInStackQueuedSpinLock((int)v6);
  }
  return result;
}
