// MiSetPfnOwnedAndActive 
 
int __fastcall MiSetPfnOwnedAndActive(int a1, int a2, int a3, int a4)
{
  int v8; // r10
  unsigned __int8 *v9; // lr
  unsigned int v10; // r5
  char v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r0

  v8 = KfRaiseIrql(2);
  v9 = (unsigned __int8 *)(a1 + 15);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  __dmb(0xBu);
  if ( v10 >> 7 )
    return sub_513ADC();
  if ( (*(_DWORD *)(a1 + 20) & 0xFFFFF) == 1048574 )
    *(_DWORD *)(a1 + 20) &= 0xFFF00000;
  if ( *(unsigned __int8 *)(a1 + 18) >> 6 != a3 )
    MiChangePageAttribute(a1, a3, 1);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(a1 + 12) & 0xC0000000 | 1;
  if ( a4 )
    *(_WORD *)(a1 + 16) = a4;
  v12 = *(_BYTE *)(a1 + 18);
  *(_DWORD *)(a1 + 4) = a2;
  *(_BYTE *)(a1 + 18) = v12 & 0xF8 | 6;
  __dmb(0xBu);
  v13 = (unsigned int *)(a1 + 12);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 & 0x7FFFFFFF, v13) );
  return KfLowerIrql(v8);
}
