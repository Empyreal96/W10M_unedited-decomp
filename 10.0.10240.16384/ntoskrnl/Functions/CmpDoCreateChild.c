// CmpDoCreateChild 
 
int __fastcall CmpDoCreateChild(int a1, int a2, _WORD *a3, int a4, unsigned __int16 *a5, char a6, _DWORD *a7, int a8, int a9, unsigned __int16 a10, unsigned int *a11, int *a12, int a13)
{
  int v13; // r5
  unsigned __int16 v14; // r4
  int v15; // r3
  int v16; // r0
  _DWORD *v17; // r5
  int v18; // r1
  int *v19; // r0
  int v20; // r0
  int v21; // r0
  _DWORD *v22; // r1
  unsigned int v23; // r0
  int v24; // r0
  int v25; // r1
  _DWORD *v26; // r6
  unsigned int v27; // r2
  _WORD *v28; // r4
  unsigned int v29; // r3
  int v30; // r2
  int v31; // r3
  unsigned int v32; // r3
  unsigned __int16 v33; // r0
  int v34; // r4
  __int64 v35; // r0
  _DWORD *v36; // r0
  int v37; // r4
  int v38; // r1
  unsigned int *v39; // r2
  int v40; // r3
  _WORD *v41; // r2
  int v42; // r9
  unsigned int v43; // r3
  int v44; // r1
  int v45; // r0
  int v46; // r8
  unsigned int v47; // r0
  int v48; // r3
  int v49; // r0
  int v50; // r0
  _DWORD *v51; // r6
  _DWORD *v52; // r1
  _DWORD *v53; // r0
  int v54; // r0
  int v55; // r0
  _DWORD *v56; // r1
  int v57; // r3
  int v58; // r4
  unsigned int v59; // r6
  _DWORD *v60; // r8
  int v61; // r0
  int v62; // r5
  _DWORD *v63; // r5
  int v64; // r8
  int v65; // r4
  int *v67; // [sp+0h] [bp-A0h]
  int v68; // [sp+18h] [bp-88h]
  char v69[4]; // [sp+1Ch] [bp-84h] BYREF
  unsigned int v70; // [sp+20h] [bp-80h]
  _WORD *v71; // [sp+24h] [bp-7Ch]
  int v72; // [sp+28h] [bp-78h]
  _WORD *v73; // [sp+2Ch] [bp-74h]
  int v74; // [sp+30h] [bp-70h]
  int v75; // [sp+34h] [bp-6Ch]
  _DWORD *v76; // [sp+38h] [bp-68h]
  int v77; // [sp+3Ch] [bp-64h]
  int v78; // [sp+40h] [bp-60h] BYREF
  int v79; // [sp+44h] [bp-5Ch]
  int v80; // [sp+48h] [bp-58h]
  _WORD *v81; // [sp+4Ch] [bp-54h]
  _WORD *v82; // [sp+50h] [bp-50h] BYREF
  unsigned int v83; // [sp+54h] [bp-4Ch]
  int v84; // [sp+58h] [bp-48h] BYREF
  _DWORD *v85; // [sp+5Ch] [bp-44h]
  int v86; // [sp+60h] [bp-40h]
  int v87; // [sp+64h] [bp-3Ch]
  int v88; // [sp+68h] [bp-38h]
  int v89; // [sp+6Ch] [bp-34h]
  int v90; // [sp+70h] [bp-30h]
  int v91; // [sp+74h] [bp-2Ch]
  _DWORD _78[11]; // [sp+78h] [bp-28h] BYREF
  int varg_r0; // [sp+A8h] [bp+8h]
  int varg_r1; // [sp+ACh] [bp+Ch]
  _WORD *varg_r2; // [sp+B0h] [bp+10h]
  int varg_r3; // [sp+B4h] [bp+14h]

  v79 = a4;
  varg_r3 = a4;
  v71 = a3;
  varg_r2 = a3;
  v75 = a2;
  varg_r1 = a2;
  v13 = a1;
  v86 = a1;
  varg_r0 = a1;
  v70 = 0;
  v85 = 0;
  v72 = -1;
  v83 = -1;
  v73 = 0;
  v78 = -1;
  v91 = 0;
  v74 = 0;
  v84 = -1;
  v76 = 0;
  v82 = 0;
  v88 = 0;
  v80 = 0;
  v89 = 0;
  v81 = 0;
  _78[0] = 0;
  if ( !CmpIsHiveLoadingOnOtherThread(a1) )
  {
    v87 = 0;
    v90 = 0;
    if ( CmpVEEnabled && (*(_WORD *)(a9 + 106) & 0x100) != 0 )
    {
      v14 = a10 | 0x100;
      v77 = a10 | 0x100;
    }
    else
    {
      v14 = a10;
      v77 = a10;
    }
    if ( (*(_WORD *)(a9 + 106) & 0x200) != 0 )
      v77 = v14 | 0x200;
    if ( (a7[5] & 1) != 0 )
    {
      v87 = 1;
      v90 = 1;
    }
    if ( a13 )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(a9 + 20) + 92) & 2) != 0 )
      {
LABEL_13:
        v15 = -1072103423;
LABEL_14:
        v68 = v15;
        goto LABEL_82;
      }
      v16 = CmpAllocateUnitOfWork(0);
      v17 = (_DWORD *)v16;
      v88 = v16;
      v80 = v16;
      if ( !v16 )
      {
LABEL_16:
        v15 = -1073741670;
        goto LABEL_14;
      }
      v18 = v16 + 16;
      v19 = *(int **)(a9 + 112);
      v17[4] = a9 + 108;
      v17[5] = v19;
      if ( *v19 != a9 + 108 )
        __fastfail(3u);
      *v19 = v18;
      *(_DWORD *)(a9 + 112) = v18;
      v20 = CmpReferenceKeyControlBlock((unsigned int *)a9);
      v17[6] = a9;
      v21 = LOCK_TRANSACTION_LIST(v20);
      v22 = *(_DWORD **)(a13 + 12);
      *v17 = a13 + 8;
      v17[1] = v22;
      if ( *v22 != a13 + 8 )
        __fastfail(3u);
      *v22 = v17;
      *(_DWORD *)(a13 + 12) = v17;
      UNLOCK_TRANSACTION_LIST(v21);
      v17[7] = a13;
      v70 = 1;
      if ( !CmpLockIXLockIntent(a9 + 128, v17) )
        goto LABEL_13;
      v13 = v86;
    }
    else if ( *(_DWORD *)(a9 + 124) || !CmpTryAcquireIXLockIntent((_DWORD *)(a9 + 128)) )
    {
      v68 = CmpSnapshotTxOwnerArray(a9 + 128, a7 + 17, a7 + 18);
      if ( v68 >= 0 )
      {
        v68 = 260;
        a7[14] |= 4u;
      }
      goto LABEL_82;
    }
    v23 = CmpNameSize(a5);
    v67 = &v78;
    v24 = HvAllocateCell(v13, v23 + 76);
    *a11 = v24;
    if ( v24 == -1 )
      goto LABEL_16;
    v70 = 2;
    v25 = a7[1];
    if ( v25 )
    {
      v67 = &v84;
      v72 = HvAllocateCell(v13, v25);
      v83 = v72;
      if ( v72 == -1 )
        goto LABEL_16;
      v91 = v74;
    }
    v70 = 3;
    v69[0] = 1;
    v68 = ObCreateObjectEx(a6, CmKeyObjectType, 0, a6, (int)v67, 44, 0, 0, a12, (int)v69);
    if ( v68 >= 0 )
    {
      v85 = (_DWORD *)*a12;
      v26 = v85;
      *v85 = 1803104306;
      v26[1] = 0;
      v26[7] = 0;
      v26[8] = 0;
      v26[6] &= 0xFFFF0000;
      v26[6] = *((unsigned __int16 *)v26 + 12) | (a7[4] << 16);
      v26[10] = v26 + 9;
      v26[9] = v26 + 9;
      v27 = a7[1];
      if ( v27 )
      {
        memmove(v91, a7[2], v27);
        (*(void (__fastcall **)(int, int *))(v86 + 8))(v86, &v84);
        v74 = 0;
      }
      v28 = v73;
      *v73 = 27502;
      v28[1] = v77;
      KeQuerySystemTime(_78);
      *((_DWORD *)v28 + 1) = _78[0];
      *((_DWORD *)v28 + 2) = _78[1];
      *((_DWORD *)v28 + 4) = v75;
      *((_DWORD *)v28 + 5) = 0;
      *((_DWORD *)v28 + 6) = 0;
      *((_DWORD *)v28 + 7) = -1;
      *((_DWORD *)v28 + 8) = -1;
      *((_DWORD *)v28 + 9) = 0;
      *((_DWORD *)v28 + 10) = -1;
      *((_DWORD *)v28 + 11) = -1;
      *((_DWORD *)v28 + 16) = 0;
      v29 = *((_DWORD *)v28 + 13) & 0xFFFF0000;
      *((_DWORD *)v28 + 13) = v29;
      *((_DWORD *)v28 + 13) = v29 & 0xFFF0FFFF;
      *((_DWORD *)v28 + 3) = 0;
      *((_DWORD *)v28 + 12) = v72;
      v28[37] = a7[1];
      *((_DWORD *)v28 + 14) = 0;
      v30 = *(_DWORD *)(a9 + 104);
      v31 = *((_DWORD *)v28 + 13);
      if ( (v30 & 0x80) != 0 )
        v32 = *((_DWORD *)v28 + 13) ^ (v31 ^ (v30 << 16)) & 0xF00000;
      else
        v32 = v31 & 0xFF0FFFFF;
      *((_DWORD *)v28 + 13) = v32;
      *((_DWORD *)v28 + 13) = v32 & 0xFFFFFF;
      *((_DWORD *)v28 + 15) = 0;
      v33 = CmpCopyName((int)(v28 + 38), a5);
      v28[36] = v33;
      if ( v33 < (unsigned int)*a5 )
        v28[1] |= 0x20u;
      v34 = v86;
      (*(void (__fastcall **)(int, int *))(v86 + 8))(v86, &v78);
      v73 = 0;
      HIDWORD(v35) = *a11;
      LODWORD(v35) = v34;
      v36 = (_DWORD *)CmpCreateKeyControlBlock(v35, (unsigned int *)a9, 2, a5);
      v37 = (int)v36;
      v76 = v36;
      if ( !v36 )
      {
        ObDereferenceObjectDeferDelete(*a12);
        goto LABEL_16;
      }
      CmpUnlockAndLockKcbs(a8, 0, v36, 0);
      v70 = 4;
      if ( (a7[5] & 0x1000000) != 0 )
      {
        *(_DWORD *)(v37 + 52) = a7[10];
        *(_DWORD *)(v37 + 104) = *(unsigned __int16 *)(v37 + 104) | ((*(unsigned __int16 *)(v37 + 106) | 0x40) << 16);
      }
      *v26 = 1803104306;
      v26[1] = v37;
      v26[2] = 0;
      v26[3] = PsGetCurrentThreadProcessId();
      v26[10] = v26 + 9;
      v26[9] = v26 + 9;
      EnlistKeyBodyWithKCB(v26, 2);
      v26[7] = 0;
      v26[8] = 0;
      v70 = 5;
      if ( (*(_DWORD *)(*(_DWORD *)(v37 + 20) + 3228) & 0x20) != 0 )
      {
        if ( v71 )
        {
          v40 = 0;
          v41 = v71;
          v81 = v71;
        }
        else
        {
          v41 = (_WORD *)CmpGenerateAppHiveSecurityDescriptor();
          v81 = v41;
          if ( !v41 )
            goto LABEL_16;
          v40 = 1;
        }
        v72 = v40;
        v42 = 0;
        v68 = 0;
        v71 = v41;
        v82 = v41;
      }
      else
      {
        v72 = 0;
        v43 = *(unsigned __int16 *)(v37 + 106);
        if ( (v43 & 0x200) == 0 || CmpIsSystemEntity(a7 + 3, v38, v39, v43) )
        {
          v45 = v79;
          v44 = *(_DWORD *)(v79 + 44);
        }
        else
        {
          v44 = 0;
          v45 = v79;
        }
        v42 = SeAssignSecurity(
                v71,
                v44,
                &v82,
                1,
                v45 + 28,
                (char *)CmKeyObjectType + 52,
                *((_DWORD *)CmKeyObjectType + 19));
        v68 = v42;
        v71 = v82;
      }
      if ( v42 >= 0 )
      {
        CmLockHiveSecurityExclusive(*(_DWORD *)(v37 + 20));
        v42 = CmpAssignSecurityDescriptorWrapper(*a12, v71, 0, (int)a12);
        v68 = v42;
        CmUnlockHiveSecurity(*(_DWORD *)(v37 + 20));
      }
      if ( (*(_DWORD *)(*(_DWORD *)(v37 + 20) + 3228) & 0x20) == 0 )
      {
        if ( (*a7 & 1) != 0 && (a7[5] & 4) != 0 )
        {
          SeDeassignSecurity((unsigned int *)&v82);
        }
        else
        {
          v46 = *(_DWORD *)(v79 + 48);
          v47 = *(_DWORD *)(v46 + 44);
          if ( v47 )
            ExFreePoolWithTag(v47);
          *(_DWORD *)(v46 + 44) = v71;
        }
      }
      if ( v72 )
        ExFreePoolWithTag((unsigned int)v81);
      if ( v42 >= 0 )
      {
        if ( !a13 )
          goto LABEL_79;
        v26[7] = *(_DWORD *)(a13 + 24);
        if ( *(_DWORD *)(a13 + 24) )
          v48 = 0;
        else
          v48 = a13 + 40;
        v26[8] = v48;
        v49 = v26[7];
        if ( v49 )
        {
          v49 = CmReferenceKtmTransaction();
          v68 = v49;
          if ( v49 < 0 )
          {
            v26[7] = 0;
            v26[8] = 0;
            goto LABEL_82;
          }
        }
        v50 = CmpAllocateUnitOfWork(v49);
        v51 = (_DWORD *)v50;
        v89 = v50;
        if ( !v50 )
          goto LABEL_16;
        v52 = (_DWORD *)(v50 + 16);
        v53 = *(_DWORD **)(v37 + 112);
        *v52 = v37 + 108;
        v52[1] = v53;
        if ( *v53 != v37 + 108 )
          __fastfail(3u);
        *v53 = v52;
        *(_DWORD *)(v37 + 112) = v52;
        v54 = CmpReferenceKeyControlBlock((unsigned int *)v37);
        v51[6] = v37;
        v55 = LOCK_TRANSACTION_LIST(v54);
        v56 = *(_DWORD **)(a13 + 12);
        *v51 = a13 + 8;
        v51[1] = v56;
        if ( *v56 != a13 + 8 )
          __fastfail(3u);
        *v56 = v51;
        *(_DWORD *)(a13 + 12) = v51;
        UNLOCK_TRANSACTION_LIST(v55);
        v51[7] = a13;
        v51[9] = 0;
        v51[10] = v87;
        *(_DWORD *)(v37 + 124) = a13;
        CmpLockIXLockExclusive(v37 + 128, v51, 0);
        CmpLockIXLockExclusive(v37 + 136, v51, 1);
        v57 = v88;
        *(_DWORD *)(v88 + 36) = 1;
        *(_DWORD *)(v57 + 48) = v37;
        v68 = CmAddLogForAction(v51);
        if ( v68 >= 0 )
LABEL_79:
          CmpReportNotify(v37, *(void (__fastcall ***)(void *, int *))(v37 + 20), *(_DWORD *)(v37 + 24), a13, 1, 0);
      }
    }
LABEL_82:
    v58 = varg_r0;
    if ( v74 )
      (*(void (__fastcall **)(int, int *))(varg_r0 + 8))(varg_r0, &v84);
    if ( v73 )
      (*(void (__fastcall **)(int, int *))(v58 + 8))(v58, &v78);
    if ( v68 >= 0 )
      return v68;
    v59 = v70;
    if ( v70 != 1 )
    {
      if ( v70 != 2 )
      {
        if ( v70 != 3 )
        {
          if ( v70 == 4 )
          {
            v64 = a8;
            v63 = v76;
          }
          else
          {
            if ( v70 != 5 )
              return v68;
            v60 = v85;
            v61 = v85[7];
            if ( v61 )
            {
              ObfDereferenceObject(v61);
              v60[7] = 0;
              v60[8] = 0;
            }
            v62 = v89;
            if ( v89 )
            {
              CmpRundownUnitOfWork(v89);
              CmpFreeUnitOfWork(v62);
            }
            v63 = v76;
            CmpMarkKcbDeleted(v76);
            v64 = a8;
            CmpUnlockAndLockKcbs(a8, v63, 0, 0);
            ObDereferenceObjectDeferDelete(*a12);
          }
          if ( v59 < 5 )
          {
            CmpMarkKcbDeleted(v63);
            CmpDereferenceKeyControlBlockWithLock((int)v63, 0);
            CmpUnlockAndLockKcbs(v64, v63, 0, 0);
          }
        }
        if ( v83 != -1 )
          HvFreeCell(v58, v83);
      }
      HvFreeCell(v58, *a11);
    }
    v65 = v80;
    if ( v80 )
    {
      CmpRundownUnitOfWork(v80);
      CmpFreeUnitOfWork(v65);
    }
    return v68;
  }
  return -1073741772;
}
