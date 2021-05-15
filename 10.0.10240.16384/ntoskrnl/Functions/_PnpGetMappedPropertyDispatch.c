// _PnpGetMappedPropertyDispatch 
 
int __fastcall PnpGetMappedPropertyDispatch(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  unsigned int v12; // r4
  int v13; // r2
  int (__fastcall *v14)(int, int, int, int, int *); // r5
  int v16; // [sp+8h] [bp-30h] BYREF
  int v17; // [sp+Ch] [bp-2Ch]
  int v18; // [sp+10h] [bp-28h]
  int v19; // [sp+14h] [bp-24h]
  int v20; // [sp+18h] [bp-20h]
  int v21; // [sp+1Ch] [bp-1Ch]
  int v22; // [sp+20h] [bp-18h]
  int v23; // [sp+24h] [bp-14h]

  v12 = a3 - 1;
  v13 = 0;
  v14 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  if ( v12 > 9 )
    v13 = -1073741811;
  else
    v14 = *(int (__fastcall **)(int, int, int, int, int *))(a1 + 4 * a3 + 64);
  if ( v13 < 0 )
    return v13;
  if ( !v14 )
    return -1073741822;
  v17 = a5;
  v18 = a6;
  v19 = a7;
  v20 = a8;
  v21 = a9;
  v22 = a10;
  v23 = a11;
  v16 = a4;
  return v14(a1, a2, a3, 8, &v16);
}
