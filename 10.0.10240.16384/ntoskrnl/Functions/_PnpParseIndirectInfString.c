// _PnpParseIndirectInfString 
 
int __fastcall PnpParseIndirectInfString(unsigned __int16 *a1, int a2, int a3, unsigned int a4)
{
  int v5; // r2
  unsigned __int16 *v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r1
  unsigned __int16 *v10; // r2
  int v11; // r3
  unsigned __int16 *v13; // r2
  unsigned int v14; // [sp+0h] [bp-8h] BYREF

  v14 = a4;
  if ( RtlUnalignedStringCchLengthW(a1, 0x7FFF, &v14) < 0 || v14 < 5 || *a1 != 64 )
    return 0;
  v5 = 1;
  if ( a1[1] )
  {
    v6 = a1 + 1;
    do
    {
      if ( *v6 == 44 )
        break;
      v6 = &a1[++v5];
    }
    while ( *v6 );
  }
  if ( a1[v5] != 44 )
    return 0;
  v7 = v5 + 1;
  if ( a1[v7] != 37 )
    return 0;
  do
    ++v7;
  while ( a1[v7] && a1[v7] != 59 );
  if ( a1[v7] != 59 )
    v7 = 0;
  v8 = v7 ? v7 - 1 : v14 - 1;
  if ( a1[v8] != 37 )
    return 0;
  if ( !v7 )
    return 1;
  v9 = v7 + 1;
  v10 = &a1[v7 + 1];
  v11 = *v10;
  if ( !*v10 )
    return 1;
  while ( v11 != 59 )
  {
    v13 = &a1[++v9];
    v11 = *v13;
    if ( !*v13 )
      return 1;
  }
  return sub_7C7164(&a1[v14]);
}
