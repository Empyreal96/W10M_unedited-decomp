// KeReleaseInStackQueuedSpinLock 
 
int __fastcall KeReleaseInStackQueuedSpinLock(int a1)
{
  int v3; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int *v6; // r2
  unsigned int v7; // r0

  if ( (dword_682604 & 0x10000) != 0 )
    return sub_50C720();
  v3 = *(_DWORD *)a1;
  if ( !*(_DWORD *)a1 )
  {
    v4 = *(unsigned int **)(a1 + 4);
    __dmb(0xBu);
    do
      v5 = __ldrex(v4);
    while ( v5 == a1 && __strex(0, v4) );
    if ( v5 == a1 )
      return KfLowerIrql(*(unsigned __int8 *)(a1 + 8));
    v3 = KxWaitForLockChainValid((int *)a1);
  }
  *(_DWORD *)a1 = 0;
  __dmb(0xBu);
  v6 = (unsigned int *)(v3 + 4);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 ^ 1, v6) );
  return KfLowerIrql(*(unsigned __int8 *)(a1 + 8));
}
