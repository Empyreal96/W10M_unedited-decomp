// VerifierExTryToAcquireFastMutex 
 
int __fastcall VerifierExTryToAcquireFastMutex(_DWORD *a1)
{
  int v2; // r4
  unsigned int vars4; // [sp+14h] [bp+4h]

  v2 = ViExTryToAcquireFastMutexCommon(a1, (MmVerifierData & 0x20000) != 0);
  if ( v2 )
    VfDeadlockAcquireResource(a1, 3, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, vars4);
  return v2;
}
