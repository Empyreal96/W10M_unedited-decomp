// MiLockAndSelectSessionAttachProcess 
 
int *__fastcall MiLockAndSelectSessionAttachProcess(_DWORD *a1, int a2, int a3, int a4)
{
  int *v5; // r4
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[1] = a3;
  v7[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v7);
  v5 = MiSelectSessionAttachProcess(a1);
  KeReleaseInStackQueuedSpinLock((int)v7);
  return v5;
}
