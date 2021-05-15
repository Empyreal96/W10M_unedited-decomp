// MiLockSetPfnPriority 
 
int __fastcall MiLockSetPfnPriority(int a1, char a2)
{
  unsigned __int8 *v2; // r4
  unsigned int v3; // r2
  int result; // r0
  unsigned int *v5; // r2

  v2 = (unsigned __int8 *)(a1 + 15);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  __dmb(0xBu);
  if ( v3 >> 7 )
    return sub_53ADF8();
  *(_BYTE *)(a1 + 19) ^= (*(_BYTE *)(a1 + 19) ^ a2) & 7;
  __dmb(0xBu);
  v5 = (unsigned int *)(a1 + 12);
  do
    result = __ldrex(v5);
  while ( __strex(result & 0x7FFFFFFF, v5) );
  return result;
}
