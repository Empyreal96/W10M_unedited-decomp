// PopUpdateWakeSource 
 
int __fastcall PopUpdateWakeSource(int a1, int a2, int a3, int a4)
{
  int *v5; // r0
  int *v6; // r4
  int v7; // r5
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r1
  int **v11; // r1
  _DWORD v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[1] = a3;
  v13[2] = a4;
  v5 = (int *)ExAllocatePoolWithTag(512, 20);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  memset(v5, 0, 20);
  PopAcquireWakeSourceSpinLock((unsigned int)v13);
  if ( PopCurrentWakeInfo )
  {
    ObfReferenceObjectWithTag(a1);
    v8 = PopCurrentWakeInfo;
    v6[2] = a1;
    v6[3] = v8;
    __dmb(0xBu);
    v9 = (unsigned int *)(v8 + 8);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 + 1, v9) );
    __dmb(0xBu);
    v11 = (int **)dword_61F2FC;
    *v6 = (int)&PopWakeSourceWorkList;
    v6[1] = (int)v11;
    if ( *v11 != &PopWakeSourceWorkList )
      __fastfail(3u);
    *v11 = v6;
    dword_61F2FC = (int)v6;
    v6 = 0;
    if ( !PopWakeSourceWorkInProgress )
    {
      PopWakeSourceWorkInProgress = 1;
      ExQueueWorkItem(&PopWakeSourceWorkItem, 1);
    }
  }
  PopWakeSourceLockOwner = 0;
  KeReleaseInStackQueuedSpinLock((int)v13);
  v7 = 0;
  if ( v6 )
    ExFreePoolWithTag(v6);
  return v7;
}
