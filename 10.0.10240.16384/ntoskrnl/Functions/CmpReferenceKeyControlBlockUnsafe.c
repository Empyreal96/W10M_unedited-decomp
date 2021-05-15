// CmpReferenceKeyControlBlockUnsafe 
 
int __fastcall CmpReferenceKeyControlBlockUnsafe(unsigned int *a1)
{
  unsigned int v1; // r1
  unsigned int v2; // r2
  unsigned int v3; // r4

  v1 = *a1;
  __dmb(0xBu);
  v2 = v1 + 1;
  if ( v1 == -1 )
    return 0;
  while ( 1 )
  {
    if ( v2 == 1 )
      sub_7FE54C();
    __dmb(0xBu);
    do
      v3 = __ldrex(a1);
    while ( v3 == v1 && __strex(v2, a1) );
    __dmb(0xBu);
    if ( v3 == v1 )
      break;
    v1 = v3;
    v2 = v3 + 1;
    if ( v3 == -1 )
      return 0;
  }
  return 1;
}
