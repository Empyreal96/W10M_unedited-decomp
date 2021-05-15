// MiFreeOverlappedFlushEntry 
 
int __fastcall MiFreeOverlappedFlushEntry(int a1)
{
  int v2; // r7
  _DWORD *v3; // r8
  unsigned int *v4; // r5
  int v5; // r9
  int v6; // r0
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1

  v2 = *(_DWORD *)(a1 + 20);
  v3 = **(_DWORD ***)a1;
  v4 = v3 + 9;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
  }
  else
  {
    v8 = (unsigned __int8 *)v3 + 39;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4);
    while ( 1 )
    {
      v10 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v11 = __ldrex(v4);
        while ( v11 == v10 && __strex(v10 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MiDecrementSubsections(*(_DWORD *)a1, *(_DWORD *)a1);
  MiDecrementSubsections(*(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 4));
  --v3[5];
  MiCheckControlArea(v3, v5);
  v6 = *(_DWORD *)(a1 + 24);
  if ( v6 )
    ExFreePoolWithTag(v6);
  **(_DWORD **)(a1 + 16) = *(_DWORD *)(a1 + 12);
  if ( *(int *)(a1 + 12) < 0 )
    *(_DWORD *)(*(_DWORD *)(a1 + 16) + 4) = 0;
  ExFreePoolWithTag(a1);
  return KeSetEvent(v2, 0, 0);
}
