// PopUserPresentSet 
 
int *__fastcall PopUserPresentSet(int a1)
{
  unsigned int v2; // r4
  unsigned int v3; // r1
  int *result; // r0
  unsigned int v5; // r1

  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&PopUserPresentSetStatus);
  while ( __strex(1u, (unsigned int *)&PopUserPresentSetStatus) );
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&algn_61EC13[1]);
  while ( !v3 && __strex(0, (unsigned int *)&algn_61EC13[1]) );
  __dmb(0xBu);
  if ( v3 )
    return (int *)sub_5296D8(0, v3, &algn_61EC13[1]);
  PopResetIdleTime(2, 0, &algn_61EC13[1]);
  result = &PopFullWake;
  if ( (PopFullWake & 3) == 0 )
  {
    __dmb(0xBu);
    do
      v5 = __ldrex((unsigned int *)&PopFullWake);
    while ( __strex(v5 | 2, (unsigned int *)&PopFullWake) );
    __dmb(0xBu);
    result = (int *)PopSetNotificationWork(1);
  }
  if ( !v2 )
  {
    *(_DWORD *)&algn_61E6A4[4] = PopUserPresentSetWorker;
    *(_DWORD *)&algn_61E6A4[8] = a1;
    PopUserPresentWorkItem = 0;
    result = (int *)ExQueueWorkItem(&PopUserPresentWorkItem, 1);
  }
  return result;
}
