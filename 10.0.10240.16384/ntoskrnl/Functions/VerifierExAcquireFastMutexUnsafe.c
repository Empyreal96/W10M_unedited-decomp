// VerifierExAcquireFastMutexUnsafe 
 
_DWORD *__fastcall VerifierExAcquireFastMutexUnsafe(_DWORD *a1)
{
  unsigned int vars4; // [sp+14h] [bp+4h]

  VerifierExAcquireFastMutexUnsafeNoReboot(a1);
  return VfDeadlockAcquireResource(a1, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, vars4);
}
