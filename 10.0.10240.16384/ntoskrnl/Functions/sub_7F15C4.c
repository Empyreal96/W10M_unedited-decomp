// sub_7F15C4 
 
void sub_7F15C4()
{
  unsigned int *v0; // r2
  unsigned int v1; // r1
  unsigned int v2; // r4
  int *v3; // r5
  unsigned int *v4; // r6
  unsigned int v5; // r8
  int v6; // r0

  if ( v2 >= *v4 )
    v6 = 0;
  else
    v6 = *v3;
  if ( v6 )
  {
    __dmb(0xBu);
    v0 = (unsigned int *)(v6 + 3124);
    do
      v1 = __ldrex(v0);
    while ( !v1 && __strex(v5, v0) );
    __dmb(0xBu);
    if ( !v1 )
      IoWMIRegistrationControl(v6 + 3120, -2147483647);
  }
  JUMPOUT(0x78C428);
}
