// MiReAcquireCommitFailWorker 
 
int __fastcall MiReAcquireCommitFailWorker(int a1)
{
  PsTerminateProcess(a1, -1073741523);
  KeForceResumeProcess(a1);
  return ObfDereferenceObjectWithTag(a1);
}
