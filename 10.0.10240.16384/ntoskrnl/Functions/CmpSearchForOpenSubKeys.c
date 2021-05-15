// CmpSearchForOpenSubKeys 
 
int __fastcall CmpSearchForOpenSubKeys(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r8
  unsigned int v7; // r3
  int v8; // r5
  int v10; // r0
  int v11; // r4
  unsigned int v13; // r10
  _DWORD *v14; // r8
  _DWORD *v15; // r5
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int v18; // r3
  unsigned int v19; // r2
  _DWORD *i; // r3
  _DWORD *v21; // r0
  int v22; // r0
  int v23; // [sp+0h] [bp-30h]
  int v24; // [sp+4h] [bp-2Ch]
  unsigned int v25; // [sp+8h] [bp-28h]
  int v26; // [sp+Ch] [bp-24h]

  v4 = *(_DWORD *)(a1 + 20);
  v7 = *(_DWORD *)(v4 + 1848);
  v8 = *(_DWORD *)(v4 + 1844);
  v24 = v8;
  v25 = v7;
  v26 = v4;
  v10 = CmpCleanUpKCBCacheTable(v4, 0, 1);
  if ( (*(_WORD *)(a1 + 106) & 4) != 0 && *(_DWORD *)a1 == 2 && a2 != 3 || *(_DWORD *)a1 == 1 && a2 != 3 )
    return 0;
  v11 = 0;
  v23 = 0;
  if ( a2 == 2 )
    return sub_7D14F4(v10);
  v13 = 0;
  if ( !v25 )
    return v11;
LABEL_9:
  while ( 2 )
  {
    v14 = *(_DWORD **)(v8 + 8);
    while ( v14 )
    {
      v15 = v14 - 3;
      v16 = *(v14 - 2);
      v17 = (v16 >> 21) & 0x3FF;
      v18 = (*(_DWORD *)(a1 + 4) >> 21) & 0x3FF;
      if ( v17 <= v18 )
        goto LABEL_21;
      v19 = v17 - v18;
      for ( i = v14 - 3; v19; --v19 )
        i = (_DWORD *)i[10];
      if ( i != (_DWORD *)a1 )
        goto LABEL_21;
      switch ( a2 )
      {
        case 0:
          return 1;
        case 4:
          *((_WORD *)v14 - 4) = v16 | 0x20;
          goto LABEL_21;
        case 1:
          if ( (v16 & 0x80) != 0 )
          {
            v23 = ++v11;
            goto LABEL_21;
          }
          if ( a4 )
          {
            if ( !CmpTryAcquireIXLockExclusive(v14 + 29) )
            {
              v21 = v14 + 29;
              goto LABEL_37;
            }
            if ( !CmpTryAcquireIXLockExclusive(v14 + 31) )
            {
              v21 = v14 + 31;
LABEL_37:
              if ( CmpSnapshotTxOwnerArray(v21, a4 + 1, a4 + 2) >= 0 )
                *a4 = -1073741267;
              ++v11;
              return v11;
            }
          }
          CmpFlushNotifiesOnKeyBodyList(v14 - 3, 1, 1);
          CmpCleanUpSubKeyInfo(v14[7]);
          v22 = v14[2];
          v14 = (_DWORD *)v14[1];
          v15[1] |= 0x20000u;
          CmpRemoveKeyHash(v22, v15 + 3);
          v15[4] = -1;
          v15[6] = -1;
          break;
        default:
          if ( a2 == 3 && CmpRehashKcbSubtree(a1, v14 - 3) == 1 )
          {
            ++v11;
            v8 = v24;
            v23 = v11;
            goto LABEL_9;
          }
LABEL_21:
          v14 = (_DWORD *)v14[1];
          break;
      }
    }
    ++v13;
    v8 = v24 + 12;
    v24 += 12;
    if ( v13 < v25 )
      continue;
    return v11;
  }
}
