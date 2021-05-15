// KeGetAffinitizedInterruptsInfo 
 
int __fastcall KeGetAffinitizedInterruptsInfo(_DWORD *a1)
{
  int v1; // r2
  int v2; // r3

  v1 = *(_DWORD *)algn_621814;
  v2 = dword_621818;
  *a1 = *(_DWORD *)&KiIntSteerAffinitizedInterrupts;
  a1[1] = v1;
  a1[2] = v2;
  a1[2] |= 1 << KiClockTimerOwner;
  return 0;
}
