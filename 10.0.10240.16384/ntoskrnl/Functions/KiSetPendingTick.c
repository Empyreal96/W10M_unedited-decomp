// KiSetPendingTick 
 
int __fastcall KiSetPendingTick(int result)
{
  unsigned int v1; // r1

  if ( !KiClockTimerPerCpu )
    return sub_50F420();
  v1 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  *(_BYTE *)(v1 + 1426) ^= (*(_BYTE *)(v1 + 1426) ^ result) & 1;
  return result;
}
