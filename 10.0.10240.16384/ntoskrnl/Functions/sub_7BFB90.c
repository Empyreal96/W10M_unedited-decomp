// sub_7BFB90 
 
void sub_7BFB90()
{
  unsigned int *v0; // r6
  unsigned int v1; // r5
  unsigned int v2; // r0
  unsigned int v3; // r1

  v1 = *v0;
  __dmb(0xBu);
  while ( 1 )
  {
    v2 = v1;
    __dmb(0xBu);
    do
      v3 = __ldrex(v0);
    while ( v3 == v1 && __strex((v1 & 0x3FFF) - 1, v0) );
    v1 = v3;
    __dmb(0xBu);
    if ( v3 == v2 )
      JUMPOUT(0x6A4FB4);
  }
}
