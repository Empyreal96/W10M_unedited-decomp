// AuthzBasepInitializeResourceClaimsFromSacl 
 
int __fastcall AuthzBasepInitializeResourceClaimsFromSacl(int a1, int a2)
{
  int v3; // r4
  char *v4; // r5
  int *v5; // r0
  int *v6; // r6
  unsigned int v7; // r2
  unsigned __int8 *v8; // r7
  int v10; // r3
  int v11; // r1
  int v12; // r9
  int v13; // r1
  int v14; // r0
  unsigned int v15; // [sp+8h] [bp-140h]
  int v16; // [sp+Ch] [bp-13Ch] BYREF
  __int16 v17; // [sp+10h] [bp-138h] BYREF
  _BYTE v18[10]; // [sp+12h] [bp-136h]
  int v19; // [sp+1Ch] [bp-12Ch] BYREF
  unsigned int v20; // [sp+20h] [bp-128h] BYREF
  int **v21; // [sp+24h] [bp-124h]
  char v22[288]; // [sp+28h] [bp-120h] BYREF

  v19 = 2;
  v17 = 0;
  *(_DWORD *)v18 = 0;
  *(_DWORD *)&v18[4] = 0;
  *(_WORD *)&v18[8] = 0;
  v21 = (int **)a2;
  v3 = 0;
  v4 = v22;
  v5 = (int *)AuthzBasepMemAlloc(24, a2, 1950442835);
  v6 = v5;
  if ( !v5 )
    return -1073741801;
  v7 = 0;
  *v5 = 0;
  v5[1] = (int)(v5 + 1);
  v5[2] = (int)(v5 + 1);
  v5[3] = 0;
  v5[4] = (int)(v5 + 4);
  v5[5] = (int)(v5 + 4);
  v15 = 0;
  v8 = (unsigned __int8 *)(a1 + 8);
  if ( !*(_WORD *)(a1 + 4) )
    goto LABEL_3;
  while ( 1 )
  {
    if ( v4 != v22 )
      return sub_522554();
    v10 = *v8;
    v4 = v22;
    v16 = 256;
    if ( v10 != 18 || (v8[1] & 8) != 0 )
      goto LABEL_8;
    v11 = v8[9];
    v12 = *((unsigned __int16 *)v8 + 1) - 4 * v11;
    v3 = AuthzBasepConvertRelativeToAbsoluteTokenAttribute(&v8[4 * v11 + 16], v12 - 16, v22, &v16);
    if ( v3 == -1073741789 )
      break;
LABEL_19:
    if ( v3 < 0 )
      goto LABEL_9;
    v17 = 1;
    *(_DWORD *)&v18[2] = 1;
    *(_DWORD *)&v18[6] = v4;
    v14 = AuthzBasepQuerySecurityAttributesToken(v6, (unsigned __int16 *)v4, 1u, 0, 0, &v20);
    v3 = v14;
    if ( v14 == -1073741789 || v14 == -1073741275 )
      v3 = 0;
    if ( v3 < 0 )
      goto LABEL_9;
    if ( v20 <= 0xC )
      v3 = AuthzBasepSetSecurityAttributesToken(v6, &v19, &v17);
    if ( v3 < 0 )
      goto LABEL_9;
    v7 = v15;
LABEL_8:
    v15 = ++v7;
    v8 += *((unsigned __int16 *)v8 + 1);
    if ( v7 >= *(unsigned __int16 *)(a1 + 4) )
      goto LABEL_9;
  }
  v4 = (char *)AuthzBasepMemAlloc(v16, v13, 1950442835);
  if ( v4 )
  {
    v3 = AuthzBasepConvertRelativeToAbsoluteTokenAttribute(&v8[4 * v8[9] + 16], v12 - 16, v4, &v16);
    goto LABEL_19;
  }
  v3 = -1073741801;
LABEL_9:
  if ( v4 )
  {
    if ( v4 != v22 )
      ExFreePoolWithTag(v4, 0);
  }
  if ( v3 < 0 )
  {
    AuthzBasepFreeSecurityAttributesList((int)v6);
    ExFreePoolWithTag(v6, 0);
    return v3;
  }
LABEL_3:
  *v21 = v6;
  return v3;
}
