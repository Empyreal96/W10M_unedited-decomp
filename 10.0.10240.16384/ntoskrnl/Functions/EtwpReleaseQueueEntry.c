// EtwpReleaseQueueEntry 
 
unsigned int __fastcall EtwpReleaseQueueEntry(int *a1, int a2)
{
  int v4; // r4
  unsigned int *v5; // r2
  unsigned int result; // r0
  int v7; // r0
  int v8; // r4

  if ( (a2 & 2) != 0 )
  {
    v7 = ObfDereferenceObject(a1[4]);
    v8 = a1[5];
    if ( v8 )
    {
      if ( (a1[5] & 7) == 5 )
        return sub_8084B4(v7, a1[3], 5, 1);
      PspChargeJobWakeCounter((_DWORD *)(a1[5] & 0xFFFFFFF8), 0, a1[5] & 7, -1, 0xFFFFFFFF, 0xFFFFFFFF, 1, 0, a1[3]);
      ObDereferenceObjectDeferDeleteWithTag(v8 & 0xFFFFFFF8);
    }
  }
  __dmb(0xBu);
  v4 = ~a2;
  v5 = (unsigned int *)(a1 + 7);
  do
    result = __ldrex(v5);
  while ( __strex(result & v4, v5) );
  __dmb(0xBu);
  if ( (v4 & result) == 0 )
    result = ExFreePoolWithTag((unsigned int)a1);
  return result;
}
