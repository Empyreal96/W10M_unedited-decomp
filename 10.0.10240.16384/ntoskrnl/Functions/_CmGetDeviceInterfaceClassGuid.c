// _CmGetDeviceInterfaceClassGuid 
 
int __fastcall CmGetDeviceInterfaceClassGuid(int a1, unsigned __int16 *a2, _BYTE *a3)
{
  int result; // r0
  unsigned __int16 v5[4]; // [sp-4h] [bp-60h] BYREF
  unsigned __int16 v6[44]; // [sp+4h] [bp-58h] BYREF

  result = CmGetDeviceInterfaceClassGuidString(a1, a2, v6);
  if ( result >= 0 )
  {
    result = RtlInitUnicodeStringEx((int)v5, v6);
    if ( result >= 0 )
      result = RtlGUIDFromString(v5, a3);
  }
  return result;
}
