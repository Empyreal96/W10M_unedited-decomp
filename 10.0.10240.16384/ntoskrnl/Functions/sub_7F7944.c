// sub_7F7944 
 
void sub_7F7944()
{
  _DWORD *v0; // r5
  _DWORD *v1; // r6
  unsigned int v2; // r0
  void (*v3)(void); // r3

  while ( 1 )
  {
    v2 = (unsigned int)(v0 - 3);
    v3 = (void (*)(void))v0[3];
    v0 = (_DWORD *)*v0;
    if ( v3 )
      v3();
    else
      ExFreePoolWithTag(v2);
    if ( v0 == v1 )
      JUMPOUT(0x71C99E);
  }
}
