// MiUnlinkSessionWorkingSet 
 
int __fastcall MiUnlinkSessionWorkingSet(int a1, int a2, int a3, int a4)
{
  _DWORD v6[6]; // [sp+0h] [bp-18h] BYREF

  v6[1] = a3;
  v6[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v6);
  *(_DWORD *)(a1 + 4) |= 2u;
  if ( *(_DWORD *)(a1 + 76) )
  {
    *(_BYTE *)(a1 + 80) = 7;
    *(_BYTE *)(a1 + 81) = 1;
    *(_BYTE *)(a1 + 82) = 4;
    *(_DWORD *)(a1 + 84) = 0;
    *(_DWORD *)(a1 + 88) = a1 + 88;
    *(_DWORD *)(a1 + 92) = a1 + 88;
    KeReleaseInStackQueuedSpinLock((int)v6);
    KeWaitForGate(a1 + 80, 18);
    KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v6);
  }
  MiUnlinkWorkingSet(a1 + 3248, v6);
  return KeReleaseInStackQueuedSpinLock((int)v6);
}
