// sub_53A38C 
 
void sub_53A38C()
{
  int v0; // r4
  int v1; // r3

  v1 = *(_DWORD *)(v0 + 4) - 2;
  *(_DWORD *)(v0 + 4) = v1;
  if ( v1 )
    JUMPOUT(0x499E5A);
  JUMPOUT(0x499E6A);
}
