// PspEvaluateAndNotifyEmptyJob 
 
int __fastcall PspEvaluateAndNotifyEmptyJob(int *a1, int a2, int a3)
{
  int v6; // r3
  unsigned int v7; // r5
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  int result; // r0
  __int16 v13; // r3

  v6 = __mrc(15, 0, 13, 0, 3);
  v7 = v6 & 0xFFFFFFC0;
  if ( (v6 & 0xFFFFFFC0) != 0 )
  {
    v6 = *(__int16 *)((v6 & 0xFFFFFFC0) + 0x136) - 1;
    *(_WORD *)(v7 + 310) = v6;
  }
  ExAcquireResourceExclusiveLite((int)(a1 + 8), 1, a3, v6);
  if ( a2 )
    --a1[170];
  if ( !a1[170] )
  {
    __dmb(0xBu);
    v8 = (unsigned __int8 *)(a1 + 186);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 & 0x7F, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      KeSetEvent((int)a1, 0, 0);
    __dmb(0xBu);
    v10 = (unsigned __int8 *)a1 + 746;
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x20, v10) );
    __dmb(0xBu);
    if ( !((unsigned __int8)(v11 & 0x20) >> 5) && a3 && a1[53] && (a1[107] & 0x10) != 0 )
      PspSendReliableJobNotification(a1, 4);
  }
  result = ExReleaseResourceLite((int)(a1 + 8));
  if ( v7 )
  {
    v13 = *(_WORD *)(v7 + 310) + 1;
    *(_WORD *)(v7 + 310) = v13;
    if ( !v13 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
