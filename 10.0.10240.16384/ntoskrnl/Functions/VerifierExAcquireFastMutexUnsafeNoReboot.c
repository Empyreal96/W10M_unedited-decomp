// VerifierExAcquireFastMutexUnsafeNoReboot 
 
int __fastcall VerifierExAcquireFastMutexUnsafeNoReboot(int a1)
{
  if ( (MmVerifierData & 0x800) != 0 )
    ViExCheckAPCsDisabled(57, a1);
  return pXdvExAcquireFastMutexUnsafe(a1);
}
