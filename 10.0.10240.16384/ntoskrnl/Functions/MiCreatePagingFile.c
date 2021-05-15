// MiCreatePagingFile 
 
int __fastcall MiCreatePagingFile(int *a1, int a2, unsigned int *a3, int a4, int a5)
{
  int v5; // r9
  int v9; // r4
  unsigned __int64 v10; // r2
  int v11; // r6
  _DWORD *v12; // r0
  unsigned int v13; // r5
  unsigned int v14; // r2
  int v15; // r1
  int v16; // r5
  int v17; // r4
  int v18; // r4
  int v19; // r0
  int v20; // r8
  _DWORD *v21; // r8
  int v22; // r3
  int v23; // r0
  int v24; // r0
  unsigned int v25; // r5
  int v26; // r3
  int v27; // r5
  int v28; // r10
  unsigned int v29; // r1
  unsigned int v30; // lr
  unsigned int v31; // r10
  __int16 *v32; // r0
  int v33; // r1
  int v34; // r9
  unsigned int v35; // r1
  unsigned int v36; // r10
  unsigned int v37; // r2
  int v38; // r9
  _DWORD *v39; // r0
  int v40; // r3
  unsigned int v41; // r0
  int v42; // r0
  int v43; // r2
  int v44; // r3
  int v46; // [sp+28h] [bp-A0h]
  int v47; // [sp+2Ch] [bp-9Ch] BYREF
  __int64 v48; // [sp+30h] [bp-98h] BYREF
  unsigned int v49; // [sp+38h] [bp-90h]
  int v50; // [sp+3Ch] [bp-8Ch]
  _DWORD *v51; // [sp+40h] [bp-88h] BYREF
  int v52; // [sp+44h] [bp-84h]
  int v53; // [sp+48h] [bp-80h] BYREF
  unsigned int v54; // [sp+4Ch] [bp-7Ch]
  unsigned int v55; // [sp+50h] [bp-78h]
  _DWORD v56[2]; // [sp+58h] [bp-70h] BYREF
  _DWORD *v57; // [sp+60h] [bp-68h]
  _DWORD v58[4]; // [sp+68h] [bp-60h] BYREF
  _DWORD v59[6]; // [sp+78h] [bp-50h] BYREF
  _BYTE v60[8]; // [sp+90h] [bp-38h] BYREF
  _BYTE _98[52]; // [sp+98h] [bp-30h] BYREF
  int *varg_r0; // [sp+D0h] [bp+8h]
  int varg_r1; // [sp+D4h] [bp+Ch]
  unsigned int *varg_r2; // [sp+D8h] [bp+10h]
  int varg_r3; // [sp+DCh] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v5 = (char)a4;
  LOBYTE(varg_r3) = a4;
  varg_r2 = a3;
  varg_r0 = a1;
  v52 = 0;
  v50 = 0;
  if ( (a5 & 0x1FFFFFF) != 0 || a5 < 0 && (a5 & 0x60000000) != 0 )
    return -1073741582;
  if ( (_BYTE)a4 )
  {
    if ( !SeSinglePrivilegeCheck(SeCreatePagefilePrivilege, dword_922BAC, (char)a4, (int)&SeCreatePagefilePrivilege)
      || PsIsCurrentThreadInServerSilo() )
    {
      return -1073741727;
    }
    if ( ((unsigned __int8)a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(0);
    if ( ((unsigned __int8)a3 & 7) != 0 )
      ExRaiseDatatypeMisalignment(0);
    if ( (a2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(0);
    v10 = *(_QWORD *)a2;
    v48 = *(_QWORD *)a2;
    v11 = a5;
  }
  else
  {
    v10 = *(_QWORD *)a2;
    v48 = *(_QWORD *)a2;
    v11 = a5;
  }
  if ( v10 > 0x7FFFF000 || (unsigned int)v10 < 0x100000 )
    return -1073741584;
  v49 = *a3;
  v56[0] = v49;
  v55 = a3[1];
  v56[1] = v55;
  if ( __PAIR64__(v55, v49) > 0x7FFFF000 || (unsigned int)v10 > v49 )
    return -1073741583;
  v53 = *a1;
  v54 = a1[1];
  HIWORD(v53) = v53;
  if ( !(_WORD)v53 || (unsigned __int16)v53 > 0x100u )
    return -1073741773;
  v12 = (_DWORD *)ExAllocatePoolWithTag(1, (unsigned __int16)v53, 538996045);
  v13 = (unsigned int)v12;
  v57 = v12;
  v51 = v12;
  if ( !v12 )
    return -1073741670;
  if ( v5 )
  {
    v14 = (unsigned __int16)v53;
    v15 = v54;
    if ( (unsigned __int16)v53 + v54 > MmUserProbeAddress || (unsigned __int16)v53 + v54 < v54 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v15 = v54;
      v14 = (unsigned __int16)v53;
    }
    memmove((int)v12, v15, v14);
  }
  else
  {
    memmove((int)v12, v54, (unsigned __int16)v53);
  }
  v54 = v13;
  v46 = 0;
  v16 = 0;
  v47 = 0;
  v9 = RtlCreateSecurityDescriptor(_98, 1);
  if ( v9 < 0 )
    goto LABEL_129;
  v17 = RtlLengthSid(SeLocalSystemSid);
  v18 = v17 + RtlLengthSid(SeAliasAdminsSid);
  v19 = ExAllocatePoolWithTag(1, v18 + 32, 1818452292);
  v20 = v19;
  v52 = v19;
  if ( !v19 )
  {
    v9 = -1073741670;
LABEL_128:
    v16 = v47;
LABEL_129:
    if ( v16 )
      ObCloseHandle(v16);
    v20 = v52;
    goto LABEL_132;
  }
  v9 = RtlCreateAcl(v19, v18 + 32, 2);
  if ( v9 < 0 )
    goto LABEL_128;
  v9 = RtlAddAccessAllowedAce(v20, 2, 2032127, SeAliasAdminsSid);
  if ( v9 < 0 )
    goto LABEL_128;
  v9 = RtlAddAccessAllowedAce(v20, 2, 2032127, SeLocalSystemSid);
  if ( v9 < 0 )
    goto LABEL_128;
  v9 = RtlSetDaclSecurityDescriptor((int)_98, 1, v20, 0);
  if ( v9 < 0 )
    goto LABEL_128;
  v50 = 0;
  if ( v11 >= 0 )
  {
    if ( (v11 & 0x20000000) != 0 )
      v50 = 2;
  }
  else
  {
    v50 = 3;
  }
  v59[0] = 24;
  v59[1] = 0;
  v59[3] = 576;
  v59[2] = &v53;
  v59[4] = _98;
  v59[5] = 0;
  v58[3] = (unsigned __int64)(v48 + 4095) >> 32;
  v58[2] = (v48 + 4095) & 0xFFFFF000;
  if ( IoCreateFile((int)&v47, 1310723, (int)v59, (int)v58, (int)&v48, 6, 2, 0, 36872, 0, 0, 0, 0, 274) < 0 )
  {
    v9 = IoCreateFile((int)&v47, 1048578, (int)v59, (int)v58, (int)&v48, 6, 3, 1, 32776, 0, 0, 0, 0, 274);
    if ( v9 < 0 )
    {
      v47 = 0;
LABEL_132:
      if ( v20 )
        ExFreePoolWithTag(v20);
      ExFreePoolWithTag((unsigned int)v57);
      return v9;
    }
    v9 = ObReferenceObjectByHandle(v47, 3, (int)IoFileObjectType, 0, (int)&v51, 0);
    v21 = v51;
    if ( v9 < 0 )
      goto LABEL_128;
    v27 = 0;
    v56[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v56[0] + 310);
    v28 = KeAbPreAcquire((unsigned int)&dword_63F95C, 0, 0);
    do
      v29 = __ldrex((unsigned __int8 *)&dword_63F95C);
    while ( __strex(v29 | 1, (unsigned __int8 *)&dword_63F95C) );
    __dmb(0xBu);
    if ( (v29 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_63F95C, v28, (unsigned int)&dword_63F95C);
    if ( v28 )
      *(_BYTE *)(v28 + 14) |= 1u;
    v30 = dword_64050C;
    __dmb(0xBu);
    v31 = 0;
    v51 = 0;
    if ( v30 )
    {
      v32 = MiSystemPartition;
      while ( 1 )
      {
        v33 = *((_DWORD *)v32 + 900);
        if ( (*(_WORD *)(v33 + 96) & 0x40) == 0 && *(_DWORD *)(*(_DWORD *)(v33 + 32) + 20) == v21[5] )
          break;
        v51 = (_DWORD *)++v31;
        v32 += 2;
        if ( v31 >= v30 )
          goto LABEL_90;
      }
      if ( ((*(_WORD *)(v33 + 96) & 0x10) == 0) != ((v50 & 1) == 0) )
      {
        v9 = -1073741811;
LABEL_88:
        v34 = 0;
        goto LABEL_116;
      }
      v27 = *((_DWORD *)v32 + 900);
    }
LABEL_90:
    if ( !v27 )
    {
      v9 = -1073741275;
      goto LABEL_88;
    }
    v35 = (v55 << 20) | (v49 >> 12);
    v49 = v35;
    v36 = v48 >> 12;
    if ( *(_DWORD *)(v27 + 8) > v36 )
    {
      v9 = -1073741584;
      goto LABEL_88;
    }
    v37 = *(_DWORD *)(v27 + 4);
    if ( v35 < v37 )
    {
LABEL_95:
      v9 = -1073741583;
      goto LABEL_88;
    }
    if ( v35 > v37 )
    {
      if ( (*(_WORD *)(v27 + 96) & 0x10) == 0 )
      {
        v46 = v35 - v37;
        if ( !MiIncreaseCommitLimits(MiSystemPartition, 0, v35 - v37, 0, 0) )
          goto LABEL_95;
        v35 = v49;
      }
      v38 = 0;
      if ( *(_DWORD *)(v27 + 108) && (v38 = MiReservePageHash(v35)) == 0
        || (v39 = (_DWORD *)MiCreatePageFileSpaceBitmaps(v49)) == 0 )
      {
        v9 = -1073741670;
LABEL_115:
        v34 = v46;
LABEL_116:
        __dmb(0xBu);
        do
          v41 = __ldrex((unsigned int *)&dword_63F95C);
        while ( __strex(v41 - 1, (unsigned int *)&dword_63F95C) );
        if ( (v41 & 2) != 0 && (v41 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&dword_63F95C);
        v42 = KeAbPostRelease((unsigned int)&dword_63F95C);
        v43 = v56[0];
        v44 = (__int16)(*(_WORD *)(v56[0] + 310) + 1);
        *(_WORD *)(v56[0] + 310) = v44;
        if ( !(_WORD)v44 )
        {
          v44 = *(_DWORD *)(v43 + 100);
          if ( v44 != v43 + 100 )
            KiCheckForKernelApcDelivery(v42);
        }
        if ( v34 )
          MiReduceCommitLimits(MiSystemPartition, 0, v34, v44);
        goto LABEL_126;
      }
      MiExtendPagingFileMaximum((_DWORD *)v27, v39, v38);
      v37 = dword_640714;
      if ( dword_640604 + 100 > (unsigned int)dword_640714 && MiChargeCommit((int)MiSystemPartition, 0xC8u, 0) == 1 )
        MiReturnCommit((int)MiSystemPartition, 200);
    }
    if ( v36 > *(_DWORD *)(v27 + 8) )
    {
      while ( 1 )
      {
        v40 = *(_DWORD *)v27;
        if ( v36 > *(_DWORD *)v27 )
          break;
        if ( MiCheckAndUpdatePagingFileMinimum((unsigned int *)v27, v36, v37, v40) == 1 )
          goto LABEL_113;
      }
      MiIssuePageExtendRequest((int)MiSystemPartition, v36 - v40, (unsigned int)v51, 1);
      if ( *(_DWORD *)(v27 + 8) < v36 )
        v9 = -1073741670;
    }
LABEL_113:
    if ( (v50 & 2) != 0 )
      *(_WORD *)(v27 + 96) |= 0x80u;
    goto LABEL_115;
  }
  if ( v58[0] >= 0 )
  {
    v9 = ZwSetSecurityObject();
    if ( v9 < 0 )
      goto LABEL_128;
  }
  ExFreePoolWithTag(v20);
  v52 = 0;
  v9 = v58[0];
  if ( v58[0] < 0 )
    goto LABEL_128;
  v9 = ZwSetInformationFile();
  if ( v9 < 0 )
    goto LABEL_128;
  v9 = v58[0];
  if ( v58[0] < 0 )
    goto LABEL_128;
  v9 = ObReferenceObjectByHandle(v47, 3, (int)IoFileObjectType, 0, (int)&v51, 0);
  v21 = v51;
  if ( v9 < 0 )
    goto LABEL_128;
  v22 = *(_DWORD *)(IoGetRelatedDeviceObject(v51) + 44);
  if ( v22 != 8 && v22 != 20 && v22 != 54 && v22 != 53 )
  {
    v9 = -1073741489;
    goto LABEL_126;
  }
  v9 = MiCheckPageFileMapping((int)v21);
  if ( v9 < 0 )
    goto LABEL_126;
  v9 = IoQueryVolumeInformation((int)v21, 4, 8, (int)v60, (int)v56);
  if ( v9 < 0 )
    goto LABEL_126;
  if ( (v60[4] & 4) != 0 )
  {
    v9 = -1073741468;
    goto LABEL_126;
  }
  v9 = PiPagePathSetState(v21, 1);
  if ( v9 < 0 )
  {
LABEL_126:
    if ( v21 )
      ObfDereferenceObject((int)v21);
    goto LABEL_128;
  }
  FsRtlIssueFileNotificationFsctl(v21);
  v23 = MiZeroPageFileFirstPage(v21);
  v9 = v23;
  if ( v23 < 0 )
  {
    PiPagePathSetState(v21, 0);
    goto LABEL_126;
  }
  v24 = MiCreatePagefile(v23, (int)v21, v47, v48 >> 12, (v55 << 20) | (v49 >> 12), &v53, v11, 1);
  v25 = v24;
  if ( !v24 )
    return -1073741670;
  v9 = MiInsertPageFileInList(v24);
  if ( v9 >= 0 )
  {
    if ( (*(_WORD *)(v25 + 96) & 0xF) == 0 && (dword_636CC0 & 3) != 0 )
      SmpSystemStoreCreate();
    if ( !byte_63434C )
    {
      v26 = *(unsigned __int16 *)(v25 + 96);
      if ( (v26 & 0x10) == 0 )
        byte_63434C = IoInitializeCrashDump(v47, *(_DWORD *)(v25 + 56), *(_DWORD *)(v25 + 60), v26);
    }
    v9 = 0;
  }
  else
  {
    MiDeletePagefile(v25);
  }
  return v9;
}
