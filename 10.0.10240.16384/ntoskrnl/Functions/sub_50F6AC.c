// sub_50F6AC 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_50F6AC(int a1)
{
  unsigned int v1; // r2
  int v2; // r3
  unsigned int v3; // r2
  unsigned int v4; // r1
  int v5; // r3

  if ( a1 != 3 )
    goto LABEL_14;
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  if ( !CmpNoWrite )
  {
    if ( CmpWorkerDataInitialized )
    {
      v2 = CmpForceFlushPending;
      __dmb(0xBu);
      if ( !v2 )
      {
        __dmb(0xBu);
        a1 = 1;
        do
          v3 = __ldrex((unsigned int *)&CmpForceFlushPending);
        while ( !v3 && __strex(1u, (unsigned int *)&CmpForceFlushPending) );
        __dmb(0xBu);
        if ( !v3 )
          a1 = ExQueueWorkItem(&CmpForceFlushWorkItem, 1);
      }
    }
  }
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (__int16)(*(_WORD *)(v4 + 0x134) + 1);
  *(_WORD *)(v4 + 308) = v5;
  if ( v5 || *(_DWORD *)(v4 + 100) == v4 + 100 || *(_WORD *)(v4 + 310) )
LABEL_14:
    JUMPOUT(0x42540E);
  return KiCheckForKernelApcDelivery(a1);
}
