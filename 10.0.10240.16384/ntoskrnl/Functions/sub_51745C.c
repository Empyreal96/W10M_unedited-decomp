// sub_51745C 
 
void sub_51745C()
{
  int v0; // r4
  int v1; // r6
  _BYTE *v2; // r8

  if ( v1 != 1 && *(_DWORD *)(v0 + 4) > 1u )
  {
    *v2 = 1;
    JUMPOUT(0x439860);
  }
  JUMPOUT(0x4397F0);
}
