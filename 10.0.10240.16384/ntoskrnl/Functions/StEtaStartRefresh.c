// StEtaStartRefresh 
 
int __fastcall StEtaStartRefresh(int a1, int a2, unsigned int a3)
{
  unsigned int *v6; // r2
  unsigned int v7; // r0
  int i; // r2

  if ( *(int *)(a1 + 8) > 0 )
    return 0;
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 40);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 1, v6) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    return 0;
  for ( i = *(_DWORD *)(a1 + 4 * a2 + 16); *(_DWORD *)i < a3; i += 32 )
    ;
  *(_WORD *)(i + 4) = 112;
  *(_WORD *)(i + 6) = 0;
  return 1;
}
