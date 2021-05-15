// PoClearPowerRequestInternal 
 
int __fastcall PoClearPowerRequestInternal(int a1, unsigned int a2, int a3, int a4)
{
  BOOL v6; // r7
  int v7; // r5
  int v9; // r2
  int v10; // r3
  int v11; // r5
  _DWORD v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = a2;
  v12[1] = a3;
  v12[2] = a4;
  v6 = (unsigned int)KeGetCurrentIrql(a1) < 2;
  if ( a2 > 4 )
    return -1073741637;
  if ( ((1 << a2) & *(_DWORD *)(a1 + 12)) == 0 )
    return -1073741637;
  v7 = a1 + 4 * a2;
  if ( !*(_DWORD *)(v7 + 24) )
    return -1073741637;
  if ( a2 == 3 )
    return sub_529754();
  KeAcquireInStackQueuedSpinLock(&PopPowerRequestSpinLock, v12);
  v9 = *(_DWORD *)(v7 + 24) - 1;
  *(_DWORD *)(v7 + 24) = v9;
  if ( ((1 << a2) & *(_DWORD *)(a1 + 16)) == 0 && !v9 )
  {
    v10 = PopPowerRequestAttributes[2 * a2] - 1;
    PopPowerRequestAttributes[2 * a2] = v10;
    if ( !v10 || !a2 )
      PopQueuePowerRequestCallback(a1, a2, 0, !v6);
  }
  PopDiagTracePowerRequestChange(a1);
  v11 = 0;
  KeReleaseInStackQueuedSpinLock(v12);
  if ( v6 )
  {
    if ( *(_BYTE *)(a1 + 57) )
      PopPowerRequestCallbackWorker(0);
  }
  return v11;
}
