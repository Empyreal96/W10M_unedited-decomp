// CmpInitializeHardwareConfiguration 
 
int __fastcall CmpInitializeHardwareConfiguration(int a1)
{
  int v1; // r6
  int v2; // r4
  void *v3; // r0
  int v5; // [sp+10h] [bp-30h] BYREF
  int v6; // [sp+18h] [bp-28h] BYREF
  int v7; // [sp+1Ch] [bp-24h]
  void *v8; // [sp+20h] [bp-20h]
  int v9; // [sp+24h] [bp-1Ch]
  int v10; // [sp+28h] [bp-18h]
  int v11; // [sp+2Ch] [bp-14h]

  v6 = 24;
  v7 = 0;
  v1 = *(_DWORD *)(a1 + 100);
  v8 = &CmRegistryMachineHardwareDeviceMapName;
  v10 = 0;
  v11 = 0;
  v9 = 64;
  v2 = NtCreateKey((int)&v5, 131103, (int)&v6, 0, 0);
  if ( v2 >= 0 )
  {
    NtClose();
    v6 = 24;
    v7 = 0;
    v8 = &CmRegistryMachineHardwareDescriptionName;
    v10 = 0;
    v11 = 0;
    v9 = 64;
    v2 = NtCreateKey((int)&v5, 131103, (int)&v6, 0, 0);
    if ( v2 >= 0 )
    {
      v3 = (void *)ExAllocatePoolWithTag(1, CmpConfigurationAreaSize, 538987843);
      CmpConfigurationData = v3;
      if ( v3 )
      {
        if ( v1 )
        {
          v2 = CmpSetupConfigurationTree(v1, v5, -1, -1);
          v3 = CmpConfigurationData;
        }
        else
        {
          v2 = 0;
        }
        ExFreePoolWithTag((unsigned int)v3);
        CmpConfigurationData = 0;
      }
      else
      {
        v2 = -1073741670;
      }
      NtClose();
    }
  }
  return v2;
}
