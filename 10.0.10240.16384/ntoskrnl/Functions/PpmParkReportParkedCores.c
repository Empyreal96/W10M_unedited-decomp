// PpmParkReportParkedCores 
 
int PpmParkReportParkedCores()
{
  int v0; // r5
  unsigned int v2; // r2
  int v3; // r0

  if ( !PpmIsParkingEnabled )
    return 1;
  v0 = dword_616330 & dword_61633C;
  if ( (dword_616330 & dword_61633C) == 0 )
    return 1;
  PpmCheckCount = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v0 >> 16))
                                  + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v0 >> 8))
                                  + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v0)
                                  + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v0 >> 24)));
  while ( v0 )
  {
    v2 = __clz(__rbit(v0));
    v0 &= ~(1 << v2);
    if ( v2 >= KeNumberProcessors_0 )
      v3 = 0;
    else
      v3 = (int)*(&KiProcessorBlock + v2);
    PpmPerfQueueAction(v3, 3);
  }
  return 0;
}
