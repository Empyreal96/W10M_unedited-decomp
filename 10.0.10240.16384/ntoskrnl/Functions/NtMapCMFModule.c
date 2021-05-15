// NtMapCMFModule 
 
int __fastcall NtMapCMFModule(unsigned int a1, int a2, unsigned int a3, unsigned int a4, unsigned int *a5, _DWORD *a6)
{
  int v7; // r5
  int v8; // r4
  int v9; // r8
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r3
  int v16; // r5
  unsigned int v17; // r0
  int v18; // r0
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r2
  int v24; // r3
  char v25; // r5
  int v26; // r9
  int v27; // r8
  int *v28; // r4
  unsigned int v29; // r1
  int v30; // r3
  _BYTE *v31; // r0
  unsigned int v32; // r4
  unsigned int v33; // r2
  int v34; // r2
  int v35; // r0
  int v36; // r1
  unsigned int v37; // r4
  unsigned int v38; // r6
  unsigned __int64 v39; // r8
  unsigned __int64 v40; // kr08_8
  unsigned __int64 v41; // r2
  int v42; // r0
  unsigned int v43; // r1
  __int16 v44; // r3
  _DWORD *v45; // r0
  unsigned int *v46; // r0
  _DWORD *v47; // r1
  _DWORD *v48; // r0
  _DWORD *v49; // r1
  _DWORD *v50; // r0
  int v52; // [sp+18h] [bp-C8h]
  int v53; // [sp+18h] [bp-C8h]
  _BYTE *v54; // [sp+1Ch] [bp-C4h] BYREF
  char v55; // [sp+20h] [bp-C0h]
  unsigned int v56; // [sp+24h] [bp-BCh] BYREF
  unsigned int v57; // [sp+28h] [bp-B8h]
  unsigned int v58; // [sp+30h] [bp-B0h] BYREF
  int v59; // [sp+34h] [bp-ACh]
  int v60; // [sp+38h] [bp-A8h]
  unsigned int v61; // [sp+3Ch] [bp-A4h]
  int v62; // [sp+40h] [bp-A0h]
  int v63; // [sp+44h] [bp-9Ch]
  unsigned int v64; // [sp+48h] [bp-98h]
  __int64 v65; // [sp+50h] [bp-90h] BYREF
  int v66; // [sp+58h] [bp-88h]
  int *v67; // [sp+5Ch] [bp-84h]
  int v68; // [sp+60h] [bp-80h]
  int v69; // [sp+68h] [bp-78h]
  int v70; // [sp+6Ch] [bp-74h]
  int v71; // [sp+70h] [bp-70h]
  char v72; // [sp+74h] [bp-6Ch]
  _BYTE *v73; // [sp+78h] [bp-68h]
  unsigned int v74; // [sp+7Ch] [bp-64h]
  unsigned int v75; // [sp+80h] [bp-60h]
  int v76; // [sp+84h] [bp-5Ch]
  int v77; // [sp+88h] [bp-58h]
  int *v78; // [sp+8Ch] [bp-54h]
  int v79; // [sp+90h] [bp-50h]
  _DWORD v80[6]; // [sp+98h] [bp-48h] BYREF
  _BYTE _B0[52]; // [sp+B0h] [bp-30h] BYREF
  unsigned int varg_r0; // [sp+E8h] [bp+8h]
  int varg_r1; // [sp+ECh] [bp+Ch]
  unsigned int varg_r2; // [sp+F0h] [bp+10h]
  unsigned int varg_r3; // [sp+F4h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v61 = a2;
  v7 = 0;
  v54 = 0;
  v56 = 0;
  v57 = 0;
  v64 = 0;
  v66 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !v66 || InitSafeBootMode )
  {
    v8 = -1073741823;
    goto LABEL_147;
  }
  if ( (a1 & 0xFFE0FE81) != 0 )
    goto LABEL_5;
  v8 = MUIInitializeResourceLock(&CMFLock);
  v52 = v8;
  if ( (v8 & 0xC0000000) != -1073741824 )
  {
    if ( (a1 & 0x20000) != 0 )
    {
      if ( (a1 & 0x40000) != 0 && (a1 & 0x180000) != 0 || (a1 & 0x180000) == 1572864 )
      {
LABEL_5:
        v8 = -1073741811;
        goto LABEL_147;
      }
      v9 = a1 & 0x1C0000;
      if ( v9 == (CMFFlagsCache & 0x1C0000) )
        goto LABEL_12;
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v11 = *(__int16 *)(v10 + 0x134) - 1;
      *(_WORD *)(v10 + 308) = v11;
      ExAcquireResourceExclusiveLite(CMFLock, 1, v10, v11);
      v12 = CMFFlagsCache;
      if ( v9 != (CMFFlagsCache & 0x1C0000) )
      {
        v13 = CMFDirectorySectionPointer;
        if ( CMFDirectorySectionPointer )
        {
          if ( !v9 )
          {
            v53 = -1073741637;
            goto LABEL_37;
          }
          if ( CMFDirectorySectionPointer )
          {
            v14 = 0x80000000;
            v68 = 0x80000000;
            if ( (CMFFlagsCache & 0x1C0000) != 0 )
            {
              v14 = -1073741824;
              v68 = -1073741824;
            }
            v53 = CMFCheckAccess(CMFDirectorySectionPointer, v14, v66);
            if ( (v53 & 0xC0000000) == -1073741824 )
              goto LABEL_37;
            v12 = CMFFlagsCache;
            v13 = CMFDirectorySectionPointer;
          }
        }
        v15 = v12 & 0xFFE3FFFF | v9;
        CMFFlagsCache = v15;
        if ( v13 )
        {
          v16 = 0x80000;
          if ( (v15 & 0x80000) != 0 || (v15 & 0x100000) != 0 )
          {
            v54 = 0;
            v56 = 104;
            v58 = 0;
            v59 = 0;
            if ( MmMapViewInSystemSpace(v13, (int)&v54, (int)&v56) >= 0 )
            {
              v17 = (unsigned int)v54;
              if ( v54 )
              {
                if ( v56 >= 0x68 )
                {
                  *((_DWORD *)v54 + 12) &= 0xFFE3FFFF;
                  if ( (CMFFlagsCache & 0x80000) == 0 )
                    v16 = 0x100000;
                  *(_DWORD *)(v17 + 48) |= v16;
                }
                MmUnmapViewInSystemSpace(v17);
                v54 = 0;
              }
            }
            if ( (CMFFlagsCache & 0x100000) != 0 )
              v18 = 304;
            else
              v18 = 32;
            CMFUnmapModules(v18);
            CMFRegisterEventTime(4);
          }
        }
      }
      v53 = 0;
LABEL_37:
      v19 = ExReleaseResourceLite(CMFLock);
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = *(_WORD *)(v20 + 0x134) + 1;
      *(_WORD *)(v20 + 308) = v21;
      if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
        KiCheckForKernelApcDelivery(v19);
      v8 = v53;
LABEL_146:
      v7 = (int)v54;
      goto LABEL_147;
    }
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v22 + 308);
    ExAcquireResourceSharedLite(CMFLock, 1);
    if ( CMFFlagsCache )
    {
      if ( (CMFFlagsCache & 0xF) != 0 )
      {
        varg_r0 = a1 & 0xFFFFFFF0;
        v23 = CMFFlagsCache & 0xF | a1 & 0xFFFFFFF0;
      }
      else
      {
        v23 = a1 | 1;
      }
      varg_r0 = v23;
      if ( (CMFFlagsCache & 0x100000) != 0 )
      {
        if ( (v23 & 0x10000) == 0 )
        {
LABEL_48:
          v24 = -1073741672;
LABEL_122:
          v52 = v24;
          goto LABEL_123;
        }
        v23 |= 0x100000u;
      }
      else if ( (CMFFlagsCache & 0x80000) != 0 )
      {
        if ( (v23 & 0x130) == 32 && (v23 & 0x10000) == 0 )
          goto LABEL_48;
        v23 |= 0x80000u;
      }
      else
      {
        if ( (CMFFlagsCache & 0x40000) == 0 )
          goto LABEL_58;
        v23 |= 0x40000u;
      }
    }
    else
    {
      v23 = a1 | 1;
    }
    varg_r0 = v23;
LABEL_58:
    v25 = v23 & 0xCF;
    v58 = v23 & 0xFFFFFECF;
    v64 = v23 & 0xFFFFFECF;
    v26 = v23 & 0x130;
    varg_r0 = v26;
    if ( (v23 & 0x40) != 0 )
    {
      v62 = 4;
      v63 = -1073741824;
    }
    else
    {
      v62 = 2;
      v63 = 0x80000000;
    }
    v57 = 10000;
    v60 = 0;
    v55 = 0;
    switch ( v26 )
    {
      case 16:
        v27 = CMFCacheIndex;
        if ( (unsigned int)CMFCacheIndex < 0x2710 )
        {
          v57 = CMFCacheIndex;
LABEL_68:
          if ( (v23 & 2) != 0 )
          {
            v60 = 1;
            v55 = 1;
          }
          v28 = &CMFDirectorySectionPointer;
LABEL_71:
          v67 = v28;
          goto LABEL_92;
        }
        if ( v61 < 0x2710 )
        {
          v27 = v61;
          v57 = v61;
          goto LABEL_68;
        }
        if ( CMFFirstAccess )
        {
          CMFRegisterEventTime(1);
          CMFFirstAccess = 0;
        }
        break;
      case 32:
        v29 = v61;
        if ( v61 < 0x1E )
        {
          v27 = CMFCacheIndex;
          if ( CMFCacheIndex != 10000 )
          {
            v57 = CMFCacheIndex;
            v30 = CMFSegmentSectionPointer;
            if ( !CMFSegmentSectionPointer )
            {
              v31 = (_BYTE *)ExAllocatePoolWithTag(1, 120, 1668114000);
              v32 = (unsigned int)v31;
              v54 = v31;
              if ( !v31 )
              {
                v24 = -1073741801;
                goto LABEL_122;
              }
              memset(v31, 0, 120);
              __dmb(0xBu);
              do
                v33 = __ldrex((unsigned int *)&CMFSegmentSectionPointer);
              while ( !v33 && __strex(v32, (unsigned int *)&CMFSegmentSectionPointer) );
              __dmb(0xBu);
              if ( v33 )
                ExFreePoolWithTag(v32);
              v54 = 0;
              v30 = CMFSegmentSectionPointer;
              v29 = v61;
            }
            if ( (v25 & 4) != 0 )
            {
              v60 = 1;
              v55 = 1;
            }
            v28 = (int *)(v30 + 4 * v29);
            goto LABEL_71;
          }
        }
        break;
      case 256:
        v27 = CMFCacheIndex;
        v57 = CMFCacheIndex;
        if ( (v23 & 8) != 0 )
        {
          v60 = 1;
          v55 = 1;
        }
        v28 = &CMFHitsSectionPointer;
        v67 = &CMFHitsSectionPointer;
        if ( !CMFHitsSectionPointer )
        {
          KeQuerySystemTime(&v65);
          CMFHitsLastFlushTime = v65;
        }
LABEL_92:
        if ( !*v28 )
        {
          ExReleaseResourceLite(CMFLock);
          ExAcquireResourceExclusiveLite(CMFLock, 1, v34, (int)&CMFLock);
          if ( ((CMFFlagsCache ^ v58) & 0x1C0000) != 0 && (CMFFlagsCache & 0x180000) != 0 )
            goto LABEL_95;
          if ( !*v28 )
          {
            v69 = 0x8000000;
            v70 = v27;
            v71 = v63;
            v72 = v60;
            v73 = 0;
            v74 = v58;
            v75 = v61;
            v76 = v62;
            v78 = v28;
            v79 = v26;
            KeInitializeEvent((int)_B0, 1, 0);
            v73 = _B0;
            v80[0] = 24;
            v80[1] = 0;
            v80[3] = 512;
            v80[2] = 0;
            v80[4] = 0;
            v80[5] = 0;
            v52 = PsCreateSystemThread((int)&v58, 0x1FFFFF, (int)v80);
            if ( (v52 & 0xC0000000) == -1073741824 )
              goto LABEL_123;
            ZwClose();
            v35 = KeWaitForSingleObject((unsigned int)_B0, 0, 0, 0, 0);
            v52 = v35;
            if ( v35 )
            {
              if ( v35 >= 0 )
              {
LABEL_95:
                v24 = -1073741823;
                goto LABEL_122;
              }
LABEL_123:
              v42 = ExReleaseResourceLite(CMFLock);
              v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v44 = *(_WORD *)(v43 + 0x134) + 1;
              *(_WORD *)(v43 + 308) = v44;
              if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
                KiCheckForKernelApcDelivery(v42);
              v8 = v52;
              if ( (v52 & 0xC0000000) != -1073741824 )
              {
                if ( a6 )
                {
                  v45 = a6;
                  if ( (unsigned int)a6 >= MmUserProbeAddress )
                    v45 = (_DWORD *)MmUserProbeAddress;
                  *v45 = *v45;
                  *a6 = v54;
                  v7 = 0;
                  v54 = 0;
                }
                else
                {
                  v7 = (int)v54;
                }
                if ( a5 )
                {
                  v46 = a5;
                  if ( (unsigned int)a5 >= MmUserProbeAddress )
                    v46 = (unsigned int *)MmUserProbeAddress;
                  *v46 = *v46;
                  *a5 = v56;
                }
                v47 = (_DWORD *)varg_r2;
                if ( varg_r2 )
                {
                  v48 = (_DWORD *)varg_r2;
                  if ( varg_r2 >= MmUserProbeAddress )
                    v48 = (_DWORD *)MmUserProbeAddress;
                  *v48 = *v48;
                  *v47 = v57;
                }
                v49 = (_DWORD *)varg_r3;
                if ( varg_r3 )
                {
                  v50 = (_DWORD *)varg_r3;
                  if ( varg_r3 >= MmUserProbeAddress )
                    v50 = (_DWORD *)MmUserProbeAddress;
                  *v50 = *v50;
                  *v49 = v64;
                }
LABEL_12:
                v8 = 0;
                goto LABEL_147;
              }
              goto LABEL_146;
            }
            v64 = v74;
            v52 = v77;
            if ( (v77 & 0xC0000000) == -1073741824 )
              goto LABEL_123;
            if ( v26 == 16 )
              CMFRegisterEventTime(2);
          }
          ExConvertExclusiveToSharedLite(CMFLock);
        }
        v54 = 0;
        v56 = 0;
        v58 = 0;
        v59 = 0;
        if ( a6 )
        {
          if ( v26 == 256 || (v52 = CMFCheckAccess(*v28, v63, v66), (v52 & 0xC0000000) != -1073741824) )
          {
            v36 = __mrc(15, 0, 13, 0, 3);
            v52 = MmMapViewOfSection(
                    *v28,
                    *(_DWORD *)((v36 & 0xFFFFFFC0) + 0x74),
                    &v54,
                    0,
                    0,
                    &v58,
                    &v56,
                    1,
                    0x400000,
                    v62);
            if ( (v52 & 0xC0000000) == -1073741824 )
            {
              v54 = 0;
            }
            else if ( v26 == 256 )
            {
              v37 = HIDWORD(CMFHitsLastFlushTime);
              v38 = CMFHitsLastFlushTime;
              KeQuerySystemTime(&v65);
              v39 = v65;
              if ( v65 > (__int64)(__PAIR64__(v37, v38) + 36000000000i64) )
              {
                __dmb(0xBu);
                do
                  v40 = __ldrexd((unsigned __int64 *)&CMFHitsLastFlushTime);
                while ( __PAIR64__(v40, HIDWORD(v40)) == __PAIR64__(v38, v37)
                     && __strexd(v39, (unsigned __int64 *)&CMFHitsLastFlushTime) );
                __dmb(0xBu);
                if ( __PAIR64__(v38, v37) == __PAIR64__(v40, HIDWORD(v40)) && CMFFlushHitsFile(v54, v56) < 0 )
                {
                  __dmb(0xBu);
                  do
                    v41 = __ldrexd((unsigned __int64 *)&CMFHitsLastFlushTime);
                  while ( v41 == v39 && __strexd(__PAIR64__(v37, v38), (unsigned __int64 *)&CMFHitsLastFlushTime) );
                  __dmb(0xBu);
                }
              }
            }
          }
        }
        goto LABEL_123;
    }
    v24 = -1073741811;
    goto LABEL_122;
  }
LABEL_147:
  if ( v7 )
    MiUnmapViewOfSection(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v7, 0);
  return v8;
}
