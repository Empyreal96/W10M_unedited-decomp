// KeAcquireQueuedSpinLock 
 
int __fastcall KeAcquireQueuedSpinLock(int a1)
{
  int v2; // r5
  int v3; // r0
  unsigned int *v4; // r4
  _DWORD *v6; // r1

  v2 = KfRaiseIrql(2);
  v3 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) + 8 * a1;
  v4 = *(unsigned int **)(v3 + 4);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50DCE8();
  do
    v6 = (_DWORD *)__ldrex(v4);
  while ( __strex(v3, v4) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForLockOwnerShip(v3, v6);
  return v2;
}
