// PnpBootDeviceWait 
 
int __fastcall PnpBootDeviceWait(int a1, int (__fastcall *a2)(int, int, __int16 *), int a3)
{
  int v7; // [sp+8h] [bp-38h] BYREF
  int v8[2]; // [sp+10h] [bp-30h] BYREF
  __int16 v9[2]; // [sp+18h] [bp-28h] BYREF
  int v10; // [sp+1Ch] [bp-24h]
  __int16 v11[2]; // [sp+20h] [bp-20h] BYREF
  const __int16 *v12; // [sp+24h] [bp-1Ch]

  v9[1] = 0;
  v9[0] = 0;
  v10 = 0;
  v11[1] = 110;
  v11[0] = 108;
  v12 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PnP";
  if ( IopOpenRegistryKeyEx(&v7, 0, v11, 131097) >= 0 )
  {
    if ( IopGetRegistryValue(v7, L"PollBootPartitionTimeout", 0, v8) >= 0 && *(_DWORD *)(v8[0] + 12) == 4 )
      ExFreePoolWithTag(v8[0], 0);
    ZwClose();
  }
  v8[0] = -2000000;
  v8[1] = -1;
  RtlFreeAnsiString(v9);
  if ( a2(a1, a3, v9) < 0 )
    return sub_54DEF4();
  RtlFreeAnsiString(v9);
  return 0;
}
