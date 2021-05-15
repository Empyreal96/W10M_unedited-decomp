// VerifierExReleaseFastMutexUnsafeNoReboot 
 
int __fastcall VerifierExReleaseFastMutexUnsafeNoReboot(int a1)
{
  if ( (MmVerifierData & 0x800) != 0 )
    ViExCheckAPCsDisabled(58, a1);
  return pXdvExReleaseFastMutexUnsafe(a1);
}
