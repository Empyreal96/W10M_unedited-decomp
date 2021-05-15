// WmipSaveGuidSecurityDescriptor 
 
int __fastcall WmipSaveGuidSecurityDescriptor(int a1, int a2)
{
  RtlLengthSecurityDescriptor(a2);
  return RtlWriteRegistryValue(2, (int)L"WMI\\Security", *(unsigned __int16 **)(a1 + 4));
}
