// FsRtlBalanceReads 
 
int __fastcall FsRtlBalanceReads(int a1)
{
  int v2; // r0
  int result; // r0
  char v4[24]; // [sp+20h] [bp-18h] BYREF

  KeInitializeEvent((int)v4, 0, 0);
  v2 = IoBuildDeviceIoControlRequest((int)&off_660018 + 3, a1, 0, 0, 0, 0);
  if ( !v2 )
    return -1073741670;
  result = IofCallDriver(a1, v2);
  if ( result == 259 )
    result = sub_81AB10();
  return result;
}
