// MmDetachSession 
 
int __fastcall MmDetachSession(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r2
  int v7; // r3
  int v8; // r0
  int result; // r0
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v10[2] = a3;
  v10[3] = a4;
  v4 = *(_DWORD *)(a1 + 324);
  KeAcquireInStackQueuedSpinLock(&dword_634980, v10);
  v6 = *(_DWORD *)(v4 + 76) - 1;
  v7 = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v4 + 76) = v6;
  if ( (v7 & 2) == 0 || v6 )
    v4 = 0;
  KeReleaseInStackQueuedSpinLock(v10);
  v8 = KiUnstackDetachProcess(a2, 0);
  if ( v4 )
    result = sub_50A1CC(v8);
  else
    result = 0;
  return result;
}
