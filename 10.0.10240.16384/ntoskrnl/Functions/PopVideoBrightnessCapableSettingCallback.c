// PopVideoBrightnessCapableSettingCallback 
 
int __fastcall PopVideoBrightnessCapableSettingCallback(unsigned int a1, _DWORD *a2, int a3)
{
  int v5; // r1
  int v6; // r0

  if ( memcmp((unsigned int)&GUID_VIDEO_BRIGHTNESS_CAPABLE, a1, 16) || a3 != 4 || !a2 )
    return -1073741811;
  v6 = PopAcquirePolicyLock(0, v5);
  if ( *a2 )
    byte_61EA4A = 1;
  PopReleasePolicyLock(v6);
  return 0;
}
