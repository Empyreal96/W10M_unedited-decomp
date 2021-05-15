// SepInternalQuerySecurityAttributesTokenEx 
 
int __fastcall SepInternalQuerySecurityAttributesTokenEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 176) & 0x20000) != 0 || !SepDetermineGlobalTableCheckNeededForQuery() )
    result = AuthzBasepQuerySecurityAttributesToken(*(_DWORD *)(a1 + 476), a3, a4, a5, a6, a7, 0);
  else
    result = sub_517C94();
  return result;
}
