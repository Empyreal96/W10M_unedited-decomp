// CmpCopyKeyPartial 
 
int __fastcall CmpCopyKeyPartial(int a1, int a2, int a3, unsigned int a4, int a5, int a6, int a7)
{
  int v9; // r6
  unsigned int v10; // r10
  int v12; // r9
  int v13; // r0
  int v14; // r8
  int v15; // r2
  int v16; // r9
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r9
  _DWORD *v20; // r3
  unsigned int v21; // r4
  int v22; // r1
  int v23; // r0
  int v24; // r8
  int v25; // r4
  int v26; // r0
  unsigned int v27; // r8
  unsigned int v28; // t1
  int v31; // [sp+8h] [bp-50h]
  int v32; // [sp+Ch] [bp-4Ch]
  int v33; // [sp+10h] [bp-48h]
  int v34; // [sp+14h] [bp-44h]
  int v35; // [sp+18h] [bp-40h] BYREF
  int v36; // [sp+1Ch] [bp-3Ch] BYREF
  int v37; // [sp+20h] [bp-38h] BYREF
  int v38; // [sp+24h] [bp-34h] BYREF
  int v39; // [sp+28h] [bp-30h] BYREF
  _DWORD *v40; // [sp+2Ch] [bp-2Ch]
  int v41; // [sp+30h] [bp-28h] BYREF
  _DWORD *v42; // [sp+34h] [bp-24h]

  v9 = 0;
  v34 = -1;
  v10 = -1;
  v38 = -1;
  v39 = -1;
  v40 = 0;
  v41 = -1;
  v36 = -1;
  v37 = -1;
  v32 = a7;
  if ( a7 == 2 )
  {
    v12 = a4 >> 31;
    if ( a4 == -1 )
      v12 = 0;
    v32 = v12;
  }
  v13 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v38);
  v14 = v13;
  if ( !v13 )
    goto LABEL_54;
  v42 = *(_DWORD **)(v13 + 44);
  v35 = *(_DWORD *)(v13 + 48);
  v33 = *(unsigned __int16 *)(v13 + 74);
  if ( (a5 & 2) == 0 )
  {
    v35 = -1;
    v33 = 0;
  }
  v16 = CmpCopyCell(a1, a2, a3);
  v31 = v16;
  if ( v16 == -1 )
    goto LABEL_41;
  if ( v33 )
  {
    v34 = CmpCopyCell(a1, v35, a3);
    if ( v34 == -1 )
      goto LABEL_41;
  }
  v17 = (*(int (__fastcall **)(int, int, int *))(a3 + 4))(a3, v16, &v39);
  v9 = v17;
  if ( !v17 )
    goto LABEL_41;
  *(_DWORD *)(v17 + 44) = -1;
  *(_DWORD *)(v17 + 48) = v34;
  v15 = a5;
  *(_WORD *)(v17 + 74) = v33;
  *(_DWORD *)(v17 + 20) = 0;
  *(_DWORD *)(v17 + 24) = 0;
  *(_DWORD *)(v17 + 28) = -1;
  *(_DWORD *)(v17 + 32) = -1;
  *(_DWORD *)(v17 + 12) = 0;
  *(_DWORD *)(v17 + 16) = a4;
  *(_WORD *)(v17 + 2) = *(_WORD *)(v14 + 2) & 0x30;
  if ( (a5 & 0x20) != 0 )
  {
    v15 = a5;
    *(_WORD *)(v17 + 2) = *(_WORD *)(v14 + 2) & 0xFFBF;
  }
  if ( a4 == -1 )
    *(_WORD *)(v17 + 2) |= 0xCu;
  if ( (v15 & 0x10) == 0 )
  {
    CmpLockTwoSecurityCachesExclusiveShared(a3, a1);
    if ( !CmpFindSecurityCellCacheIndex((_DWORD *)a1, (int)v42, &v35) )
    {
      CmpUnlockTwoSecurityCaches(a3, a1);
      goto LABEL_41;
    }
    v18 = CmpAssignSecurityDescriptor(a3, v16, v9, (_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v35 + 4) + 24), 0);
    CmpUnlockTwoSecurityCaches(a3, a1);
    if ( v18 < 0 )
      goto LABEL_41;
    v15 = a5;
  }
  if ( (*(_WORD *)(v14 + 2) & 0x40) != 0 )
    v19 = 0;
  else
    v19 = *(_DWORD *)(v14 + 36);
  *(_QWORD *)(v9 + 36) = 0xFFFFFFFF00000000ui64;
  if ( !v19 || (v15 & 4) == 0 )
  {
LABEL_33:
    v16 = v31;
    v25 = 1;
    goto LABEL_42;
  }
  v20 = (_DWORD *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v14 + 40), &v41);
  v40 = v20;
  if ( v20 )
  {
    v21 = 0;
    while ( 1 )
    {
      v22 = *v20;
      v42 = v20 + 1;
      v23 = CmpCopyValue(a1, v22, a3, v32);
      v24 = v23;
      if ( v23 == -1 || !(*(int (__fastcall **)(int, int, int *))(a3 + 4))(a3, v23, &v36) )
      {
        v10 = *(_DWORD *)(v9 + 40);
        goto LABEL_40;
      }
      (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v36);
      if ( CmpAddValueToListEx(a3, v24, v21, v32, (unsigned int *)(v9 + 36), v19) < 0 )
        break;
      ++v21;
      v20 = v42;
      if ( v21 >= v19 )
        goto LABEL_33;
    }
    v10 = *(_DWORD *)(v9 + 40);
    if ( v10 != -1 )
    {
      v26 = (*(int (__fastcall **)(int, _DWORD, int *))(a3 + 4))(a3, *(_DWORD *)(v9 + 40), &v37);
      if ( v26 )
      {
        if ( v21 )
        {
          v27 = v26 + 4 * v21;
          do
          {
            v28 = *(_DWORD *)(v27 - 4);
            v27 -= 4;
            HvFreeCell(a3, v28);
            --v21;
          }
          while ( v21 );
        }
        (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v37);
      }
    }
  }
LABEL_40:
  v16 = v31;
LABEL_41:
  v25 = 0;
LABEL_42:
  (*(void (__fastcall **)(int, int *, int))(a1 + 8))(a1, &v38, v15);
  if ( v9 )
    (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v39);
  if ( v40 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v41);
  if ( !v25 )
  {
    if ( v10 != -1 )
      HvFreeCell(a3, v10);
    if ( v34 != -1 )
      HvFreeCell(a3, v34);
    if ( v16 != -1 )
      HvFreeCell(a3, v16);
LABEL_54:
    v16 = -1;
  }
  return v16;
}
