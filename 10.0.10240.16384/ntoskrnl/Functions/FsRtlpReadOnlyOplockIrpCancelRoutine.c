// FsRtlpReadOnlyOplockIrpCancelRoutine 
 
_DWORD *__fastcall FsRtlpReadOnlyOplockIrpCancelRoutine(int a1, int a2)
{
  return FsRtlpCancelReadOnlyOplockIrp(a2, 0);
}
