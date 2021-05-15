// MiLockNonPagedPoolPte 
 
int __fastcall MiLockNonPagedPoolPte(int *a1, _BYTE *a2)
{
  int v4; // r10
  int v5; // r7
  int v6; // r0
  int v7; // lr
  unsigned __int8 *v8; // r3
  unsigned int v9; // r4
  int v11; // r3
  unsigned int *v12; // r2
  unsigned int v13; // r0

  while ( 1 )
  {
    v4 = *a1;
    v5 = MmPfnDatabase + 24 * ((unsigned int)*a1 >> 12);
    v6 = KfRaiseIrql(2);
    v7 = v6;
    v8 = (unsigned __int8 *)(v5 + 15);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      return sub_54BE70();
    v11 = *a1;
    *a2 = v6;
    if ( v4 == v11 )
      break;
    __dmb(0xBu);
    v12 = (unsigned int *)(v5 + 12);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 & 0x7FFFFFFF, v12) );
    KfLowerIrql(v7);
  }
  return v5;
}
