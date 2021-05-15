// CmpFindTagIndex 
 
int __fastcall CmpFindTagIndex(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, int, int *); // r4
  int v9; // r0
  int *v10; // r6
  int v11; // r0
  int v12; // r3
  int v13; // r4
  int v14; // r0
  int v15; // r4
  int v16; // r6
  int *v17; // r1
  int v18; // t1
  char v20[4]; // [sp+10h] [bp-38h] BYREF
  int v21; // [sp+14h] [bp-34h] BYREF
  int v22; // [sp+18h] [bp-30h] BYREF
  int v23; // [sp+1Ch] [bp-2Ch] BYREF
  _DWORD *v24; // [sp+20h] [bp-28h] BYREF
  int v25; // [sp+24h] [bp-24h] BYREF
  int v26; // [sp+28h] [bp-20h] BYREF
  unsigned int v27[7]; // [sp+2Ch] [bp-1Ch] BYREF

  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v25 = -1;
  v26 = -1;
  v21 = -1;
  v22 = -1;
  v23 = -1;
  v24 = 0;
  v9 = v5(a1, a2, &v21);
  if ( !v9 )
    return -2;
  v10 = (int *)CmpValueToData(a1, a2, v9, v27, (int)&v26);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
  if ( !v10 )
    return -2;
  v11 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a3, &v22);
  if ( !v11 )
    goto LABEL_20;
  v13 = CmpFindValueByName(a1, v11, a4, v12);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
  if ( v13 == -1 )
  {
    v15 = *v10;
    goto LABEL_15;
  }
  v14 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v13, &v23);
  if ( !v14
    || (CmpGetValueData(a1, v13, v14, v27, (int *)&v24, v20, (int)&v25),
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v23),
        !v24) )
  {
LABEL_20:
    v15 = -2;
    goto LABEL_15;
  }
  v15 = 1;
  if ( !*v24 )
  {
LABEL_11:
    if ( v20[0] )
      ExFreePoolWithTag((unsigned int)v24);
    v15 = -2;
LABEL_14:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v25);
LABEL_15:
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
    return v15;
  }
  v16 = *v10;
  v17 = v24 + 1;
  while ( 1 )
  {
    v18 = *v17++;
    if ( v18 == v16 )
      break;
    if ( (unsigned int)++v15 > *v24 )
      goto LABEL_11;
  }
  if ( !v20[0] )
    goto LABEL_14;
  return sub_968148();
}
