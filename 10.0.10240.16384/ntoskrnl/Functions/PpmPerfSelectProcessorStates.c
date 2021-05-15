// PpmPerfSelectProcessorStates 
 
int PpmPerfSelectProcessorStates()
{
  int *i; // r2
  int v1; // r3
  unsigned int v2; // r4
  unsigned int v3; // r2
  int v4; // r0

  for ( i = (int *)PpmPerfDomainHead; i != &PpmPerfDomainHead; i = (int *)*i )
  {
    v1 = i[44];
    if ( v1 != -1 )
      i[44] = v1 + 1;
  }
  v2 = dword_6174A8;
  while ( v2 )
  {
    v3 = __clz(__rbit(v2));
    v2 &= ~(1 << v3);
    if ( v3 >= KeNumberProcessors_0 )
      v4 = 0;
    else
      v4 = (int)*(&KiProcessorBlock + v3);
    PpmPerfSelectProcessorState(v4);
  }
  return 1;
}
