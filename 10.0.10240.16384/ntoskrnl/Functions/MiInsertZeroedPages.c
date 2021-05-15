// MiInsertZeroedPages 
 
int __fastcall MiInsertZeroedPages(_DWORD *a1)
{
  int v2; // r9
  _DWORD *v3; // r5
  unsigned int v4; // r4
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned int *v8; // r2
  unsigned int v9; // r0

  v2 = KfRaiseIrql(2);
  do
  {
    v3 = a1;
    a1[2] = 0;
    a1 = (_DWORD *)*a1;
    v4 = (int)((unsigned __int64)(715827883i64 * ((int)v3 - MmPfnDatabase)) >> 32) >> 2;
    v5 = (unsigned __int8 *)v3 + 15;
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      return sub_533280();
    MiInsertPageInFreeOrZeroedList(v4 + (v4 >> 31), 1);
    __dmb(0xBu);
    v8 = v3 + 3;
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 & 0x7FFFFFFF, v8) );
  }
  while ( a1 );
  return KfLowerIrql(v2);
}
