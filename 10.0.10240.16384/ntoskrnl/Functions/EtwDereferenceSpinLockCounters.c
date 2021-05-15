// EtwDereferenceSpinLockCounters 
 
int EtwDereferenceSpinLockCounters()
{
  KeWaitForSingleObject((unsigned int)&EtwpCrimsonMaskMutex, 0, 0, 0, 0);
  if ( !--EtwpSpinLockCountersCount )
  {
    dword_61AD44 &= 0xFFDFFFFF;
    EtwpUpdateKernelGroupMasks(0, 8);
  }
  return KeReleaseMutex((int)&EtwpCrimsonMaskMutex);
}
