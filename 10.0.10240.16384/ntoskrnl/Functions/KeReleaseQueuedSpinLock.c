// KeReleaseQueuedSpinLock 
 
int __fastcall KeReleaseQueuedSpinLock(int a1, int a2)
{
  int *v3; // r4
  int v5; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int *v8; // r2
  unsigned int v9; // r0

  v3 = (int *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) + 8 * a1);
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_50DCDC();
  v5 = *v3;
  if ( !*v3 )
  {
    v6 = (unsigned int *)v3[1];
    __dmb(0xBu);
    do
      v7 = __ldrex(v6);
    while ( (int *)v7 == v3 && __strex(0, v6) );
    if ( (int *)v7 == v3 )
      return KfLowerIrql(a2);
    v5 = KxWaitForLockChainValid(v3);
  }
  *v3 = 0;
  __dmb(0xBu);
  v8 = (unsigned int *)(v5 + 4);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 ^ 1, v8) );
  return KfLowerIrql(a2);
}
