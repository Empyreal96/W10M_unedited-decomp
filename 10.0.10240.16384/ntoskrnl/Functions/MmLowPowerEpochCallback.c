// MmLowPowerEpochCallback 
 
int __fastcall MmLowPowerEpochCallback(unsigned int a1, _DWORD *a2, int a3)
{
  if ( !memcmp((unsigned int)&GUID_LOW_POWER_EPOCH, a1, 16) && a3 == 4 && a2 )
    byte_63434D = *a2 != 0;
  return 0;
}
