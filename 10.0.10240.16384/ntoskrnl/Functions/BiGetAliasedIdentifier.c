// BiGetAliasedIdentifier 
 
int __fastcall BiGetAliasedIdentifier(int a1, int a2, int a3)
{
  if ( a2 == 1 )
    return BiGetCurrentBootEntryIdentifier(a3);
  if ( a2 == 2 )
    return BiGetDefaultBootEntryIdentifier(a1, a3);
  return -1073741811;
}
