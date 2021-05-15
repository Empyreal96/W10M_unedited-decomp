// PpmPerfApplyProcessorStates 
 
int PpmPerfApplyProcessorStates()
{
  unsigned int v0; // r5
  unsigned int v1; // r4
  unsigned int v2; // r2
  int v3; // r0
  unsigned __int8 v4; // r1
  unsigned int v5; // r2
  int v6; // r0
  char v8; // [sp+0h] [bp-30h]
  int v9; // [sp+10h] [bp-20h]

  v9 = dword_616308;
  v0 = dword_616308;
  PpmPerfProcessorsToUpdate = 1;
  word_616302 = 1;
  *(_DWORD *)algn_616304 = 0;
  dword_616308 = 0;
  v1 = v9;
  while ( v1 )
  {
    v2 = __clz(__rbit(v1));
    v1 &= ~(1 << v2);
    v8 = v2;
    if ( v2 >= KeNumberProcessors_0 )
      v3 = 0;
    else
      v3 = (int)*(&KiProcessorBlock + v2);
    if ( PpmPerfApplyProcessorState(v3, 0) )
      v0 &= ~(1 << v8);
  }
  v4 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)(~v0 >> 16))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v0 >> 8))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v0)
     + *((_BYTE *)RtlpBitsClearTotal + (~v0 >> 24));
  PpmCheckCount = v4;
  if ( !v4 )
    return 1;
  while ( v0 )
  {
    v5 = __clz(__rbit(v0));
    v0 &= ~(1 << v5);
    if ( v5 >= KeNumberProcessors_0 )
      v6 = 0;
    else
      v6 = (int)*(&KiProcessorBlock + v5);
    PpmPerfQueueAction(v6, 2);
  }
  return 0;
}
