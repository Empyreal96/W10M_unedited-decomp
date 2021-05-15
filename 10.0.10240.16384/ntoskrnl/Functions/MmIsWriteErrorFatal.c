// MmIsWriteErrorFatal 
 
int __fastcall MmIsWriteErrorFatal(int a1, int a2, int a3)
{
  int result; // r0

  if ( a3 == -1073741740 )
    result = FsRtlIsTotalDeviceFailure(-1073741740) == 0;
  else
    result = sub_50AD68();
  return result;
}
