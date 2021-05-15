// PnpSetRegistryResourceList 
 
int __fastcall PnpSetRegistryResourceList(int a1, int a2, int *a3, int a4)
{
  _DWORD v6[4]; // [sp+8h] [bp-10h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  RtlInitUnicodeString((unsigned int)v6, L"BootConfig");
  if ( !a3 )
    return ZwDeleteValueKey();
  PnpDetermineResourceListSize(a3);
  return ZwSetValueKey();
}
