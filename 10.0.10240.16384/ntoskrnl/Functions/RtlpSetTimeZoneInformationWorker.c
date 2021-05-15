// RtlpSetTimeZoneInformationWorker 
 
int __fastcall RtlpSetTimeZoneInformationWorker(int a1, unsigned int a2)
{
  int v4; // r4
  int v6[9]; // [sp+Ch] [bp-24h] BYREF

  if ( wcsnlen((unsigned __int16 *)(a1 + 4), 0x20u) >= 0x20
    || wcsnlen((unsigned __int16 *)(a1 + 88), 0x20u) >= 0x20
    || a2 >= 0x1B0 && wcsnlen((unsigned __int16 *)(a1 + 172), 0x80u) >= 0x80 )
  {
    return -1073741811;
  }
  v4 = RtlpGetRegistryHandle(2, (int)L"TimeZoneInformation", 1, v6);
  if ( v4 >= 0 )
  {
    if ( RtlWriteRegistryValue(0x40000000, v6[0], L"Bias") < 0
      || RtlWriteRegistryValue(0x40000000, v6[0], L"StandardName") < 0
      || RtlWriteRegistryValue(0x40000000, v6[0], L"StandardBias") < 0
      || RtlWriteRegistryValue(0x40000000, v6[0], L"StandardStart") < 0
      || RtlWriteRegistryValue(0x40000000, v6[0], (unsigned __int16 *)&szDaylightName) < 0
      || RtlWriteRegistryValue(0x40000000, v6[0], L"DaylightBias") < 0
      || RtlWriteRegistryValue(0x40000000, v6[0], L"DaylightStart") < 0
      || a2 < 0x1B0 )
    {
      v4 = RtlWriteRegistryValue(0x40000000, v6[0], (unsigned __int16 *)&szTimeZoneKeyName);
      if ( v4 >= 0 )
      {
        v6[1] = *(unsigned __int8 *)(a1 + 428);
LABEL_19:
        v4 = RtlWriteRegistryValue(0x40000000, v6[0], L"DynamicDaylightTimeDisabled");
        goto LABEL_20;
      }
    }
    else
    {
      v4 = RtlWriteRegistryValue(0x40000000, v6[0], (unsigned __int16 *)&szTimeZoneKeyName);
      if ( v4 >= 0 )
        goto LABEL_19;
    }
LABEL_20:
    ZwClose();
  }
  return v4;
}
