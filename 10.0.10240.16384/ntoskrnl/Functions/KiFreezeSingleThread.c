// KiFreezeSingleThread 
 
int __fastcall KiFreezeSingleThread(int a1, int a2)
{
  unsigned __int8 *v2; // r4
  unsigned int v3; // r2
  int result; // r0
  unsigned __int8 *v5; // r5
  unsigned int v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r3

  v2 = (unsigned __int8 *)(a2 + 452);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  __dmb(0xBu);
  if ( v3 >> 7 )
    return sub_5216E0();
  __dmb(0xBu);
  v5 = (unsigned __int8 *)(a2 + 81);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 | 0x20, v5) );
  __dmb(0xBu);
  result = KiSuspendThread(a2, a1);
  if ( !result )
  {
    __dmb(0xBu);
    do
      v8 = __ldrex(v5);
    while ( __strex(v8 & 0xDF, v5) );
    __dmb(0xBu);
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)v2);
  while ( __strex(v7 & 0xFFFFFF7F, (unsigned int *)v2) );
  return result;
}
