// CmpInitializeMachineDependentConfiguration 
 
int __fastcall CmpInitializeMachineDependentConfiguration(int a1)
{
  unsigned int i; // r3
  int result; // r0
  void *v4; // r0
  unsigned int v5; // r9
  int *v6; // r8
  int v7; // t1
  int v8; // r3
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // [sp+10h] [bp-78h] BYREF
  int v13; // [sp+18h] [bp-70h] BYREF
  int v14; // [sp+1Ch] [bp-6Ch]
  unsigned __int16 *v15; // [sp+20h] [bp-68h]
  int v16; // [sp+24h] [bp-64h]
  int v17; // [sp+28h] [bp-60h]
  int v18; // [sp+2Ch] [bp-5Ch]
  int v19; // [sp+30h] [bp-58h]
  int v20; // [sp+34h] [bp-54h] BYREF
  int v21[4]; // [sp+38h] [bp-50h] BYREF
  char v22[8]; // [sp+48h] [bp-40h] BYREF
  char v23[8]; // [sp+50h] [bp-38h] BYREF
  _DWORD v24[12]; // [sp+58h] [bp-30h] BYREF

  for ( i = 0; i < 0x54; i += 2 )
    *(_WORD *)((char *)&CmpDeviceIndexTable + i) = 0;
  v13 = 24;
  v14 = 0;
  v15 = CmRegistryMachineHardwareDescriptionSystemName;
  v16 = 64;
  v17 = 0;
  v18 = 0;
  result = NtCreateKey((int)&v12, 131097, (int)&v13, 0, 0);
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v22, L"CentralProcessor");
    v13 = 24;
    v14 = v12;
    v15 = (unsigned __int16 *)v22;
    v17 = 0;
    v18 = 0;
    v16 = 64;
    RtlInitUnicodeString((unsigned int)v23, L"Processor");
    NtCreateKey((int)&v20, 131103, (int)&v13, 0, (int)v23);
    NtClose();
    if ( v19 == 1 )
    {
      v4 = (void *)ExAllocatePoolWithTag(1, CmpConfigurationAreaSize, 538987843);
      CmpConfigurationData = v4;
      v5 = 0;
      if ( KeNumberProcessors_0 )
      {
        v6 = (int *)&KiProcessorBlock;
        do
        {
          v7 = *v6++;
          v21[0] = 0;
          v21[1] = 0;
          v8 = *(_DWORD *)(v7 + 20);
          v21[2] = 0;
          v21[0] = 1 << v8;
          KeSetSystemGroupAffinityThread((int)v21, v24);
          CmpAddProcessorConfigurationEntry(v7, v5, v12);
          KeRevertToUserGroupAffinityThread((int)v24, v9, v10, v11);
          ++v5;
        }
        while ( v5 < KeNumberProcessors_0 );
        v4 = CmpConfigurationData;
      }
      if ( v4 )
      {
        ExFreePoolWithTag((unsigned int)v4);
        CmpConfigurationData = 0;
      }
    }
    CmpInitializeSystemBiosInformation(a1);
    NtClose();
    result = 0;
  }
  return result;
}
