// MiReleaseFreshPage 
 
int __fastcall MiReleaseFreshPage(int a1)
{
  unsigned int v2; // r5
  int v3; // r6
  unsigned __int8 *v4; // r1
  unsigned int v5; // r2
  char v7; // r1
  unsigned int *v8; // r2
  unsigned int v9; // r0

  v2 = (int)((unsigned __int64)(715827883i64 * (a1 - MmPfnDatabase)) >> 32) >> 2;
  v3 = KfRaiseIrql(2);
  v4 = (unsigned __int8 *)(a1 + 15);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_50B8D4();
  *(_DWORD *)(a1 + 20) &= 0xF7FFFFFF;
  *(_BYTE *)(a1 + 18) &= 0xC7u;
  *(_BYTE *)(a1 + 19) &= 0xCFu;
  *(_DWORD *)(a1 + 12) &= 0xC0000000;
  *(_WORD *)(a1 + 16) = 0;
  if ( (*(_DWORD *)(a1 + 8) & 0x3E0) != 0 )
    v7 = 2;
  else
    v7 = 1;
  MiInsertPageInFreeOrZeroedList(v2 + (v2 >> 31), v7);
  __dmb(0xBu);
  v8 = (unsigned int *)(a1 + 12);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 & 0x7FFFFFFF, v8) );
  return KfLowerIrql(v3);
}
