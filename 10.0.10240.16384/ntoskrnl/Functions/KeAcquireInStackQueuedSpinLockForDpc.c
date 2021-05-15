// KeAcquireInStackQueuedSpinLockForDpc 
 
unsigned int *__fastcall KeAcquireInStackQueuedSpinLockForDpc(unsigned int *a1, unsigned int a2)
{
  unsigned int *result; // r0

  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
    result = (unsigned int *)KeAcquireInStackQueuedSpinLock(a1, a2);
  else
    result = KeAcquireInStackQueuedSpinLockAtDpcLevel(a1, (_DWORD *)a2);
  return result;
}
