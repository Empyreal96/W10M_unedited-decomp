// MiInitializeNonPagedPoolThresholds 
 
int __fastcall MiInitializeNonPagedPoolThresholds(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  _DWORD v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[1] = a3;
  v10[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_640280, (unsigned int)v10);
  v4 = dword_634D50;
  if ( dword_634D50 > (unsigned int)dword_640508 )
    v4 = dword_640508;
  MiState[0] = v4;
  v5 = KeReleaseInStackQueuedSpinLock((int)v10);
  return MiSignalNonPagedPoolWatchers(v5, v6, v7, v8);
}
