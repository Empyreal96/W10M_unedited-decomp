// ObpIsUnsecureName 
 
int __fastcall ObpIsUnsecureName(unsigned __int16 *a1, int a2, int a3, int a4)
{
  unsigned __int16 *v4; // r4
  int v7; // r5
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v4 = (unsigned __int16 *)&ObpUnsecureGlobalNamesBuffer;
  if ( !ObpUnsecureGlobalNamesBuffer )
    return 0;
  while ( 1 )
  {
    RtlInitUnicodeString((unsigned int)v9, v4);
    v7 = LOWORD(v9[0]);
    if ( LOWORD(v9[0]) )
    {
      if ( RtlPrefixUnicodeString((unsigned __int16 *)v9, a1, a2) )
        break;
    }
    v4 += (unsigned int)(v7 + 2) >> 1;
    if ( !v7 )
      return 0;
  }
  return 1;
}
