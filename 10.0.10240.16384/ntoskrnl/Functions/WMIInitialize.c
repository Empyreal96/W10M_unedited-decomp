// WMIInitialize 
 
int __fastcall WMIInitialize(int a1, int a2)
{
  int v4; // [sp+0h] [bp-18h] BYREF
  char v5; // [sp+4h] [bp-14h]
  int (__fastcall *v6)(_DWORD *); // [sp+8h] [bp-10h]
  int v7; // [sp+Ch] [bp-Ch]

  if ( a1 )
  {
    WmipInitializeRegistration();
    v4 = 1381190978;
    v5 = 1;
    v6 = WmipRawSMBiosTableHandler;
    v7 = PnpDriverObject;
    NtSetSystemInformation(75, (unsigned int)&v4, 0x10u, PnpDriverObject);
  }
  else
  {
    WmipInitializeAllocs();
    RtlInitUnicodeString((unsigned int)&v4, L"\\Driver\\WMIxWDM");
    if ( IoCreateDriver(&v4, (int (__fastcall *)(_BYTE *, _DWORD))WmipDriverEntry) < 0 )
      return 0;
    WmipGetSMBiosFromLoaderBlock(a2);
    WmipGetSMBiosProcessorInfo();
  }
  return 1;
}
