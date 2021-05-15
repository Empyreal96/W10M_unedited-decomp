// MiPageHasRelocations 
 
int __fastcall MiPageHasRelocations(int a1, unsigned int a2)
{
  _DWORD *v2; // r3
  int v4; // r2
  _DWORD *v5; // r1

  v2 = **(_DWORD ***)(a1 + 56);
  if ( a2 >= v2[6] )
    return 0;
  v4 = 0;
  v5 = (_DWORD *)(*v2 + 4 * a2);
  while ( !*v5++ )
  {
    if ( ++v4 )
      return 0;
  }
  return 1;
}
