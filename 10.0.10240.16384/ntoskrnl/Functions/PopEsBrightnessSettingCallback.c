// PopEsBrightnessSettingCallback 
 
int __fastcall PopEsBrightnessSettingCallback(unsigned int a1, int *a2, int a3)
{
  int v5; // r4

  v5 = -1073741811;
  if ( !memcmp((unsigned int)&GUID_ENERGY_SAVER_BRIGHTNESS, a1, 16) && a3 == 4 && a2 )
  {
    PopAcquirePolicyLock();
    dword_61EC40 = *a2;
    PopReleasePolicyLock();
    v5 = 0;
  }
  return v5;
}
