// EtwReferenceSpinLockCounters 
 
int EtwReferenceSpinLockCounters()
{
  KeWaitForSingleObject((unsigned int)&EtwpCrimsonMaskMutex, 0, 0, 0, 0);
  if ( ++EtwpSpinLockCountersCount == 1 )
  {
    dword_61AD44 |= 0x200000u;
    EtwpUpdateKernelGroupMasks(0, 8);
  }
  return KeReleaseMutex((int)&EtwpCrimsonMaskMutex);
}
