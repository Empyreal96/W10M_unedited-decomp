// NtQueryEaFile 
 
int __fastcall NtQueryEaFile(int a1, _DWORD *a2, unsigned int a3, int a4, char a5, unsigned int a6, unsigned int a7, int *a8, char a9)
{
  int v10; // r8
  int v11; // r10
  _DWORD *v12; // r2
  unsigned int v13; // r0
  int *v14; // r3
  int v15; // r3
  int v16; // r0
  int v17; // r1
  _DWORD *v18; // r2
  int v19; // r5
  unsigned int v20; // r3
  int v21; // r2
  int v22; // r4
  _DWORD *v23; // r2
  int v24; // r0
  int v25; // r3
  int v26; // r6
  _DWORD *v27; // r9
  _DWORD *v28; // r3
  int v29; // r0
  int v30; // r4
  unsigned int v31; // r2
  unsigned int *v32; // r2
  unsigned int v33; // r1
  unsigned int v34; // r1
  __int16 v35; // r3
  int v36; // r4
  int v37; // r10
  int v38; // r0
  int v39; // r3
  int v40; // r0
  _DWORD *v41; // r4
  _DWORD *v42; // r3
  unsigned __int8 *v43; // r6
  int v44; // r8
  int v45; // r3
  int v46; // r0
  int v47; // r3
  int v48; // r0
  int v49; // r6
  int v50; // r0
  char v52; // [sp+10h] [bp-78h] BYREF
  char v53; // [sp+11h] [bp-77h]
  char v54; // [sp+12h] [bp-76h]
  _DWORD *v55; // [sp+14h] [bp-74h] BYREF
  int v56; // [sp+18h] [bp-70h]
  _DWORD *v57; // [sp+1Ch] [bp-6Ch]
  int v58; // [sp+20h] [bp-68h]
  int v59; // [sp+24h] [bp-64h]
  int v60; // [sp+28h] [bp-60h]
  int v61; // [sp+2Ch] [bp-5Ch]
  unsigned int v62; // [sp+30h] [bp-58h] BYREF
  unsigned int v63; // [sp+34h] [bp-54h]
  int v64; // [sp+38h] [bp-50h]
  int v65; // [sp+3Ch] [bp-4Ch]
  unsigned int v66; // [sp+40h] [bp-48h]
  unsigned int v67; // [sp+44h] [bp-44h]
  int *v68; // [sp+48h] [bp-40h]
  int v69; // [sp+4Ch] [bp-3Ch]
  int v70; // [sp+50h] [bp-38h]
  int v71; // [sp+54h] [bp-34h]
  int v72; // [sp+58h] [bp-30h]
  _DWORD _60[16]; // [sp+60h] [bp-28h] BYREF

  v63 = a4;
  _60[15] = a4;
  v69 = a3;
  _60[14] = a3;
  v57 = a2;
  _60[13] = a2;
  v55 = (_DWORD *)a1;
  _60[12] = a1;
  v59 = 0;
  v70 = 0;
  v10 = 0;
  v58 = 0;
  v11 = 0;
  v61 = 0;
  v53 = 0;
  v64 = 0;
  v65 = 0;
  v67 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v62 = v67;
  v60 = *(char *)(v67 + 0x15A);
  v54 = v60;
  if ( !v60 )
  {
    if ( a6 )
    {
      v66 = a7;
      if ( a7 )
      {
        v11 = 1;
        v61 = 1;
        v53 = 1;
        if ( ViVerifierDriverAddedThunkListHead )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v25 = 40;
          else
            v25 = 32;
          v10 = ExAllocatePoolWithTagPriority(512, a7, 538996553, v25);
          if ( !v10 )
            RtlRaiseStatus(-1073741670);
          v11 = v61;
        }
        else
        {
          v10 = ExAllocatePoolWithQuotaTag(0x200u, a7, 538996553);
        }
        v58 = v10;
        memmove(v10, a6, a7);
      }
    }
    else
    {
      v66 = a7;
    }
    v68 = a8;
    v24 = (int)v55;
    if ( a8 )
    {
      v64 = *a8;
      v65 = v64;
    }
LABEL_52:
    v26 = ObReferenceObjectByHandle(v24, 8, (int)IoFileObjectType, v60, (int)&v55, 0);
    v27 = v55;
    if ( v26 >= 0 )
    {
      v28 = (_DWORD *)v55[31];
      if ( v28 )
      {
        if ( (*v28 & 4) != 0 )
        {
          v29 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v62 = 0;
          v30 = PsReferencePrimaryToken(v29);
          SeQueryInformationToken(v30, 29, &v62);
          ObfDereferenceObject(v30);
          if ( v62 )
          {
            ObfDereferenceObject((int)v27);
            v26 = -1073739504;
          }
        }
      }
    }
    if ( v26 < 0 )
    {
      if ( v11 )
        ExFreePoolWithTag(v10);
      return v26;
    }
    if ( (v27[11] & 2) != 0 )
    {
      v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v31 + 308);
      __dmb(0xBu);
      v32 = v27 + 17;
      do
        v33 = __ldrex(v32);
      while ( __strex(1u, v32) );
      __dmb(0xBu);
      if ( !v33 )
      {
        ObfReferenceObject((int)v27);
LABEL_74:
        v37 = 1;
LABEL_87:
        v52 = v37;
        if ( (v27[11] & 0x4000000) == 0 )
          KeResetEvent((int)(v27 + 23));
        v72 = IoGetRelatedDeviceObject(v27);
        v71 = v72;
        v40 = pIoAllocateIrp(v72, *(char *)(v72 + 48), 0, _60[11]);
        v41 = (_DWORD *)v40;
        v62 = v40;
        if ( v40 )
        {
          *(_DWORD *)(v40 + 100) = v27;
          *(_DWORD *)(v40 + 80) = v67;
          *(_BYTE *)(v40 + 32) = v60;
          if ( v37 )
          {
            *(_DWORD *)(v40 + 44) = 0;
            v42 = v57;
          }
          else
          {
            *(_DWORD *)(v40 + 44) = v59;
            v42 = _60;
            *(_DWORD *)(v40 + 8) = 4;
          }
          *(_DWORD *)(v40 + 40) = v42;
          *(_DWORD *)(v40 + 48) = 0;
          v43 = (unsigned __int8 *)(*(_DWORD *)(v40 + 96) - 40);
          v67 = (unsigned int)v43;
          *v43 = 7;
          *((_DWORD *)v43 + 7) = v27;
          if ( v61 )
          {
            *(_DWORD *)(v40 + 84) = v10;
            *((_DWORD *)v43 + 3) = v10;
            *((_DWORD *)v43 + 4) = v66;
          }
          v44 = v72;
          v45 = *(_DWORD *)(v72 + 28);
          if ( (v45 & 4) != 0 )
          {
            if ( v63 )
            {
              if ( ViVerifierDriverAddedThunkListHead )
              {
                if ( (MmVerifierData & 0x10) != 0 )
                  v47 = 40;
                else
                  v47 = 32;
                v46 = ExAllocatePoolWithTagPriority(512, v63, 538996553, v47);
                if ( !v46 )
                  RtlRaiseStatus(-1073741670);
              }
              else
              {
                v46 = ExAllocatePoolWithQuotaTag(0x200u, v63, 538996553);
              }
              v41[3] = v46;
              v41[15] = v69;
              v41[2] |= 0x70u;
            }
            else
            {
              *(_DWORD *)(v40 + 12) = 0;
              *(_DWORD *)(v40 + 8) |= 0x50u;
            }
          }
          else if ( (v45 & 0x10) != 0 )
          {
            if ( v63 )
            {
              v48 = IoAllocateMdl(v69, v63, 0, 1, v40);
              if ( !v48 )
                RtlRaiseStatus(-1073741670);
              sub_564C48(v48, v60, 1, v44, *v43);
            }
          }
          else
          {
            *(_DWORD *)(v40 + 60) = v69;
          }
          *((_DWORD *)v43 + 2) = v63;
          *((_DWORD *)v43 + 5) = v64;
          v43[2] = 0;
          if ( a9 )
            v43[2] = 1;
          if ( a5 )
            v43[2] |= 2u;
          if ( v68 )
            v43[2] |= 4u;
          v49 = v60;
          v50 = IopSynchronousServiceTail(v44, (int)v41, v27, 0, v60, v37, 2);
          v19 = v50;
          if ( !v37 )
            v19 = IopSynchronousApiServiceTail(v50, v59, (int)v41, v49, _60, v57);
        }
        else
        {
          if ( (v27[11] & 2) == 0 )
            ExFreePoolWithTag(v59);
          IopAllocateIrpCleanup((int)v27, 0);
          if ( v61 )
            ExFreePoolWithTag(v10);
          v19 = -1073741670;
        }
        return v19;
      }
      v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v35 = *(_WORD *)(v34 + 0x134) + 1;
      *(_WORD *)(v34 + 308) = v35;
      if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
        KiCheckForKernelApcDelivery(1);
      v36 = IopAcquireFileObjectLock((int)v27, v60, (v27[11] & 4) != 0, &v52);
      if ( !v52 )
        goto LABEL_74;
      if ( v11 )
        ExFreePoolWithTag(v10);
      v19 = v36;
    }
    else
    {
      if ( ViVerifierDriverAddedThunkListHead )
      {
        if ( (MmVerifierData & 0x10) != 0 )
          v39 = 40;
        else
          v39 = 32;
        v38 = ExAllocatePoolWithTagPriority(512, 0x10u, 538996553, v39);
      }
      else
      {
        v38 = ExAllocatePoolWithTag(512, 16, 538996553);
      }
      v59 = v38;
      v70 = v38;
      if ( v38 )
      {
        KeInitializeEvent(v38, 1, 0);
        v37 = 0;
        goto LABEL_87;
      }
      if ( v11 )
        ExFreePoolWithTag(v10);
      v19 = -1073741670;
    }
    ObfDereferenceObject((int)v27);
    return v19;
  }
  v12 = a2;
  if ( (unsigned int)a2 >= MmUserProbeAddress )
    v12 = (_DWORD *)MmUserProbeAddress;
  *v12 = *v12;
  v13 = ProbeForWrite(a3, a4, 4);
  v68 = a8;
  if ( a8 )
  {
    v14 = a8;
    if ( (unsigned int)a8 >= MmUserProbeAddress )
      v14 = (int *)MmUserProbeAddress;
    v64 = *v14;
    v65 = v64;
  }
  if ( !a6 )
  {
    v66 = a7;
    goto LABEL_37;
  }
  v66 = a7;
  if ( !a7 )
  {
LABEL_37:
    v24 = (int)v55;
    goto LABEL_52;
  }
  v11 = 1;
  v61 = 1;
  v53 = 1;
  if ( (a6 & 3) != 0 )
    ExRaiseDatatypeMisalignment(v13);
  if ( a6 + a7 > MmUserProbeAddress || a6 + a7 < a6 )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v15 = 40;
    else
      v15 = 32;
    v10 = ExAllocatePoolWithTagPriority(512, a7, 538996553, v15);
    if ( !v10 )
      RtlRaiseStatus(-1073741670);
    v11 = v61;
  }
  else
  {
    v10 = ExAllocatePoolWithQuotaTag(0x200u, a7, 538996553);
  }
  v58 = v10;
  memmove(v10, a6, a7);
  v16 = v10;
  v17 = a7;
  while ( 1 )
  {
    if ( v17 < 5 )
    {
      ExFreePoolWithTag(v10);
      v58 = 0;
      v18 = v57;
      *v57 = -2147483628;
      v18[1] = 0;
      v19 = -2147483628;
      v56 = -2147483628;
      return v19;
    }
    v20 = *(unsigned __int8 *)(v16 + 4) + 6;
    if ( v17 < v20 )
      break;
    v21 = *(_DWORD *)v16;
    if ( !*(_DWORD *)v16 )
    {
      if ( (int)(v17 - v20) >= 0 )
        goto LABEL_37;
      break;
    }
    if ( ((*(unsigned __int8 *)(v16 + 4) + 9) & 0xFFFFFFFC) != v21 )
      break;
    if ( v21 < 0 )
      break;
    v17 -= v21;
    if ( v17 < 0 )
      break;
    v16 += v21;
  }
  v22 = v16 - v10;
  ExFreePoolWithTag(v10);
  v58 = 0;
  v23 = v57;
  *v57 = -2147483628;
  v23[1] = v22;
  v19 = -2147483628;
  v56 = -2147483628;
  return v19;
}
