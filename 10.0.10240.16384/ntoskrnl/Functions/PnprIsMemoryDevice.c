// PnprIsMemoryDevice 
 
int __fastcall PnprIsMemoryDevice(int a1, int a2)
{
  unsigned __int16 *v2; // r4
  int v3; // r5
  int v4; // r0
  char v6; // [sp+10h] [bp-20h]
  unsigned __int16 *v7[2]; // [sp+14h] [bp-1Ch] BYREF

  v2 = 0;
  v3 = 0;
  v7[0] = 0;
  if ( !a2 )
  {
    if ( IoGetDevicePropertyData(a1) < 0 || v7[1] != (unsigned __int16 *)17 || !v6 )
      return v3;
    goto LABEL_8;
  }
  v4 = IoGetDeviceInterfaces((int)&GUID_DEVICE_MEMORY, a1, 0, v7);
  v2 = v7[0];
  if ( v4 >= 0 && *v7[0] )
LABEL_8:
    v3 = 1;
  if ( v2 )
    ExFreePoolWithTag((unsigned int)v2);
  return v3;
}
