// VerifierExReleaseFastMutexNoReboot 
 
int __fastcall VerifierExReleaseFastMutexNoReboot(int a1)
{
  ViExReleaseFastMutexCommon();
  return pXdvExReleaseFastMutex(a1);
}
