// CmpKcbCacheLookup 
 
int __fastcall CmpKcbCacheLookup(int a1, int a2, int a3, signed int a4, int a5, _DWORD *a6, unsigned int **a7, int a8, _DWORD *a9, _DWORD *a10, _BYTE *a11, int a12, char a13, _BYTE *a14)
{
  int v14; // r4
  unsigned int *v16; // r7
  int v17; // r5
  int result; // r0
  unsigned int v19; // r3
  int v20; // r7
  signed int v21; // r8
  int v22; // r6
  int v23; // r9
  int v24; // r0
  unsigned int v25; // r0
  int v26; // r5
  int v27; // r4
  int v28; // r0
  unsigned int *v29; // r6
  signed int v30; // r7
  int v31; // r1
  unsigned int v32; // r2
  int v33; // r0
  int v34; // r0
  int v35; // r2
  _WORD *v36; // r2
  int v37; // r7
  _WORD *v38; // r5
  _WORD *v39; // r0
  __int64 v40; // kr00_8
  int *v41; // r6
  int v42; // r5
  int v43; // r2
  bool v44; // zf
  int v45; // r0
  int v46; // r5
  int v47; // r7
  int v48; // r3
  int v49; // r0
  int v50; // r0
  int v51; // r0
  int v53; // [sp+4h] [bp-44h]
  int v54; // [sp+8h] [bp-40h]
  unsigned int *v57; // [sp+14h] [bp-34h]
  unsigned int v58; // [sp+18h] [bp-30h]
  int v59; // [sp+1Ch] [bp-2Ch]
  __int16 v60[2]; // [sp+20h] [bp-28h] BYREF
  unsigned int v61; // [sp+24h] [bp-24h]

  v14 = 0;
  v54 = 0;
  v16 = *a7;
  *a11 = 0;
  v17 = a1;
  v53 = v16[5];
  *a14 = 0;
  v57 = v16;
  if ( !CmpReferenceKeyControlBlockUnsafe(v16) )
    return sub_7FE7E4();
LABEL_3:
  v19 = v16[1];
  v20 = a3;
  v21 = a5 - 1;
  v22 = v53;
  v23 = ((v19 >> 21) & 0x3FF) - a4 + a5 + 1;
  while ( v21 >= a4 )
  {
    --v23;
    v24 = CmpGetConvKeyAtIndex(v17, v20, v21);
    if ( v14 )
      CmpLockHashEntryExclusive(v22, v24);
    else
      CmpLockHashEntryShared(v22, v24);
    v25 = CmpGetConvKeyAtIndex(v17, v20, v21);
    v26 = *(_DWORD *)(*(_DWORD *)(v22 + 1844)
                    + 12
                    * (((101027 * (v25 ^ (v25 >> 9))) ^ ((101027 * (v25 ^ (v25 >> 9))) >> 9)) & (*(_DWORD *)(v22 + 1848)
                                                                                               - 1))
                    + 8);
    if ( v26 )
    {
      do
      {
        v27 = v26 - 12;
        v59 = v26 - 12;
        if ( ((*(_DWORD *)(v26 - 8) >> 21) & 0x3FF) == v23 )
        {
          v29 = (unsigned int *)(v26 - 12);
          v30 = v21;
          while ( CmpGetConvKeyAtIndex(a1, a3, v30) == v29[3] )
          {
            v32 = v29[11];
            v58 = v32;
            if ( (*(_DWORD *)v32 & 1) != 0 )
            {
              v33 = CmpFindKeyNameAtIndex(a2, v31, v30);
              v34 = CmpCompareCompressedName(v33, v58 + 14, *(unsigned __int16 *)(v58 + 12), 2);
            }
            else
            {
              v61 = v32 + 14;
              v60[0] = *(_WORD *)(v32 + 12);
              v60[1] = v60[0];
              v49 = CmpFindKeyNameAtIndex(a2, v31, v30);
              v34 = CmpCompareUnicodeString(v49, v60, 2);
            }
            if ( v34 )
              break;
            --v30;
            v29 = (unsigned int *)v29[10];
            if ( v30 < a4 )
            {
              v16 = v57;
              if ( v57 != v29 )
                break;
              if ( v54 )
                CmpLockKcbExclusive(v27);
              else
                CmpLockKcbShared(v27);
              v35 = (*(_DWORD *)(*(_DWORD *)(v26 + 28) + 4) >> 17) & 1;
              if ( v35 || (*(_DWORD *)(v26 - 8) & 0x20000) != 0 )
              {
                if ( !v54 )
                {
                  CmpUnlockKcb(v27);
                  v17 = a1;
                  v50 = CmpGetConvKeyAtIndex(a1, a3, v21);
                  CmpUnlockHashEntry(v53, v50);
                  v14 = 1;
                  v54 = 1;
                  goto LABEL_3;
                }
                if ( v35 )
                {
                  if ( *(_DWORD *)v27 )
                  {
                    CmpMarkKcbDeleted(v27);
                  }
                  else
                  {
                    CmpRemoveFromDelayedClose(v27);
                    CmpCleanUpKcbCacheWithLock(v27, 0);
                  }
                  CmpUnlockKcb(v27);
                  goto LABEL_10;
                }
                if ( (*(_DWORD *)(v26 - 8) & 0x20000) != 0 )
                {
                  CmpRemoveKeyControlBlock(v27, 0x20000);
                  CmpUnlockKcb(v27);
                  v51 = CmpGetConvKeyAtIndex(a1, a3, v21);
                  CmpUnlockHashEntry(v53, v51);
                  CmpDereferenceKeyControlBlock(v57);
                  return -1073741772;
                }
              }
              if ( *(_WORD *)a8 )
              {
                do
                {
                  v36 = *(_WORD **)(a8 + 4);
                  if ( *v36 != 92 )
                    break;
                  *(_DWORD *)(a8 + 4) = v36 + 1;
                  v48 = (unsigned __int16)(*(_WORD *)a8 - 2);
                  *(_WORD *)a8 = v48;
                }
                while ( v48 );
              }
              if ( a4 <= v21 )
              {
                LOWORD(v37) = *(_WORD *)a8;
                v38 = *(_WORD **)(a8 + 4);
                do
                {
                  v39 = (_WORD *)CmpFindKeyNameAtIndex(a2, a3, a4);
                  v38 += (unsigned __int16)*v39 >> 1;
                  *(_DWORD *)(a8 + 4) = v38;
                  v37 = (unsigned __int16)(v37 - *v39);
                  for ( *(_WORD *)a8 = v37; v37; *(_DWORD *)(a8 + 4) = v38 )
                  {
                    if ( *v38 != 92 )
                      break;
                    v37 = (unsigned __int16)(v37 - 2);
                    ++v38;
                    *(_WORD *)a8 = v37;
                  }
                  ++a4;
                }
                while ( a4 <= v21 );
                v27 = v59;
                v16 = v57;
              }
              CmpReferenceKeyControlBlock((unsigned int *)v27);
              CmpUnlockKcb(v27);
              CmpUnlockHashEntryByKcb(v27);
              CmpDereferenceKeyControlBlock(v16);
              v40 = *(_QWORD *)(v27 + 20);
              v41 = (int *)a7;
              *a9 = v40;
              *a7 = (unsigned int *)v27;
              *a10 = HIDWORD(v40);
              goto LABEL_32;
            }
          }
        }
        v26 = *(_DWORD *)(v26 + 4);
      }
      while ( v26 );
LABEL_10:
      v20 = a3;
      v22 = v53;
      v14 = v54;
    }
    v17 = a1;
    v28 = CmpGetConvKeyAtIndex(a1, v20, v21);
    CmpUnlockHashEntry(v22, v28);
    --v21;
  }
  v41 = (int *)a7;
LABEL_32:
  if ( (*(_DWORD *)(*v41 + 4) & 0x10) != 0 )
  {
    result = 0;
    *a6 = v21 + 1;
    return result;
  }
  CmpLockKcbShared(*v41);
  v42 = *v41;
  v44 = CmRmIsKCBVisible(*v41, a12, v43) == 0;
  v45 = v42;
  if ( v44 )
    goto LABEL_68;
  if ( CmRmIsKCBDeleted(v42, a12) )
  {
    if ( a12 )
    {
      if ( (*(_DWORD *)(*v41 + 4) & 0x20000) == 0 )
      {
        v46 = a5;
        if ( a5 == v21 + 1 )
        {
          if ( a13 )
          {
            CmpUnlockKcb(*v41);
            CmpLockTwoKcbsExclusive(*v41, *(_DWORD *)(*v41 + 40));
            if ( CmRmIsKCBDeleted(*(_DWORD *)(*v41 + 40), a12)
              || (*(_DWORD *)(*v41 + 4) & 0x20000) != 0
              || (v47 = CmpUndoDeleteKeyForTrans(), v47 < 0) )
            {
              CmpUnlockTwoKcbs(*v41, *(_DWORD *)(*v41 + 40));
              CmpDereferenceKeyControlBlock(*v41);
              return -1073741772;
            }
            *a14 = 1;
            CmpUnlockKcb(*(_DWORD *)(*v41 + 40));
            goto LABEL_36;
          }
        }
      }
    }
    v45 = *v41;
LABEL_68:
    CmpUnlockKcb(v45);
    CmpDereferenceKeyControlBlock(*v41);
    return -1073741772;
  }
  v46 = a5;
  v47 = 0;
LABEL_36:
  if ( v46 == v21 + 1 )
  {
    result = v47;
    *a11 = 1;
  }
  else
  {
    CmpUnlockKcb(*v41);
    result = v47;
  }
  *a6 = v21 + 1;
  return result;
}
