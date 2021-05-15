// WmipEventNotification 
 
unsigned int WmipEventNotification()
{
  _DWORD *v0; // r5
  _DWORD *v1; // r0
  int v2; // r3
  int v3; // r0
  unsigned int result; // r0
  unsigned int v5; // r2
  unsigned int v6; // r2

  do
  {
    v0 = ExInterlockedRemoveHeadList(&WmipNPEvent, (unsigned int *)&WmipNPNotificationSpinlock);
    v1 = (_DWORD *)v0[3];
    v2 = v1[10];
    v1[10] = 0;
    v1[2] = v2;
    v1[3] = 0;
    WmipProcessEvent();
    v3 = v0[2];
    if ( v3 )
      WmipUnreferenceRegEntry(v3);
    result = ExFreePoolWithTag((unsigned int)v0);
    __dmb(0xBu);
    do
    {
      v5 = __ldrex((unsigned int *)&WmipEventWorkItems);
      v6 = v5 - 1;
    }
    while ( __strex(v6, (unsigned int *)&WmipEventWorkItems) );
    __dmb(0xBu);
  }
  while ( v6 );
  return result;
}
