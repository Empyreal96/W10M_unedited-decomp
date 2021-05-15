// KeAcquireInStackQueuedSpinLock 
 
int __fastcall KeAcquireInStackQueuedSpinLock(unsigned int *a1, unsigned int a2)
{
  int result; // r0
  unsigned int v5; // r1

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = a1;
  __dmb(0xBu);
  result = KfRaiseIrql(2);
  *(_BYTE *)(a2 + 8) = result;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50C608();
  do
    v5 = __ldrex(a1);
  while ( __strex(a2, a1) );
  __dmb(0xBu);
  if ( v5 )
    result = KxWaitForLockOwnerShip(a2);
  return result;
}
