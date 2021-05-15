// PopAllowAwayModeSettingCallback 
 
int __fastcall PopAllowAwayModeSettingCallback(unsigned int a1, _DWORD *a2, int a3)
{
  int v3; // r5

  v3 = -1073741811;
  PopAcquirePolicyLock();
  if ( !memcmp((unsigned int)&GUID_ALLOW_AWAYMODE, a1, 16) && a3 == 4 && a2 )
  {
    if ( *a2 )
      return sub_81C538();
    byte_61EC12 = 0;
    if ( byte_61EC11 )
      PopSetSystemState(4, 7);
    v3 = 0;
  }
  PopReleasePolicyLock();
  return v3;
}
