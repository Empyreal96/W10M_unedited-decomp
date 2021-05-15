// MiInsertLargePageInFreeOrZeroList 
 
int __fastcall MiInsertLargePageInFreeOrZeroList(unsigned int a1, int a2)
{
  unsigned int v2; // r5
  unsigned int v3; // r8
  int v4; // r6
  char v5; // r7
  int v6; // r9
  unsigned int *v7; // r4
  unsigned __int8 *v8; // r1
  unsigned int v9; // r2
  int v11; // r3
  unsigned int v12; // r1

  v2 = a1;
  v3 = a1 + 24576;
  v4 = (int)(a1 - MmPfnDatabase) / 24;
  if ( a2 )
    v5 = 2;
  else
    v5 = 1;
  v6 = KfRaiseIrql(2);
  if ( v2 >= v3 )
    return KfLowerIrql(v6);
  while ( 1 )
  {
    v7 = (unsigned int *)(v2 + 12);
    v8 = (unsigned __int8 *)(v2 + 15);
    do
      v9 = __ldrex(v8);
    while ( __strex(v9 | 0x80, v8) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      break;
    v11 = *(_DWORD *)(v2 + 12);
    *(_DWORD *)(v2 + 20) &= 0xFFF00000;
    *(_DWORD *)(v2 + 12) = v11 & 0xC0000000;
    MiInsertPageInFreeOrZeroedList(v4, v5 | 0x40);
    __dmb(0xBu);
    do
      v12 = __ldrex(v7);
    while ( __strex(v12 & 0x7FFFFFFF, v7) );
    v2 += 24;
    ++v4;
    if ( v2 >= v3 )
      return KfLowerIrql(v6);
  }
  return sub_550030();
}
