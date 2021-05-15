// AdtpBuildLogonIdStrings 
 
int __fastcall AdtpBuildLogonIdStrings(_DWORD *a1, _DWORD *a2, _BYTE *a3, unsigned int a4, _BYTE *a5, unsigned int a6, _BYTE *a7)
{
  int v11; // r0
  int v12; // r5

  v11 = SepGetLogonSessionAccountInfo(a1, a4, a6, a2);
  v12 = v11;
  if ( v11 < 0 )
  {
    if ( *a1 != 999 || a1[1] )
    {
      if ( v11 != -1073741729 )
        return v12;
      RtlInitUnicodeString(a4, L"-");
      RtlInitUnicodeString(a6, L"-");
      *a5 = 0;
      *a7 = 0;
      if ( a2 )
      {
        *a3 = 0;
        *a2 = &AdtpNullSid;
      }
    }
    else
    {
      RtlInitUnicodeString(a4, L"SYSTEM");
      RtlInitUnicodeString(a6, L"SYSTEM");
      *a5 = 0;
      *a7 = 0;
    }
    return 0;
  }
  if ( *(_DWORD *)(a4 + 4) )
    return sub_815E88();
  RtlInitUnicodeString(a4, L"-");
  if ( *(_DWORD *)(a6 + 4) )
    *a7 = 1;
  else
    RtlInitUnicodeString(a6, L"-");
  if ( a2 )
  {
    if ( a3 )
      *a3 = 1;
  }
  return v12;
}
