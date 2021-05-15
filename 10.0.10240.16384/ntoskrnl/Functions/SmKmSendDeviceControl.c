// SmKmSendDeviceControl 
 
int __fastcall SmKmSendDeviceControl(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r0
  int result; // r0
  char v9[24]; // [sp+20h] [bp-18h] BYREF

  KeInitializeEvent((int)v9, 0, 0);
  v7 = IoBuildDeviceIoControlRequest(5046272, a2, 0, 0, a5, a6);
  if ( !v7 )
    return -1073741670;
  result = IofCallDriver(a2, v7);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v9, 0, 0, 0, 0);
    result = 0;
  }
  return result;
}
