// CcFreeVirtualAddress 
 
int __fastcall CcFreeVirtualAddress(int result)
{
  int v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1

  v1 = *(_DWORD *)(result + 4);
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 8);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  __dmb(0xBu);
  if ( !(_WORD)v4 )
  {
    result = *(_DWORD *)(v1 + 116);
    if ( result )
      result = sub_54A4B0();
  }
  return result;
}
