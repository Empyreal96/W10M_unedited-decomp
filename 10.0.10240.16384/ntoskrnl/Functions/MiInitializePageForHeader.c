// MiInitializePageForHeader 
 
int __fastcall MiInitializePageForHeader(int a1, char a2)
{
  int v4; // r7
  unsigned __int8 *v5; // r5
  unsigned int v6; // r2
  unsigned int *v8; // r2
  unsigned int v9; // r0

  v4 = KfRaiseIrql(2);
  v5 = (unsigned __int8 *)(a1 + 15);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x80, v5) );
  __dmb(0xBu);
  if ( v6 >> 7 )
    return sub_53AAA4();
  *(_BYTE *)(a1 + 19) ^= (*(_BYTE *)(a1 + 19) ^ a2) & 7;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 12) |= 0x40000000u;
  __dmb(0xBu);
  v8 = (unsigned int *)(a1 + 12);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 & 0x7FFFFFFF, v8) );
  return KfLowerIrql(v4);
}
