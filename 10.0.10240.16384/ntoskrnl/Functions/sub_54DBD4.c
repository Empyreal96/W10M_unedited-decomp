// sub_54DBD4 
 
void sub_54DBD4()
{
  int v0; // r4
  unsigned int v1; // r5

  if ( v1 <= *(_DWORD *)(v0 + 4) - *(_DWORD *)(v0 + 8) )
    JUMPOUT(0x4E3800);
  JUMPOUT(0x4E3802);
}
