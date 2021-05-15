// MiPreInitializeSystemImagePage 
 
int __fastcall MiPreInitializeSystemImagePage(int a1)
{
  int v2; // r5
  unsigned __int8 *v3; // r1
  unsigned int v4; // r2
  unsigned int *v6; // r2
  unsigned int v7; // r0

  v2 = KfRaiseIrql(2);
  v3 = (unsigned __int8 *)(a1 + 15);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    return sub_519130();
  *(_DWORD *)(a1 + 12) &= 0xC0000000;
  *(_WORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) &= 0xF7FFFFFF;
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0xC0 | 5;
  *(_BYTE *)(a1 + 19) &= 0xDFu;
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 12);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 & 0x7FFFFFFF, v6) );
  return KfLowerIrql(v2);
}
