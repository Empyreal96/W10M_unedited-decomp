// IopErrorLogQueueRequest 
 
int IopErrorLogQueueRequest()
{
  int result; // r0
  int v1; // r3
  int v2; // r4

  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v1 = 40;
    else
      v1 = 32;
    result = ExAllocatePoolWithTagPriority(512, 0x50u, 538996553, v1);
  }
  else
  {
    result = ExAllocatePoolWithTag(512, 80, 538996553);
  }
  v2 = result;
  if ( result )
  {
    KeInitializeDpc(result, (int)IopErrorLogDpc, 0);
    KeInitializeTimerEx((_DWORD *)(v2 + 32), 0);
    result = KeSetCoalescableTimer((unsigned int)(v2 + 32), -300000000i64, 0, 0x7D0u, v2);
  }
  else
  {
    IopErrorLogSessionPending = 0;
  }
  return result;
}
