// MiUnlockNestedProtoPoolPage 
 
int __fastcall MiUnlockNestedProtoPoolPage(int a1)
{
  unsigned __int8 *v2; // r1
  unsigned int v3; // r2
  int result; // r0
  unsigned int *v5; // r2

  v2 = (unsigned __int8 *)(a1 + 15);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  __dmb(0xBu);
  if ( v3 >> 7 )
    return sub_54F70C();
  *(_BYTE *)(a1 + 18) &= 0xDFu;
  MiRemoveLockedPageChargeAndDecRef(a1);
  __dmb(0xBu);
  v5 = (unsigned int *)(a1 + 12);
  do
    result = __ldrex(v5);
  while ( __strex(result & 0x7FFFFFFF, v5) );
  return result;
}
