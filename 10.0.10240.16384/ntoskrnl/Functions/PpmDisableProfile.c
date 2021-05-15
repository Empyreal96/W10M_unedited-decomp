// PpmDisableProfile 
 
int __fastcall PpmDisableProfile(int a1)
{
  int v2; // r6
  int v3; // r2
  _DWORD *v4; // r3

  v2 = *(unsigned __int8 *)(a1 + 4);
  *(_DWORD *)(a1 + 24) &= 0xFFFFFFFE;
  memmove(a1 + 32, (int)dword_61DBC0, 0xB0u);
  memmove(a1 + 208, (int)&dword_61DC70, 0xB0u);
  v3 = 2;
  v4 = (_DWORD *)a1;
  do
  {
    v4[8] = 0;
    v4[9] = 0;
    v4[52] = 0;
    v4[53] = 0;
    v4 += 2;
    --v3;
  }
  while ( v3 );
  if ( !memcmp(a1 + 8, (unsigned int)&GUID_POWER_POLICY_PROFILE_LOW_POWER, 16) )
    PpmLowPowerProfile = 0;
  return PpmEventTraceProfileEnable(v2, 0);
}
