// NtFreeVirtualMemory 
 
int __fastcall NtFreeVirtualMemory(int a1, int *a2, int *a3, int a4)
{
  __int16 v4; // r8
  int v7; // r3
  int v8; // r6
  int v9; // r1
  int *v10; // r2
  int *v11; // r2
  unsigned int v12; // r5
  unsigned int v13; // r9
  int v14; // r4
  unsigned int v15; // r4
  int v16; // r8
  int v17; // r0
  _DWORD *v18; // r6
  unsigned int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // lr
  int v22; // r3
  unsigned int v23; // r4
  int v24; // r2
  __int16 v25; // r3
  int v26; // r4
  unsigned int v27; // r3
  unsigned int v28; // r1
  unsigned int *v29; // r0
  int v30; // r5
  unsigned int v31; // r1
  int v32; // r3
  unsigned int v33; // r9
  unsigned int v34; // r4
  int v35; // r0
  int v36; // r4
  int v37; // r0
  __int16 *v38; // r0
  int v39; // r1
  int v40; // r5
  char v42[4]; // [sp+10h] [bp-90h] BYREF
  int v43; // [sp+14h] [bp-8Ch]
  unsigned int v44; // [sp+18h] [bp-88h]
  unsigned int v45; // [sp+1Ch] [bp-84h]
  int v46; // [sp+20h] [bp-80h]
  int v47; // [sp+24h] [bp-7Ch] BYREF
  unsigned int v48; // [sp+28h] [bp-78h]
  unsigned int v49; // [sp+2Ch] [bp-74h]
  int v50; // [sp+30h] [bp-70h]
  int v51; // [sp+34h] [bp-6Ch]
  int v52; // [sp+38h] [bp-68h] BYREF
  int *v53; // [sp+3Ch] [bp-64h]
  int v54[4]; // [sp+40h] [bp-60h] BYREF
  unsigned int v55; // [sp+50h] [bp-50h]
  _DWORD v56[3]; // [sp+58h] [bp-48h] BYREF
  int v57; // [sp+64h] [bp-3Ch]
  _DWORD _68[20]; // [sp+68h] [bp-38h] BYREF

  _68[16] = a1;
  _68[17] = a2;
  _68[18] = a3;
  v4 = a4;
  v43 = a4;
  _68[19] = a4;
  v53 = a3;
  v50 = a1;
  v47 = a1;
  v46 = (int)a2;
  v45 = (unsigned int)a3;
  v56[0] = 0;
  v56[1] = 0;
  v56[2] = 0;
  v57 = 0;
  if ( (a4 & 0xFFFF3FFF) != 0 && ((a4 & 0x10000) == 0 || (a4 & 0x4000) != 0) )
    return -1073741582;
  v7 = a4 & 0xC000;
  if ( (v4 & 0xC000) == 0 || v7 == 49152 )
    return -1073741582;
  v54[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v51 = v54[0];
  v8 = *(_DWORD *)(v54[0] + 0x74);
  v52 = v8;
  v42[0] = *(_BYTE *)(v54[0] + 0x15A);
  v9 = v42[0];
  if ( v42[0] )
  {
    v10 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v10 = (int *)MmUserProbeAddress;
    *v10 = *v10;
    v11 = a3;
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      v11 = (int *)MmUserProbeAddress;
    *v11 = *v11;
  }
  v55 = *a2;
  v12 = v55;
  v13 = *a3;
  v54[3] = *a3;
  if ( v55 > MmHighestUserAddress )
    return -1073741584;
  if ( MmHighestUserAddress - v55 < v13 )
    return -1073741583;
  v48 = (v13 + v55 - 1) | 0xFFF;
  v15 = v55 & 0xFFFFF000;
  v49 = v55 & 0xFFFFF000;
  v44 = (v55 & 0xFFFFF000) >> 12;
  v45 = v48 >> 12;
  v46 = 0;
  _68[4] = 0;
  if ( v50 == -1 )
  {
    v16 = v8;
    v47 = v8;
  }
  else
  {
    v14 = ObReferenceObjectByHandleWithTag(v50, 8, PsProcessType, v9, 1834380621, &v47, 0);
    v52 = v14;
    if ( v14 < 0 )
      return v14;
    v16 = v47;
    if ( v8 != v47 )
    {
      v46 = 1;
      KiStackAttachProcess(v47, 0, (int)_68);
    }
    v15 = v49;
  }
  v51 = 0;
  v42[0] = 0;
  v17 = MiObtainReferencedVad(v15, &v52);
  v18 = (_DWORD *)v17;
  if ( v17 )
  {
    v51 = v17;
    while ( 1 )
    {
      v19 = v18[3];
      v20 = v18[4];
      if ( v13 )
        break;
      v21 = v18[4];
      v45 = v21;
      v48 = (v20 << 12) | 0xFFF;
      v22 = v43;
      v23 = v44;
      if ( (v43 & 0x8000) != 0 )
      {
        if ( v44 != v19 )
          goto LABEL_68;
        v49 = v19 << 12;
        goto LABEL_29;
      }
LABEL_30:
      if ( v23 < v19 || v23 > v20 || v21 < v19 || v21 > v20 )
      {
        v14 = -1073741798;
        v30 = (unsigned __int8)v42[0];
        goto LABEL_87;
      }
      v24 = v18[7];
      if ( (v22 & 0x10000) != 0 )
      {
        v25 = v43;
        if ( (v24 & 0x8000) != 0 )
          goto LABEL_54;
        if ( (v18[7] & 7) == 1 )
          goto LABEL_54;
        v21 = v45;
        if ( (v24 & 7) != 0 || v44 == v19 && v45 == v20 )
          goto LABEL_54;
      }
      else
      {
        if ( (v24 & 0x8000) == 0 || (v18[7] & 7) == 1 )
        {
LABEL_54:
          v14 = -1073741797;
LABEL_55:
          v30 = (unsigned __int8)v42[0];
          goto LABEL_87;
        }
        v25 = v43;
      }
      v26 = v44;
      if ( (v24 & 0x4000) != 0 )
      {
        if ( (v25 & 0x8000) != 0 )
        {
          v27 = v20 - v19;
          v28 = v19 << 12;
        }
        else
        {
          v27 = v21 - v44;
          v28 = v12;
        }
        v14 = MiCheckSecuredVad(v18, v28, (v27 + 1) << 12, 0x55u);
        if ( v14 < 0 )
          goto LABEL_55;
        v25 = v43;
        v26 = v44;
        v21 = v45;
      }
      if ( (v25 & 0x8000) == 0 )
      {
        v32 = v18[7] & 7;
        if ( v32 == 3 )
        {
          v14 = -1073741664;
          v30 = (unsigned __int8)v42[0];
          goto LABEL_87;
        }
        if ( v32 == 5 )
        {
          v14 = -1073741664;
          v30 = (unsigned __int8)v42[0];
          goto LABEL_87;
        }
        if ( !v13 )
        {
          if ( v12 >> 12 != v18[3] )
          {
LABEL_68:
            v14 = -1073741665;
            v30 = (unsigned __int8)v42[0];
            goto LABEL_87;
          }
          v48 = (v18[4] << 12) | 0xFFF;
        }
        v33 = v49;
        v34 = ((v48 >> 10) & 0x3FFFFC) - 0x40000000;
        MiDecommitPages(v49, v34, v16, (int)v18, 1, v56);
        v35 = ((int)(v34 - (((v33 >> 10) & 0x3FFFFC) - 0x40000000)) >> 2) - v57 + 1;
        v18[8] = v18[8] & 0x80000000 | ((v18[8] & 0x7FFFFFFF) - v35) & 0x7FFFFFFF;
        MiFillCommitReturnInfo(v35, (int)v56, v54);
        v36 = v54[0];
        if ( v54[0] )
        {
          MiReturnProcessCommitment(v16, v54[0]);
          if ( (*(_DWORD *)(v16 + 188) & 0x10) != 0 )
            PspChangeJobMemoryUsageByProcess(16, -v36, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0);
        }
        MiUnlockAndDereferenceVad((int)v18);
        if ( v36 && v16 != PsInitialSystemProcess )
        {
          v37 = *(_DWORD *)(v16 + 332);
          __dmb(0xBu);
          v16 = v47;
          PspReturnQuota(v37, v47, 2, v54[0]);
        }
        if ( v54[1] )
        {
          v38 = MiGetThreadPartition();
          MiReturnCommit((int)v38, v39);
        }
        v40 = v48 - v33 + 1;
        if ( (dword_682604 & 0x8000) != 0 )
          PerfInfoLogVirtualFree(v33, v48 - v33 + 1, v16);
        if ( (v46 & 1) != 0 )
          KiUnstackDetachProcess((unsigned int)_68, 0);
        if ( v50 != -1 )
          ObfDereferenceObjectWithTag(v16);
        *v53 = v40;
        *a2 = v33;
        return 0;
      }
      v29 = MiFreeVadRange((int)v18, (int)v42, v26, v21);
      v14 = (int)v29;
      if ( (int)v29 >= 0 )
      {
        if ( (v46 & 1) != 0 )
          KiUnstackDetachProcess((unsigned int)_68, 0);
        if ( v50 != -1 )
          ObfDereferenceObjectWithTag(v16);
        v31 = v49;
        *v53 = v48 - v49 + 1;
        *a2 = v31;
        return 0;
      }
      if ( v29 != (unsigned int *)-1073741267 )
        goto LABEL_55;
    }
    v23 = v44;
    v21 = v45;
LABEL_29:
    v22 = v43;
    goto LABEL_30;
  }
  v14 = v52;
  v30 = 0;
LABEL_87:
  if ( v51 )
    MiUnlockAndDereferenceVad(v51);
  if ( v30 == 1 )
    UNLOCK_ADDRESS_SPACE(v54[0], v16);
  if ( (v46 & 1) != 0 )
    KiUnstackDetachProcess((unsigned int)_68, 0);
  if ( v50 != -1 )
    ObfDereferenceObjectWithTag(v16);
  return v14;
}
