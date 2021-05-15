// CmpDoCreate 
 
int __fastcall CmpDoCreate(int a1, int a2, _DWORD *a3, unsigned __int16 *a4, char a5, int *a6, int a7, int a8, int a9, int *a10, int *a11, int a12)
{
  int v13; // r4
  int v16; // r10
  int *v17; // r8
  int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r3
  int v21; // r0
  int v22; // r0
  _DWORD *v23; // r4
  int v24; // r4
  int v25; // r0
  int v26; // r6
  int v27; // r0
  int v28; // r4
  int v29; // r8
  int v30; // r6
  int v31; // r8
  __int64 v32; // r1
  unsigned __int16 *v33; // r1
  unsigned int v34; // r2
  unsigned int v35; // r2
  int *v36; // r1
  int v37; // r0
  __int16 v38; // r2
  int v39; // r0
  unsigned int v40; // r0
  int v41; // r3
  int v42; // r8
  int v43; // r3
  char v44[4]; // [sp+28h] [bp-50h] BYREF
  unsigned __int16 *v45; // [sp+2Ch] [bp-4Ch]
  int v46; // [sp+30h] [bp-48h] BYREF
  int v47; // [sp+34h] [bp-44h] BYREF
  int v48; // [sp+38h] [bp-40h] BYREF
  int v49; // [sp+3Ch] [bp-3Ch] BYREF
  int v50[2]; // [sp+40h] [bp-38h] BYREF
  __int64 v51; // [sp+48h] [bp-30h] BYREF
  __int64 v52[5]; // [sp+50h] [bp-28h] BYREF

  v45 = a4;
  LODWORD(v52[0]) = a3;
  v13 = *a6;
  v50[0] = -1;
  v46 = -1;
  v47 = a2;
  v49 = 0;
  if ( (v13 & 1) != 0 )
  {
    if ( (a6[5] & 4) != 0 )
      return sub_805474();
    a6[7] = 1;
  }
  if ( (a6[5] & 2) != 0 )
    v16 = 32;
  else
    v16 = 0;
  v17 = a11;
  if ( !CmpVEEnabled
    || (*(_WORD *)(a8 + 106) & 0x200) != 0
    || CmpIsMasterHive(a8)
    || CmpIsSystemEntity(a6 + 3, v18, v19, v20) )
  {
    goto LABEL_10;
  }
  v51 = 0i64;
  v44[0] = 0;
  if ( (*(_WORD *)(a8 + 106) & 0x80) != 0 && CmpReparseToVirtualPath(a8) )
  {
    RtlFreeAnsiString(&v51);
LABEL_69:
    v39 = CmRealKCBToVirtualPath(a8, v45, &v51);
    if ( v39 >= 0 )
    {
      v40 = *(_DWORD *)(a12 + 4);
      if ( v40 )
        ExFreePoolWithTag(v40);
      v39 = 260;
      *(_QWORD *)a12 = v51;
      *a6 |= 8u;
    }
    return v39;
  }
  if ( (*(_DWORD *)(a8 + 104) & 0x20) != 0 || CmpDoAccessCheckOnKCB(a8, *a11, v16 | 4, a5) )
  {
LABEL_10:
    if ( !CmpOKToFollowLink(a9, a1) )
      return -1073741790;
    CmpLockHiveFlusherShared(a1);
    if ( (*(_DWORD *)(a8 + 4) & 0x80) != 0 || (*(_DWORD *)(a1 + 3228) & 0x20) != 0 && a3[11] )
    {
LABEL_40:
      v28 = -1073741790;
      goto LABEL_37;
    }
    if ( CmRmIsKCBDeleted(a8, *a11) == 1 )
    {
      v28 = -1073741772;
      goto LABEL_37;
    }
    v21 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v47, &v46);
    if ( !v21 )
      goto LABEL_77;
    CmpFindSubKeyByNameWithStatus(a1, v21, (int)v45, &v51);
    if ( (_DWORD)v51 != -1 )
      goto LABEL_97;
    LODWORD(v51) = 0;
    while ( 1 )
    {
      v22 = CmListGetPrevElement(a8 + 108, &v51);
      if ( !v22 )
        break;
      if ( *(_DWORD *)(v22 + 36) == 1 )
      {
        v23 = *(_DWORD **)(v22 + 48);
        if ( (v23[1] & 0x20000) == 0 && !CmpDoCompareKeyName(v23[5], v45, v23[6]) )
          goto LABEL_19;
      }
    }
    v23 = 0;
LABEL_19:
    if ( v23 )
    {
LABEL_97:
      v28 = 260;
      v36 = &v46;
      *a6 &= 0xFFFFFFF7;
      goto LABEL_36;
    }
    v24 = CmGetKCBCacheSecurity(a8, *a11);
    LODWORD(v51) = v24;
    if ( v47 < 0 && (a6[5] & 1) == 0 && (!*a11 || !*(_DWORD *)(a8 + 124)) )
    {
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v46);
      v28 = -1073741439;
      goto LABEL_37;
    }
    v25 = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v46);
    if ( (*(_WORD *)(a8 + 106) & 0x10) != 0 )
      goto LABEL_40;
    if ( v49 == 1 )
    {
      a3[4] = 0;
      a3[5] = 0;
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v42 = *(char *)(v41 + 346);
      if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v42, v41) )
      {
        v43 = a3[5] | 0x1020019;
        a3[5] = v43;
      }
      if ( SeSinglePrivilegeCheck(SeRestorePrivilege, dword_922B9C, v42, v43) )
        a3[5] |= 0x10F0006u;
      if ( a3[5] )
      {
        v17 = a11;
        v24 = v51;
LABEL_24:
        if ( !HvpMarkCellDirty(a1, v47, 0, 0) )
        {
          v28 = -1073741443;
          goto LABEL_37;
        }
        v26 = v47;
        v27 = CmpDoCreateChild(a1, v47, v24 + 24, v52[0], v45, a5, a6, a7, a8, 0, &v48, a10, *v17);
        v28 = v27;
        if ( v27 < 0 || v27 == 260 )
          goto LABEL_37;
        v47 = -1;
        v29 = *a10;
        if ( *a11 || CmpAddSubKeyEx(a1, v26, v48, 0) )
        {
          v30 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v26, &v47);
          if ( v30 )
          {
            v31 = *a10;
            CmpCleanUpSubKeyInfo(*(_DWORD *)(*(_DWORD *)(*a10 + 4) + 40));
            KeQuerySystemTime(v52);
            v32 = v52[0];
            *(_QWORD *)(v30 + 4) = v52[0];
            *(_QWORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 4) + 40) + 88) = v32;
            v33 = v45;
            v34 = *v45;
            if ( *(unsigned __int16 *)(v30 + 52) < v34 )
            {
              *(_WORD *)(v30 + 52) = v34;
              *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 4) + 40) + 96) = *v33;
            }
            v35 = a6[1];
            if ( *(_DWORD *)(v30 + 56) < v35 )
              *(_DWORD *)(v30 + 56) = v35;
            if ( (a6[5] & 2) == 0 )
              goto LABEL_35;
            v37 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v48, v50);
            if ( v37 )
            {
              v38 = *(_WORD *)(v37 + 2) | 0x10;
              *(_WORD *)(v37 + 2) = v38;
              *(_WORD *)(*(_DWORD *)(v31 + 4) + 106) = v38;
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v50);
LABEL_35:
              v36 = &v47;
LABEL_36:
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v36);
LABEL_37:
              CmpUnlockHiveFlusher(a1);
              return v28;
            }
            CmpMarkKcbDeleted(*(_DWORD *)(v31 + 4));
            CmpUnlockAndLockKcbs(a7, *(_DWORD **)(v31 + 4), 0, 0);
            ObDereferenceObjectDeferDelete(*a10);
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v47);
LABEL_77:
            v28 = -1073741670;
            goto LABEL_37;
          }
        }
        else
        {
          CmpFreeKeyByCell(a1, v48, 0);
        }
        CmpMarkKcbDeleted(*(_DWORD *)(v29 + 4));
        CmpUnlockAndLockKcbs(a7, *(_DWORD **)(v29 + 4), 0, 0);
        ObDereferenceObjectDeferDelete(*a10);
        goto LABEL_77;
      }
      v28 = -1073741790;
    }
    else
    {
      if ( CmpCheckCreateAccess(v25, v24 + 24, a3, a5, v16, &v51) )
        goto LABEL_24;
      v28 = v51;
    }
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) == 1
      && MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74))
      && CmpCheckWrpKeyAccess(a8) )
    {
      CmpPublishEventForPcaResolver(a8);
    }
    goto LABEL_37;
  }
  if ( !CmpDoAccessCheckOnKCB(a8, *a11, 131097, a5) )
    return -1073741790;
  v39 = CmpCheckAdminAccess(4, *(_DWORD *)(a8 + 48) + 24, v44);
  if ( v39 < 0 )
    return v39;
  if ( !v44[0] )
    return -1073741790;
  v39 = CmpReplicateKeyToVirtual(a8, &v49);
  v28 = -1073741739;
  if ( v39 != -1073741739 )
  {
    if ( v39 < 0 )
      return v39;
    v44[0] = 0;
    v39 = CmpExamineSaclForAuditEvent(*(_DWORD *)(a8 + 48) + 24, v44);
    if ( v39 < 0 )
      return v39;
    if ( v44[0] )
      v39 = CmpReportAuditVirtualizationEvent(a8);
    if ( v39 < 0 )
      return v39;
    a6[14] |= 2u;
    a6[16] = v49;
    goto LABEL_69;
  }
  RtlFreeAnsiString(&v51);
  return v28;
}
