// MiAllocateVirtualMemory 
 
int __fastcall MiAllocateVirtualMemory(int a1, unsigned int *a2, unsigned int a3, int *a4, int a5, unsigned int a6, char a7, char a8, _DWORD *a9)
{
  int v11; // r4
  int v12; // r8
  int v13; // r4
  unsigned int v14; // r0
  int v15; // lr
  unsigned int *v16; // r2
  int *v17; // r2
  unsigned int v18; // r10
  unsigned int v19; // r9
  int v20; // r3
  unsigned int v21; // r6
  int v22; // r8
  int v23; // r1
  int v24; // r2
  int v25; // r3
  _BYTE *v26; // r0
  _DWORD *v27; // r8
  unsigned int v28; // lr
  int v29; // r1
  int v30; // r0
  unsigned int v31; // r0
  unsigned int v32; // r8
  unsigned int v33; // r10
  int v34; // r1
  int v35; // r0
  unsigned int v36; // r8
  int v37; // r0
  int v38; // r5
  int v39; // r0
  unsigned int v40; // r2
  int v41; // r3
  int v42; // lr
  char v43; // r0
  int v44; // r3
  unsigned int v45; // r1
  int v46; // r8
  int v47; // r3
  int v48; // r3
  unsigned int v49; // r1
  unsigned int v50; // r2
  int v51; // r3
  int v52; // r4
  int v54; // [sp+4h] [bp-10Ch]
  int v55; // [sp+8h] [bp-108h]
  unsigned int *v56; // [sp+18h] [bp-F8h]
  unsigned int v57; // [sp+1Ch] [bp-F4h]
  _DWORD *v58; // [sp+1Ch] [bp-F4h]
  char v59; // [sp+20h] [bp-F0h]
  unsigned __int8 v60[4]; // [sp+24h] [bp-ECh] BYREF
  unsigned int v61; // [sp+28h] [bp-E8h]
  int v62; // [sp+2Ch] [bp-E4h]
  int v63; // [sp+30h] [bp-E0h]
  int v64; // [sp+34h] [bp-DCh]
  int v65; // [sp+38h] [bp-D8h]
  unsigned int v66; // [sp+3Ch] [bp-D4h] BYREF
  unsigned int v67; // [sp+40h] [bp-D0h]
  int v68; // [sp+44h] [bp-CCh]
  unsigned int v69; // [sp+48h] [bp-C8h] BYREF
  int v70; // [sp+4Ch] [bp-C4h]
  int v71; // [sp+50h] [bp-C0h] BYREF
  _DWORD *v72; // [sp+54h] [bp-BCh]
  unsigned int v73; // [sp+58h] [bp-B8h]
  char v74; // [sp+5Ch] [bp-B4h]
  int v75[2]; // [sp+60h] [bp-B0h] BYREF
  int v76; // [sp+68h] [bp-A8h]
  unsigned int v77; // [sp+6Ch] [bp-A4h] BYREF
  unsigned int v78; // [sp+70h] [bp-A0h] BYREF
  int v79; // [sp+74h] [bp-9Ch]
  int v80; // [sp+78h] [bp-98h]
  int v81[2]; // [sp+80h] [bp-90h] BYREF
  unsigned int *v82; // [sp+88h] [bp-88h]
  _DWORD *v83; // [sp+90h] [bp-80h]
  unsigned int v84; // [sp+94h] [bp-7Ch]
  int v85; // [sp+98h] [bp-78h]
  unsigned int v86; // [sp+9Ch] [bp-74h]
  unsigned int v87; // [sp+A0h] [bp-70h]
  unsigned int v88; // [sp+A4h] [bp-6Ch]
  unsigned int *v89; // [sp+A8h] [bp-68h]
  _DWORD v90[10]; // [sp+B0h] [bp-60h] BYREF
  _DWORD _D8[20]; // [sp+D8h] [bp-38h] BYREF

  _D8[16] = a1;
  _D8[17] = a2;
  _D8[19] = a4;
  v83 = a4;
  v78 = a3;
  _D8[18] = a3;
  v82 = a2;
  v79 = a1;
  v81[0] = a1;
  v89 = a2;
  v69 = (unsigned int)a4;
  v72 = a9;
  v75[0] = (int)a9;
  if ( a3 && a3 > 0x15 )
    v11 = -1073741811;
  else
    v11 = 0;
  v71 = v11;
  if ( v11 < 0 )
    return -1073741583;
  v59 = 0;
  v68 = 0;
  v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v61 = *(_DWORD *)(v65 + 116);
  v86 = v61;
  v73 = a5 & 0x7F;
  v88 = v73;
  if ( v73 > (unsigned __int16)KeNumberNodes )
    return -1073741581;
  v13 = a5 & 0xFFFFFF80;
  if ( (a5 & 0x9E07CF80) != 0 || (a5 & 0x1083000) == 0 )
    return -1073741581;
  if ( (a5 & 0x61E80000) == 0 )
  {
    v80 = 0x1000000;
    v70 = 0x20000000;
    v64 = 0x800000;
    goto LABEL_37;
  }
  if ( (a5 & 0x40000000) != 0 && (a5 & 0x21F80000) != 0 )
    return -1073741581;
  if ( (a5 & 0x80000) != 0 && v13 != 0x80000 )
    return -1073741581;
  v80 = 0x1000000;
  if ( (a5 & 0x1000000) != 0 && v13 != 0x1000000 )
    return -1073741581;
  v70 = 0x20000000;
  if ( (a5 & 0x20000000) != 0 )
  {
    if ( (a5 & 0x1000) != 0 && (a5 & 0xE00000) == 0 )
    {
      v64 = 0x800000;
LABEL_37:
      v14 = a6;
      v57 = a6;
LABEL_38:
      v76 = 0x400000;
      goto LABEL_39;
    }
    return -1073741581;
  }
  v64 = 0x800000;
  if ( (a5 & 0x800000) != 0 )
  {
    if ( (a5 & 0x600000) == 0 )
    {
      v14 = a6;
      v57 = a6;
      if ( (a6 & 0xFFFFF9F9) != 0 )
        return -1073741755;
      goto LABEL_38;
    }
    return -1073741581;
  }
  v76 = 0x400000;
  if ( (a5 & 0x200000) != 0 )
  {
    if ( (a5 & 0x400000) != 0 || (a5 & 0x2000) == 0 )
      return -1073741581;
LABEL_35:
    v14 = a6;
    v57 = a6;
    goto LABEL_39;
  }
  if ( (a5 & 0x400000) == 0 )
    goto LABEL_35;
  if ( (a5 & 0x2000) == 0 || (a5 & 0xFFAFDF80) != 0 )
    return -1073741581;
  v14 = a6;
  v57 = a6;
  if ( a6 != 4 )
    return -1073741580;
LABEL_39:
  v63 = 1;
  v60[0] = 1;
  v77 = 0;
  v74 = 0;
  if ( (v14 & 0x40000000) == 0 )
    goto LABEL_42;
  if ( (v14 & 0xF0) == 0 )
    return -1073741580;
  v14 &= 0xBFFFFFFF;
  v57 = v14;
  v63 = 0;
  v60[0] = 0;
LABEL_42:
  v62 = MiMakeProtectionMask(v14);
  v85 = v62;
  if ( v62 == -1 )
    return -1073741755;
  v15 = a7;
  v66 = a7;
  if ( a7 )
  {
    v16 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v16 = (unsigned int *)MmUserProbeAddress;
    *v16 = *v16;
    v17 = a4;
    if ( (unsigned int)a4 >= MmUserProbeAddress )
      v17 = (int *)MmUserProbeAddress;
    *v17 = *v17;
  }
  v67 = *a2;
  v18 = v67;
  v87 = v67;
  v84 = *a4;
  v19 = v84;
  v81[0] = v84;
  v68 = 0x10000;
  if ( v67 > MmHighestUserAddress - 0x10000 )
    return -1073741584;
  if ( MmHighestUserAddress - v67 - 0xFFFF < v84 || !v84 )
    return -1073741582;
  if ( v79 == -1 )
  {
    v20 = v61;
  }
  else
  {
    v12 = ObReferenceObjectByHandleWithTag(v79, 8, PsProcessType, a7, 1834380621, v75, 0);
    v71 = v12;
    if ( v12 < 0 )
      return v12;
    v20 = v75[0];
    v15 = v66;
  }
  v56 = (unsigned int *)v20;
  v21 = 0;
  v66 = 0;
  v22 = v70;
  if ( (v13 & v70) != 0 )
  {
    if ( !SeSinglePrivilegeCheck(SeLockMemoryPrivilege, dword_922B7C, v15, (int)&SeLockMemoryPrivilege) )
    {
      v12 = -1073741727;
LABEL_263:
      v24 = (int)v56;
LABEL_264:
      if ( (dword_682604 & 0x8000) != 0 && (v13 & v80) != 0 && v12 == -1073740748 )
      {
        MiLogMemResetInfo(v21, v19, 0);
        v24 = (int)v56;
      }
      if ( (v59 & 2) != 0 )
      {
        KiUnstackDetachProcess((unsigned int)_D8, 0);
        v24 = (int)v56;
      }
      if ( v79 != -1 )
        ObfDereferenceObjectWithTag(v24);
      return v12;
    }
    v20 = (int)v56;
  }
  v23 = v61;
  if ( v61 != v20 )
  {
    KiStackAttachProcess(v20, 0, (int)_D8);
    v59 = 2;
    v23 = v61;
  }
  if ( (a5 & 0x1000) != 0 && !v67 )
    v13 |= 0x2000u;
  if ( (v13 & 0x2000) != 0 )
  {
    if ( (v57 & 0x88) != 0 )
    {
      v12 = -1073741755;
      goto LABEL_263;
    }
    v69 = v62 & 2;
    if ( (v62 & 2) != 0 )
    {
      v12 = MiArbitraryCodeBlocked(v23);
      if ( v12 < 0 )
        goto LABEL_263;
      v22 = v70;
    }
    if ( !v67 )
    {
      v19 = (v19 + 4095) & 0xFFFFF000;
      v63 = v19 >> 12;
      v61 = 0;
      v67 = v13 & v22;
      if ( (v13 & v22) != 0 )
      {
        if ( (v19 & 0x3FFFFF) != 0 )
        {
          v12 = -1073741582;
          goto LABEL_263;
        }
        v68 = 0x400000;
      }
LABEL_92:
      v26 = (_BYTE *)ExAllocatePoolWithTag(512, 40, 1399087446);
      v27 = v26;
      v58 = v26;
      if ( !v26 )
      {
        v12 = -1073741670;
        goto LABEL_263;
      }
      memset(v26, 0, 40);
      v27[2] = -2;
      v27[6] = 0;
      v28 = v73;
      v27[7] ^= (v27[7] ^ (v73 << 8)) & 0x3F00;
      if ( v28 )
        MEMORY[0xC040213C] = 1;
      if ( (v13 & 0x1000) != 0 )
      {
        v29 = v63;
        v27[8] |= 0x80000000;
      }
      else
      {
        v29 = 0;
      }
      v27[7] = v27[7] & 0xFFFFFF07 | (8 * (v62 & 0x1F | 0x1000));
      if ( (a8 & 1) != 0 )
        v29 = 524286;
      v27[8] = v27[8] & 0x80000000 | v29 & 0x7FFFFFFF;
      v63 = 0;
      v70 = 0;
      v75[0] = v13 & v76;
      if ( (v13 & v76) != 0 )
      {
        if ( v56[82] || (v70 = MiAllocateAweInfo()) != 0 )
        {
          v30 = ExAllocatePoolWithTag(512, 16, 1987079501);
          v63 = v30;
          if ( !v30 )
          {
            if ( v70 )
              MiFreeAweInfo(v70);
            goto LABEL_115;
          }
          v27[7] = v27[7] & 0xFFFFFFF8 | 3;
          *(_DWORD *)(v30 + 12) = v27;
LABEL_121:
          v73 = 0;
          v77 = 0;
          LOCK_ADDRESS_SPACE(v65, (int)v56);
          if ( (v56[48] & 0x20) != 0 )
          {
            v12 = -1073741558;
            if ( v70 )
              MiFreeAweInfo(v70);
            goto LABEL_137;
          }
          if ( v70 )
            MiInsertAweInfo((int)v56, v70);
          if ( v18 )
          {
            v32 = v61;
            if ( !MiCheckForConflictingVadExistence() )
              goto LABEL_135;
            v12 = -1073741800;
          }
          else
          {
            v12 = MiSelectUserAddress(v13, v78, v19, v68, v62, &v77, &v66);
            if ( v12 >= 0 )
            {
              if ( v67 )
                v73 = 0;
              else
                v73 = v77;
              v21 = v66;
              v61 = (v66 + v19 - 1) | 0xFFF;
              v32 = v61;
LABEL_135:
              v33 = (unsigned int)v58;
              v58[3] = v21 >> 12;
              v58[4] = v32 >> 12;
              v12 = MiInsertVadCharges(v58, v56);
              v71 = v12;
              if ( v12 < 0 )
                goto LABEL_138;
              MiInsertPrivateVad((int)v58, v63, (int)v56);
              if ( (v58[7] & 7) == 5 )
                MiMapUserLargePages((int)v58, v34, (int)v56);
              if ( v73 == 1 )
                MiAdvanceVadHint(v21 >> 12, v61 >> 12);
              v19 = v61 - v21 + 1;
              v59 |= 1u;
              if ( v69 && MiIsProcessCfgEnabled() )
              {
                MiLockVad(v65, (int)v58);
                UNLOCK_ADDRESS_SPACE_UNORDERED(v65, (int)v56);
                v59 &= 0xFEu;
                v12 = MiCommitVadCfgBits((int)v58, 0, v60);
                v71 = v12;
                if ( v12 < 0 )
                {
                  v35 = MiReferenceVad((int)v58);
                  MiDeleteVad(v35, 0);
                  goto LABEL_263;
                }
                if ( !v72 )
                  MiUnlockVad(v65, (int)v58);
              }
              else
              {
                if ( !v72 )
                {
LABEL_160:
                  if ( (v59 & 1) != 0 )
                    UNLOCK_ADDRESS_SPACE(v65, (int)v56);
                  goto LABEL_250;
                }
                MiLockVad(v65, (int)v58);
              }
              if ( v72 )
              {
                UNLOCK_ADDRESS_SPACE_UNORDERED(v65, (int)v56);
                v59 &= 0xFEu;
                MiReferenceVad((int)v58);
                *v72 = v58;
              }
              goto LABEL_160;
            }
            v21 = v66;
          }
LABEL_137:
          v33 = (unsigned int)v58;
LABEL_138:
          UNLOCK_ADDRESS_SPACE(v65, (int)v56);
          if ( (v59 & 8) != 0 )
          {
            MiFreeWriteWatchView(v56, v33);
          }
          else if ( (v13 & v64) != 0 )
          {
            MiFreeRotateView(v33);
          }
          else if ( v67 )
          {
            MiFreeLargePageView(v56, v33, 0);
          }
          ExFreePoolWithTag(v33);
          if ( v75[0] )
            ExFreePoolWithTag(v63);
          goto LABEL_263;
        }
LABEL_115:
        ExFreePoolWithTag((unsigned int)v27);
        v12 = -1073741670;
        goto LABEL_263;
      }
      if ( v67 )
      {
        v12 = MiCreateLargePageVad(v56, v27, v73, v62);
        v31 = (unsigned int)v58;
        if ( v12 >= 0 )
        {
          v58[7] = v58[7] & 0xFFFFFFF8 | 5;
          goto LABEL_121;
        }
      }
      else
      {
        if ( (v13 & v64) != 0 )
        {
          if ( MiCreateRotateView((int)v27) )
          {
            v27[7] = v27[7] & 0xFFFFFFF8 | 6;
            goto LABEL_121;
          }
          goto LABEL_115;
        }
        if ( (v13 & 0x200000) == 0 )
          goto LABEL_121;
        v12 = MiCreateWriteWatchView((int)v56);
        v31 = (unsigned int)v58;
        if ( v12 >= 0 )
        {
          v58[7] = v58[7] & 0xFFFFFFF8 | 4;
          v59 |= 8u;
          goto LABEL_121;
        }
      }
      ExFreePoolWithTag(v31);
      goto LABEL_263;
    }
    v24 = (int)v56;
    if ( v67 < 0x10000 && !v56[195] )
    {
LABEL_80:
      v12 = -1073741584;
      goto LABEL_264;
    }
    v67 = v13 & v22;
    if ( (v13 & v22) != 0 )
    {
      if ( (v19 & 0x3FFFFF) != 0 )
      {
        v12 = -1073741582;
        goto LABEL_264;
      }
      v68 = 0x400000;
      v21 = v18 & 0xFFC00000;
      v66 = v18 & 0xFFC00000;
      v25 = (v18 & 0xFFC00000) + v19 - 1;
    }
    else
    {
      if ( (v13 & 0x40000000) != 0 )
      {
        if ( (v18 & 0xFFF) != 0 || (v19 & 0xFFF) != 0 )
          goto LABEL_80;
        v21 = v18;
        v66 = v18;
      }
      else
      {
        v21 = v18 & 0xFFFF0000;
        v66 = v18 & 0xFFFF0000;
      }
      v25 = (v19 + v18 - 1) | 0xFFF;
    }
    v61 = v25;
    v63 = ((((_WORD)v25 - (_WORD)v21) & 0xFFF) != 0) + ((int)(v25 - v21) >> 12);
    goto LABEL_92;
  }
  if ( (v13 & 0x40000000) != 0 )
  {
    v12 = -1073741581;
    goto LABEL_263;
  }
  if ( v13 == 0x80000 || v13 == v80 )
  {
    if ( v19 + v67 < 0x1000 )
    {
      v12 = -1073741800;
      goto LABEL_263;
    }
    v36 = ((v19 + v67) & 0xFFFFF000) - 1;
    v64 = v36;
    v21 = (v67 + 4095) & 0xFFFFF000;
    if ( v21 > v36 )
    {
      v12 = -1073741800;
      goto LABEL_263;
    }
  }
  else
  {
    v36 = (v19 + v67 - 1) | 0xFFF;
    v64 = v36;
    v21 = v67 & 0xFFFFF000;
  }
  v19 = v36 - v21 + 1;
  v69 = v36 >> 12;
  v37 = MiObtainReferencedVad(v21, &v71);
  v38 = v37;
  if ( !v37 )
  {
    v12 = v71;
    v24 = (int)v56;
    if ( v71 == -1073741664 )
      v12 = -1073741800;
    goto LABEL_264;
  }
  if ( v36 >> 12 > *(_DWORD *)(v37 + 16) )
  {
    v12 = -1073741800;
    goto LABEL_262;
  }
  v39 = *(_DWORD *)(v37 + 28);
  if ( ((1 << (v39 & 7)) & 0x55) == 0 )
  {
    v12 = -1073741800;
    goto LABEL_262;
  }
  if ( (*(_DWORD *)(v38 + 32) & 0x7FFFFFFFu) >= 0x7FFFE )
  {
    v12 = -1073741800;
    goto LABEL_262;
  }
  if ( (v39 & 7) != 6 )
  {
    v42 = v62;
    goto LABEL_194;
  }
  v40 = v57 & 0xFFFFF9FF;
  v57 &= 0xFFFFF9FF;
  v41 = (unsigned __int8)v39 >> 6;
  if ( v41 == 3 && (v39 & 0x38) != 0 )
  {
    v40 |= 0x400u;
  }
  else
  {
    if ( v41 != 1 )
      goto LABEL_191;
    v40 |= 0x200u;
  }
  v57 = v40;
LABEL_191:
  v42 = MiMakeProtectionMask(v40);
  v62 = v42;
  if ( v42 == -1 )
    goto LABEL_261;
LABEL_194:
  if ( (v13 & 0x1080000) != 0 )
  {
    v12 = MiResetVirtualMemory(v21, v36, v38, v13);
    v71 = v12;
    MiUnlockAndDereferenceVad(v38);
    if ( v12 < 0 )
      goto LABEL_263;
  }
  else
  {
    v43 = v59 & 0xFB;
    v59 &= 0xFBu;
    if ( (v42 & 2) != 0 )
    {
      v12 = MiAllowProtectionChange((int)v56, v61, v38, v42, v21, v36);
      if ( v12 < 0 )
        goto LABEL_262;
      if ( (!v63 || (*(_DWORD *)(v38 + 28) & 0x10) == 0) && MiIsProcessCfgEnabled() )
      {
        if ( (*(_DWORD *)(v38 + 28) & 0x4000) != 0 )
        {
          v12 = MiCheckSecuredVad((_DWORD *)v38, v67, v19, v62);
          if ( v12 < 0 )
            goto LABEL_262;
          v59 |= 4u;
        }
        v75[0] = v21;
        v75[1] = v64;
        v12 = MiCommitVadCfgBits(v38, v75, v60);
        if ( v12 < 0 )
          goto LABEL_262;
        v77 = 1;
      }
      v43 = v59;
      v42 = v62;
    }
    v44 = *(_DWORD *)(v38 + 28);
    if ( (v44 & 0x8000) == 0 )
    {
      v45 = v57;
      if ( (v57 & 0x600) == 0 )
      {
        if ( (v44 & 0x4000) != 0 && (v43 & 4) == 0 )
        {
          v12 = MiCheckSecuredVad((_DWORD *)v38, v67, v19, v42);
          if ( v12 < 0 )
            goto LABEL_262;
          v45 = v57;
        }
        v46 = **(_DWORD **)(v38 + 44);
        v75[0] = v46;
        if ( *(_DWORD *)(v46 + 32) )
        {
          if ( *(int *)(v38 + 68) < 0 )
          {
            v47 = (v64
                 - (*(_DWORD *)(v38 + 12) << 12)
                 + 1
                 + __PAIR64__((*(_DWORD *)(v38 + 40) & 0xFFFFFFu) >> 16, *(_DWORD *)(v38 + 40) << 16)) >> 32;
            v81[0] = v64 - (*(_DWORD *)(v38 + 12) << 12) + 1 + (*(_DWORD *)(v38 + 40) << 16);
            v81[1] = v47;
            if ( MiFlushAcquire(v46, 0, 0) )
            {
              v68 = 0;
              if ( (*(_DWORD *)(v38 + 28) & 0x8000) == 0 )
              {
                v48 = *(_DWORD *)(v38 + 72);
                if ( v48 )
                {
                  v68 = *(_DWORD *)(v38 + 72);
                  ObfReferenceObject(v48);
                }
              }
              MiUnlockVad(v65, v38);
              memset(v90, 0, sizeof(v90));
              if ( v68 )
              {
                if ( (*(_DWORD *)(v46 + 28) & 0x20) != 0 )
                  v90[5] = v68 | 1;
                else
                  v90[5] = v68 | 2;
              }
              else
              {
                v90[5] = v46;
              }
              v90[8] = *(_DWORD *)(v46 + 28);
              v90[9] = v90[9] & 0xFFFFF000 | 4;
              v12 = MmExtendSection((int)v90);
              if ( v68 )
                ObfDereferenceObject(v68);
              MiLockVad(v65, v38);
              MiFlushRelease(v75[0], 0, 0);
              if ( v12 >= 0
                && !MiVadDeleted(v38)
                && v21 >> 12 >= v49
                && v21 >> 12 <= v50
                && v69 <= v50
                && v69 >= v49
                && ((*(_DWORD *)(v38 + 28) & 0x4000) == 0 || MiCheckSecuredVad((_DWORD *)v38, v67, v19, v62) >= 0)
                && *(int *)(v38 + 68) < 0 )
              {
                v12 = MiSetProtectionOnSection((int)v56, (_DWORD *)v38, v21, v64, v57, 0, &v69, v75);
              }
            }
            else
            {
              v12 = -1073741670;
            }
          }
          else
          {
            v12 = -1073741791;
          }
        }
        else
        {
          v12 = MiCommitPagefileBackedSection(v56, (_DWORD *)v38, v21, v64, v45, v54, v55, &v69, v75);
          v71 = v12;
          if ( v12 >= 0 )
          {
            MiUnlockAndDereferenceVad(v38);
            goto LABEL_250;
          }
        }
LABEL_262:
        MiUnlockAndDereferenceVad(v38);
        goto LABEL_263;
      }
LABEL_261:
      v12 = -1073741755;
      goto LABEL_262;
    }
    if ( (v57 & 0x88) != 0 || (*(_DWORD *)(v38 + 28) & 7) == 6 && (v57 & 0xFFFFF9F9) != 0 )
      goto LABEL_261;
    v78 = 0;
    v12 = MiCommitExistingVad((_DWORD *)v38, v67, v81[0], v57, &v78);
    v71 = v12;
    if ( v12 < 0 )
      goto LABEL_262;
    MiUnlockAndDereferenceVad(v38);
    if ( v78 == 1 )
    {
      v69 = v21;
      v75[0] = v19;
      if ( v77 && !v63 )
        v57 |= 0x40000000u;
      MiProtectVirtualMemory(v61, v56, &v69, v75, v57, v81);
    }
  }
LABEL_250:
  if ( (dword_682604 & 0x8000) == 0 )
  {
LABEL_255:
    v52 = (int)v56;
    goto LABEL_256;
  }
  if ( (v13 & 0x3000) == 0 )
  {
    if ( (v13 & 0x1080000) != 0 )
      MiLogMemResetInfo(v21, v19, v13);
    goto LABEL_255;
  }
  v51 = v13;
  v52 = (int)v56;
  PerfInfoLogVirtualAlloc(v21, v19, v56, v51);
LABEL_256:
  if ( (v59 & 2) != 0 )
    KiUnstackDetachProcess((unsigned int)_D8, 0);
  if ( v79 != -1 )
    ObfDereferenceObjectWithTag(v52);
  *v83 = v19;
  *v82 = v21;
  return v12;
}
