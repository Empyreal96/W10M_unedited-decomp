// FsRtlpExclusiveIrpCancelRoutine 
 
int __fastcall FsRtlpExclusiveIrpCancelRoutine(int a1, int a2, int a3, int a4)
{
  return FsRtlpCancelExclusiveIrp(a2, 0, 1, a4);
}
