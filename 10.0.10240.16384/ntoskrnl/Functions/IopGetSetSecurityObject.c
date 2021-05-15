// IopGetSetSecurityObject 
 
int __fastcall IopGetSetSecurityObject(int a1, int a2, _DWORD *a3, unsigned int a4, _DWORD *a5, int a6, int a7, int a8, char a9)
{
  _DWORD *v12; // r5
  int v13; // r6
  int v14; // r4
  unsigned int v15; // r2
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r1
  __int16 v19; // r3
  int v20; // r4
  int v21; // r4
  int v22; // r0
  int v23; // r4
  int v24; // r2
  _DWORD *v25; // r9
  unsigned __int64 *v26; // r3
  unsigned __int64 v27; // kr00_8
  unsigned int *v28; // r2
  unsigned int v29; // r1
  int v30; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r1
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  int v36; // r5
  unsigned int v37; // r4
  int v38; // r5
  int v39; // r0
  __int16 v40; // r3
  _DWORD *v41; // r2
  int v42; // r0
  unsigned int v43; // r5
  int v44; // r3
  int v45; // r2
  int v46; // r0
  int v47; // r3
  unsigned int v48; // r4
  int v49; // r0
  __int16 v50; // r3
  char v52[4]; // [sp+8h] [bp-50h] BYREF
  int v53; // [sp+Ch] [bp-4Ch] BYREF
  int v54; // [sp+10h] [bp-48h]
  _DWORD *v55; // [sp+14h] [bp-44h]
  _DWORD v56[2]; // [sp+18h] [bp-40h] BYREF
  int v57; // [sp+20h] [bp-38h] BYREF
  int v58; // [sp+24h] [bp-34h]
  _BYTE v59[48]; // [sp+28h] [bp-30h] BYREF
  __int64 savedregs; // [sp+58h] [bp+0h]

  v55 = a3;
  v12 = (_DWORD *)a1;
  if ( *(_WORD *)a1 == 3 )
  {
    v13 = a1;
    v12 = 0;
    goto LABEL_65;
  }
  v13 = *(_DWORD *)(a1 + 4);
  if ( !*(_WORD *)(a1 + 48) && !*(_DWORD *)(a1 + 32) || (*(_DWORD *)(a1 + 44) & 0x800) != 0 )
  {
LABEL_65:
    switch ( a2 )
    {
      case 3:
        v20 = 0;
        if ( !v12 || (v12[11] & 0x100) == 0 )
        {
          v20 = ObLogSecurityDescriptor(a4, v56, 1);
          if ( v20 >= 0 )
          {
            ExFreePoolWithTag(a4);
            v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v44 = *(__int16 *)(v43 + 0x134) - 1;
            *(_WORD *)(v43 + 308) = v44;
            ExAcquireResourceExclusiveLite((int)&IopSecurityResource, 1, v45, v44);
            if ( *(_DWORD *)(v13 + 152) )
              *(_DWORD *)(*(_DWORD *)(v13 + 176) + 16) &= 0xFFFFF7FF;
            *(_DWORD *)(v13 + 152) = v56[0];
            v46 = ExReleaseResourceLite((int)&IopSecurityResource);
            v47 = (__int16)(*(_WORD *)(v43 + 308) + 1);
            *(_WORD *)(v43 + 308) = v47;
            if ( !v47 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
              KiCheckForKernelApcDelivery(v46);
          }
        }
        return v20;
      case 0:
        v12 = (_DWORD *)IopGetDevicePDO(v13);
        if ( !v12 )
          return IopSetDeviceSecurityDescriptor(v13, a3, a4, a7, a8);
        v20 = IopSetDeviceSecurityDescriptors(v13, v12, a3, a4, a7, a8);
        goto LABEL_78;
      case 1:
        v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v48 + 308);
        ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
        v38 = *(_DWORD *)(v13 + 152);
        v53 = v38;
        if ( v38 )
          ObReferenceSecurityDescriptor(v38, 1);
        v49 = ExReleaseResourceLite((int)&IopSecurityResource);
        v50 = *(_WORD *)(v48 + 308) + 1;
        *(_WORD *)(v48 + 308) = v50;
        if ( !v50 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
          KiCheckForKernelApcDelivery(v49);
        v41 = a5;
        v42 = (int)a3;
LABEL_88:
        v20 = SeQuerySecurityDescriptorInfo(v42, a4, v41, &v53);
        if ( v38 )
          ObDereferenceSecurityDescriptor(v38, 1);
        return v20;
    }
    return 0;
  }
  if ( a2 == 2 )
    return 0;
  v57 = 0;
  v58 = 0;
  v56[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(char *)(v56[0] + 346);
  ObfReferenceObject(a1);
  if ( (v12[11] & 2) != 0 )
  {
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v15 + 308);
    __dmb(0xBu);
    v16 = v12 + 17;
    do
      v17 = __ldrex(v16);
    while ( __strex(1u, v16) );
    __dmb(0xBu);
    if ( v17 )
    {
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = *(_WORD *)(v18 + 0x134) + 1;
      *(_WORD *)(v18 + 308) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
        KiCheckForKernelApcDelivery(1);
      v20 = IopAcquireFileObjectLock(v12, v14, (v12[11] & 4) != 0, v52);
      if ( v52[0] )
      {
LABEL_78:
        ObfDereferenceObject((int)v12);
        return v20;
      }
    }
    else
    {
      ObfReferenceObject((int)v12);
    }
    v21 = 1;
  }
  else
  {
    KeInitializeEvent((int)v59, 1, 0);
    v21 = 0;
  }
  v54 = v21;
  if ( (v12[11] & 0x4000000) == 0 )
    KeResetEvent((int)(v12 + 23));
  v53 = IoGetRelatedDeviceObject(v12);
  v22 = pIoAllocateIrp(v53, *(char *)(v53 + 48), v21 == 0, HIDWORD(savedregs));
  v23 = v22;
  if ( !v22 )
  {
    IopAllocateIrpCleanup(v12, 0);
    return -1073741670;
  }
  *(_DWORD *)(v22 + 100) = v12;
  *(_DWORD *)(v22 + 80) = v56[0];
  *(_BYTE *)(v22 + 32) = a9;
  if ( (v12[11] & 2) != 0 )
  {
    *(_DWORD *)(v22 + 44) = 0;
    *(_BYTE *)(v22 + 39) |= 2u;
  }
  else
  {
    *(_DWORD *)(v22 + 44) = v59;
    *(_DWORD *)(v22 + 8) = 4;
  }
  *(_DWORD *)(v22 + 40) = &v57;
  *(_DWORD *)(v22 + 48) = 0;
  v24 = *(_DWORD *)(v22 + 96);
  if ( a2 == 1 )
  {
    *(_BYTE *)(v24 - 40) = 20;
    *(_DWORD *)(v24 - 32) = *a3;
    v25 = a5;
    *(_DWORD *)(v24 - 28) = *a5;
    *(_DWORD *)(v22 + 60) = a4;
  }
  else
  {
    *(_BYTE *)(v24 - 40) = 21;
    *(_DWORD *)(v24 - 32) = *a3;
    *(_DWORD *)(v24 - 28) = a4;
    v25 = a5;
  }
  *(_DWORD *)(v24 - 12) = v12;
  IopQueueThreadIrp(v22);
  if ( IoCountOperations == 1 )
  {
    v26 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
    do
      v27 = __ldrexd(v26);
    while ( __strexd(v27 + 1, v26) );
    v28 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 + 1, v28) );
  }
  v30 = IofCallDriver(v53, v23);
  v20 = v30;
  if ( v54 )
  {
    if ( v30 == 259 )
    {
      KeWaitForSingleObject((unsigned int)(v12 + 23), 0, 0, 0, 0);
      v20 = v12[7];
    }
    __dmb(0xBu);
    v31 = v12 + 17;
    do
      v32 = __ldrex(v31);
    while ( __strex(0, v31) );
    __dmb(0xBu);
    if ( v12[16] )
      KeSetEvent((int)(v12 + 19), 0, 0);
    v33 = ObfDereferenceObject((int)v12);
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v35 = *(_WORD *)(v34 + 0x134) + 1;
    *(_WORD *)(v34 + 308) = v35;
    if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
      KiCheckForKernelApcDelivery(v33);
  }
  else if ( v30 == 259 )
  {
    KeWaitForSingleObject((unsigned int)v59, 0, 0, 0, 0);
    v20 = v57;
  }
  if ( v20 == -1073741808 )
  {
    if ( a2 == 1 )
    {
      v36 = v53;
      if ( (*(_DWORD *)(v53 + 32) & 0x100) == 0 )
      {
        v20 = SeAssignWorldSecurityDescriptor(a4, v25, v55);
        v56[1] = v20;
        return v20;
      }
      v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v37 + 308);
      ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
      v38 = *(_DWORD *)(v36 + 152);
      v53 = v38;
      if ( v38 )
        ObReferenceSecurityDescriptor(v38, 1);
      v39 = ExReleaseResourceLite((int)&IopSecurityResource);
      v40 = *(_WORD *)(v37 + 308) + 1;
      *(_WORD *)(v37 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v37 + 100) != v37 + 100 && !*(_WORD *)(v37 + 310) )
        KiCheckForKernelApcDelivery(v39);
      v41 = v25;
      v42 = (int)v55;
      goto LABEL_88;
    }
    if ( !a2 && (*(_DWORD *)(v53 + 28) & 0x100) != 0 )
      return -1073741808;
    return 0;
  }
  if ( a2 == 1 )
  {
    if ( v20 == -2147483643 )
      v20 = -1073741789;
    *v25 = v58;
  }
  return v20;
}
