// FsRtlpNotifyOplockBreakComplete 
 
int __fastcall FsRtlpNotifyOplockBreakComplete(int a1, int a2)
{
  return IofCompleteRequest(a2, 1);
}
