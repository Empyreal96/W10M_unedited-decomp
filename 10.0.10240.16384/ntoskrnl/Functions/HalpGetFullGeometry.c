// HalpGetFullGeometry 
 
int __fastcall HalpGetFullGeometry(int a1, int a2, _QWORD *a3)
{
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r0
  int v10; // r4
  int v11; // r0
  __int64 v12; // r0
  int v13; // [sp+18h] [bp-48h]
  char v14[8]; // [sp+20h] [bp-40h] BYREF
  __int64 v15; // [sp+28h] [bp-38h]

  v6 = ExAllocatePoolWithTag(512, 16, 1651798854);
  v7 = v6;
  if ( !v6 )
    JUMPOUT(0x7D5C94);
  KeInitializeEvent(v6, 0, 0);
  v8 = IoBuildDeviceIoControlRequest(458752, a1, 0, 0, a2, 24);
  if ( !v8 )
    return sub_7D5C8C();
  v10 = IofCallDriver(a1, v8);
  if ( v10 == 259 )
  {
    KeWaitForSingleObject(v7, 0, 0, 0, 0);
    v10 = v13;
  }
  KeResetEvent(v7);
  if ( v10 >= 0 )
  {
    v11 = IoBuildDeviceIoControlRequest(475140, a1, 0, 0, (int)v14, 32);
    if ( v11 )
    {
      v10 = IofCallDriver(a1, v11);
      if ( v10 == 259 )
      {
        KeWaitForSingleObject(v7, 0, 0, 0, 0);
        v10 = v13;
      }
      if ( v10 >= 0 )
      {
        v12 = *(unsigned int *)(a2 + 20);
        if ( !(_DWORD)v12 )
          __brkdiv0();
        *a3 = (unsigned int)_rt_sdiv64((unsigned int)v12, v15);
      }
    }
    else
    {
      v10 = -1073741670;
    }
  }
  ExFreePoolWithTag(v7);
  return v10;
}
