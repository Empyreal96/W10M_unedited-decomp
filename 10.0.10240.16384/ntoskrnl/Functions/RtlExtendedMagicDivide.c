// RtlExtendedMagicDivide 
 
int __fastcall RtlExtendedMagicDivide(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, char a7)
{
  unsigned int v10; // r3
  int v11; // r2
  char v12[24]; // [sp+8h] [bp-18h] BYREF
  _DWORD *varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  if ( a4 < 0 )
    return sub_51C8E0();
  Mult64By64To128(a3, a4, a5, a6, a1, v12);
  v10 = a1[1];
  *a1 = *(_QWORD *)a1 >> a7;
  a1[1] = v10 >> a7;
  if ( a4 < 0 )
  {
    v11 = -*(_QWORD *)a1 >> 32;
    *a1 = -*a1;
    a1[1] = v11;
  }
  return (int)a1;
}
