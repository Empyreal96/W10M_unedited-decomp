// FsRtlIsTotalDeviceFailure 
 
BOOL __fastcall FsRtlIsTotalDeviceFailure(int a1)
{
  return a1 < 0 && a1 != -1073741761 && a1 != -1073741668 && a1 != -1073740688;
}
