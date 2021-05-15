// VfThunkAddDriverThunks 
 
int VfThunkAddDriverThunks()
{
  int *v0; // r4
  int **v2; // r1

  v0 = (int *)ViThunkCreateThunkTable();
  if ( !v0 )
    return -1073741670;
  VfDriverLock();
  VfThunksExtended = 1;
  __dmb(0xFu);
  ++ViActiveVerifierThunks;
  v2 = (int **)dword_61CEB4;
  *v0 = (int)&ViVerifierDriverAddedThunkListHead;
  v0[1] = (int)v2;
  if ( *v2 != &ViVerifierDriverAddedThunkListHead )
    __fastfail(3u);
  *v2 = v0;
  dword_61CEB4 = (int)v0;
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  return 0;
}
