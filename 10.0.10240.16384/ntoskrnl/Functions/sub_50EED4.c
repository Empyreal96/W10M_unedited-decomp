// sub_50EED4 
 
void __fastcall sub_50EED4(int a1, int a2, int a3, _WORD *a4)
{
  int v4; // r5
  int v5; // r6
  int v6; // r7
  int v7; // r8
  char v8[4]; // [sp+8h] [bp-38h] BYREF
  char v9; // [sp+Ch] [bp-34h] BYREF

  if ( *a4 && !v6 )
  {
    if ( v4 )
      sub_565F48(0, 2 * v4, v5, &v9, v8, v7);
    JUMPOUT(0x4E5044);
  }
  JUMPOUT(0x4E503E);
}
