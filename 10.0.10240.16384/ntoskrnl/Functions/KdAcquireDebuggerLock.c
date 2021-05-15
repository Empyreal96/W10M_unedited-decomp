// KdAcquireDebuggerLock 
 
int *__fastcall KdAcquireDebuggerLock(_BYTE *a1)
{
  int *result; // r0
  unsigned int v2; // r2

  *a1 = KfRaiseIrql(2);
  result = &KdDebuggerLock;
  if ( (dword_682604 & 0x210000) != 0 )
    return (int *)KiAcquireSpinLockInstrumented((int)&KdDebuggerLock);
  do
    v2 = __ldrex((unsigned int *)&KdDebuggerLock);
  while ( __strex(1u, (unsigned int *)&KdDebuggerLock) );
  __dmb(0xBu);
  if ( v2 )
    result = (int *)KxWaitForSpinLockAndAcquire((unsigned int *)&KdDebuggerLock);
  return result;
}
