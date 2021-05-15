// sub_52CCF0 
 
void sub_52CCF0()
{
  int v0; // r6
  int v1; // r0
  _DWORD *v2; // r5
  int v3; // r4

  if ( (unsigned int)CcNumberOfFreeHighPriorityVacbs < 5 )
  {
    v1 = CcAllocateInitializeVacbArray();
    v2 = (_DWORD *)v1;
    if ( v1 )
    {
      if ( v0 == 1 )
        CcBuildUpHighPriorityMappings(v1);
      v3 = KeAcquireQueuedSpinLock(4);
      CcInsertVacbArray(v2);
      KeReleaseQueuedSpinLock(4, v3);
    }
  }
  JUMPOUT(0x476322);
}
