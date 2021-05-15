// BuildQueryDirectoryIrp 
 
int __fastcall BuildQueryDirectoryIrp(int a1, int a2, int a3, int a4, unsigned int a5, int a6, unsigned int a7, int a8, char a9, int *a10, char a11, int a12, _BYTE *a13, int *a14, int *a15, _DWORD *a16, _BYTE *a17)
{
  int v17; // r6
  int v18; // r5
  unsigned int v19; // r1
  _DWORD *v20; // r2
  int v21; // r10
  int v22; // r2
  int *v23; // r2
  unsigned int v24; // r9
  unsigned int v25; // r6
  int v26; // r10
  int v27; // r3
  int v28; // r4
  int v29; // r9
  _DWORD *v30; // r6
  _DWORD *v31; // r3
  int v32; // r0
  int v33; // r4
  int v34; // r4
  int v35; // r9
  int v36; // r2
  unsigned int *v37; // r2
  unsigned int v38; // r1
  unsigned int v39; // r1
  __int16 v40; // r3
  _BYTE *v41; // r4
  int v42; // r9
  int v43; // r0
  _DWORD *v44; // r4
  int v45; // r1
  unsigned __int8 *v46; // r5
  unsigned int v47; // r6
  int v48; // r3
  int v49; // r0
  int v50; // r3
  int v51; // r3
  int v52; // r0
  int v53; // r2
  char v55[4]; // [sp+8h] [bp-70h] BYREF
  _DWORD *v56; // [sp+Ch] [bp-6Ch] BYREF
  int v57; // [sp+10h] [bp-68h] BYREF
  unsigned int v58; // [sp+14h] [bp-64h]
  int v59; // [sp+18h] [bp-60h]
  int v60; // [sp+1Ch] [bp-5Ch]
  int v61; // [sp+20h] [bp-58h]
  int v62; // [sp+24h] [bp-54h]
  int v63; // [sp+28h] [bp-50h]
  unsigned __int8 *v64; // [sp+2Ch] [bp-4Ch]
  int v65; // [sp+30h] [bp-48h]
  int v66; // [sp+34h] [bp-44h]
  int v67; // [sp+38h] [bp-40h]
  unsigned int v68; // [sp+3Ch] [bp-3Ch]
  int v69; // [sp+40h] [bp-38h]
  unsigned int v70; // [sp+44h] [bp-34h]
  int v71; // [sp+48h] [bp-30h]
  int v72; // [sp+50h] [bp-28h]
  unsigned int v73; // [sp+54h] [bp-24h]
  int vars4; // [sp+7Ch] [bp+4h]
  int varg_r0; // [sp+80h] [bp+8h]
  int varg_r1; // [sp+84h] [bp+Ch]
  int varg_r2; // [sp+88h] [bp+10h]
  int varg_r3; // [sp+8Ch] [bp+14h]

  v64 = (unsigned __int8 *)a4;
  varg_r3 = a4;
  v69 = a3;
  varg_r2 = a3;
  v61 = a2;
  varg_r1 = a2;
  v17 = a1;
  v56 = (_DWORD *)a1;
  varg_r0 = a1;
  v65 = 0;
  v66 = 0;
  v59 = 0;
  v67 = 0;
  v70 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v57 = v70;
  v18 = *(char *)(v70 + 0x15A);
  v71 = v18;
  v55[0] = v18;
  *a17 = v18;
  if ( !v18 )
  {
    v63 = a8;
    v58 = a7;
    v60 = a6;
    v68 = a5;
    goto LABEL_34;
  }
  v19 = 0;
  v68 = a5;
  v20 = (_DWORD *)a5;
  if ( a5 >= MmUserProbeAddress )
    v20 = (_DWORD *)MmUserProbeAddress;
  *v20 = *v20;
  v63 = a8;
  if ( a8 == 1 )
    goto LABEL_5;
  if ( a8 == 3 )
    goto LABEL_29;
  if ( a8 > 37 )
  {
    if ( a8 > 60 )
    {
      if ( a8 == 63 )
        v19 = 120;
      goto LABEL_27;
    }
    if ( a8 != 60 )
    {
      if ( a8 == 38 )
      {
        v19 = 88;
        goto LABEL_30;
      }
      if ( a8 != 50 )
      {
LABEL_27:
        if ( !v19 )
        {
          v21 = -1073741821;
          v62 = -1073741821;
          v58 = a7;
          v60 = a6;
          return v21;
        }
        goto LABEL_30;
      }
    }
LABEL_29:
    v19 = 96;
    goto LABEL_30;
  }
  if ( a8 == 37 )
  {
    v19 = 112;
    goto LABEL_30;
  }
  if ( a8 > 29 )
  {
    if ( a8 == 32 )
    {
      v19 = 56;
      goto LABEL_30;
    }
    if ( a8 == 33 )
    {
      v19 = 16;
      goto LABEL_30;
    }
    goto LABEL_27;
  }
  if ( a8 != 29 && a8 != 2 )
  {
    if ( a8 == 12 )
    {
      v19 = 16;
      goto LABEL_30;
    }
    goto LABEL_27;
  }
LABEL_5:
  v19 = 72;
LABEL_30:
  v58 = a7;
  if ( a7 < v19 )
  {
    v21 = -1073741820;
    v62 = -1073741820;
    v60 = a6;
    return v21;
  }
  v22 = *((unsigned __int8 *)IopQuerySetAlignmentRequirement + a8);
  v60 = a6;
  ProbeForWrite(a6, a7, v22);
LABEL_34:
  v23 = a10;
  if ( a10 )
  {
    if ( v18 )
    {
      if ( (unsigned int)a10 >= MmUserProbeAddress )
        v23 = (int *)MmUserProbeAddress;
      v72 = *v23;
      v24 = v23[1];
    }
    else
    {
      v72 = *a10;
      v24 = a10[1];
    }
    v73 = v24;
    v25 = (unsigned __int16)v72;
    if ( (v72 & 1) != 0 )
    {
      v21 = -1073741811;
      v62 = -1073741811;
      return v21;
    }
    if ( (_WORD)v72 )
    {
      if ( v18 )
      {
        if ( (unsigned __int16)v72 + v24 > MmUserProbeAddress || (unsigned __int16)v72 + v24 < v24 )
          *(_BYTE *)MmUserProbeAddress = 0;
        if ( v25 >= 0x200 )
          RtlRaiseStatus(-1073741811);
      }
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v27 = 40;
        else
          v27 = 32;
        v26 = ExAllocatePoolWithTagPriority(512, v25 + 8, 538996553, v27);
        v59 = v26;
        if ( !v26 )
          RtlRaiseStatus(-1073741670);
      }
      else
      {
        v26 = ExAllocatePoolWithQuotaTag(0x200u, v25 + 8, 538996553);
        v59 = v26;
      }
      v67 = v26;
      memmove(v26 + 8, v24, v25);
      *(_WORD *)v26 = v25;
      *(_WORD *)(v26 + 2) = v25;
      *(_DWORD *)(v26 + 4) = v26 + 8;
    }
    v17 = (int)v56;
  }
  v28 = v61;
  v29 = ObReferenceObjectByHandle(v17, 1, IoFileObjectType, v18, &v56, 0);
  v30 = v56;
  if ( v29 < 0 )
    goto LABEL_65;
  v31 = (_DWORD *)v56[31];
  if ( v31 && (*v31 & 4) != 0 )
  {
    v32 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v57 = 0;
    v33 = PsReferencePrimaryToken(v32);
    SeQueryInformationToken(v33, 29, &v57);
    ObfDereferenceObject(v33);
    if ( v57 )
    {
      ObfDereferenceObject((int)v30);
      v29 = -1073739504;
LABEL_65:
      if ( v59 )
        ExFreePoolWithTag(v59);
      return v29;
    }
    v28 = v61;
  }
  *a16 = v30;
  if ( v30[27] && v69 )
  {
    ObfDereferenceObject((int)v30);
    if ( v59 )
      ExFreePoolWithTag(v59);
    return -1073741811;
  }
  if ( v28 )
  {
    v34 = ObReferenceObjectByHandle(v28, 2, ExEventObjectType, v18, &v57, 0);
    v35 = v57;
    v65 = v57;
    v66 = v57;
    if ( v34 < 0 )
    {
      if ( v59 )
        ExFreePoolWithTag(v59);
LABEL_77:
      ObfDereferenceObject((int)v30);
      return v34;
    }
    KeResetEvent(v57);
  }
  else
  {
    v35 = v65;
  }
  if ( (v30[11] & 2) != 0 )
  {
    v36 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v36 & 0xFFFFFFC0) + 0x134);
    __dmb(0xBu);
    v37 = v30 + 17;
    do
      v38 = __ldrex(v37);
    while ( __strex(1u, v37) );
    __dmb(0xBu);
    if ( v38 )
    {
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v40 = *(_WORD *)(v39 + 0x134) + 1;
      *(_WORD *)(v39 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
        KiCheckForKernelApcDelivery(1);
      v34 = IopAcquireFileObjectLock(v30, v18, (v30[11] & 4) != 0, v55);
      if ( v55[0] )
      {
        if ( v59 )
          ExFreePoolWithTag(v59);
        if ( v35 )
          ObfDereferenceObject(v35);
        goto LABEL_77;
      }
    }
    else
    {
      ObfReferenceObject((int)v30);
    }
    v41 = a13;
    *a13 = 1;
  }
  else
  {
    v41 = a13;
    *a13 = 0;
  }
  if ( (v30[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v30 + 23));
  v42 = IoGetRelatedDeviceObject(v30);
  *a14 = v42;
  v43 = pIoAllocateIrp(v42, *(char *)(v42 + 48), *v41 == 0, vars4);
  v44 = (_DWORD *)v43;
  v57 = v43;
  v45 = v65;
  if ( v43 )
  {
    *a15 = v43;
    *(_DWORD *)(v43 + 100) = v30;
    *(_DWORD *)(v43 + 80) = v70;
    *(_BYTE *)(v43 + 32) = v18;
    *(_DWORD *)(v43 + 44) = v45;
    *(_DWORD *)(v43 + 40) = v68;
    *(_DWORD *)(v43 + 48) = v69;
    *(_DWORD *)(v43 + 52) = v64;
    v46 = (unsigned __int8 *)(*(_DWORD *)(v43 + 96) - 40);
    v64 = v46;
    *v46 = 12;
    v46[1] = 1;
    *((_DWORD *)v46 + 7) = v30;
    v47 = v59;
    *(_DWORD *)(v43 + 84) = v59;
    *(_DWORD *)(v43 + 12) = 0;
    *(_DWORD *)(v43 + 4) = 0;
    v48 = *(_DWORD *)(v42 + 28);
    if ( (v48 & 4) != 0 )
    {
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v50 = 40;
        else
          v50 = 32;
        v49 = ExAllocatePoolWithTagPriority(512, v58, 538996553, v50);
        if ( !v49 )
          RtlRaiseStatus(-1073741670);
      }
      else
      {
        v49 = ExAllocatePoolWithQuotaTag(0x200u, v58, 538996553);
      }
      v44[3] = v49;
      v51 = v63;
      v44[15] = v60;
      v44[2] = 112;
    }
    else if ( (v48 & 0x10) != 0 )
    {
      v52 = IoAllocateMdl(v60, v58, 0, 1, v43);
      if ( !v52 )
        RtlRaiseStatus(-1073741670);
      sub_564C10(v52, v71, v53, v42, *v46);
      v51 = v63;
    }
    else
    {
      *(_DWORD *)(v43 + 60) = v60;
      v51 = v63;
    }
    *((_DWORD *)v46 + 2) = v58;
    *((_DWORD *)v46 + 4) = v51;
    *((_DWORD *)v46 + 5) = 0;
    *((_DWORD *)v46 + 3) = v47;
    v46[2] = 0;
    if ( a11 )
      v46[2] = 1;
    if ( a9 )
      v46[2] |= 2u;
    v44[2] |= 0x800u;
    v21 = 0;
  }
  else
  {
    IopAllocateIrpCleanup(v30, v65);
    if ( v59 )
      ExFreePoolWithTag(v59);
    v21 = -1073741670;
  }
  return v21;
}
