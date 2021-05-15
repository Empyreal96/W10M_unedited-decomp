// KeAcquireInStackQueuedSpinLockAtDpcLevel 
 
unsigned int *__fastcall KeAcquireInStackQueuedSpinLockAtDpcLevel(unsigned int *result, _DWORD *a2)
{
  _DWORD *v3; // r1

  *a2 = 0;
  a2[1] = result;
  __dmb(0xBu);
  if ( (dword_682604 & 0x210000) != 0 )
    return (unsigned int *)sub_50DCD0();
  do
    v3 = (_DWORD *)__ldrex(result);
  while ( __strex((unsigned int)a2, result) );
  __dmb(0xBu);
  if ( v3 )
    result = (unsigned int *)KxWaitForLockOwnerShip((int)a2, v3);
  return result;
}
