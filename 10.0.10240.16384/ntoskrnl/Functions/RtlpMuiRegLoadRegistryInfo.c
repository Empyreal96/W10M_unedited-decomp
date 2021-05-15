// RtlpMuiRegLoadRegistryInfo 
 
int __fastcall RtlpMuiRegLoadRegistryInfo(_DWORD *a1)
{
  int result; // r0
  int v3; // r0
  int v4; // [sp+0h] [bp-8h] BYREF

  v4 = 0;
  if ( !a1 )
    return -1073741811;
  if ( RtlpMuiRegLoadLicInformation(a1) < 0 )
    return sub_817F68();
  result = RtlpMuiRegLoadInstalled((int)a1);
  if ( result >= 0 )
  {
    v3 = RtlpMuiRegFreeRegistryInfo(a1, 4);
    result = RtlpLoadLanguageConfigList(v3, &v4, a1);
    if ( result >= 0 )
    {
      if ( v4 )
      {
        a1[7] = v4;
        *a1 |= 4u;
      }
    }
  }
  return result;
}
