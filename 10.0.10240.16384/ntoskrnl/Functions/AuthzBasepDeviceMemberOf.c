// AuthzBasepDeviceMemberOf 
 
int __fastcall AuthzBasepDeviceMemberOf(int a1, int a2, int a3, int a4, char a5, _BYTE *a6)
{
  int v7; // r6
  int v8; // r3
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r0
  int v16; // [sp+8h] [bp-90h]
  char v18[20]; // [sp+10h] [bp-88h] BYREF
  unsigned int v19; // [sp+24h] [bp-74h]
  int v20; // [sp+28h] [bp-70h]
  unsigned __int16 v21[52]; // [sp+30h] [bp-68h] BYREF

  v16 = a3;
  v7 = 1;
  v8 = 0;
  if ( !a5 )
    v7 = 0;
  *a6 = 0;
  while ( 1 )
  {
    v10 = AuthzBasepGetNextValue(a1, v18, a3, v8);
    v11 = v10;
    if ( v10 == -2147483622 )
      break;
    if ( v10 < 0 )
      return v11;
    v12 = v19;
    if ( v19 >= 0x44 )
      v12 = 68;
    memmove((int)v21, v20, v12);
    a3 = a2;
    v8 = *(_DWORD *)(a2 + 636);
    if ( v8 )
    {
      if ( a4 )
        v14 = v8 + 152;
      else
        v14 = v8 + 16;
      v13 = SepSidInTokenSidHash(v14, 0, v21, v16, a4, 0);
    }
    else
    {
      v13 = 0;
    }
    if ( a5 )
    {
      v7 &= v13;
      if ( !v7 )
        goto LABEL_20;
    }
    else
    {
      v8 = v13 | v7;
      v7 = (unsigned __int8)(v13 | v7);
      if ( v7 )
        goto LABEL_20;
    }
  }
  v11 = 0;
LABEL_20:
  if ( v11 >= 0 )
    *a6 = v7;
  return v11;
}
