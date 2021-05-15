// MmRotatePhysicalView 
 
int __fastcall MmRotatePhysicalView(unsigned int a1, unsigned int *a2, int a3, int a4, int (__fastcall *a5)(_DWORD *, unsigned int, int), int a6)
{
  _DWORD *v6; // r9
  int v7; // r10
  int v8; // r6
  int v9; // r5
  unsigned int v10; // r8
  int v11; // r4
  int v12; // r0
  int v13; // r4
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  unsigned int v18; // r5
  int *v19; // r2
  unsigned int i; // r5
  int v21; // r0
  int v22; // r0
  unsigned int v23; // r5
  int v24; // r2
  unsigned int v25; // r1
  char v26; // r4
  unsigned int v27; // r3
  int v28; // r5
  int v29; // r0
  _BYTE *v30; // r4
  int v31; // r0
  int v32; // r6
  __int16 v33; // r5
  int v34; // r5
  int v35; // r2
  unsigned int v36; // r3
  unsigned int *v37; // r6
  int v38; // r5
  unsigned int v39; // t1
  int v41; // [sp+10h] [bp-168h]
  _BYTE *v42; // [sp+10h] [bp-168h]
  int v43; // [sp+14h] [bp-164h]
  int v44; // [sp+18h] [bp-160h]
  unsigned int v45; // [sp+1Ch] [bp-15Ch]
  int *v46; // [sp+1Ch] [bp-15Ch]
  int v47; // [sp+1Ch] [bp-15Ch]
  int v48; // [sp+20h] [bp-158h]
  int v49; // [sp+24h] [bp-154h] BYREF
  unsigned int v50; // [sp+28h] [bp-150h]
  int v51; // [sp+2Ch] [bp-14Ch]
  unsigned int *v52; // [sp+30h] [bp-148h]
  int v53; // [sp+34h] [bp-144h]
  int v54; // [sp+38h] [bp-140h]
  int v55; // [sp+3Ch] [bp-13Ch]
  int v56; // [sp+40h] [bp-138h]
  int (__fastcall *v57)(_DWORD *, unsigned int, int); // [sp+44h] [bp-134h]
  int v58; // [sp+48h] [bp-130h]
  unsigned int v59; // [sp+4Ch] [bp-12Ch]
  unsigned int v60; // [sp+50h] [bp-128h]
  int v61; // [sp+54h] [bp-124h]
  unsigned int v62; // [sp+58h] [bp-120h]
  int v63; // [sp+5Ch] [bp-11Ch]
  __int16 *v64; // [sp+60h] [bp-118h]
  unsigned int v65; // [sp+64h] [bp-114h]
  int v66; // [sp+68h] [bp-110h]
  int v67; // [sp+6Ch] [bp-10Ch]
  unsigned int v68; // [sp+70h] [bp-108h]
  __int16 *v69; // [sp+74h] [bp-104h]
  unsigned int *v70; // [sp+78h] [bp-100h]
  unsigned int v71; // [sp+7Ch] [bp-FCh]
  int (__fastcall *v72)(_DWORD, _DWORD, _DWORD); // [sp+80h] [bp-F8h]
  _DWORD v73[4]; // [sp+88h] [bp-F0h] BYREF
  _BYTE v74[96]; // [sp+98h] [bp-E0h] BYREF
  _DWORD _F8[38]; // [sp+F8h] [bp-80h] BYREF

  _F8[34] = a1;
  _F8[35] = a2;
  _F8[36] = a3;
  v54 = a4;
  _F8[37] = a4;
  v6 = (_DWORD *)a3;
  v52 = a2;
  v7 = a1;
  v62 = a1;
  v70 = a2;
  v61 = a3;
  v57 = a5;
  v72 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))a5;
  v55 = a6;
  v67 = a6;
  v8 = 0;
  v9 = 0;
  v43 = 0;
  v63 = 0;
  v10 = *a2;
  v59 = *a2;
  v50 = 0;
  v65 = 0;
  if ( (a1 & 0xFFF) != 0 )
  {
    v11 = -1073741585;
LABEL_78:
    if ( v8 )
      MiUnlockAndDereferenceVad(v8);
    if ( v11 < 0 )
    {
      v37 = v6 + 7;
      while ( v9 )
      {
        v39 = *v37++;
        v38 = v39;
        if ( MI_IS_PFN(v39) )
        {
          v9 = v43;
        }
        else
        {
          MiDereferenceIoPages(1, v38, 1);
          v9 = --v43;
        }
      }
    }
    *v52 = v50;
    return v11;
  }
  if ( (v10 & 0xFFF) != 0 )
    goto LABEL_4;
  if ( a4 >= 4 )
  {
    v11 = -1073741583;
    goto LABEL_78;
  }
  v60 = a1 + v10 - 1;
  v71 = v60;
  if ( v60 <= a1 )
  {
LABEL_4:
    v11 = -1073741584;
    goto LABEL_78;
  }
  v45 = 0;
  __mrc(15, 0, 13, 0, 3);
  v64 = MiGetThreadPartition();
  v69 = v64;
  while ( 1 )
  {
    v12 = MiObtainReferencedVad(v7, &v49);
    v13 = v12;
    v44 = v12;
    v66 = v12;
    if ( !v12 )
    {
      v11 = v49;
      v8 = 0;
      if ( v49 == -1073741664 )
        v11 = -1073741819;
LABEL_12:
      v9 = 0;
      goto LABEL_78;
    }
    v14 = *(_DWORD *)(v12 + 28);
    if ( (v14 & 7) != 6 || *(_DWORD *)(v12 + 16) < v60 >> 12 )
    {
      v11 = -1073741800;
      v8 = v12;
      goto LABEL_12;
    }
    v15 = 1;
    v41 = 1;
    v56 = 1;
    v16 = (unsigned __int8)v14 >> 6;
    if ( v16 == 3 && (v14 & 0x38) != 0 )
    {
      v15 = 2;
    }
    else
    {
      if ( v16 != 1 )
        goto LABEL_21;
      v15 = 0;
    }
    v56 = v15;
    v41 = v15;
LABEL_21:
    v17 = MiPlatformCacheAttributes[v15];
    v51 = v17;
    v58 = MiPlatformCacheAttributes[v15 + 6];
    v18 = v10;
    v53 = v10;
    v68 = v10 >> 12;
    if ( v54 <= 1 )
    {
      v19 = v6 + 7;
      for ( i = 0; i < v10 >> 12; ++i )
      {
        v46 = v19 + 1;
        v49 = *v19;
        if ( !MI_IS_PFN(v49) )
        {
          v11 = MiReferenceIoPages(1, v49, 1, v58, 0, 0);
          if ( v11 < 0 )
            goto LABEL_30;
          v63 = ++v43;
        }
        v19 = v46;
      }
      if ( MiChargeCommit((int)v64, v10 >> 12, 0) )
      {
        v21 = MmSizeOfMdl(v7, v10);
        v22 = ExAllocatePoolWithTag(512, v21, 1868983881);
        v23 = v22;
        v58 = v22;
        if ( v22 )
        {
          *(_DWORD *)v22 = 0;
          v24 = v7 & 0xFFF;
          *(_WORD *)(v22 + 4) = 4 * (((v24 + v10 + 4095) >> 12) + 7);
          *(_WORD *)(v22 + 6) = 0;
          *(_DWORD *)(v22 + 16) = v7 & 0xFFFFF000;
          *(_DWORD *)(v22 + 24) = v24;
          *(_DWORD *)(v22 + 20) = v10;
          MmProbeAndLockPages(v22);
          v25 = v60;
          v73[1] = v44;
          v73[2] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          MiDeleteRotateAndStopFaults(v7, v25, v73);
          v26 = v54;
          if ( !v54 )
          {
            *(_WORD *)(v23 + 6) |= 0x2000u;
            if ( v57(v6, v23, v55) < 0 )
              MiSlowRotateCopy((int)v6, v23, v44, v27);
          }
          MiMapLockedPagesInUserSpaceHelper(v7, v6 + 7, (_DWORD *)(v23 + 28), v41, v10 >> 12, 0, 16);
          MiRotateComplete(v73);
          MiUnlockAndDereferenceVad(v44);
          MmUnlockPages(v23);
          ExFreePoolWithTag(v23);
          *v52 = v10;
          if ( (dword_682604 & 0x8000) != 0 && v10 )
            MiLogVirtualRotateEvent(v7, v10, v26);
          return 0;
        }
        MiReturnCommit((int)v64, v10 >> 12);
      }
      v11 = -1073741670;
LABEL_30:
      v8 = v44;
      v9 = v43;
      goto LABEL_78;
    }
    if ( v54 == 3 )
      break;
    v29 = MmSizeOfMdl(v7, v10);
    if ( v10 > 0x10000 )
    {
      v30 = (_BYTE *)ExAllocatePoolWithTag(512, v29, 1868983881);
      v42 = v30;
      if ( v30 )
        goto LABEL_50;
      v18 = 0x10000;
      v53 = 0x10000;
    }
    v30 = v74;
    v42 = v74;
LABEL_50:
    v31 = MmSizeOfMdl(v7, v18);
    if ( v18 > 0x10000 )
    {
      v6 = (_DWORD *)ExAllocatePoolWithTag(512, v31, 1868983881);
      if ( v6 )
        goto LABEL_54;
      v18 = 0x10000;
      v53 = 0x10000;
    }
    v6 = _F8;
LABEL_54:
    *(_DWORD *)v30 = 0;
    v32 = v7 & 0xFFF;
    v33 = 4 * (((v32 + v18 + 4095) >> 12) + 7);
    *((_WORD *)v30 + 2) = v33;
    *((_WORD *)v30 + 3) = 0;
    *((_DWORD *)v42 + 4) = v7 & 0xFFFFF000;
    *((_DWORD *)v42 + 6) = v32;
    *((_DWORD *)v42 + 5) = v53;
    MmBuildMdlForNonPagedPool((int)v42);
    *((_WORD *)v42 + 3) |= 0x2000u;
    *v6 = 0;
    *((_WORD *)v6 + 2) = v33;
    v6[4] = v7 & 0xFFFFF000;
    v6[6] = v32;
    v34 = v53;
    v6[5] = v53;
    *((_WORD *)v6 + 3) = 0x2000;
    v47 = v45 | 1;
    v51 = MiSwitchToTransition((unsigned int)v6, v44, v51);
    v35 = v6[5];
    if ( v35 == v34 )
    {
      v48 = 0;
    }
    else
    {
      v34 = v6[5];
      v48 = *((_DWORD *)v42 + 5) - v35;
      *((_DWORD *)v42 + 5) = v35;
    }
    if ( v6[5] )
    {
      v49 = v57(v6, (unsigned int)v42, v55);
      if ( v49 < 0 )
        MiSlowRotateCopy((int)v6, (int)v42, v44, v36);
      MiMarkMdlComplete((int)v6, v44);
    }
    MiUnlockAndDereferenceVad(v44);
    v8 = 0;
    if ( (dword_682604 & 0x8000) != 0 && v34 )
      MiLogVirtualRotateEvent(v7, v34, v54);
    if ( v48 )
      *((_DWORD *)v42 + 5) += v48;
    if ( v42 != v74 )
      ExFreePoolWithTag((unsigned int)v42);
    v45 = v47 & 0xFFFFFFFE;
    if ( v6[5] )
      MmUnlockPages((int)v6);
    if ( v6 != _F8 )
      ExFreePoolWithTag((unsigned int)v6);
    v50 += v34;
    v65 = v50;
    v7 += v34;
    v62 = v7;
    if ( v51 == 1 )
    {
      v11 = 1073741849;
      goto LABEL_12;
    }
    v10 -= v34;
    v59 = v10;
    if ( !v10 )
    {
      v11 = 0;
      goto LABEL_12;
    }
    v6 = 0;
    v61 = 0;
  }
  v28 = MiReplaceRotateWithDemandZero(v7, v60, v17);
  MiUnlockAndDereferenceVad(v13);
  *v52 = v10;
  if ( (dword_682604 & 0x8000) != 0 && v10 )
    MiLogVirtualRotateEvent(v7, v10, 3);
  if ( v28 == 1 )
    return 1073741849;
  return 0;
}
