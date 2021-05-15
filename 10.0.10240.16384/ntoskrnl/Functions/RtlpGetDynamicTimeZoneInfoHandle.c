// RtlpGetDynamicTimeZoneInfoHandle 
 
int __fastcall RtlpGetDynamicTimeZoneInfoHandle(_WORD *a1, int *a2)
{
  int result; // r0
  int v5; // r3
  int v6; // r3
  unsigned __int16 v7[264]; // [sp-4h] [bp-210h] BYREF

  if ( !*a1 )
    return -1073741811;
  result = RtlStringCbCopyW((int)v7, 0x200u);
  if ( result >= 0 )
  {
    result = RtlStringCbCatW(v7, 0x200u, (int)a1, v5);
    if ( result >= 0 )
    {
      result = RtlStringCbCatW(v7, 0x200u, (int)L"\\Dynamic DST", v6);
      if ( result >= 0 )
        result = RtlpGetRegistryHandle(3, (int)v7, 0, a2);
    }
  }
  return result;
}
