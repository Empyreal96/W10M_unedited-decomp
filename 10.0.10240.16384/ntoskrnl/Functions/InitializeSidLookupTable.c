// InitializeSidLookupTable 
 
int InitializeSidLookupTable()
{
  char *v0; // r4
  int v1; // r5
  int v3; // r3
  int v4; // r0
  int v5; // r1
  char *v6; // r1
  _BYTE *v7; // r0
  char v8[8]; // [sp+0h] [bp-50h] BYREF
  char v9[8]; // [sp+8h] [bp-48h] BYREF
  char v10[8]; // [sp+10h] [bp-40h] BYREF
  char v11[8]; // [sp+18h] [bp-38h] BYREF
  char v12[8]; // [sp+20h] [bp-30h] BYREF
  char v13[8]; // [sp+28h] [bp-28h] BYREF
  char v14[32]; // [sp+30h] [bp-20h] BYREF

  v9[0] = 0;
  v9[1] = 0;
  v9[2] = 0;
  v9[3] = 0;
  v9[4] = 0;
  v9[5] = 1;
  v10[0] = 0;
  v10[1] = 0;
  v10[2] = 0;
  v10[3] = 0;
  v10[4] = 0;
  v10[5] = 2;
  v11[0] = 0;
  v11[1] = 0;
  v11[2] = 0;
  v11[3] = 0;
  v11[4] = 0;
  v11[5] = 3;
  v8[0] = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  v8[4] = 0;
  v8[5] = 5;
  v12[0] = 0;
  v12[1] = 0;
  v12[2] = 0;
  v12[3] = 0;
  v12[4] = 0;
  v12[5] = 16;
  v13[0] = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  v13[4] = 0;
  v13[5] = 15;
  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[3] = 0;
  v14[4] = 0;
  v0 = &byte_60EAA0;
  v1 = 63;
  v14[5] = 18;
  do
  {
    if ( *v0 == 1 )
      return sub_8181B4();
    v3 = *((_DWORD *)v0 + 6);
    v4 = (int)(v0 + 28);
    *((_DWORD *)v0 + 4) = v0 + 28;
    switch ( v3 )
    {
      case 1:
        v6 = v9;
        goto LABEL_12;
      case 2:
        v6 = v10;
        goto LABEL_12;
      case 4:
        v6 = v11;
        goto LABEL_12;
      case 5:
        v6 = v8;
        goto LABEL_12;
      case 6:
        RtlInitializeSid(v4, (int)v8, 2u);
        *(_DWORD *)RtlSubAuthoritySid(*((_DWORD *)v0 + 4), 0) = 32;
        goto LABEL_6;
      case 8:
        v6 = v12;
        goto LABEL_12;
      case 9:
        RtlInitializeSid(v4, (int)v13, 2u);
        *(_DWORD *)RtlSubAuthoritySid(*((_DWORD *)v0 + 4), 0) = 2;
LABEL_6:
        v5 = 1;
        goto LABEL_7;
      case 10:
        RtlInitializeSid(v4, (int)v8, 6u);
        *(_DWORD *)RtlSubAuthoritySid(*((_DWORD *)v0 + 4), 0) = 84;
        v7 = (_BYTE *)RtlSubAuthoritySid(*((_DWORD *)v0 + 4), 1);
        memset(v7, 0, 20);
        goto LABEL_8;
      case 11:
        v6 = v14;
LABEL_12:
        RtlInitializeSid(v4, (int)v6, 1u);
        v5 = 0;
LABEL_7:
        *(_DWORD *)RtlSubAuthoritySid(*((_DWORD *)v0 + 4), v5) = *((_DWORD *)v0 + 5);
LABEL_8:
        *v0 = 1;
        break;
      default:
        break;
    }
    v0 += 100;
    --v1;
  }
  while ( v1 );
  return 1;
}
