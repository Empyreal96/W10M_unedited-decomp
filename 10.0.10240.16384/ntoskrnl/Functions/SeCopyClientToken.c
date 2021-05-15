// SeCopyClientToken 
 
int __fastcall SeCopyClientToken(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v7; // r5
  int v8; // r4
  int v9; // r3
  unsigned __int16 *v11; // r2
  int v12; // [sp+0h] [bp-40h]
  int v13; // [sp+4h] [bp-3Ch]
  int v14; // [sp+10h] [bp-30h] BYREF
  int v15[10]; // [sp+18h] [bp-28h] BYREF

  v15[0] = 24;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  v15[4] = 0;
  v15[5] = 0;
  v7 = SepDuplicateToken(a1, v15, 0, 2, a2, 0, 0, &v14);
  if ( v7 < 0 )
    goto LABEL_12;
  v8 = v14;
  if ( a4 )
    v7 = SepSetTokenTrust(v14, a5);
  if ( v7 < 0 || (v7 = ObInsertObjectEx(v8, 0, 0, 0, 0, 0, 0), v7 < 0) )
  {
LABEL_12:
    *a6 = 0;
    return v7;
  }
  v9 = *(_DWORD *)(v8 + 176);
  if ( (v9 & 0x4000) == 0
    || (v11 = *(unsigned __int16 **)(v8 + 480)) == 0
    || (v7 = SepAppendAceToTokenObjectAcl(v8, 983551, v11, v9, v12, v13), v7 >= 0) )
  {
    SepAppendAceToTokenObjectAcl(v8, 8, (unsigned __int16 *)SeAliasAdminsSid, (int)&SeAliasAdminsSid, v12, v13);
    *a6 = v8;
    return v7;
  }
  return sub_7C535C();
}
