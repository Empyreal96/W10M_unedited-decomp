// PopBatteryWakeDpc 
 
int PopBatteryWakeDpc()
{
  unsigned int v0; // r1

  byte_61EE28 = 0;
  KeSetEvent((int)&byte_61EE18, 0, 0);
  __dmb(0xBu);
  do
    v0 = __ldrex(dword_61EDC0);
  while ( __strex(0, dword_61EDC0) );
  __dmb(0xBu);
  return PopBatteryQueueWork(1);
}
