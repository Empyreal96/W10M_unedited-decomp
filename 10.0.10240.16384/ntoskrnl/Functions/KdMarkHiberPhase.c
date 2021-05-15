// KdMarkHiberPhase 
 
char *KdMarkHiberPhase()
{
  char *result; // r0
  unsigned int v1; // r4
  unsigned int v2; // r3
  int *v3; // r5
  const void *v4; // r2
  const void *v5; // t1

  result = PoSetHiberRange(0, 0x10000, &KdPitchDebugger, 0, 1651270731);
  if ( !KdPitchDebugger )
  {
    result = (char *)KdSetHiberRange_0();
    v1 = 0;
    v2 = KeNumberProcessors_0;
    if ( KeNumberProcessors_0 )
    {
      v3 = KdLogBuffer;
      do
      {
        v5 = (const void *)*v3++;
        v4 = v5;
        if ( v5 )
        {
          result = PoSetHiberRange(0, 0x10000, v4, (const void *)0x1000, 1651270731);
          v2 = KeNumberProcessors_0;
        }
        ++v1;
      }
      while ( v1 < v2 );
    }
  }
  return result;
}
