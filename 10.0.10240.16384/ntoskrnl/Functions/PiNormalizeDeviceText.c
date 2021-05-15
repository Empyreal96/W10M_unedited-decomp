// PiNormalizeDeviceText 
 
int __fastcall PiNormalizeDeviceText(unsigned __int16 *a1, _DWORD *a2)
{
  int v3; // r4
  unsigned __int16 v5[4]; // [sp+40h] [bp-48h] BYREF
  _DWORD v6[16]; // [sp+48h] [bp-40h] BYREF

  *a2 = 0;
  RtlInitUnicodeString((unsigned int)v6, 0);
  v3 = RtlInitUnicodeStringEx((int)v5, a1);
  if ( v3 >= 0 )
  {
    if ( RtlPrefixUnicodeString(CmRegistryMachineName, v5, 1) )
      return sub_7EFD40();
    v3 = 0;
  }
  RtlFreeAnsiString(v6);
  return v3;
}
