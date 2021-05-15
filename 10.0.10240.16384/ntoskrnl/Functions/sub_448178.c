// sub_448178 
 
int __fastcall sub_448178(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  int v5; // r4
  int v6; // r1
  int result; // r0
  int v8; // r2
  int v9[2]; // [sp+10h] [bp-20h] BYREF
  int v10[6]; // [sp+18h] [bp-18h] BYREF

  RtlExtendedMagicDivide(v9, a2, *a1, a1[1], -501652180, -776530088, 13);
  v5 = v9[0];
  result = RtlExtendedMagicDivide(v10, v6, v9[0], v9[1], -93865714, -958967573, 26);
  v8 = v10[0];
  *a2 = v10[0];
  *a3 = v5 - 86400000 * v8;
  return result;
}
