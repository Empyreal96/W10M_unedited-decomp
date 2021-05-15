// AuthzBasepMemberOf 
 
int __fastcall AuthzBasepMemberOf(int a1, int a2, int a3, char a4, char a5, _BYTE *a6)
{
  int v7; // r5
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  int v12; // r0
  char v16[20]; // [sp+10h] [bp-88h] BYREF
  unsigned int v17; // [sp+24h] [bp-74h]
  int v18; // [sp+28h] [bp-70h]
  char v19[104]; // [sp+30h] [bp-68h] BYREF

  v7 = a5 != 0;
  *a6 = 0;
  while ( 1 )
  {
    v9 = AuthzBasepGetNextValue(a1, (int)v16);
    v10 = v9;
    if ( v9 == -2147483622 )
      break;
    if ( v9 < 0 )
      return v10;
    v11 = v17;
    if ( v17 >= 0x44 )
      v11 = 68;
    memmove((int)v19, v18, v11);
    v12 = SepSidInToken(a2, 0, (int)v19, a3, a4);
    if ( a5 )
    {
      v7 &= v12;
      if ( !v7 )
        goto LABEL_12;
    }
    else
    {
      v7 = (unsigned __int8)(v7 | v12);
      if ( v7 )
        goto LABEL_12;
    }
  }
  v10 = 0;
LABEL_12:
  if ( v10 >= 0 )
    *a6 = v7;
  return v10;
}
