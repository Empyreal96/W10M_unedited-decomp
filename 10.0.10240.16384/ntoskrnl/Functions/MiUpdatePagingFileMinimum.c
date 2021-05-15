// MiUpdatePagingFileMinimum 
 
void __fastcall __spoils<R2,R3,R12> MiUpdatePagingFileMinimum(int a1, int a2, int a3, int a4)
{
  _DWORD v6[6]; // [sp+0h] [bp-18h] BYREF

  v6[2] = a3;
  v6[3] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 116), (unsigned int)v6);
  *(_DWORD *)(a1 + 8) += a2;
  KeReleaseInStackQueuedSpinLock((int)v6);
}
