// IoQueryDeviceDescription 
 
int __fastcall IoQueryDeviceDescription(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r4
  int v10; // [sp+8h] [bp-38h] BYREF
  int v11; // [sp+Ch] [bp-34h] BYREF
  int v12; // [sp+10h] [bp-30h] BYREF
  int v13; // [sp+14h] [bp-2Ch]
  _DWORD v14[10]; // [sp+18h] [bp-28h] BYREF

  v11 = -1;
  if ( !a1 )
    return -1073741822;
  v14[2] = a3;
  v14[3] = a4;
  v14[0] = a1;
  v14[1] = a2;
  v14[4] = a5;
  v14[5] = a6;
  v14[6] = a7;
  v14[7] = a8;
  v12 = 0x8000000;
  v13 = ExAllocatePoolWithTag(1, 2048, 1314025289);
  if ( !v13 )
    return -1073741670;
  RtlAppendUnicodeStringToString((unsigned __int16 *)&v12, CmRegistryMachineHardwareDescriptionSystemName);
  v8 = IopOpenRegistryKey((int)&v10, 0, (int)&v12, 131097, 0);
  if ( v8 >= 0 )
  {
    v8 = pIoQueryBusDescription(v14, v12, v13, v10, &v11, 1);
    ZwClose();
  }
  ExFreePoolWithTag(v13);
  if ( v8 == -2147483622 )
    v8 = -1073741772;
  return v8;
}
