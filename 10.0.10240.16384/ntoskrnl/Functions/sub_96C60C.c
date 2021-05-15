// sub_96C60C 
 
void __fastcall sub_96C60C(int a1, int a2, _DWORD *a3)
{
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v10; // r3

  v3 = a3[10];
  if ( v3 )
    a3[10] = (char *)a3 + v3;
  v4 = a3[13];
  if ( v4 )
    a3[13] = (char *)a3 + v4;
  v5 = a3[15];
  if ( v5 )
    a3[15] = (char *)a3 + v5;
  v6 = a3[17];
  if ( v6 )
    a3[17] = (char *)a3 + v6;
  v7 = a3[29];
  if ( v7 )
    a3[29] = (char *)a3 + v7;
  v8 = a3[31];
  if ( v8 )
    a3[31] = (char *)a3 + v8;
  v9 = a3[33];
  if ( v9 )
    a3[33] = (char *)a3 + v9;
  v10 = a3[35];
  if ( v10 )
    a3[35] = (char *)a3 + v10;
  a3[2] = a2 | 1;
  JUMPOUT(0x95AA1E);
}
