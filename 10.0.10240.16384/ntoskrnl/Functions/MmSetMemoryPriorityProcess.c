// MmSetMemoryPriorityProcess 
 
void __fastcall __spoils<R2,R3,R12> MmSetMemoryPriorityProcess(int a1, char a2, int a3, int a4)
{
  _DWORD v6[6]; // [sp+0h] [bp-18h] BYREF

  v6[2] = a3;
  v6[3] = a4;
  KeAcquireInStackQueuedSpinLock(&dword_634980, v6);
  *(_BYTE *)(a1 + 606) = a2;
  KeReleaseInStackQueuedSpinLock(v6);
}
