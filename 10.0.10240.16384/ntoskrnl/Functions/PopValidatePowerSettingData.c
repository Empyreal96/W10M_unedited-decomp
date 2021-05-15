// PopValidatePowerSettingData 
 
int __fastcall PopValidatePowerSettingData(unsigned int a1, int a2, _DWORD *a3)
{
  int v6; // r5

  v6 = -1073741275;
  if ( !memcmp((unsigned int)&GUID_DISK_POWERDOWN_TIMEOUT, a1, 16) && a2 == 4 && a3 && *a3 && !PopPlatformAoAc )
    return sub_7C38E0();
  if ( !memcmp((unsigned int)&GUID_STANDBY_TIMEOUT, a1, 16) && a2 == 4 && a3 && *a3 && *a3 < 0x1Eu )
  {
    *a3 = 30;
    v6 = 0;
  }
  if ( !memcmp((unsigned int)&GUID_HIBERNATE_TIMEOUT, a1, 16) && a2 == 4 && a3 && *a3 && *a3 < 0x3Cu )
  {
    *a3 = 60;
    v6 = 0;
  }
  return v6;
}
