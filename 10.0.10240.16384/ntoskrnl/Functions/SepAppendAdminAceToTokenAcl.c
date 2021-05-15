// SepAppendAdminAceToTokenAcl 
 
int __fastcall SepAppendAdminAceToTokenAcl(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return SepAppendAceToTokenObjectAcl(a1, 8, (unsigned __int16 *)SeAliasAdminsSid, (int)&SeAliasAdminsSid, a5, a6);
}
