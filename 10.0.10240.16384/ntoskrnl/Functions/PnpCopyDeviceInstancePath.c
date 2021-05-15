// PnpCopyDeviceInstancePath 
 
int __fastcall PnpCopyDeviceInstancePath(int a1, unsigned __int16 *a2)
{
  return RtlCopyUnicodeString((unsigned __int16 *)(a1 + 20), a2);
}
