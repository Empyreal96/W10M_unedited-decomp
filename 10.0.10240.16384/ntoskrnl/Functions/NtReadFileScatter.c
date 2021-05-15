// NtReadFileScatter 
 
int __fastcall NtReadFileScatter(int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6, unsigned int a7, int *a8, int *a9)
{
  int *v9; // r8
  int v10; // r10
  int v11; // r6
  _DWORD *v12; // r5
  _DWORD *v13; // r3
  int v14; // r0
  int v15; // r4
  int v16; // r0
  int v17; // lr
  int v18; // r3
  int v19; // r3
  unsigned int v20; // r0
  unsigned int v21; // r6
  int v22; // r2
  _DWORD *v23; // r2
  int *v24; // r9
  unsigned int v25; // r4
  int v26; // r4
  unsigned int v27; // r3
  int v28; // r3
  unsigned int v29; // r2
  int *v30; // r2
  int v31; // r0
  int v32; // r10
  int v33; // r3
  unsigned int v34; // r2
  unsigned int *v35; // r2
  unsigned int v36; // r1
  unsigned int v37; // r1
  __int16 v38; // r3
  int v39; // r3
  int v40; // r10
  unsigned int *v41; // r2
  unsigned int v42; // r1
  int v43; // r0
  unsigned int v44; // r1
  int v45; // r3
  int v46; // r0
  int v47; // r4
  _DWORD *v48; // r9
  int v49; // r0
  int v50; // r3
  int v52; // [sp+0h] [bp-98h]
  int v53; // [sp+8h] [bp-90h]
  int v54; // [sp+Ch] [bp-8Ch]
  int v55; // [sp+10h] [bp-88h] BYREF
  int v56; // [sp+14h] [bp-84h]
  int *v57; // [sp+18h] [bp-80h]
  int v58; // [sp+1Ch] [bp-7Ch]
  int v59; // [sp+20h] [bp-78h]
  int v60; // [sp+24h] [bp-74h]
  int v61; // [sp+28h] [bp-70h]
  int v62; // [sp+2Ch] [bp-6Ch]
  int v63; // [sp+30h] [bp-68h]
  int v64; // [sp+34h] [bp-64h] BYREF
  int v65; // [sp+38h] [bp-60h]
  int v66; // [sp+40h] [bp-58h]
  int v67; // [sp+44h] [bp-54h]
  unsigned int v68; // [sp+48h] [bp-50h] BYREF
  int v69; // [sp+4Ch] [bp-4Ch]
  _DWORD *v70; // [sp+50h] [bp-48h]
  unsigned int v71; // [sp+54h] [bp-44h]
  _DWORD *v72; // [sp+58h] [bp-40h] BYREF
  int *v73; // [sp+5Ch] [bp-3Ch]
  unsigned int v74; // [sp+60h] [bp-38h]
  int v75; // [sp+64h] [bp-34h]
  _DWORD *v76; // [sp+68h] [bp-30h]
  unsigned int v77; // [sp+6Ch] [bp-2Ch]
  int v78; // [sp+70h] [bp-28h]
  unsigned int v79; // [sp+74h] [bp-24h]
  int vars4; // [sp+9Ch] [bp+4h]
  int varg_r0; // [sp+A0h] [bp+8h]
  int varg_r1; // [sp+A4h] [bp+Ch]
  int varg_r2; // [sp+A8h] [bp+10h]
  int varg_r3; // [sp+ACh] [bp+14h]

  varg_r0 = a1;
  v70 = (_DWORD *)a4;
  varg_r3 = a4;
  v75 = a3;
  varg_r2 = a3;
  v61 = a2;
  varg_r1 = a2;
  v9 = 0;
  v73 = 0;
  v10 = 0;
  v63 = 0;
  v74 = 0;
  v65 = 0;
  v69 = 0;
  v62 = 0;
  v66 = 0;
  v59 = 0;
  v67 = 0;
  v77 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v68 = v77;
  v56 = *(char *)(v77 + 0x15A);
  LOBYTE(v58) = v56;
  v11 = ObReferenceObjectByHandle(a1, 1, IoFileObjectType, v56, &v72);
  v12 = v72;
  v76 = v72;
  if ( v11 >= 0 )
  {
    v13 = (_DWORD *)v72[31];
    if ( v13 )
    {
      if ( (*v13 & 4) != 0 )
      {
        v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v64 = 0;
        v15 = PsReferencePrimaryToken(v14);
        SeQueryInformationToken(v15, 29, &v64);
        ObfDereferenceObject(v15);
        if ( v64 )
        {
          ObfDereferenceObject((int)v12);
          v11 = -1073739504;
        }
      }
    }
  }
  if ( v11 >= 0 )
  {
    v16 = IoGetRelatedDeviceObject(v12);
    v17 = v16;
    v64 = v16;
    v72 = (_DWORD *)v16;
    v18 = v12[11];
    if ( (v18 & 8) == 0
      || (v18 & 2) != 0
      || (*(_DWORD *)(v16 + 28) & 4) != 0
      || (v19 = *(_DWORD *)(v16 + 44), v19 != 8)
      && v19 != 6
      && v19 != 32
      && v19 != 3
      && v19 != 20
      && v19 != 9
      && v19 != 54
      && v19 != 83 )
    {
      ObfDereferenceObject((int)v12);
      return -1073741811;
    }
    v20 = a7;
    v21 = ((a7 & 0xFFF) != 0) + (a7 >> 12);
    v22 = v56;
    if ( v56 )
    {
      v78 = 0;
      v71 = a5;
      v23 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v23 = (_DWORD *)MmUserProbeAddress;
      *v23 = *v23;
      if ( v12[27] && v75 )
        goto LABEL_23;
      v24 = a8;
      if ( a8 )
      {
        if ( ((unsigned __int8)a8 & 3) != 0 )
          ExRaiseDatatypeMisalignment(a7);
        v62 = *a8;
        v66 = v62;
        v59 = a8[1];
        v67 = v59;
      }
      if ( (v12[11] & 8) != 0 )
      {
        v25 = *(unsigned __int16 *)(v17 + 172);
        if ( *(_WORD *)(v17 + 172) && ((v25 - 1) & a7) != 0 )
        {
          if ( !*(_WORD *)(v17 + 172) )
            __brkdiv0();
          if ( a7 % v25 )
            goto LABEL_23;
          v20 = a7;
        }
        if ( a8 && *(_WORD *)(v17 + 172) && ((v25 - 1) & v62) != 0 )
        {
LABEL_23:
          ObfDereferenceObject((int)v12);
          v11 = -1073741811;
          v60 = -1073741811;
          v57 = (int *)a6;
          return v11;
        }
      }
      v26 = 8 * v21;
      v57 = (int *)a6;
      if ( 8 * v21 )
      {
        if ( (a6 & 7) != 0 )
          ExRaiseDatatypeMisalignment(v20);
        v27 = MmUserProbeAddress;
        if ( v26 + a6 > MmUserProbeAddress || v26 + a6 < a6 )
        {
          *(_BYTE *)MmUserProbeAddress = 0;
          v27 = MmUserProbeAddress;
        }
      }
      else
      {
        v27 = MmUserProbeAddress;
      }
      if ( v20 )
      {
        if ( ViVerifierDriverAddedThunkListHead )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v28 = 40;
          else
            v28 = 32;
          v9 = (int *)ExAllocatePoolWithTagPriority(1, 8 * v21, 538996553, v28);
          if ( !v9 )
            RtlRaiseStatus(-1073741670);
        }
        else
        {
          v9 = (int *)ExAllocatePoolWithQuotaTag(1u, 8 * v21, 538996553);
        }
        v73 = v9;
        memmove((int)v9, a6, 8 * v21);
        v57 = v9;
        v29 = 0;
        v79 = 0;
        while ( v29 < v21 )
        {
          if ( (v9[2 * v29] & 0xFFF) != 0 )
            RtlRaiseStatus(-1073741811);
          v79 = ++v29;
        }
        v27 = MmUserProbeAddress;
      }
      v30 = a9;
      if ( a9 )
      {
        if ( (unsigned int)a9 >= v27 )
          v30 = (int *)v27;
        v65 = *v30;
        v69 = v65;
      }
      v10 = 0;
      v31 = v61;
      v22 = v56;
    }
    else
    {
      v24 = a8;
      if ( a8 )
      {
        v62 = *a8;
        v66 = v62;
        v59 = a8[1];
        v67 = v59;
      }
      v31 = v61;
      if ( a9 )
      {
        v65 = *a9;
        v69 = v65;
      }
      v57 = (int *)a6;
      v71 = a5;
    }
    if ( v31 )
    {
      v32 = ObReferenceObjectByHandle(v31, 2, ExEventObjectType, v22, &v68);
      v63 = v68;
      v74 = v68;
      if ( v32 < 0 )
      {
LABEL_72:
        ObfDereferenceObject((int)v12);
        if ( v9 )
          ExFreePoolWithTag((unsigned int)v9);
        return v32;
      }
      v10 = v63;
      KeResetEvent(v63);
    }
    v33 = v12[11];
    if ( (v33 & 2) != 0 )
    {
      v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v34 + 308);
      __dmb(0xBu);
      v35 = v12 + 17;
      do
        v36 = __ldrex(v35);
      while ( __strex(1u, v35) );
      __dmb(0xBu);
      if ( v36 )
      {
        v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v38 = *(_WORD *)(v37 + 0x134) + 1;
        *(_WORD *)(v37 + 308) = v38;
        if ( !v38 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
          KiCheckForKernelApcDelivery(1);
        v32 = IopAcquireFileObjectLock(v12, v56, (v12[11] & 4) != 0, &v55);
        if ( (_BYTE)v55 )
        {
          if ( v63 )
            ObfDereferenceObject(v63);
          goto LABEL_72;
        }
      }
      else
      {
        ObfReferenceObject((int)v12);
      }
      if ( !v24 || (v39 = v59, v62 == -2) && v59 == -1 )
      {
        v62 = v12[14];
        v66 = v62;
        v39 = v12[15];
        v59 = v39;
        v67 = v39;
      }
      v40 = 1;
    }
    else
    {
      if ( !v24 && (v33 & 0x280) == 0 )
      {
        if ( v10 )
          ObfDereferenceObject(v10);
        goto LABEL_97;
      }
      v40 = 0;
      v39 = v59;
    }
    LOBYTE(v55) = v40;
    if ( v39 < 0 )
    {
      if ( v63 )
        ObfDereferenceObject(v63);
      if ( v40 )
      {
        __dmb(0xBu);
        v41 = v12 + 17;
        do
          v42 = __ldrex(v41);
        while ( __strex(0, v41) );
        __dmb(0xBu);
        if ( v12[16] )
          KeSetEvent((int)(v12 + 19), 0, 0);
        v43 = ObfDereferenceObject((int)v12);
        v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v45 = (__int16)(*(_WORD *)(v44 + 0x134) + 1);
        *(_WORD *)(v44 + 308) = v45;
        if ( !v45 && *(_DWORD *)(v44 + 100) != v44 + 100 && !*(_WORD *)(v44 + 310) )
          KiCheckForKernelApcDelivery(v43);
      }
LABEL_97:
      ObfDereferenceObject((int)v12);
      if ( v9 )
        ExFreePoolWithTag((unsigned int)v9);
      return -1073741811;
    }
    if ( (v12[11] & 0x4000000) == 0 )
      KeResetEvent((int)(v12 + 23));
    v46 = pIoAllocateIrp(v64, *(char *)(v64 + 48), v40 == 0, vars4);
    v47 = v46;
    v68 = v46;
    if ( v46 )
    {
      *(_DWORD *)(v46 + 100) = v12;
      *(_DWORD *)(v46 + 80) = v77;
      *(_DWORD *)(v46 + 84) = 0;
      *(_BYTE *)(v46 + 32) = v56;
      *(_BYTE *)(v46 + 33) = 0;
      *(_BYTE *)(v46 + 36) = 0;
      *(_DWORD *)(v46 + 56) = 0;
      *(_DWORD *)(v46 + 44) = v63;
      *(_DWORD *)(v46 + 40) = v71;
      *(_DWORD *)(v46 + 48) = v75;
      *(_DWORD *)(v46 + 52) = v70;
      v48 = (_DWORD *)(*(_DWORD *)(v46 + 96) - 40);
      v70 = v48;
      *v48 = 3;
      v48[7] = v12;
      *(_DWORD *)(v46 + 12) = 0;
      *(_DWORD *)(v46 + 4) = 0;
      *(_DWORD *)(v46 + 8) = 0;
      if ( a7 )
      {
        v49 = IoAllocateMdl(*v57, a7, 0, 1, v46);
        if ( !v49 )
          RtlRaiseStatus(-1073741670);
        MmProbeAndLockSelectedPages(v49, (int)v57, v56, 1, v52, 0, v53, v54, v55, v56, (int)v57, v58, v59);
        *(_DWORD *)(v47 + 60) = *v57;
      }
      if ( v9 )
        ExFreePoolWithTag((unsigned int)v9);
      if ( (v12[11] & 8) != 0 )
        v50 = *(_DWORD *)(v47 + 8) | 0x901;
      else
        v50 = *(_DWORD *)(v47 + 8) | 0x900;
      *(_DWORD *)(v47 + 8) = v50;
      v48[2] = a7;
      v48[3] = v65;
      v48[4] = v62;
      v48[5] = v59;
      v11 = IopSynchronousServiceTail(v64, v47, v12, 1, v56, v40, 0);
    }
    else
    {
      IopAllocateIrpCleanup(v12, v63);
      if ( v9 )
        ExFreePoolWithTag((unsigned int)v9);
      v11 = -1073741670;
    }
  }
  return v11;
}
