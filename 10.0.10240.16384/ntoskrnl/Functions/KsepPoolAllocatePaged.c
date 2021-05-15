// KsepPoolAllocatePaged 
 
int __fastcall KsepPoolAllocatePaged(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4
  unsigned int v5; // r1

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, a1, 1631933259);
  v3 = v2;
  __dmb(0xBu);
  if ( !v2 )
    return sub_50A604();
  do
    v5 = __ldrex(&dword_621720);
  while ( __strex(v5 + 1, &dword_621720) );
  __dmb(0xBu);
  memset(v2, 0, a1);
  return (int)v3;
}
