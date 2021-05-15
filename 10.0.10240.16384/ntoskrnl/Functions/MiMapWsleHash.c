// MiMapWsleHash 
 
int __fastcall MiMapWsleHash(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int *v8; // r2
  unsigned int v9; // r1

  v2 = MiMapWsMetaPage();
  v3 = v2;
  if ( !v2 )
    return 0;
  *(_DWORD *)(a1 + 80) += v2;
  if ( (*(_BYTE *)(a1 + 112) & 7) == 1 )
  {
    v6 = (unsigned int *)(a1 - 3220);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 + 1, v6) );
    v8 = (unsigned int *)(a1 - 3216);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 + 1, v8) );
  }
  else
  {
    do
      v4 = __ldrex(&dword_634DA0);
    while ( __strex(v4 + v3, &dword_634DA0) );
  }
  return 1;
}
