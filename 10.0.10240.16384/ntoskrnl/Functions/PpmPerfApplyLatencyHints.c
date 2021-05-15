// PpmPerfApplyLatencyHints 
 
int PpmPerfApplyLatencyHints()
{
  unsigned int v1; // r4
  unsigned int v2; // r2
  int v3; // r0

  if ( PpmCheckLatencyBoostActive )
  {
    v1 = dword_6174A8;
    while ( v1 )
    {
      v2 = __clz(__rbit(v1));
      v1 &= ~(1 << v2);
      if ( v2 >= KeNumberProcessors_0 )
        v3 = 0;
      else
        v3 = (int)*(&KiProcessorBlock + v2);
      PpmPerfApplyLatencyHint(v3);
    }
  }
  return 1;
}
