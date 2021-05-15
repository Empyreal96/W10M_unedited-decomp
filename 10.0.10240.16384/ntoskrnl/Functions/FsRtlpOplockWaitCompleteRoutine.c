// FsRtlpOplockWaitCompleteRoutine 
 
int __fastcall FsRtlpOplockWaitCompleteRoutine(int a1)
{
  return KeSetEvent(a1, 0, 0);
}
