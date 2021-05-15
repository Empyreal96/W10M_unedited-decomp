// PiPnpRtlObjectEventWorker 
 
int __fastcall PiPnpRtlObjectEventWorker(int result, int a2, int a3, int a4, unsigned int a5)
{
  int v6; // r7
  int v8; // r10
  int v9; // r6
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r9
  unsigned int v13; // r1
  int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r2
  unsigned int v17; // r6
  __int64 v18; // kr00_8
  int v19; // r1
  __int64 v20; // r2
  unsigned int v21; // r9
  int v22; // r2
  int v23; // r5
  int v24; // r4
  __int64 v25; // r2
  int v26; // r5
  int v27; // r1
  __int64 v28; // r2
  unsigned __int64 v29; // r2
  unsigned int v30; // r1
  int v31; // r3
  unsigned __int16 *v32; // r1
  int v33; // r0
  unsigned int v34; // r4
  int v35; // r3
  int v36; // r3
  unsigned __int8 *v37; // r5
  unsigned int v38; // r2
  int v39; // r0
  int v40; // r4
  unsigned int v41; // r2
  int v42; // r2
  BOOL v43; // r5
  int *v44; // r4
  int v45; // r1
  unsigned int v46; // r0
  unsigned int v47; // r2
  int v48; // r0
  unsigned int v49; // r1
  __int16 v50; // r3
  int v51; // r2
  int v52; // r3
  unsigned int v53; // r2
  int *i; // r5
  int *v55; // r0
  int v56; // r2
  int v57; // r3
  int v58; // r4
  int **v59; // r0
  int v60; // r2
  int v61; // r0
  unsigned int v62; // r1
  __int16 v63; // r3
  int v64; // r2
  int v65; // r3
  unsigned int *v66; // r0
  unsigned int v67; // r2
  unsigned int v68; // r1
  __int16 v69; // r3
  unsigned int v70; // r2
  int v71; // r2
  unsigned int *v72; // r0
  unsigned int v73; // r2
  int v74; // r0
  unsigned int v75; // r1
  __int16 v76; // r3
  unsigned int v77; // [sp+8h] [bp-58h] BYREF
  char v78[4]; // [sp+Ch] [bp-54h] BYREF
  int v79; // [sp+10h] [bp-50h]
  int v80; // [sp+14h] [bp-4Ch] BYREF
  int v81; // [sp+18h] [bp-48h]
  int v82; // [sp+20h] [bp-40h] BYREF
  int v83; // [sp+24h] [bp-3Ch]
  __int64 v84; // [sp+28h] [bp-38h]
  int v85; // [sp+30h] [bp-30h]
  unsigned __int64 v86; // [sp+34h] [bp-2Ch] BYREF

  v81 = a4;
  v6 = 0;
  v77 = 0;
  v8 = a2;
  v79 = a2;
  v80 = 0;
  v9 = result;
  if ( a2 < 6 )
  {
    if ( a3 == 1 )
    {
LABEL_101:
      result = PiDqGetObjectManagerForPnpObjectType(v8);
      if ( result )
        result = PiDqObjectManagerMakeInconsistent();
      goto LABEL_22;
    }
    v10 = PiPnpRtlBeginOperation(&v80);
    v6 = v80;
    if ( v10 < 0 )
      goto LABEL_91;
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    ExAcquireResourceSharedLite((int)&PiPnpRtlRemoveOperationDispatchLock, 1);
    v12 = PiPnpRtlObjectEventCreate(v9, v8, v6, &v77);
    v80 = v12;
    result = ExReleaseResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 )
      return sub_7C5C74(result);
    if ( v12 < 0 )
    {
LABEL_91:
      v15 = v77;
LABEL_92:
      if ( v15 )
      {
        v70 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v70 + 308);
        ExAcquireResourceSharedLite((int)&PiPnpRtlRemoveOperationDispatchLock, 1);
        if ( !*(_DWORD *)(v77 + 32) )
        {
          RtlDeleteElementGenericTableAvl(v6 + 12, (int)&v77, v71, 0);
          v72 = *(unsigned int **)(v6 + 72);
          v73 = v77 + 32;
          *(_DWORD *)(v77 + 32) = v6 + 68;
          *(_DWORD *)(v73 + 4) = v72;
          if ( *v72 != v6 + 68 )
            __fastfail(3u);
          *v72 = v73;
          *(_DWORD *)(v6 + 72) = v73;
        }
        v74 = ExReleaseResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
        v75 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v76 = *(_WORD *)(v75 + 0x134) + 1;
        *(_WORD *)(v75 + 308) = v76;
        if ( !v76 && *(_DWORD *)(v75 + 100) != v75 + 100 && !*(_WORD *)(v75 + 310) )
          KiCheckForKernelApcDelivery(v74);
      }
      goto LABEL_101;
    }
    v15 = v77;
    if ( v77 )
    {
      switch ( a3 )
      {
        case 4:
          result = PiDmObjectProcessPropertyChange(
                     v8,
                     v9,
                     *(unsigned __int8 **)(v77 + 8),
                     *(_DWORD *)(a4 + 4),
                     *(_DWORD *)(a4 + 8),
                     v78);
          if ( !v78[0] )
          {
            v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v16 + 308);
            ExAcquireResourceSharedLite((int)&PiPnpRtlRemoveOperationDispatchLock, 1);
            v17 = v77;
            if ( *(_DWORD *)(v77 + 32) )
            {
LABEL_19:
              result = ExReleaseResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
              v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              v31 = (__int16)(*(_WORD *)(v30 + 0x134) + 1);
              *(_WORD *)(v30 + 308) = v31;
              if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
                result = KiCheckForKernelApcDelivery(result);
              goto LABEL_20;
            }
            v18 = *(_QWORD *)(a4 + 4);
            v19 = *(_DWORD *)(HIDWORD(v18) + 4);
            v20 = *(_QWORD *)(HIDWORD(v18) + 8);
            v82 = *(_DWORD *)HIDWORD(v18);
            v83 = v19;
            v84 = v20;
            v21 = 0;
            v85 = *(_DWORD *)(HIDWORD(v18) + 16);
            HIDWORD(v20) = *(_DWORD *)(v77 + 44);
            v86 = __PAIR64__(v18, a5);
            if ( HIDWORD(v20) )
            {
              v22 = v85;
              v23 = 0;
              do
              {
                v24 = v23 + v17;
                if ( v22 == *(_DWORD *)(v23 + v17 + 64) )
                {
                  if ( !memcmp((unsigned int)&v82, v24 + 48, 16) && a5 == *(_DWORD *)(v24 + 68) )
                  {
                    v32 = *(unsigned __int16 **)(HIDWORD(v18) + 72);
                    if ( (unsigned __int16 *)v18 == v32 )
                      goto LABEL_29;
                    if ( (_DWORD)v18 && v32 )
                    {
                      if ( !wcsicmp(v18, v32) )
                      {
LABEL_29:
                        v12 = v80;
                        goto LABEL_18;
                      }
                      v17 = v77;
                    }
                  }
                  v22 = v85;
                }
                ++v21;
                v23 += 28;
              }
              while ( v21 < *(_DWORD *)(v17 + 44) );
            }
            if ( a5 == 1 )
            {
              v36 = *(_DWORD *)(v17 + 4);
              if ( (v36 & 4) == 0 )
              {
                *(_DWORD *)(v17 + 4) = v36 | 4;
                SeCaptureSubjectContext(v77 + 16);
                v17 = v77;
              }
            }
            v25 = *(_QWORD *)(v17 + 40);
            if ( HIDWORD(v25) == (_DWORD)v25 )
            {
              v33 = ExAllocatePoolWithTag(1, 56 * v25 + 48, 1097887312);
              v34 = v33;
              if ( !v33 )
              {
                v12 = -1073741670;
LABEL_18:
                v8 = v79;
                goto LABEL_19;
              }
              memmove(v33, v77, 28 * *(_DWORD *)(v77 + 44) + 48);
              *(_DWORD *)(v34 + 40) *= 2;
              *(_DWORD *)RtlLookupElementGenericTableAvl(v6 + 12, (int)&v77) = v34;
              ExFreePoolWithTag(v77);
              v77 = v34;
            }
            v12 = PnpAllocatePWSTR(*(_DWORD *)(v81 + 4), 0x7FFFFFFF, 1097887312, (char *)&v86 + 4);
            if ( v12 >= 0 )
            {
              v26 = v77 + 28 * *(_DWORD *)(v77 + 44) + 48;
              v27 = v83;
              v28 = v84;
              *(_DWORD *)v26 = v82;
              *(_DWORD *)(v26 + 4) = v27;
              *(_QWORD *)(v26 + 8) = v28;
              v26 += 16;
              v29 = v86;
              *(_DWORD *)v26 = v85;
              *(_QWORD *)(v26 + 4) = v29;
              ++*(_DWORD *)(v77 + 44);
            }
            goto LABEL_18;
          }
LABEL_20:
          v15 = v77;
          break;
        case 2:
          v35 = *(_DWORD *)(v77 + 4) | 1;
          goto LABEL_36;
        case 3:
          *(_DWORD *)(v77 + 4) |= 2u;
          v37 = *(unsigned __int8 **)(v77 + 8);
          v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v38 + 308);
          v39 = KeAbPreAcquire((unsigned int)v37, 0, 0);
          v40 = v39;
          do
            v41 = __ldrex(v37);
          while ( __strex(v41 | 1, v37) );
          __dmb(0xBu);
          if ( (v41 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v37, v39, (unsigned int)v37);
          if ( v40 )
            *(_BYTE *)(v40 + 14) |= 1u;
          v42 = *(_DWORD *)(v77 + 8);
          v43 = (*(_DWORD *)(v42 + 24) & 1) != 0;
          *(_DWORD *)(v42 + 24) &= 0xFFFFFFFE;
          v44 = *(int **)(v77 + 8);
          __pld(v44);
          v45 = *v44;
          if ( (*v44 & 0xFFFFFFF0) <= 0x10 )
            v46 = 0;
          else
            v46 = v45 - 16;
          if ( (v45 & 2) != 0 )
            goto LABEL_65;
          __dmb(0xBu);
          do
            v47 = __ldrex((unsigned int *)v44);
          while ( v47 == v45 && __strex(v46, (unsigned int *)v44) );
          if ( v47 != v45 )
LABEL_65:
            ExfReleasePushLock(v44, v45);
          v48 = KeAbPostRelease((unsigned int)v44);
          v49 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v50 = *(_WORD *)(v49 + 0x134) + 1;
          *(_WORD *)(v49 + 308) = v50;
          if ( !v50 && *(_DWORD *)(v49 + 100) != v49 + 100 && !*(_WORD *)(v49 + 310) )
            KiCheckForKernelApcDelivery(v48);
          if ( v43 )
            PiDmRemoveCacheReferenceForObject(v8, v9);
          v51 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v52 = *(__int16 *)(v51 + 0x134) - 1;
          *(_WORD *)(v51 + 308) = v52;
          ExAcquireResourceExclusiveLite((int)&PiPnpRtlRemoveOperationDispatchLock, 1, v51, v52);
          v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v53 + 308);
          ExAcquireResourceSharedLite((int)&PiPnpRtlActiveOperationsLock, 1);
          for ( i = (int *)PiPnpRtlActiveOperations; i != &PiPnpRtlActiveOperations; i = (int *)*i )
          {
            if ( i != (int *)v6 )
            {
              v55 = (int *)RtlLookupElementGenericTableAvl((int)(i + 3), (int)&v77);
              if ( v55 )
              {
                v58 = *v55;
                RtlDeleteElementGenericTableAvl((int)(i + 3), (int)v55, v56, v57);
                v59 = (int **)i[18];
                v60 = v58 + 32;
                *(_DWORD *)(v58 + 32) = i + 17;
                *(_DWORD *)(v58 + 36) = v59;
                if ( *v59 != i + 17 )
                  __fastfail(3u);
                *v59 = (int *)v60;
                i[18] = v60;
              }
            }
          }
          v61 = ExReleaseResourceLite((int)&PiPnpRtlActiveOperationsLock);
          v62 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v63 = *(_WORD *)(v62 + 0x134) + 1;
          *(_WORD *)(v62 + 308) = v63;
          if ( !v63 && *(_DWORD *)(v62 + 100) != v62 + 100 && !*(_WORD *)(v62 + 310) )
            KiCheckForKernelApcDelivery(v61);
          PiPnpRtlObjectEventDispatch(v77);
          RtlDeleteElementGenericTableAvl(v6 + 12, (int)&v77, v64, v65);
          v66 = *(unsigned int **)(v6 + 72);
          v67 = v77 + 32;
          *(_DWORD *)(v77 + 32) = v6 + 68;
          *(_DWORD *)(v67 + 4) = v66;
          if ( *v66 != v6 + 68 )
            __fastfail(3u);
          *v66 = v67;
          *(_DWORD *)(v6 + 72) = v67;
          result = ExReleaseResourceLite((int)&PiPnpRtlRemoveOperationDispatchLock);
          v68 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v69 = *(_WORD *)(v68 + 0x134) + 1;
          *(_WORD *)(v68 + 308) = v69;
          if ( !v69 && *(_DWORD *)(v68 + 100) != v68 + 100 && !*(_WORD *)(v68 + 310) )
            result = KiCheckForKernelApcDelivery(result);
          v15 = 0;
          v77 = 0;
          break;
        case 5:
          v35 = *(_DWORD *)(v77 + 4) | 8;
LABEL_36:
          *(_DWORD *)(v77 + 4) = v35;
          goto LABEL_20;
      }
    }
    if ( v12 >= 0 )
    {
LABEL_22:
      if ( v6 )
        result = PiPnpRtlEndOperation(v6);
      return result;
    }
    goto LABEL_92;
  }
  return result;
}
