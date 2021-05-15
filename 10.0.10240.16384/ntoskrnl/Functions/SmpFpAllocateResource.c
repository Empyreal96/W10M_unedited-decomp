// SmpFpAllocateResource 
 
int __fastcall SmpFpAllocateResource(int a1, int a2)
{
  int v4; // r7
  _DWORD *i; // r2
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  int v11; // r5
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)a1);
  }
  else
  {
    v6 = (unsigned __int8 *)(a1 + 3);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
    while ( 1 )
    {
      v8 = *(_DWORD *)a1;
      if ( (*(_DWORD *)a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v8 & 0x40000000) == 0 )
      {
        do
          v9 = __ldrex((unsigned int *)a1);
        while ( v9 == v8 && __strex(v8 | 0x40000000, (unsigned int *)a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  for ( i = *(_DWORD **)(a1 + 4 * a2 + 20); ; i = (_DWORD *)*i )
  {
    v10 = i[1];
    if ( (v10 & 1) == 0 )
      break;
  }
  v11 = i[1];
  i[1] = v10 | 1;
  ++*(_BYTE *)(a1 + a2 + 40);
  ++*(_BYTE *)(a1 + 45);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)a1, vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(v4);
  return v11;
}
