// AdtpBuildSockAddrString 
 
int __fastcall AdtpBuildSockAddrString(_WORD *a1, unsigned int a2, _BYTE *a3, unsigned int a4, _BYTE *a5)
{
  int v7; // r2

  if ( a3 )
    *a3 = 0;
  if ( a5 )
    *a5 = 0;
  v7 = (unsigned __int16)*a1;
  switch ( v7 )
  {
    case 2:
      return AdtpBuildIPv4Strings((int)a1, a2, a3, a4, a5);
    case 23:
      return AdtpBuildIPv6Strings(a1, a2, a3, a4, a5);
    case 33:
      return AdtpBuildMacStrings((int)a1, a2, a3);
  }
  if ( a2 && a3 )
  {
    RtlInitUnicodeString(a2, L"-");
    *a3 = 0;
  }
  if ( a4 )
  {
    if ( a5 )
    {
      RtlInitUnicodeString(a4, L"-");
      *a5 = 0;
    }
  }
  return 0;
}
