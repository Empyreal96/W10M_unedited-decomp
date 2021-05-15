// KsepPoolAllocateNonPaged 
 
_BYTE *__fastcall KsepPoolAllocateNonPaged(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4
  unsigned int v4; // r1
  unsigned int v5; // r1

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, a1);
  v3 = v2;
  __dmb(0xBu);
  if ( v2 )
  {
    do
      v4 = __ldrex(&dword_621724[1]);
    while ( __strex(v4 + 1, &dword_621724[1]) );
    __dmb(0xBu);
    memset(v2, 0, a1);
  }
  else
  {
    do
      v5 = __ldrex(&dword_621724[4]);
    while ( __strex(v5 + 1, &dword_621724[4]) );
    __dmb(0xBu);
  }
  return v3;
}
