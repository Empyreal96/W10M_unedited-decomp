// VerifierExTryToAcquireFastMutexNoReboot 
 
int __fastcall VerifierExTryToAcquireFastMutexNoReboot(int a1)
{
  return ViExTryToAcquireFastMutexCommon(a1, 0);
}
