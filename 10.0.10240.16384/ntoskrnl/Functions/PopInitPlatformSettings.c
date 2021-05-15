// PopInitPlatformSettings 
 
int PopInitPlatformSettings()
{
  unsigned int v0; // r4
  int v1; // r5
  _DWORD *v2; // r0
  int v3; // r2

  v0 = 0;
  v1 = ZwQuerySystemInformation();
  if ( v1 == -1073741789 )
  {
    v2 = (_DWORD *)ExAllocatePoolWithTag(1, 0, 544040269);
    v0 = (unsigned int)v2;
    if ( !v2 )
      sub_96F51C();
    *v2 = 1094930505;
    v2[1] = 1;
    v2[2] = 1346584902;
    v2[3] = -16;
    if ( ZwQuerySystemInformation() < 0 )
LABEL_22:
      JUMPOUT(0x96F51E);
    if ( *(unsigned __int8 *)(v0 + 24) >= 3u )
      PopFirmwarePlatformRole = *(unsigned __int8 *)(v0 + 61);
    if ( off_617AD8() )
      PopPlatformAoAc = 1;
    v3 = PopPlatformRoleOverride;
    if ( PopPlatformRoleOverride == -1 )
      v3 = PopFirmwarePlatformRole;
    else
      PopFirmwarePlatformRole = PopPlatformRoleOverride;
    if ( PopPlatformAoAcOverride != -1 )
      PopPlatformAoAc = PopPlatformAoAcOverride != 0;
    if ( v3 < 0 || v3 >= 9 )
    {
      v3 = 0;
      PopFirmwarePlatformRole = 0;
    }
    v1 = 0;
    PopPlatformRole = v3;
  }
  if ( v1 < 0 )
    goto LABEL_22;
  if ( v0 )
    ExFreePoolWithTag(v0);
  return v1;
}
