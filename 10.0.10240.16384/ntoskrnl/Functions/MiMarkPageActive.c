// MiMarkPageActive 
 
int __fastcall MiMarkPageActive(int a1)
{
  int v2; // r0
  int v3; // r5
  unsigned __int8 *v4; // r1
  unsigned int v5; // r2
  int result; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r0

  v2 = KfRaiseIrql(2);
  v3 = v2;
  v4 = (unsigned __int8 *)(a1 + 15);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_509BEC();
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0xF8 | 6;
  __dmb(0xBu);
  v7 = (unsigned int *)(a1 + 12);
  if ( v2 == 17 )
  {
    do
      result = __ldrex(v7);
    while ( __strex(result & 0x7FFFFFFF, v7) );
  }
  else
  {
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 & 0x7FFFFFFF, v7) );
    result = KfLowerIrql(v3);
  }
  return result;
}
