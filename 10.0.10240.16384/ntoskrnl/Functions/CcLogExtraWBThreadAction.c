// CcLogExtraWBThreadAction 
 
int *__fastcall CcLogExtraWBThreadAction(int a1)
{
  int v2; // r0
  int v3; // r5
  int v4; // r6
  int v5; // r7
  int *result; // r0
  int v7; // r3
  int v8; // r2
  _DWORD v9[6]; // [sp+8h] [bp-40h] BYREF
  int v10[10]; // [sp+20h] [bp-28h] BYREF

  v2 = KeAcquireQueuedSpinLock(5);
  v3 = CcGlobalDirtyPageStatistics;
  v4 = CcGlobalDirtyPageThresholds;
  v5 = CcActiveExtraWriteBehindThreads;
  result = (int *)KeReleaseQueuedSpinLock(5, v2);
  v7 = *(_DWORD *)(*(_DWORD *)dword_634340 + 3712);
  __dmb(0xBu);
  if ( a1 == 2 )
  {
    v8 = 1;
  }
  else
  {
    if ( a1 != 3 )
      return result;
    v8 = 2;
  }
  v9[3] = v4;
  v9[4] = v7;
  v10[0] = (int)v9;
  v10[1] = 0;
  v10[2] = 20;
  v10[3] = 0;
  v9[0] = v8;
  v9[1] = v5;
  v9[2] = v3;
  return EtwTraceKernelEvent(v10, 1, 0x80020000, 5646, 4200706);
}
