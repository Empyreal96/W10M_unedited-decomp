// IopQueryDeviceResetRegistrySettings 
 
int __fastcall IopQueryDeviceResetRegistrySettings(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int result; // r0
  unsigned int v7; // r4
  unsigned int v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  v5 = 10;
  if ( IopGetRegistryValue(a1, L"DeviceResetRetryInterval", 0, (int *)v8) >= 0 )
    return sub_970A78();
  result = IopGetRegistryValue(a1, L"DeviceResetMaximumRetries", 0, (int *)v8);
  if ( result >= 0 )
  {
    result = v8[0];
    if ( *(_DWORD *)(v8[0] + 12) == 4 )
    {
      v7 = *(_DWORD *)(*(_DWORD *)(v8[0] + 8) + v8[0]);
      result = ExFreePoolWithTag(v8[0]);
      if ( v7 <= 0x64 )
        v5 = v7;
    }
  }
  PnpResetRetryInterval = -30000000i64;
  PnpResetMaximumRetryAttempts = v5;
  return result;
}
