// CmSaveMergedKeys 
 
int __fastcall CmSaveMergedKeys(_DWORD *a1, _DWORD *a2, int a3)
{
  char v5; // r9
  int v6; // r5
  _DWORD *v7; // r8
  int v8; // r5
  unsigned int v9; // r0
  int v10; // r10
  int v11; // r4
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r10
  unsigned int *v17; // r0
  int v18; // r1
  unsigned int *v19; // r10
  int v21; // [sp+4h] [bp-64h]
  int v22; // [sp+10h] [bp-58h]
  _DWORD *v23; // [sp+10h] [bp-58h]
  int v24; // [sp+14h] [bp-54h] BYREF
  int v25; // [sp+18h] [bp-50h] BYREF
  unsigned int v26; // [sp+1Ch] [bp-4Ch]
  int v27; // [sp+20h] [bp-48h]
  int v28; // [sp+24h] [bp-44h]
  char v29[16]; // [sp+28h] [bp-40h] BYREF
  char v30[48]; // [sp+38h] [bp-30h] BYREF

  v24 = -1;
  v25 = -1;
  v28 = a3;
  v5 = 0;
  v6 = CmpUuidCreate((int)v30);
  if ( v6 >= 0 )
  {
    v6 = CmpUuidCreate((int)v29);
    if ( v6 >= 0 )
    {
      v7 = (_DWORD *)a1[5];
      v8 = a2[5];
      if ( (_DWORD *)v8 == v7 )
        return -1073741811;
      CmpLockRegistry();
      v9 = CmpLockTwoKcbsShared((unsigned int)a1, a2);
      if ( (a1[1] & 0x20000) != 0 || (a2[1] & 0x20000) != 0 )
      {
        CmpUnlockTwoKcbs(a1, a2);
        CmpUnlockRegistry();
        return -1073741444;
      }
      v10 = a1[6];
      v27 = a2[6];
      v22 = v10;
      if ( (v7[23] & 2) != 0 && v7[11] || (*(_DWORD *)(v8 + 92) & 2) != 0 && *(_DWORD *)(v8 + 44) )
      {
        CmpUnlockTwoKcbs(a1, a2);
        CmpUnlockRegistry();
        return -1073741811;
      }
      v11 = CmpCreateTemporaryHive(v9, v30, v29);
      if ( v11 )
      {
        CmpBlockTwoHiveWrites((_DWORD *)v8, v7, 0);
        CmpLockHiveFlusherExclusive(v11, v12, v13, v14);
        v5 = 7;
        v15 = CmpCopyKeyPartial((int)v7, v10, v11, 0xFFFFFFFF, 6, v21, 0);
        v16 = v15;
        v26 = v15;
        if ( v15 != -1 )
        {
          *(_DWORD *)(*(_DWORD *)(v11 + 32) + 36) = v15;
          if ( CmpCopySyncTree((int)v7, v22, v11, v15) )
          {
            CmpUnlockHiveFlusher((int)v7);
            v5 = 5;
            v23 = (_DWORD *)(*(int (__fastcall **)(int, int, int *))(v8 + 4))(v8, v27, &v24);
            if ( v23 )
            {
              v17 = (unsigned int *)(*(int (__fastcall **)(int, int, int *))(v11 + 4))(v11, v16, &v25);
              v19 = v17;
              if ( v17 )
              {
                if ( CmpMergeKeyValues(v8, v18, v23, v11, v26, v17) )
                {
                  (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v24);
                  v23 = 0;
                  (*(void (__fastcall **)(int, int *))(v11 + 8))(v11, &v25);
                  v19 = 0;
                  if ( CmpCopySyncTree(v8, v27, v11, v26) )
                  {
                    CmpUnlockHiveFlusher(v8);
                    CmpUnlockHiveFlusher(v11);
                    CmpUnlockTwoKcbs(a1, a2);
                    CmpUnlockRegistry();
                    *(_DWORD *)(v11 + 1784) = v28;
                    v6 = HvWriteExternal((_DWORD *)v11);
                    *(_DWORD *)(v11 + 1784) = 0;
                    CmpDestroyTemporaryHive(v11);
                    return v6;
                  }
                }
              }
              if ( v23 )
                (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, &v24);
              if ( v19 )
                (*(void (__fastcall **)(int, int *))(v11 + 8))(v11, &v25);
            }
          }
        }
      }
      if ( (v5 & 4) != 0 )
        CmpUnlockHiveFlusher(v8);
      if ( (v5 & 2) != 0 )
        CmpUnlockHiveFlusher((int)v7);
      if ( (v5 & 1) != 0 )
        CmpUnlockHiveFlusher(v11);
      CmpUnlockTwoKcbs(a1, a2);
      CmpUnlockRegistry();
      if ( v11 )
        CmpDestroyTemporaryHive(v11);
      v6 = -1073741670;
    }
  }
  return v6;
}
