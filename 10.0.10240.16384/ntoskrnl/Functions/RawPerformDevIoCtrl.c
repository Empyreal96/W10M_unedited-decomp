// RawPerformDevIoCtrl 
 
int __fastcall RawPerformDevIoCtrl(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // r0
  int result; // r0
  char v8[24]; // [sp+20h] [bp-18h] BYREF

  KeInitializeEvent((int)v8, 0, 0);
  v6 = IoBuildDeviceIoControlRequest(458752, a2, 0, 0, a5, 24);
  if ( !v6 )
    return -1073741670;
  *(_BYTE *)(*(_DWORD *)(v6 + 96) - 38) |= 2u;
  result = IofCallDriver(a2, v6);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v8, 0, 0, 0, 0);
    result = 0;
  }
  return result;
}
