// CmpDoOpen 
 
int __fastcall CmpDoOpen(int *a1, int a2, int a3, char a4, __int16 a5, _DWORD *a6, char a7, _DWORD *a8, int *a9, int *a10, int a11, int a12, int a13, int *a14, int a15, _BYTE *a16, _BYTE *a17)
{
  int v17; // r6
  int v18; // r5
  int v19; // r6
  int v20; // r4
  int v21; // r1
  int v22; // r9
  int v23; // r4
  int v24; // r0
  int v25; // r3
  int v26; // r1
  int v27; // r3
  int v28; // r6
  int v29; // r5
  _DWORD *v30; // r9
  int v31; // r1
  unsigned int *v32; // r2
  unsigned int v33; // r3
  int v35; // r0
  int v36; // r0
  int v37; // r5
  int v38; // r0
  unsigned int v39; // r3
  int v40; // r1
  int v41; // r3
  int v42; // r8
  int v43; // r3
  int v44; // r6
  int v45; // r3
  int v46; // r0
  int v47; // r5
  int v48; // r0
  unsigned int v49; // r3
  int v50; // r0
  _DWORD *v51; // r2
  unsigned int *v52; // r2
  __int64 v53; // r0
  int v54; // r0
  int v55; // r8
  int v56; // r4
  unsigned int v57; // r0
  int v58; // r4
  int v59; // r1
  int v60; // r5
  int v61; // [sp+4h] [bp-5Ch]
  int v62; // [sp+8h] [bp-58h]
  int v63; // [sp+Ch] [bp-54h]
  int v64; // [sp+10h] [bp-50h]
  int v65; // [sp+14h] [bp-4Ch]
  char v66[4]; // [sp+18h] [bp-48h] BYREF
  int v67; // [sp+1Ch] [bp-44h] BYREF
  _DWORD v68[2]; // [sp+20h] [bp-40h] BYREF
  __int64 v69; // [sp+28h] [bp-38h] BYREF
  int v70; // [sp+30h] [bp-30h] BYREF
  int v71; // [sp+34h] [bp-2Ch] BYREF
  int v72; // [sp+38h] [bp-28h] BYREF
  int *v73; // [sp+3Ch] [bp-24h] BYREF

  v17 = *a1;
  v72 = a4;
  v73 = a1;
  v67 = v17;
  v68[0] = -1;
  LODWORD(v69) = a3;
  v70 = a2;
  if ( a16 )
    *a16 = 0;
  if ( a17 )
    *a17 = 0;
  if ( CmpIsHiveLoadingOnOtherThread(v17) )
    return -1073741772;
  if ( (*a6 & 1) != 0 )
  {
    if ( (*a6 & 2) != 0 )
      return -1073741790;
    if ( (a6[5] & 2) != 0 )
      return sub_7FCEB0(2);
    a6[7] = 2;
  }
  v18 = 260;
  v71 = a7 & 4;
  if ( (a7 & 4) == 0 )
  {
    v35 = (*(int (__fastcall **)(int))(v17 + 4))(v17);
    if ( v35 )
    {
      if ( (*(_WORD *)(v35 + 2) & 0x10) == 0 || (a5 & 0x100) != 0 )
      {
        (*(void (__fastcall **)(int, _DWORD *, int))(v17 + 8))(v17, v68, 256);
        v36 = CmpCreateKeyControlBlock(v17, v70, *a10, 2, a11);
        v19 = v36;
        if ( v36 )
        {
          CmpUnlockAndLockKcbs(a8, 0, v36, 0);
          if ( (*a6 & 0x20) != 0 )
          {
            *(_DWORD *)(v19 + 52) = a6[10];
            *(_WORD *)(v19 + 106) |= 0x40u;
          }
          *a10 = v19;
          v20 = v67;
          goto LABEL_11;
        }
      }
      else
      {
        (*(void (__fastcall **)(int, _DWORD *, int))(v17 + 8))(v17, v68, 256);
        v46 = CmpCreateKeyControlBlock(v17, v70, *a10, 2, a11);
        v47 = v46;
        if ( v46 )
        {
          CmpUnlockAndLockKcbs(a8, *a10, v46, 0);
          if ( a16 )
            *a16 = 1;
          else
            CmpDereferenceKeyControlBlockWithLock(v47, 0);
          *a10 = v47;
          return 260;
        }
      }
    }
    return -1073741670;
  }
  v19 = *a10;
  if ( (*(_WORD *)(*a10 + 106) & 0x10) == 0 || (a5 & 0x100) != 0 )
  {
    v20 = v67;
    goto LABEL_10;
  }
  if ( (*(_DWORD *)(v19 + 4) & 8) == 0 )
    return 260;
  v19 = *(_DWORD *)(v19 + 56);
  CmpUnlockTwoKcbs(*a8, a8[1]);
  *a8 = 0;
  a8[1] = 0;
  if ( *a9 != -1 )
  {
    CmpUnlockHashEntryByIndex(v67, *a9);
    *a9 = -1;
  }
  v38 = *(_DWORD *)(v19 + 20);
  v39 = 101027 * (*(_DWORD *)(v19 + 12) ^ (*(_DWORD *)(v19 + 12) >> 9));
  v40 = (v39 ^ (v39 >> 9)) & (*(_DWORD *)(v38 + 1848) - 1);
  *a9 = v40;
  CmpLockHashEntryByIndexExclusive(v38, v40);
  CmpUnlockAndLockKcbs(a8, 0, v19, 2);
  if ( a13 && *(_DWORD *)(*a10 + 20) != *(_DWORD *)(v19 + 20) || (*(_DWORD *)(v19 + 4) & 0x20000) != 0 )
  {
    v70 = -1;
    CmpUnlockAndLockKcbs(a8, v19, 0, 0);
    if ( *a9 != -1 )
    {
      CmpUnlockHashEntryByIndex(*(_DWORD *)(v19 + 20), *a9);
      *a9 = -1;
    }
    v48 = *(_DWORD *)(*a10 + 20);
    v49 = 101027 * (*(_DWORD *)(*a10 + 12) ^ (*(_DWORD *)(*a10 + 12) >> 9));
    *a9 = (v49 ^ (v49 >> 9)) & (*(_DWORD *)(v48 + 1848) - 1);
    CmpLockHashEntryByIndexShared(v48);
    CmpUnlockAndLockKcbs(a8, 0, *a10, 1);
    CmpCleanUpKcbValueCache(*a10);
    v50 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(*a10 + 20) + 4))(
            *(_DWORD *)(*a10 + 20),
            *(_DWORD *)(*a10 + 24),
            &v70);
    if ( v50 )
    {
      v51 = (_DWORD *)*a10;
      v51[13] = *(_DWORD *)(v50 + 36);
      v51[14] = *(_DWORD *)(v50 + 40);
      (*(void (__fastcall **)(_DWORD, int *))(v51[5] + 8))(v51[5], &v70);
      return v18;
    }
    *a10 = v19;
    return -1073741670;
  }
  v41 = (int)v73;
  *a10 = v19;
  v20 = *(_DWORD *)(v19 + 20);
  *(_DWORD *)v41 = v20;
  LOWORD(v41) = *(_WORD *)(v19 + 106);
  v67 = v20;
  if ( (v41 & 0x10) != 0 )
    return v18;
LABEL_10:
  if ( !CmpReferenceKeyControlBlock(v19) )
    return -1073741670;
LABEL_11:
  if ( !CmpOKToFollowLink(a12, v20) )
  {
    v22 = -1073741790;
    goto LABEL_77;
  }
  if ( CmpVEEnabled )
  {
    if ( (*(_WORD *)(v19 + 106) & 0x200) != 0 )
    {
      v52 = *(unsigned int **)(v19 + 4);
      if ( ((unsigned int)v52 & 0x7FE00000) > 0xA00000
        && !CmpIsSystemEntity(a6 + 3, v21, v52, (unsigned int)v52 & 0x7FE00000)
        && (!CmpVEEnabled || (*(_WORD *)(v19 + 106) & 0x100) == 0) )
      {
        LOWORD(v69) = 0;
        v53 = *(_QWORD *)a8;
        *(_DWORD *)((char *)&v69 + 2) = 0;
        HIWORD(v69) = 0;
        v54 = CmpUnlockTwoKcbs(v53, HIDWORD(v53));
        *a8 = 0;
        a8[1] = 0;
        if ( *a9 != -1 )
        {
          v54 = CmpUnlockHashEntryByIndex(v20, *a9);
          *a9 = -1;
        }
        CmpUnlockRegistry(v54);
        CmpLockRegistryExclusive();
        if ( (*(_DWORD *)(v19 + 4) & 0x20000) != 0 )
        {
          CmpDereferenceKeyControlBlock(v19);
          return -1073741772;
        }
        v22 = CmVirtualKCBToRealPath(v19, &v69);
        if ( v22 >= 0 )
        {
          *a6 |= 8u;
          v55 = CmpBlockHiveWrites(0, 16, &v73);
          if ( v55 >= 0 )
          {
            v56 = CmpFindPathByName(0, &v69, 0, &v71, &v72);
            CmpUnblockHiveWrites(0, 16, v73);
            v55 = 260;
            if ( v56 )
            {
              if ( a15 )
              {
                v57 = *(_DWORD *)(a15 + 4);
                if ( v57 )
                  ExFreePoolWithTag(v57);
                *(_QWORD *)a15 = v69;
              }
              else
              {
                v55 = -1073741670;
              }
            }
            else
            {
              v58 = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD *))(*(_DWORD *)(v19 + 20) + 4))(
                      *(_DWORD *)(v19 + 20),
                      *(_DWORD *)(v19 + 24),
                      v68);
              if ( v58 )
              {
                if ( HvpMarkCellDirty(v67, v70, 1, 0) )
                {
                  *(_WORD *)(v58 + 2) |= 0x100u;
                  *(_WORD *)(v19 + 106) |= 0x100u;
                }
                else
                {
                  v55 = -1073741443;
                }
                (*(void (__fastcall **)(_DWORD, _DWORD *))(*(_DWORD *)(v19 + 20) + 8))(*(_DWORD *)(v19 + 20), v68);
              }
              else
              {
                v55 = -1073741670;
              }
            }
          }
          CmpDereferenceKeyControlBlock(v19);
          if ( v55 == 260 && a17 )
            *a17 = 1;
          return v55;
        }
        goto LABEL_77;
      }
    }
  }
  v66[0] = 1;
  v22 = ObCreateObjectEx(v72, CmKeyObjectType, 0, v72);
  if ( v22 < 0 )
  {
LABEL_77:
    CmpDereferenceKeyControlBlockWithLock(v19, 0);
    return v22;
  }
  v23 = *a14;
  if ( a13 )
    v24 = *(_DWORD *)(a13 + 24);
  else
    v24 = 0;
  *(_DWORD *)(v23 + 28) = v24;
  if ( !a13 || *(_DWORD *)(a13 + 24) )
    v25 = 0;
  else
    v25 = a13 + 40;
  *(_DWORD *)(v23 + 32) = v25;
  *(_WORD *)(v23 + 24) = 0;
  *(_WORD *)(v23 + 26) = a6[4];
  if ( v24 )
  {
    v18 = CmReferenceKtmTransaction();
    if ( v18 < 0 )
    {
      *(_DWORD *)(v23 + 28) = 0;
      if ( (*(_WORD *)(v19 + 106) & 0x40) != 0 )
      {
        *(_DWORD *)v23 = *(_DWORD *)(v19 + 52);
        *(_DWORD *)(v23 + 4) = v19;
      }
      else
      {
        *(_DWORD *)v23 = 1803104306;
        *(_DWORD *)(v23 + 4) = v19;
        *(_DWORD *)(v23 + 8) = 0;
        *(_DWORD *)(v23 + 12) = PsGetCurrentThreadProcessId();
        *(_DWORD *)(v23 + 36) = v23 + 36;
        *(_DWORD *)(v23 + 40) = v23 + 36;
        if ( v71 )
          v59 = 1;
        else
          v59 = 2;
        EnlistKeyBodyWithKCB(v23, v59);
      }
      ObDereferenceObjectDeferDelete(*a14);
      return v18;
    }
  }
  if ( (*(_WORD *)(v19 + 106) & 0x40) != 0 )
  {
    *(_DWORD *)v23 = *(_DWORD *)(v19 + 52);
    *(_DWORD *)(v23 + 4) = v19;
    *(_DWORD *)(v23 + 36) = v23 + 36;
    *(_DWORD *)(v23 + 40) = v23 + 36;
    a6[10] = *(_DWORD *)v23;
    return 1073741846;
  }
  *(_DWORD *)v23 = 1803104306;
  *(_DWORD *)(v23 + 4) = v19;
  *(_DWORD *)(v23 + 8) = 0;
  *(_DWORD *)(v23 + 12) = PsGetCurrentThreadProcessId();
  *(_DWORD *)(v23 + 36) = v23 + 36;
  *(_DWORD *)(v23 + 40) = v23 + 36;
  if ( v71 )
    v26 = 1;
  else
    v26 = 2;
  EnlistKeyBodyWithKCB(v23, v26);
  v27 = a6[5];
  v18 = 0;
  v67 = 0;
  if ( (v27 & 4) != 0 )
  {
    v42 = v69;
    *(_DWORD *)(v69 + 16) = 0;
    *(_DWORD *)(v42 + 20) = 0;
    v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v44 = *(char *)(v43 + 346);
    if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v44, v43) )
    {
      v45 = *(_DWORD *)(v42 + 20) | 0x1020019;
      *(_DWORD *)(v42 + 20) = v45;
    }
    if ( SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v44, v45) )
      *(_DWORD *)(v42 + 20) |= 0x10F0026u;
    if ( *(_DWORD *)(v42 + 20) )
      return v18;
    ObDereferenceObjectDeferDelete(*a14);
    return -1073741790;
  }
  v28 = v72;
  v29 = v69;
  v30 = *(_DWORD **)(v23 + 4);
  if ( CmpCheckKeyBodyAccess(v23, a13, v69, v72, &v67, 44, 0, 0, a14, v66) )
    return v67;
  if ( !CmpIsSystemEntity(a6 + 3, v31, v32, v33) && (v30[26] & 0x40) == 0 && (*(_DWORD *)(v30[5] + 3228) & 0x10) != 0 )
  {
    v37 = CmpCheckAdminAccess(*(_DWORD *)(v29 + 16), v30[12] + 24, v66);
    v67 = v37;
    if ( v37 < 0 )
      goto LABEL_40;
    if ( v66[0] != 1 )
    {
      v37 = -1073741790;
      goto LABEL_40;
    }
    v60 = v69;
    CmpConvertToMaximumAllowed(v69);
    if ( CmpCheckKeyBodyAccess(v23, a13, v60, v28, &v67, v61, v62, v63, v64, v65) )
      return v67;
  }
  v37 = v67;
LABEL_40:
  if ( (*a6 & 2) != 0 )
  {
    v30[1] |= 0x20000u;
    v30[4] = -1;
    v30[6] = -1;
  }
  if ( (v30[1] & 0x20000) == 0
    && *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1
    && MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74))
    && (*(_DWORD *)(v69 + 16) & 0xD0026) != 0 )
  {
    if ( CmpCheckWrpKeyAccess(v30) )
      CmpPublishEventForPcaResolver(v30);
  }
  ObDereferenceObjectDeferDelete(*a14);
  return v37;
}
