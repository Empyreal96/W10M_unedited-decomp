// SmpFpReleaseResource 
 
int __fastcall SmpFpReleaseResource(int a1, int a2, int a3)
{
  int v6; // r9
  _DWORD *i; // r2
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // r5
  int vars4; // [sp+1Ch] [bp+4h]

  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)a1);
  }
  else
  {
    v8 = (unsigned __int8 *)(a1 + 3);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
    while ( 1 )
    {
      v10 = *(_DWORD *)a1;
      if ( (*(_DWORD *)a1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v10 & 0x40000000) == 0 )
      {
        do
          v11 = __ldrex((unsigned int *)a1);
        while ( v11 == v10 && __strex(v10 | 0x40000000, (unsigned int *)a1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  for ( i = *(_DWORD **)(a1 + 4 * a2 + 20); ; i = (_DWORD *)*i )
  {
    if ( !i )
    {
      v12 = 0;
      goto LABEL_18;
    }
    if ( (i[1] & 0xFFFFFFF8) == a3 )
      break;
  }
  i[1] &= 0xFFFFFFFE;
  --*(_BYTE *)(a1 + a2 + 40);
  --*(_BYTE *)(a1 + 45);
  v12 = 1;
LABEL_18:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)a1, vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(v6);
  return v12;
}
