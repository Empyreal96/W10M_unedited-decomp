// sub_7C9024 
 
void sub_7C9024()
{
  _DWORD *v0; // r5
  _DWORD *v1; // r8
  int v2; // r1
  int v3; // r2
  int v4; // r3

  v2 = v1[1];
  v3 = v1[2];
  v4 = v1[3];
  v0[1] = *v1;
  v0[2] = v2;
  v0[3] = v3;
  v0[4] = v4;
  JUMPOUT(0x7681E6);
}
