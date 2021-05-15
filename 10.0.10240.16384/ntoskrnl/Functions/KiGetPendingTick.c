// KiGetPendingTick 
 
int KiGetPendingTick()
{
  int result; // r0

  if ( KiClockTimerPerCpu )
    result = *(_BYTE *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x592) & 1;
  else
    result = sub_553764();
  return result;
}
