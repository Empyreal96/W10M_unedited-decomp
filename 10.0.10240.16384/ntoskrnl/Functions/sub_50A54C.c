// sub_50A54C 
 
void sub_50A54C()
{
  int v0; // r5
  _WORD *v1; // r6
  __int16 v2; // r7
  int v3; // r10
  char v4[4]; // [sp+8h] [bp-40h] BYREF
  char v5; // [sp+Ch] [bp-3Ch] BYREF

  if ( v0 )
    *v1 = 0;
  if ( (v2 & 0x1C00) != 0 && v0 )
    sub_565F48(v1, 2 * v0, 0, v4, &v5, v2);
  if ( v3 == -1073741811 )
    JUMPOUT(0x43E294);
  JUMPOUT(0x43E29C);
}
