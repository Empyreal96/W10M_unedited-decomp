// KiSetDebugActive 
 
_DWORD *__fastcall KiSetDebugActive(_DWORD *result, int a2)
{
  unsigned int v2; // r6
  unsigned int v3; // r5
  unsigned int v4; // r4

  __pld(result);
  v2 = *result;
  do
  {
    v3 = v2;
    __dmb(0xBu);
    do
      v4 = __ldrex(result);
    while ( v4 == v2 && __strex(v2 & 0xFEFFFFFF | (a2 << 24), result) );
    v2 = v4;
    __dmb(0xBu);
  }
  while ( v4 != v3 );
  return result;
}
