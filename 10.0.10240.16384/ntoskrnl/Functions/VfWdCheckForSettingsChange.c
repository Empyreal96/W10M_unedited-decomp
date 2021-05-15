// VfWdCheckForSettingsChange 
 
void __fastcall __spoils<R2,R3,R12> VfWdCheckForSettingsChange(char a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r2
  int v4; // r3

  if ( !VfSafeMode )
  {
    __dmb(0xBu);
    do
      v2 = __ldrex((unsigned int *)&ViWdCancelling);
    while ( __strex(1u, (unsigned int *)&ViWdCancelling) );
    __dmb(0xBu);
    KeCancelTimer((int)&ViWdIrpTimer);
    KeRemoveQueueDpcEx((int)&ViWdIrpTimerDpc, 1);
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&ViWdCancelling);
    while ( __strex(0, (unsigned int *)&ViWdCancelling) );
    __dmb(0xBu);
    if ( (a1 & 0x10) != 0 )
    {
      v4 = VfWdCancelTimeoutTicks;
      __dmb(0xBu);
      if ( v4 )
        KiSetTimerEx((int)&ViWdIrpTimer, 0, -10000000i64, 0, 0, (int)&ViWdIrpTimerDpc);
    }
  }
}
