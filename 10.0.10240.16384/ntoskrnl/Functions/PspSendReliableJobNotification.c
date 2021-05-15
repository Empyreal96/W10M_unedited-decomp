// PspSendReliableJobNotification 
 
int __fastcall PspSendReliableJobNotification(int *a1, int a2)
{
  int result; // r0
  unsigned int v5; // r2
  unsigned int *v6; // lr
  int v7; // r6
  unsigned int v8; // r7
  unsigned __int64 *v9; // r3
  unsigned __int64 v10; // kr00_8

  if ( a2 == 11 )
    return sub_7C0194();
  if ( a2 == 12 )
    result = 0x10000;
  else
    result = 0x8000;
  v5 = a1[186];
  v6 = (unsigned int *)(a1 + 186);
  while ( 1 )
  {
    v7 = v5 | 8;
    if ( (v5 & 8) != 0 )
      v7 |= result;
    __dmb(0xBu);
    do
      v8 = __ldrex(v6);
    while ( v8 == v5 && __strex(v7, v6) );
    __dmb(0xBu);
    if ( v8 == v5 )
      break;
    v5 = v8;
  }
  if ( (v5 & 8) == 0 )
  {
    ObfReferenceObjectWithTag((int)a1);
    if ( (PerfGlobalGroupMask & 0x80000) != 0 )
      EtwTraceJobSendNotification(a1, a2);
    result = IoSetIoCompletionEx(a1[53], a1[54], 0, 0);
    __dmb(0xBu);
    v9 = (unsigned __int64 *)(a1 + 56);
    do
      v10 = __ldrexd(v9);
    while ( __strexd(v10 + 1, v9) );
    __dmb(0xBu);
  }
  return result;
}
