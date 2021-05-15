// sub_802AB8 
 
void sub_802AB8()
{
  unsigned int v0; // r4
  int v1; // r7

  if ( v0 >= 0x10 )
  {
    if ( *(_DWORD *)(v1 + 12) )
      JUMPOUT(0x74206E);
  }
  JUMPOUT(0x742072);
}
