// KiSuspendClockTimer 
 
int KiSuspendClockTimer()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( (*(_BYTE *)(v0 + 1426) & 1) != 0 )
    return sub_51E908();
  if ( *(_DWORD *)(v0 + 1428) == KiClockTimerOwner )
  {
    KiClockActive = 0;
    ++dword_624FA8;
  }
  if ( *(_BYTE *)(v0 + 1425) )
    *(_BYTE *)(v0 + 1425) = 0;
  return result;
}
