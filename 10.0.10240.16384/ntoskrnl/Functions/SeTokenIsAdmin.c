// SeTokenIsAdmin 
 
int __fastcall SeTokenIsAdmin(_DWORD *a1)
{
  int v2; // r5
  int v3; // r6

  if ( (a1[44] & 0x4000) != 0 || a1[42] == 2 && (int)a1[43] < 2 )
    return 0;
  v3 = SeAliasAdminsSid;
  v2 = SepSidInToken((int)a1, 0, SeAliasAdminsSid, 0, 0);
  if ( v2 && SeTokenIsRestricted((int)a1) )
    v2 = SepSidInToken((int)a1, 0, v3, 0, 1);
  return v2;
}
