// sub_540710 
 
void sub_540710()
{
  _DWORD *v0; // r4
  unsigned int v1; // r1
  unsigned int v2; // r2
  int v3; // r3
  _DWORD *v4; // r2

  if ( PpmParkMaximumCoresParked() && PpmPerfMinimumPerfReached() )
  {
    v1 = dword_6174B8;
    while ( v1 )
    {
      v2 = __clz(__rbit(v1));
      v1 &= ~(1 << v2);
      if ( v2 >= KeNumberProcessors_0 )
        v3 = 0;
      else
        v3 = (int)*(&KiProcessorBlock + v2);
      v4 = *(_DWORD **)(v3 + 3196);
      if ( v4 )
      {
        v4[2] = v4[6];
        v4[3] = v4[7];
        *v4 = v4[8];
        v4[1] = v4[9];
      }
    }
    PpmParkCompleteMakeup(&KeNumberProcessors_0);
    *v0 = 0;
  }
  else
  {
    PpmEventTraceMakeupPerfCheck();
    --*v0;
    PpmCheckPipelineIndex = 3;
  }
  JUMPOUT(0x4AD07A);
}
