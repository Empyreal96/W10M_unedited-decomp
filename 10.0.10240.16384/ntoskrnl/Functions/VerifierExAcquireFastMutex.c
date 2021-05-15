// VerifierExAcquireFastMutex 
 
_DWORD *__fastcall VerifierExAcquireFastMutex(_DWORD *a1)
{
  unsigned int vars4; // [sp+14h] [bp+4h]

  ViExAcquireFastMutexCommon(a1, (MmVerifierData & 0x20000) != 0);
  return VfDeadlockAcquireResource(a1, 3, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, vars4);
}
