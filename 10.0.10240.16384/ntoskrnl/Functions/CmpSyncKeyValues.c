// CmpSyncKeyValues 
 
int __fastcall CmpSyncKeyValues(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v6; // r10
  unsigned int v9; // r8
  int v10; // r9
  int v12; // r1
  bool v13; // zf
  int v14; // r0
  int v15; // r9
  int v16; // r3
  int v17; // r0
  int v18; // r2
  int v19; // r1
  int v20; // r3
  int v21; // r3
  int v22; // r0
  int *v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r9
  unsigned int v27; // r9
  int *v28; // r3
  unsigned int v29; // r7
  int v30; // r1
  int v31; // r0
  int v33; // r0
  unsigned int v34; // r6
  unsigned int v35; // t1
  int v36; // [sp+8h] [bp-50h] BYREF
  int v37; // [sp+Ch] [bp-4Ch] BYREF
  int v38; // [sp+10h] [bp-48h] BYREF
  int v39; // [sp+14h] [bp-44h]
  int v40; // [sp+18h] [bp-40h]
  int v41; // [sp+1Ch] [bp-3Ch] BYREF
  int v42; // [sp+20h] [bp-38h] BYREF
  int v43; // [sp+24h] [bp-34h] BYREF
  int v44; // [sp+28h] [bp-30h]
  int *v45; // [sp+2Ch] [bp-2Ch]
  int v46; // [sp+30h] [bp-28h]
  int v47[9]; // [sp+34h] [bp-24h] BYREF

  v6 = 0;
  v42 = -1;
  v43 = -1;
  v9 = -1;
  v10 = -1;
  v40 = -1;
  v47[0] = -1;
  CmpLockTwoSecurityCachesExclusiveShared(a4, a1);
  if ( !CmpFreeKeyValues(a4, a5, a6) )
    goto LABEL_2;
  if ( *(_WORD *)(a3 + 74) )
  {
    v12 = *(_DWORD *)(a3 + 48);
    if ( v12 != -1 )
    {
      v40 = CmpCopyCell(a1, v12, a4);
      if ( v40 == -1 )
      {
LABEL_2:
        CmpUnlockTwoSecurityCaches(a4, a1);
        return v6;
      }
      v10 = v40;
      *(_WORD *)(a6 + 74) = *(_WORD *)(a3 + 74);
    }
  }
  *(_DWORD *)(a6 + 48) = v10;
  v13 = CmpFindSecurityCellCacheIndex((_DWORD *)a1, *(_DWORD *)(a3 + 44), &v41) == 0;
  v14 = a4;
  if ( v13 )
    goto LABEL_9;
  v15 = *(_DWORD *)(a6 + 44);
  v16 = *(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v41 + 4);
  *(_DWORD *)(a6 + 44) = -1;
  v17 = CmpAssignSecurityDescriptor(a4, a5, a6, (_WORD *)(v16 + 24), 0);
  if ( v17 < 0 )
  {
    *(_DWORD *)(a6 + 44) = v15;
LABEL_12:
    v14 = a4;
LABEL_9:
    CmpUnlockTwoSecurityCaches(v14, a1);
LABEL_39:
    if ( v40 != -1 )
      HvFreeCell(a4, v40);
    return v6;
  }
  v19 = *(_DWORD *)(a6 + 44);
  v20 = *(unsigned __int16 *)(a6 + 2);
  *(_DWORD *)(a6 + 44) = v15;
  v39 = v19;
  if ( (v20 & 4) == 0 || v19 == v15 )
  {
    v26 = v39;
  }
  else
  {
    v36 = -1;
    v37 = -1;
    v38 = -1;
    v44 = (*(int (__fastcall **)(int, int, int *))(a4 + 4))(a4, v19, &v36);
    v14 = a4;
    if ( !v44 )
      goto LABEL_9;
    v21 = (*(int (__fastcall **)(int, int, int *))(a4 + 4))(a4, v15, &v37);
    v45 = (int *)v21;
    v22 = a4;
    if ( !v21 )
    {
      v23 = &v36;
LABEL_18:
      (*(void (__fastcall **)(int, int *))(a4 + 8))(v22, v23);
      goto LABEL_12;
    }
    v41 = *(_DWORD *)(v21 + 8);
    v46 = (*(int (__fastcall **)(int, int, int *))(a4 + 4))(a4, v41, &v38);
    if ( !v46 )
    {
      (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v36);
      v23 = &v37;
LABEL_21:
      v22 = a4;
      goto LABEL_18;
    }
    if ( !HvpMarkCellDirty(a4, v15, 0, 0) || !HvpMarkCellDirty(a4, v41, 0, 0) )
    {
      (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v36);
      (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v37);
      v23 = &v38;
      goto LABEL_21;
    }
    v24 = v44;
    v25 = v41;
    *(_DWORD *)(v44 + 4) = v15;
    *(_DWORD *)(v24 + 8) = v25;
    v26 = v39;
    v45[2] = v39;
    *(_DWORD *)(v46 + 4) = v26;
    (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v36);
    (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v37);
    (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v38);
  }
  CmpFreeSecurityDescriptor(a4, a5, v18, v20);
  *(_DWORD *)(a6 + 44) = v26;
  CmpUnlockTwoSecurityCaches(a4, a1);
  v27 = *(_DWORD *)(a3 + 36);
  *(_DWORD *)(a6 + 40) = -1;
  *(_DWORD *)(a6 + 36) = 0;
  *(_DWORD *)(a6 + 60) = *(_DWORD *)(a3 + 60);
  *(_DWORD *)(a6 + 64) = *(_DWORD *)(a3 + 64);
  if ( !v27 )
    return 1;
  v28 = (int *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(a3 + 40), &v43);
  if ( !v28 )
    goto LABEL_39;
  v29 = 0;
  while ( 1 )
  {
    v30 = *v28;
    v45 = v28 + 1;
    v31 = CmpCopyValue(a1, v30, a4, a5 >> 31);
    v46 = v31;
    if ( v31 == -1 || !(*(int (__fastcall **)(int, int, int *))(a4 + 4))(a4, v31, v47) )
    {
      v9 = *(_DWORD *)(a6 + 40);
      goto LABEL_36;
    }
    if ( CmpAddValueToListEx(a4, v46, v29, a5 >> 31, (unsigned int *)(a6 + 36), 1) < 0 )
      break;
    ++v29;
    v28 = v45;
    if ( v29 >= v27 )
    {
      v6 = 1;
      goto LABEL_36;
    }
  }
  v9 = *(_DWORD *)(a6 + 40);
  if ( v9 != -1 )
  {
    v33 = (*(int (__fastcall **)(int, _DWORD, int *))(a4 + 4))(a4, *(_DWORD *)(a6 + 40), &v42);
    if ( v33 )
    {
      if ( v29 )
      {
        v34 = v33 + 4 * v29;
        do
        {
          v35 = *(_DWORD *)(v34 - 4);
          v34 -= 4;
          HvFreeCell(a4, v35);
          --v29;
        }
        while ( v29 );
      }
      (*(void (__fastcall **)(int, int *))(a4 + 8))(a4, &v42);
    }
  }
LABEL_36:
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v43);
  if ( !v6 )
  {
    if ( v9 != -1 )
      HvFreeCell(a4, v9);
    goto LABEL_39;
  }
  return v6;
}
