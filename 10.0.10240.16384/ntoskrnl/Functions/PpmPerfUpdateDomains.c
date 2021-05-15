// PpmPerfUpdateDomains 
 
int PpmPerfUpdateDomains()
{
  unsigned int v0; // r1
  int v1; // r0
  unsigned int v2; // r2
  int v3; // r3
  int v4; // r3

  v0 = dword_6174B8;
  v1 = dword_61749C;
  while ( v0 )
  {
    v2 = __clz(__rbit(v0));
    v0 &= ~(1 << v2);
    if ( v2 >= KeNumberProcessors_0 )
      v3 = 0;
    else
      v3 = (int)*(&KiProcessorBlock + v2);
    v4 = *(_DWORD *)(v3 + 3200);
    if ( v4 )
    {
      v1 |= 1 << *(_DWORD *)(*(_DWORD *)(v4 + 8) + 20);
      dword_61749C = v1;
    }
  }
  return PpmCheckApplyPerfConstraints(0);
}
