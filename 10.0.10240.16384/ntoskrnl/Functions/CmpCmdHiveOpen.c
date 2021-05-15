// CmpCmdHiveOpen 
 
int __fastcall CmpCmdHiveOpen(int a1, int a2, int a3, int *a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11)
{
  int v14; // r7
  int v15; // r1
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r4
  int v22; // [sp+4h] [bp-164h]
  int v23; // [sp+8h] [bp-160h]
  int v24; // [sp+28h] [bp-140h] BYREF
  char v25[284]; // [sp+2Ch] [bp-13Ch] BYREF

  v24 = 0;
  memset(v25, 0, sizeof(v25));
  v14 = IoSetThreadHardErrorMode(0);
  v15 = 0x20000;
  if ( (a6 & 1) != 0 )
    v15 = 425984;
  if ( (a5 & 0x20000000) != 0 )
    v15 |= 2u;
  v16 = CmpInitHiveFromFile(a1, v15, a4, a3, a5, v22, v23, a7, &v24);
  v19 = -1073741790;
  v20 = v16;
  if ( v16 == -1073741790 )
    return sub_7C35E0(v16, v17, v18, v19, a5, a6, a7, a8, a9, a10, a11);
  v19 = -1073741724;
  if ( v16 == -1073741724 )
    return sub_7C35E0(v16, v17, v18, v19, a5, a6, a7, a8, a9, a10, a11);
  v19 = -1073741718;
  if ( v16 == -1073741718 )
    return sub_7C35E0(v16, v17, v18, v19, a5, a6, a7, a8, a9, a10, a11);
  v19 = -1073741421;
  if ( v16 == -1073741421 )
    return sub_7C35E0(v16, v17, v18, v19, a5, a6, a7, a8, a9, a10, a11);
  v19 = -1073741710;
  if ( v16 == -1073741710 )
    return sub_7C35E0(v16, v17, v18, v19, a5, a6, a7, a8, a9, a10, a11);
  v19 = -1073741714;
  if ( v16 == -1073741714 )
    return sub_7C35E0(v16, v17, v18, v19, a5, a6, a7, a8, a9, a10, a11);
  IoSetThreadHardErrorMode(v14);
  return v20;
}
