// PpmEnableProfile 
 
int __fastcall PpmEnableProfile(int a1)
{
  int v2; // r5

  v2 = *(unsigned __int8 *)(a1 + 4);
  *(_DWORD *)(a1 + 24) |= 1u;
  if ( !memcmp(a1 + 8, (unsigned int)&GUID_POWER_POLICY_PROFILE_LOW_POWER, 16) )
    PpmLowPowerProfile = a1;
  return PpmEventTraceProfileEnable(v2, 1);
}
