// PnprIsProcessorDevice 
 
int __fastcall PnprIsProcessorDevice(int a1, int a2, int *a3, int a4)
{
  int v4; // r4
  int v8; // r3
  int v10; // [sp+10h] [bp-20h]
  int v11; // [sp+14h] [bp-1Ch]
  unsigned __int16 *v12; // [sp+18h] [bp-18h] BYREF

  v4 = 0;
  if ( a2 )
  {
    if ( IoGetDeviceInterfaces((int)&GUID_DEVICE_PROCESSOR, a1, 0, &v12) >= 0 )
    {
      if ( *v12 )
      {
        ExFreePoolWithTag((unsigned int)v12);
        if ( IoGetDevicePropertyData(a1) >= 0 && v10 == 7 && HalGetProcessorIdByNtNumber(v11, a4) >= 0 )
        {
          v8 = v11;
LABEL_11:
          v4 = 1;
          *a3 = v8;
          return v4;
        }
      }
    }
  }
  else if ( IoGetDevicePropertyData(a1) >= 0 && v10 == 7 )
  {
    v8 = -1;
    goto LABEL_11;
  }
  return v4;
}
