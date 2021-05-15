// EtwpAddReplyIndex 
 
int __fastcall EtwpAddReplyIndex(int a1, unsigned int a2)
{
  unsigned int *v2; // r0
  unsigned int v3; // r2

  v2 = (unsigned int *)(a1 + 24);
  __dmb(0xBu);
  do
    v3 = __ldrex(v2);
  while ( !v3 && __strex(a2, v2) );
  __dmb(0xBu);
  if ( v3 )
    return sub_7EB460();
  *(_WORD *)(a2 + 26) = 0;
  return 0;
}
