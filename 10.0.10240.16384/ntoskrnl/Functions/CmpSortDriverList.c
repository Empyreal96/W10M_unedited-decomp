// CmpSortDriverList 
 
int __fastcall CmpSortDriverList(int a1, int a2, int a3)
{
  int (__fastcall *v4)(int, int, int *); // r3
  int v6; // r0
  int v7; // r3
  int v8; // r4
  int v9; // r0
  int v10; // r3
  int v11; // r4
  int v12; // r0
  int v13; // r3
  int v14; // r4
  int v15; // r0
  int v16; // r0
  void (__fastcall *v17)(int, int *); // r3
  int v18; // r4
  int v19; // r4
  int v21; // [sp+8h] [bp-30h] BYREF
  int v22; // [sp+Ch] [bp-2Ch] BYREF
  int v23; // [sp+10h] [bp-28h] BYREF
  unsigned int v24; // [sp+14h] [bp-24h] BYREF
  __int16 v25[2]; // [sp+18h] [bp-20h] BYREF
  int v26; // [sp+1Ch] [bp-1Ch]

  v4 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v22 = -1;
  v23 = -1;
  v21 = -1;
  v6 = v4(a1, a2, &v21);
  if ( !v6 )
    return 0;
  v8 = CmpFindSubKeyByName(a1, v6, (int)&CmpControlString, v7);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
  if ( v8 == -1 )
    return 0;
  v9 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v8, &v21);
  if ( !v9 )
    return 0;
  v11 = CmpFindSubKeyByName(a1, v9, (int)&CmpServiceGroupOrderString, v10);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
  if ( v11 == -1 )
    return 0;
  v12 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v11, &v21);
  if ( !v12 )
    return 0;
  v14 = CmpFindValueByName(a1, v12, (int)&CmpListString, v13);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
  if ( v14 == -1 )
    return 0;
  v15 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v14, &v22);
  if ( !v15 )
    return 0;
  if ( *(_DWORD *)(v15 + 12) != 7 )
  {
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
    return 0;
  }
  v16 = CmpValueToData(a1, v14, v15, &v24, (int)&v23);
  v17 = *(void (__fastcall **)(int, int *))(a1 + 8);
  v18 = v16;
  v26 = v16;
  v17(a1, &v22);
  if ( !v18 )
    return 0;
  v25[1] = v24 - 2;
  v25[0] = v24 - 2;
  v19 = CmpDoSort(a3, v25);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v23);
  return v19;
}
