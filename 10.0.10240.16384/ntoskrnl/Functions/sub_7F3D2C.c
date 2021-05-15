// sub_7F3D2C 
 
void sub_7F3D2C()
{
  _DWORD *v0; // r4
  int *v1; // r5
  int v2; // r3

  v2 = *(_DWORD *)(v0[8] + 40) + 4096;
  *v1 = v2;
  v0[486] = v2;
  v0[487] = 0;
  JUMPOUT(0x70EF48);
}
