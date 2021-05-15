// ViDeadlockAddParticipant 
 
int __fastcall ViDeadlockAddParticipant(int result)
{
  int v1; // r1
  unsigned int v2; // r3

  v1 = ViDeadlockGlobals;
  v2 = *(_DWORD *)(ViDeadlockGlobals + 16472);
  if ( v2 < 0x20 )
  {
    *(_DWORD *)(ViDeadlockGlobals + 4 * v2 + 16476) = result;
    ++*(_DWORD *)(v1 + 16472);
  }
  else
  {
    ViDeadlockState |= 0x10u;
  }
  return result;
}
