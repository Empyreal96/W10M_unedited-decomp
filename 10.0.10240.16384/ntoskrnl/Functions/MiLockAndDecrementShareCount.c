// MiLockAndDecrementShareCount 
 
int __fastcall MiLockAndDecrementShareCount(int a1, char a2)
{
  int v4; // r6
  unsigned __int8 *v5; // r1
  unsigned int v6; // r2
  int v8; // r5
  unsigned int *v9; // r2
  unsigned int v10; // r0

  v4 = KfRaiseIrql(2);
  v5 = (unsigned __int8 *)(a1 + 15);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    return sub_50DE6C();
  if ( (a2 & 1) != 0 )
    *(_DWORD *)(a1 + 12) |= 0x40000000u;
  if ( (*(_BYTE *)(a1 + 18) & 7) != 6 )
    KeBugCheckEx(78, 153, (a1 - MmPfnDatabase) / 24);
  if ( MiUpdateShareCount(a1, -1) )
    v8 = 2;
  else
    v8 = MiPfnShareCountIsZero(a1, 0);
  __dmb(0xBu);
  v9 = (unsigned int *)(a1 + 12);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 & 0x7FFFFFFF, v9) );
  KfLowerIrql(v4);
  return v8;
}
