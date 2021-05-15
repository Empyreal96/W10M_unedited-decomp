// SiGetFirmwareBootDeviceNameFromRegistry 
 
int __fastcall SiGetFirmwareBootDeviceNameFromRegistry(unsigned __int16 **a1)
{
  int v2; // r5
  unsigned int v4; // [sp+8h] [bp-18h]
  unsigned __int16 *v5; // [sp+Ch] [bp-14h]

  v2 = SiGetRegistryValue(a1, L"FirmwareBootDevice");
  if ( v2 >= 0 )
  {
    if ( v4 < 4 )
    {
      v2 = -1073741823;
    }
    else
    {
      wcslwr(v5);
      *a1 = v5;
    }
  }
  return v2;
}
