// KeAcquireQueuedSpinLockAtDpcLevel 
 
int __fastcall KeAcquireQueuedSpinLockAtDpcLevel(int result, int a2)
{
  unsigned int *v2; // r2
  _DWORD *v3; // r1

  v2 = *(unsigned int **)(result + 4);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54ACCC(result, a2, v2);
  do
    v3 = (_DWORD *)__ldrex(v2);
  while ( __strex(result, v2) );
  __dmb(0xBu);
  if ( v3 )
    result = KxWaitForLockOwnerShip(result, v3);
  return result;
}
