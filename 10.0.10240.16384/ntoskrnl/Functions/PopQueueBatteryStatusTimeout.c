// PopQueueBatteryStatusTimeout 
 
int PopQueueBatteryStatusTimeout()
{
  unsigned int v0; // r1

  KeResetEvent((int)&byte_61EE18);
  __dmb(0xBu);
  do
    v0 = __ldrex(dword_61EDC0);
  while ( __strex(1u, dword_61EDC0) );
  __dmb(0xBu);
  return KiSetTimerEx((int)&dword_61EDC0[2], 0, -300000000i64, 0, 0, (int)&byte_61EDF8);
}
