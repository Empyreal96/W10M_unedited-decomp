// VfKeIrqlTransitionReserveLogEntry 
 
int __fastcall VfKeIrqlTransitionReserveLogEntry(char a1, char a2)
{
  int v2; // r5
  int v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r1
  unsigned int v7; // r1
  int v8; // r3

  v2 = 0;
  if ( ViTrackIrqlQueue )
  {
    v4 = ViKeTrackIrqlDisabled;
    __dmb(0xBu);
    if ( v4 )
    {
      do
        v5 = __ldrex(&ViKeTrackIrqlSkipped);
      while ( __strex(v5 + 1, &ViKeTrackIrqlSkipped) );
    }
    else
    {
      __dmb(0xBu);
      do
      {
        v6 = __ldrex(&ViTrackIrqlIndex);
        v7 = v6 + 1;
      }
      while ( __strex(v7, &ViTrackIrqlIndex) );
      __dmb(0xBu);
      v8 = ViTrackIrqlQueueLength;
      __dmb(0xBu);
      v2 = ViTrackIrqlQueue + 32 * ((v8 - 1) & v7);
      *(_BYTE *)(v2 + 4) = a1;
      *(_BYTE *)(v2 + 5) = a2;
      *(_WORD *)(v2 + 6) = KeGetCurrentProcessorNumberEx(0);
    }
  }
  return v2;
}
