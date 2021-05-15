// CmInitializeProcessor 
 
int __fastcall CmInitializeProcessor(int a1)
{
  int v2; // r4
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v7; // [sp+10h] [bp-50h]
  int v8[10]; // [sp+18h] [bp-48h] BYREF
  _DWORD v9[8]; // [sp+40h] [bp-20h] BYREF

  v8[4] = 24;
  v8[5] = 0;
  v8[6] = (int)&CmRegistryMachineHardwareDescriptionSystemName;
  v8[7] = 576;
  v8[8] = 0;
  v8[9] = 0;
  v2 = ZwCreateKey();
  if ( v2 >= 0 )
  {
    CmpConfigurationData = (void *)ExAllocatePoolWithTag(1, CmpConfigurationAreaSize, 538987843);
    if ( CmpConfigurationData )
    {
      v8[0] = 0;
      v8[1] = 0;
      v8[2] = 0;
      v8[0] = 1 << *(_DWORD *)(a1 + 20);
      KeSetSystemGroupAffinityThread((int)v8, v9);
      CmpAddProcessorConfigurationEntry(a1, *(_DWORD *)(a1 + 20), v7);
      KeRevertToUserGroupAffinityThread((int)v9, v3, v4, v5);
      ExFreePoolWithTag((unsigned int)CmpConfigurationData);
      CmpConfigurationData = 0;
      v2 = 0;
    }
    else
    {
      v2 = -1073741670;
    }
    ZwClose();
  }
  return v2;
}
