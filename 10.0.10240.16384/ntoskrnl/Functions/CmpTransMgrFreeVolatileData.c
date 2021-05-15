// CmpTransMgrFreeVolatileData 
 
int __fastcall CmpTransMgrFreeVolatileData(int result, int a2, int a3, int a4)
{
  int v4; // r8
  _DWORD *v5; // r9
  _DWORD *v6; // r5
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r1
  int v10; // r0
  int v11; // r3
  int v12; // r7
  int v13; // r4
  int v14; // r6
  int v15; // r3
  unsigned int v16; // r1
  int v17; // r4
  unsigned int v18; // r6
  int v19; // r7
  unsigned int v20; // r1
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // [sp+0h] [bp-28h] BYREF
  int v25; // [sp+4h] [bp-24h]
  int v26; // [sp+8h] [bp-20h]

  v24 = a2;
  v26 = a4;
  v25 = a2;
  v4 = result;
  v5 = (_DWORD *)(result + 8);
  while ( (_DWORD *)*v5 != v5 )
  {
    v6 = *(_DWORD **)(v4 + 12);
    if ( !*(_DWORD *)(v6[6] + 20) )
      goto LABEL_24;
    CmpLockRegistryExclusive();
    v8 = v6[9];
    if ( !v8 )
    {
      v16 = v6[12];
      if ( v16 && v16 != -1 )
        CmpFreeKeyByCell(*(_DWORD *)(v6[6] + 20), v16, 0);
      goto LABEL_23;
    }
    if ( v8 > 3 )
    {
      if ( v8 <= 5 )
      {
        CmpFreeValue(*(_DWORD *)(v6[6] + 20), v6[13], v7, v6[6]);
        goto LABEL_23;
      }
      if ( v8 == 9 )
      {
        v11 = v6[6];
        v24 = -1;
        v12 = v6[12];
        v13 = *(_DWORD *)(v11 + 20);
        v14 = (*(int (__fastcall **)(int, int, int *))(v13 + 4))(v13, v12, &v24);
        if ( !v14 )
          goto LABEL_23;
        if ( !HvpMarkCellDirty(v13, v12, 1, 0) )
          goto LABEL_18;
        v15 = *(_DWORD *)(v14 + 12);
        if ( v15 != 1 )
        {
          *(_DWORD *)(v14 + 12) = v15 - 1;
LABEL_18:
          (*(void (__fastcall **)(int, int *))(v13 + 8))(v13, &v24);
          goto LABEL_23;
        }
        (*(void (__fastcall **)(int, int *))(v13 + 8))(v13, &v24);
        CmpRemoveSecurityCellList(v13, v12);
        v9 = v12;
        v10 = v13;
      }
      else
      {
        if ( v8 != 12 )
          goto LABEL_23;
        v9 = v6[13];
        if ( !v9 || v9 == -1 )
          goto LABEL_23;
        v10 = *(_DWORD *)(v6[6] + 20);
      }
      HvFreeCell(v10, v9);
    }
LABEL_23:
    CmpUnlockRegistry();
LABEL_24:
    CmpLockRegistry();
    v17 = v6[6];
    v18 = *(_DWORD *)(v17 + 12);
    v19 = *(_DWORD *)(v17 + 20);
    CmpLockHashEntryExclusive(v19, v18);
    CmpLockKcbExclusive((_DWORD *)v17);
    if ( (*(_DWORD *)(v17 + 4) & 0x20000) == 0 )
    {
      if ( *(_DWORD *)(v17 + 152) == v4 )
      {
        v20 = *(_DWORD *)(v17 + 148);
        if ( v20 != -1 )
        {
          HvFreeCell(*(_DWORD *)(v17 + 20), v20);
          *(_DWORD *)(v17 + 144) = 0;
          *(_DWORD *)(v17 + 148) = -1;
        }
        *(_DWORD *)(v17 + 152) = 0;
      }
      if ( CmEqualTrans(*(_DWORD *)(v17 + 124), v4) )
      {
        if ( v25 == 8 && (*(_DWORD *)(v17 + 4) & 0x20000) == 0 )
        {
          CmpFlushNotifiesOnKeyBodyList(v17);
          *(_WORD *)(v17 + 4) |= 0x20u;
          CmpMarkKcbDeleted((_DWORD *)v17);
          *(_DWORD *)(v17 + 24) = -1;
        }
        *(_DWORD *)(v17 + 124) = 0;
      }
      if ( *(_DWORD *)(v17 + 24) != -1 )
      {
        v23 = *(_DWORD *)(v17 + 20);
        if ( v23 )
          CmpRebuildKcbCache(v17, v21, v22, v23);
      }
    }
    CmpRundownUnitOfWork(v6);
    CmpFreeUnitOfWork(v6);
    CmpUnlockKcb((_DWORD *)v17);
    CmpUnlockHashEntry(v19, v18);
    CmpUnlockRegistry();
  }
  return result;
}
