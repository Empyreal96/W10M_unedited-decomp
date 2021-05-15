// CmpDoAccessCheckOnSubtree 
 
int __fastcall CmpDoAccessCheckOnSubtree(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  char v5; // r10
  int v8; // r6
  int v9; // r0
  unsigned int v10; // r9
  int v11; // r7
  int v12; // r4
  int v13; // r1
  int v14; // t1
  _DWORD *v15; // r0
  unsigned int v16; // r2
  int v17; // r2
  int v19; // [sp+0h] [bp-28h] BYREF
  int v20[9]; // [sp+4h] [bp-24h] BYREF

  v20[0] = a3;
  v20[1] = a4;
  v4 = -1073741670;
  v5 = a3;
  v8 = -1073741670;
  v19 = -1;
  v9 = ExAllocatePoolWithTag(1, 10240, 1952664899);
  v10 = v9;
  if ( v9 )
  {
    *(_DWORD *)v9 = a2;
    *(_DWORD *)(v9 + 12) = 0;
    *(_BYTE *)(v9 + 16) = 0;
    v11 = 0;
    v12 = v9;
    do
    {
      if ( !*(_BYTE *)(v12 + 16) )
      {
        v13 = *(_DWORD *)v12;
        *(_BYTE *)(v12 + 16) = 1;
        v8 = CmpCheckKeyAccess(a1, v13, v5, 0x10000);
        if ( v8 < 0 )
          break;
      }
      v14 = *(_DWORD *)v12;
      v12 -= 20;
      v15 = (_DWORD *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v14, &v19);
      if ( !v15 )
      {
        v8 = -1073741670;
        break;
      }
      v16 = *(_DWORD *)(v12 + 32);
      if ( v16 >= v15[5] + v15[6] )
      {
        --v11;
      }
      else
      {
        v8 = CmpFindSubKeyByNumber(a1, v15, v16, v20);
        if ( v8 < 0 )
          goto LABEL_15;
        v17 = v20[0];
        if ( v20[0] == -1 || (++v11, ++*(_DWORD *)(v12 + 32), v12 += 40, v11 == 512) )
        {
          v8 = -1073741670;
LABEL_15:
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
          break;
        }
        *(_DWORD *)(v12 + 12) = 0;
        *(_BYTE *)(v12 + 16) = 0;
        *(_DWORD *)v12 = v17;
      }
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
    }
    while ( v11 >= 0 );
    ExFreePoolWithTag(v10);
    v4 = v8;
  }
  return v4;
}
