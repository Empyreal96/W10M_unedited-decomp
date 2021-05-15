// sub_553D7C 
 
void sub_553D7C()
{
  _DWORD *v0; // r5
  int v1; // r2
  int v2; // r2

  v1 = v0[1] - v0[5] - 1;
  if ( v0[2] )
    v1 *= 2;
  *(_DWORD *)(v0[8] + 4 * v1) = 0;
  v2 = v0[1] - v0[5];
  *(_DWORD *)(v0[7] + 4 * ((unsigned int)(v2 - 1) >> 5)) &= ~(1 << ((v2 - 1) & 0x1F));
  JUMPOUT(0x4F4AE4);
}
