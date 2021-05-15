// MiProbeAndLockComplete 
 
int __fastcall MiProbeAndLockComplete(int a1, int a2)
{
  int v4; // r0

  v4 = MiUnlockProbePacketWorkingSet();
  if ( (MmTrackLockedPages & 1) != 0 )
    return sub_51AE10(v4);
  if ( a2 < 0 )
  {
    MmUnlockPages(*(_DWORD *)(a1 + 24));
    ++dword_6343E8;
  }
  return a2;
}
