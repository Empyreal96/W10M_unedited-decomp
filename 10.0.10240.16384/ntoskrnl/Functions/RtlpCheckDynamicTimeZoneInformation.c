// RtlpCheckDynamicTimeZoneInformation 
 
int __fastcall RtlpCheckDynamicTimeZoneInformation(unsigned int a1, __int16 a2)
{
  int v5; // [sp+0h] [bp-F8h] BYREF
  char v6[48]; // [sp+8h] [bp-F0h] BYREF
  char v7[192]; // [sp+38h] [bp-C0h] BYREF

  if ( RtlpGetDynamicTimeZoneInfoHandle(a1 + 172, &v5) >= 0 )
  {
    if ( RtlpFindRegTziForCurrentYear(v6, v5, a2) >= 0 )
    {
      memmove((int)v7, a1, 0xACu);
      RtlpRegTziFormatToTzi(v7, v6);
      if ( memcmp((unsigned int)v7, a1, 172) )
        return sub_80BB24();
    }
    ZwClose();
  }
  return 0;
}
