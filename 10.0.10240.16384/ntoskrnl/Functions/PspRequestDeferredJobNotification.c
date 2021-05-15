// PspRequestDeferredJobNotification 
 
int __fastcall PspRequestDeferredJobNotification(unsigned int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r5
  int v5; // r1
  int v6; // r5
  unsigned int v7; // r2

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 744);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | a2, v2) );
  __dmb(0xBu);
  if ( (v3 & 0x22000) != 0 )
    return 0;
  v5 = PspJobNotificationList;
  do
  {
    v6 = v5;
    *(_DWORD *)(a1 + 504) = v5;
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&PspJobNotificationList);
    while ( v7 == v5 && __strex(a1, (unsigned int *)&PspJobNotificationList) );
    v5 = v7;
    __dmb(0xBu);
  }
  while ( v7 != v6 );
  if ( !v6 )
    ExQueueWorkItem(&PspJobNotificationItem, 3);
  return 1;
}
