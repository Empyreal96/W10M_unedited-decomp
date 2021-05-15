// PpmPerfForceDomainStates 
 
int PpmPerfForceDomainStates()
{
  unsigned int v0; // r2
  unsigned int v1; // r1
  unsigned int v2; // r1
  int v3; // r3
  unsigned int v4; // r4
  int v5; // r3
  int v6; // r3

  v0 = 0;
  v1 = dword_61749C;
  while ( v1 )
  {
    v4 = __clz(__rbit(v1));
    v1 &= ~(1 << v4);
    if ( v4 >= KeNumberProcessors_0 )
      v5 = 0;
    else
      v5 = (int)*(&KiProcessorBlock + v4);
    v6 = *(_DWORD *)(v5 + 3200);
    *(_BYTE *)(v6 + 180) = 1;
    v0 |= *(_DWORD *)(v6 + 20);
  }
  while ( v0 )
  {
    v2 = __clz(__rbit(v0));
    v0 &= ~(1 << v2);
    if ( v2 >= KeNumberProcessors_0 )
      v3 = 0;
    else
      v3 = (int)*(&KiProcessorBlock + v2);
    *(_BYTE *)(*(_DWORD *)(v3 + 3204) + 72) = 1;
  }
  return 1;
}
