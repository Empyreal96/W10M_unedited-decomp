// sub_539414 
 
void sub_539414()
{
  unsigned int *v0; // r5
  int v1; // r0
  unsigned int *v2; // r2
  unsigned int v3; // r0

  v1 = MiLockLeafPage(v0, 0);
  if ( v1 )
  {
    if ( (*v0 & 2) != 0 )
      JUMPOUT(0x49898E);
    __dmb(0xBu);
    v2 = (unsigned int *)(v1 + 12);
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 & 0x7FFFFFFF, v2) );
  }
  JUMPOUT(0x498750);
}
