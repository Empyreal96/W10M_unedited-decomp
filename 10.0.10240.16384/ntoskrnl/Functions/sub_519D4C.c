// sub_519D4C 
 
void sub_519D4C()
{
  int v0; // r5
  unsigned int v1; // r3

  v1 = *(_DWORD *)(v0 + 20);
  *(_BYTE *)v0 = v1;
  if ( v1 > 0xFF )
    *(_BYTE *)v0 = -1;
  JUMPOUT(0x4E054E);
}
