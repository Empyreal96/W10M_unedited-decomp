// IoGetAttachedDeviceReference 
 
int __fastcall IoGetAttachedDeviceReference(int a1)
{
  int v2; // r0
  int v3; // r3
  int i; // r6
  unsigned int *v5; // r4
  unsigned int v7; // r2
  signed int v8; // r2
  int *v9; // r4
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int *v13; // r2
  unsigned int v14; // r4

  v2 = KeAcquireQueuedSpinLock(10);
  v3 = *(_DWORD *)(a1 + 16);
  for ( i = v2; v3; v3 = *(_DWORD *)(v3 + 16) )
    a1 = v3;
  v5 = (unsigned int *)(a1 - 24);
  if ( ObpTraceFlags )
    return sub_53D158();
  do
  {
    v7 = __ldrex(v5);
    v8 = v7 + 1;
  }
  while ( __strex(v8, v5) );
  __dmb(0xBu);
  if ( v8 <= 1 )
    KeBugCheckEx(24, 0, a1);
  v9 = (int *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) + 80);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v9);
  }
  else
  {
    v10 = *v9;
    if ( !*v9 )
    {
      v11 = (unsigned int *)v9[1];
      __dmb(0xBu);
      do
        v12 = __ldrex(v11);
      while ( (int *)v12 == v9 && __strex(0, v11) );
      if ( (int *)v12 == v9 )
        goto LABEL_12;
      v10 = KxWaitForLockChainValid(v9);
    }
    *v9 = 0;
    __dmb(0xBu);
    v13 = (unsigned int *)(v10 + 4);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 ^ 1, v13) );
  }
LABEL_12:
  KfLowerIrql(i);
  return a1;
}
