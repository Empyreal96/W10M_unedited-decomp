// sub_511280 
 
void sub_511280()
{
  int *v0; // r7
  _DWORD *v1; // r8
  int v2; // r1
  int v3; // r3
  int v4; // r4
  int v5; // r5
  _DWORD *v6; // r7
  int v7; // r3

  v2 = *v0;
  v3 = v0[1];
  v4 = v0[2];
  v5 = v0[3];
  v6 = v0 + 4;
  v1[10] = v2;
  v1[11] = v3;
  v1[12] = v4;
  v1[13] = v5;
  v7 = v6[1];
  v1[14] = *v6;
  v1[15] = v7;
  JUMPOUT(0x429D54);
}
