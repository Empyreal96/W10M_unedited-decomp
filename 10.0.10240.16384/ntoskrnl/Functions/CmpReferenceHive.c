// CmpReferenceHive 
 
int __fastcall CmpReferenceHive(int a1)
{
  unsigned int *v1; // r0
  unsigned int v2; // r1
  unsigned int v3; // r4

  v1 = (unsigned int *)(a1 + 3320);
  v2 = *v1;
  __dmb(0xBu);
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex(v1);
    while ( v3 == v2 && __strex(v2 + 1, v1) );
    __dmb(0xBu);
    if ( v3 == v2 )
      break;
    v2 = v3;
    if ( !v3 )
      return 0;
  }
  return 1;
}
