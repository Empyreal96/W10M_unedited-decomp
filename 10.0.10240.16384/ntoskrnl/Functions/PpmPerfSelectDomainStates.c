// PpmPerfSelectDomainStates 
 
int PpmPerfSelectDomainStates()
{
  int *i; // r1
  unsigned int v1; // r2
  _DWORD *v2; // r3
  int v3; // r5
  int v4; // r4

  for ( i = (int *)PpmPerfDomainHead; i != &PpmPerfDomainHead; i = (int *)*i )
  {
    v1 = 1;
    v2 = *(_DWORD **)(i[2] + 3200);
    v3 = v2[6];
    if ( v3 )
    {
      v4 = v2[8];
      do
      {
        if ( *(_DWORD *)(v4 + 40) > v1 )
          v1 = *(_DWORD *)(v4 + 40);
        v4 += 80;
        --v3;
      }
      while ( v3 );
    }
    v2[32] = v1;
    if ( v1 != v2[30] )
      dword_61749C |= 1 << *(_DWORD *)(i[2] + 20);
  }
  return 1;
}
