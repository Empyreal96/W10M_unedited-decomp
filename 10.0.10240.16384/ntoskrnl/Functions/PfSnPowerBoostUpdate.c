// PfSnPowerBoostUpdate 
 
int __fastcall PfSnPowerBoostUpdate(int result)
{
  int v1; // r4
  unsigned int v2; // r5
  _DWORD v3[6]; // [sp+10h] [bp-18h] BYREF

  if ( result )
    v1 = 1;
  else
    v1 = -1;
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)algn_637414);
  while ( __strex(v2 + v1, (unsigned int *)algn_637414) );
  __dmb(0xBu);
  if ( !v2 && result || v2 == 1 && !result )
  {
    v3[0] = (2 * (result & 1)) | 1;
    v3[1] = -1;
    result = NtUpdateWnfStateData((int)WNF_SEB_APP_LAUNCH_PREFETCH, (int)v3, 8u, 0, 0, 0, 0);
  }
  return result;
}
