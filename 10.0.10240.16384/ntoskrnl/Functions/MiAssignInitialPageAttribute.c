// MiAssignInitialPageAttribute 
 
int __fastcall MiAssignInitialPageAttribute(int result, char a2)
{
  int v3; // r5
  unsigned int v4; // r4
  int v5; // r4
  unsigned __int8 *v6; // r1
  unsigned int v7; // r2
  int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r0

  v3 = result;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( dword_63437C == v4 )
  {
    v5 = 17;
  }
  else
  {
    result = KfRaiseIrql(2);
    v5 = result;
    v6 = (unsigned __int8 *)(v3 + 15);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      return sub_5264B8();
  }
  v8 = *(unsigned __int8 *)(v3 + 18);
  if ( (v8 & 0xFFFFFFC0) == 192 )
    *(_BYTE *)(v3 + 18) = v8 & 0x3F | (a2 << 6);
  if ( v5 != 17 )
  {
    __dmb(0xBu);
    v9 = (unsigned int *)(v3 + 12);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & 0x7FFFFFFF, v9) );
    result = KfLowerIrql(v5);
  }
  return result;
}
