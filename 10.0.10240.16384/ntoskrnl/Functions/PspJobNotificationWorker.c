// PspJobNotificationWorker 
 
int __fastcall PspJobNotificationWorker(int result)
{
  int v1; // r4
  int v2; // r6
  unsigned int *v3; // r2
  unsigned int v4; // r5
  unsigned int v5; // r2

  do
  {
    __dmb(0xBu);
    do
      v1 = __ldrex((unsigned int *)&PspJobNotificationList);
    while ( __strex(0xFFFFFFFF, (unsigned int *)&PspJobNotificationList) );
    __dmb(0xBu);
    do
    {
      v2 = *(_DWORD *)(v1 + 504);
      __dmb(0xBu);
      v3 = (unsigned int *)(v1 + 744);
      do
        v4 = __ldrex(v3);
      while ( __strex(v4 & 0xFFFDDFFF, v3) );
      __dmb(0xBu);
      if ( (v4 & 0x2000) != 0 )
        result = ZwUpdateWnfStateData();
      if ( (v4 & 0x20000) != 0 )
        return sub_7EB800(result);
      result = ObfDereferenceObject(v1);
      v1 = v2;
    }
    while ( v2 && v2 != -1 );
    __dmb(0xBu);
    do
      v5 = __ldrex((unsigned int *)&PspJobNotificationList);
    while ( v5 == -1 && __strex(0, (unsigned int *)&PspJobNotificationList) );
    __dmb(0xBu);
  }
  while ( v5 != -1 );
  return result;
}
