// FsRtlpOplockRHIrpCancelRoutine 
 
int __fastcall FsRtlpOplockRHIrpCancelRoutine(int a1, int a2, int a3, int a4)
{
  return FsRtlpCancelOplockRHIrp(a2, 0, 1, a4);
}
