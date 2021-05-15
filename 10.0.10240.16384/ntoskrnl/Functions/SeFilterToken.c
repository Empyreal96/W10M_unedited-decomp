// SeFilterToken 
 
int __fastcall SeFilterToken(_DWORD *a1, char a2, int *a3, int *a4, unsigned int *a5, _DWORD *a6)
{
  int *v7; // r5
  unsigned int v8; // r4
  int v9; // r6
  int v10; // r7
  int v11; // lr
  int v12; // r8
  unsigned int v13; // r1
  unsigned int *v14; // r2
  int v15; // r4
  int v17; // [sp+0h] [bp-40h]
  int v18; // [sp+4h] [bp-3Ch]

  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  *a6 = 0;
  v11 = 0;
  v12 = 0;
  if ( a3 )
  {
    v11 = *a3;
    v12 = (int)(a3 + 1);
  }
  if ( a4 )
  {
    v9 = *a4;
    v10 = (int)(a4 + 1);
  }
  if ( a5 && (v8 = *a5, v7 = (int *)(a5 + 1), v13 = 0, *a5) )
  {
    v14 = a5 + 1;
    while ( !v14[1] )
    {
      ++v13;
      v14 += 2;
      if ( v13 >= v8 )
        goto LABEL_10;
    }
    v15 = -1073741811;
  }
  else
  {
LABEL_10:
    v15 = SepFilterToken(a1, 0, a2, v11, v12, v9, v10, v8, v7, 0);
    if ( v15 >= 0 )
    {
      v15 = ObInsertObject(0, 0, 0, 0, 0, 0);
      if ( v15 >= 0 )
      {
        SepAppendAceToTokenObjectAcl(0, 8, (unsigned __int16 *)SeAliasAdminsSid, (int)&SeAliasAdminsSid, v17, v18);
        *a6 = 0;
      }
    }
  }
  return v15;
}
