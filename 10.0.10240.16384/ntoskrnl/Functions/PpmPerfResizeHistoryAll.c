// PpmPerfResizeHistoryAll 
 
void PpmPerfResizeHistoryAll()
{
  unsigned int v0; // r4
  unsigned int v1; // r2
  int v2; // r0

  v0 = dword_6174B8;
  while ( v0 )
  {
    v1 = __clz(__rbit(v0));
    v0 &= ~(1 << v1);
    if ( v1 >= KeNumberProcessors_0 )
      v2 = 0;
    else
      v2 = (int)*(&KiProcessorBlock + v1);
    PpmPerfResizeHistory(v2);
  }
}
