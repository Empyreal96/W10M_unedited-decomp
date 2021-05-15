// sub_809D68 
 
void sub_809D68()
{
  _DWORD *v0; // r6
  _DWORD *v1; // r7
  int v2; // r1
  int v3; // r2
  int v4; // r3

  v2 = v1[15];
  v3 = v1[16];
  v4 = v1[17];
  v0[84] = v1[14];
  v0[85] = v2;
  v0[86] = v3;
  v0[87] = v4;
  JUMPOUT(0x75EC42);
}
