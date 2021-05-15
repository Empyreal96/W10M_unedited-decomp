// IopOpenSystemVariableDevice 
 
int __fastcall IopOpenSystemVariableDevice(_DWORD *a1, _DWORD *a2, void ***a3)
{
  int v6; // r4
  void **v7; // r3
  unsigned __int16 *v8; // r6
  int v9; // r0
  unsigned __int16 *v11; // [sp+0h] [bp-28h] BYREF
  char v12[32]; // [sp+8h] [bp-20h] BYREF

  if ( (IopSysEnvOverrideFlags & 1) != 0 )
  {
    RtlInitUnicodeString((unsigned int)v12, L"\\Device\\WindowsTrustedRT\\{699AA2F1-A42E-40DF-BABE-3AAAD2BB6A47}");
    v6 = IoGetDeviceObjectPointer(v12, 0x10000000, a1, a2);
    if ( v6 >= 0 )
    {
LABEL_3:
      v7 = &IopSysEnvFunctionTableTrEE;
LABEL_14:
      *a3 = v7;
      return v6;
    }
    goto LABEL_8;
  }
  v11 = 0;
  if ( IoGetDeviceInterfaces((int)&GUID_EFI_VARIABLE_SERVICE, 0, 0, &v11) < 0 || (v8 = v11, !*v11) )
  {
LABEL_8:
    RtlInitUnicodeString((unsigned int)v12, L"\\Device\\SysEnv");
    v9 = IoGetDeviceObjectPointer(v12, 0x10000000, a1, a2);
    v6 = v9;
    if ( v9 >= 0 )
    {
      v7 = &IopSysEnvFunctionTableSysEnv;
      goto LABEL_14;
    }
    if ( v9 == -1073741773 || v9 == -1073741772 || v9 == -1073741766 )
    {
      *a1 = 0;
      *a2 = 0;
      v7 = &IopSysEnvFunctionTableHal;
      v6 = 0;
      goto LABEL_14;
    }
    return v6;
  }
  RtlInitUnicodeString((unsigned int)v12, v11);
  v6 = IoGetDeviceObjectPointer(v12, 0x10000000, a1, a2);
  ExFreePoolWithTag((unsigned int)v8);
  if ( v6 >= 0 )
    goto LABEL_3;
  return v6;
}
