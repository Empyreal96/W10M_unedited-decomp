// CmEnumerateKey 
 
int __fastcall CmEnumerateKey(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // r4
  _DWORD *v10; // r10
  int v13; // r5
  int v14; // r4
  int v15; // r6
  int v16; // r0
  int v17; // r7
  int v18; // r6
  int v19; // r7
  int v20; // r1
  _DWORD *v21; // r0
  int v22; // [sp+14h] [bp-34h] BYREF
  int v23; // [sp+18h] [bp-30h] BYREF
  int v24; // [sp+1Ch] [bp-2Ch]
  int v25; // [sp+20h] [bp-28h]

  v25 = a4;
  v8 = a1[7];
  v22 = -1;
  v10 = 0;
  v23 = 0;
  v24 = a3;
  if ( v8 || a1[8] )
    return sub_80483C();
  CmpLockRegistry(a1, a2);
  v13 = a1[1];
  if ( a2 )
    v10 = *(_DWORD **)(a2 + 4);
  CmpLockTwoKcbsShared(v10, a1[1]);
  if ( CmRmIsKCBDeleted(v13, 0) == 1 )
  {
    if ( (a1[6] & 1) != 0 )
      v17 = -1073740763;
    else
      v17 = -1073741444;
    goto LABEL_21;
  }
  if ( a2 )
  {
    if ( (v10[1] & 0x20000) != 0 )
    {
      CmpUnlockTwoKcbs(v10, (_DWORD *)v13);
      CmpUnlockRegistry();
      return -1073741444;
    }
  }
  else if ( !CmpVEEnabled || (*(_WORD *)(v13 + 106) & 0x100) == 0 )
  {
    v15 = *(_DWORD *)(v13 + 24);
    v14 = *(_DWORD *)(v13 + 20);
    CmpLockHiveFlusherShared(v14);
    v16 = (*(int (__fastcall **)(int, int, int *))(v14 + 4))(v14, v15, &v22);
    if ( !v16 )
      goto LABEL_22;
    CmpUpdateKeyNodeAccessBits(v14, v16, v15);
    (*(void (__fastcall **)(int, int *))(v14 + 8))(v14, &v22);
    CmpUnlockHiveFlusher(v14);
    v17 = CmpFindSubKeyByNumberEx(v14, v15, a3, &v23, 0, 0, 0, 0);
    if ( v17 >= 0 )
      goto LABEL_12;
LABEL_21:
    CmpUnlockTwoKcbs(v10, (_DWORD *)v13);
    goto LABEL_15;
  }
  if ( a2 )
  {
    v20 = v13;
    v21 = v10;
  }
  else
  {
    v20 = 0;
    v21 = (_DWORD *)v13;
  }
  v17 = CmpFindSubKeyByNumberFromMergedView(v21, v20, a3, 0);
  if ( v17 < 0 )
    goto LABEL_21;
  v14 = v24;
LABEL_12:
  v18 = v23;
  if ( v23 != -1 )
  {
    CmpLockHiveFlusherShared(v14);
    v19 = (*(int (__fastcall **)(int, int, int *))(v14 + 4))(v14, v18, &v22);
    if ( v19 )
    {
      CmpUpdateKeyNodeAccessBits(v14, v19, v18);
      CmpUnlockHiveFlusher(v14);
      v17 = CmpQueryKeyDataFromNode(v14, v19, v25, a5, a6, a7, 0, 0);
      (*(void (__fastcall **)(int, int *))(v14 + 8))(v14, &v22);
      CmpUnlockTwoKcbs(v10, (_DWORD *)v13);
LABEL_15:
      CmpUnlockRegistry();
      return v17;
    }
LABEL_22:
    CmpUnlockHiveFlusher(v14);
    CmpUnlockTwoKcbs(v10, (_DWORD *)v13);
    CmpUnlockRegistry();
    return -1073741670;
  }
  CmpUnlockTwoKcbs(v10, (_DWORD *)v13);
  CmpUnlockRegistry();
  return -2147483622;
}
