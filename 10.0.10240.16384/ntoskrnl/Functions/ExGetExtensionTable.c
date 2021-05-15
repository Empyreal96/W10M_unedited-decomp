// ExGetExtensionTable 
 
int __fastcall ExGetExtensionTable(int a1)
{
  _DWORD *v2; // r0
  unsigned int v3; // r4
  unsigned int v4; // r2
  unsigned int v5; // r1
  int result; // r0

  if ( !a1 )
    return 0;
  v2 = (_DWORD *)(a1 + 36);
  __pld(v2);
  v3 = *v2 & 0xFFFFFFFE;
  v4 = v3 + 2;
  do
    v5 = __ldrex(v2);
  while ( v5 == v3 && __strex(v4, v2) );
  __dmb(0xBu);
  if ( v5 == v3 )
    result = *(_DWORD *)(a1 + 44);
  else
    result = sub_525B10(v2, v5, v4);
  return result;
}
