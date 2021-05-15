// SdbpFindLocalDatabaseByPDB 
 
int __fastcall SdbpFindLocalDatabaseByPDB(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r6
  int v5; // r5
  int v6; // r4
  int i; // r0

  v4 = *(_DWORD *)(a1 + 16);
  v5 = 0;
  v6 = 0;
  for ( i = a1 + 20; ((1 << v6) & v4) == 0 || (*(_DWORD *)(i + 20) & 2) == 0 || a2 != *(_DWORD *)(i + 16); i += 24 )
  {
    if ( (unsigned int)++v6 >= 0x10 )
      return v5;
  }
  v5 = 1;
  if ( a4 )
    *a4 = v6;
  return v5;
}
