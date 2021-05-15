// PpmPerfMinimumPerfReached 
 
int PpmPerfMinimumPerfReached()
{
  int result; // r0
  unsigned int v1; // r4
  unsigned int v2; // r2
  int v3; // r2

  result = 1;
  v1 = dword_6174A8;
  while ( v1 )
  {
    v2 = __clz(__rbit(v1));
    v1 &= ~(1 << v2);
    if ( v2 >= KeNumberProcessors_0 )
      v3 = 0;
    else
      v3 = (int)*(&KiProcessorBlock + v2);
    if ( *(_DWORD *)(*(_DWORD *)(v3 + 3204) + 40) > *(_DWORD *)(*(_DWORD *)(v3 + 3200) + 144) )
      result = 0;
  }
  return result;
}
