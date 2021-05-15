// MiLockAndInsertPageInFreeList 
 
int __fastcall MiLockAndInsertPageInFreeList(int a1)
{
  unsigned int v2; // r5
  int v3; // r6
  unsigned __int8 *v4; // r1
  unsigned int v5; // r2
  unsigned int *v7; // r2
  unsigned int v8; // r0

  v2 = (int)((unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32) >> 2;
  v3 = KfRaiseIrql(2);
  v4 = (unsigned __int8 *)(a1 + 15);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_50EF40();
  MiInsertPageInFreeOrZeroedList(v2 + (v2 >> 31), 2);
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 12);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 & 0x7FFFFFFF, v7) );
  return KfLowerIrql(v3);
}
