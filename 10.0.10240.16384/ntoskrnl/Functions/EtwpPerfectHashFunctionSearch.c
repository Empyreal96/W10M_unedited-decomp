// EtwpPerfectHashFunctionSearch 
 
int __fastcall EtwpPerfectHashFunctionSearch(int a1, int a2)
{
  int v2; // r3
  int v3; // r2

  v2 = *(unsigned __int16 *)(a2 + 2) & __ROR4__((unsigned __int16)a1, *(_BYTE *)(a2 + 1));
  do
  {
    v3 = a2 + 4 * v2;
    if ( a1 == *(unsigned __int16 *)(v3 + 8) )
      return 1;
    v2 = *(unsigned __int8 *)(v3 + 6);
  }
  while ( v2 != 255 );
  return 0;
}
