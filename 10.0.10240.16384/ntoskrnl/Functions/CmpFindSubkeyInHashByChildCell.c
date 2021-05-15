// CmpFindSubkeyInHashByChildCell 
 
int __fastcall CmpFindSubkeyInHashByChildCell(_DWORD *a1, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  int (__fastcall *v7)(int, int, int *); // r4
  unsigned int v10; // r7
  int v11; // r0
  unsigned int v13; // r0
  unsigned int v14; // r7
  _DWORD *i; // r2
  _DWORD *v16; // r4
  _DWORD *v17; // r0
  char v18[4]; // [sp+0h] [bp-38h] BYREF
  int v19; // [sp+4h] [bp-34h] BYREF
  int v20; // [sp+8h] [bp-30h]
  unsigned __int16 v21; // [sp+10h] [bp-28h] BYREF
  int v22; // [sp+14h] [bp-24h]

  v19 = -1;
  v7 = *(int (__fastcall **)(int, int, int *))(a3 + 4);
  v20 = *(_DWORD *)(a3 + 1844);
  v10 = a1[3];
  *a5 = 0;
  v11 = v7(a3, a4, &v19);
  if ( !v11 )
    return -1073741670;
  if ( (*(_WORD *)(v11 + 2) & 0x20) != 0 )
  {
    v13 = CmpComputeHashKeyForCompressedName(v10, v11 + 76, *(unsigned __int16 *)(v11 + 72));
  }
  else
  {
    v22 = v11 + 76;
    v21 = *(_WORD *)(v11 + 72);
    v13 = CmpComputeHashKey(v10, &v21);
  }
  v14 = v13;
  (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v19);
  CmpUnlockTwoKcbs(a1, a2);
  CmpLockHashEntryShared(a1[5], v14);
  CmpLockTwoKcbsShared((unsigned int)a1, a2);
  for ( i = *(_DWORD **)(v20
                       + 12
                       * ((*(_DWORD *)(a3 + 1848) - 1) & ((101027 * (v14 ^ (v14 >> 9))) ^ ((101027 * (v14 ^ (v14 >> 9))) >> 9)))
                       + 8); i; i = (_DWORD *)i[1] )
  {
    if ( v14 == *i && a4 == i[3] && a3 == i[2] )
    {
      v16 = i - 3;
      if ( CmpIsKcbLockAllowed((unsigned int)a1, (unsigned int)(i - 3), v18) )
      {
        if ( !a2 || CmpIsKcbLockAllowed((unsigned int)a2, (unsigned int)v16, v18) )
        {
          v17 = v16;
        }
        else
        {
          CmpUnlockKcb(a2);
          CmpLockKcbShared(v16);
          v17 = a2;
        }
      }
      else
      {
        CmpUnlockKcb(a1);
        CmpLockKcbShared(v16);
        v17 = a1;
      }
      CmpLockKcbShared(v17);
      if ( CmpReferenceKeyControlBlock(v16) )
        *a5 = v16;
      CmpUnlockKcb(v16);
      break;
    }
  }
  CmpUnlockHashEntry(a1[5], v14);
  return 0;
}
