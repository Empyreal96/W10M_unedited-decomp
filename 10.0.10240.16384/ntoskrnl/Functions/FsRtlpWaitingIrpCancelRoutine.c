// FsRtlpWaitingIrpCancelRoutine 
 
int __fastcall FsRtlpWaitingIrpCancelRoutine(int a1, int a2)
{
  return FsRtlpCancelWaitingIrp(a2, 0);
}
