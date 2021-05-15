// NtMapUserPhysicalPages 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall NtMapUserPhysicalPages(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r2
  unsigned int v16; // r4
  int v17; // r7
  unsigned int v18; // r6
  unsigned int *v19; // r5
  unsigned int *v20; // r8
  unsigned int *v21; // r10
  unsigned int v22; // r9
  int v23; // r4
  _DWORD *v24; // r4
  __int64 *v25; // r4
  _DWORD *v26; // r0
  unsigned __int64 v27; // r2
  __int64 v28; // kr00_8
  unsigned int v29; // r1
  unsigned int v30; // r1
  int v31; // r1
  unsigned int *v32; // r7
  int *v33; // r10
  int v34; // t1
  unsigned int v35; // r3
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // t1
  unsigned int v39; // r0
  unsigned int v40; // r3
  unsigned int *v41; // r2
  unsigned int v42; // r0
  __int64 v43; // r0
  __int16 v44; // r3
  int v45; // r0
  int v46; // r3
  __int16 v47; // [sp-C66h] [bp-10B4h]
  __int16 v48; // [sp-C66h] [bp-10B4h]
  int v49; // [sp-C5Eh] [bp-10ACh]
  unsigned int v50; // [sp-C5Ah] [bp-10A8h]
  int *v51; // [sp-C56h] [bp-10A4h]
  unsigned int *v52; // [sp-C52h] [bp-10A0h]
  unsigned int v53; // [sp-C4Eh] [bp-109Ch]
  _DWORD *v54; // [sp-C4Ah] [bp-1098h]
  _BYTE v55[152]; // [sp-C46h] [bp-1094h] BYREF
  _BYTE v56[2990]; // [sp-BAEh] [bp-FFCh] BYREF

  _chkstk();
  v16 = v15;
  v17 = v14;
  v53 = v15;
  if ( v14 <= 0xFFFFF )
  {
    v18 = v13 & 0xFFFFF000;
    v50 = (v13 & 0xFFFFF000) + (v14 << 12) - 1;
    if ( v50 > (v13 & 0xFFFFF000) )
    {
      v19 = (unsigned int *)v56;
      v20 = 0;
      if ( v15 )
      {
        if ( !v14 )
          goto LABEL_60;
        if ( v14 > 0x400 )
        {
          v19 = (unsigned int *)ExAllocatePoolWithTag(512, 4 * v14, 2001890637);
          if ( !v19 )
            goto LABEL_60;
        }
        if ( MiCaptureUlongPtrArray((int)v19, v16, v17) < 0 )
          goto LABEL_10;
        v20 = v19;
      }
      v51 = (int *)&v19[v17];
      v21 = (unsigned int *)(((v18 >> 10) & 0x3FFFFC) - 0x40000000);
      v52 = &v21[v17];
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v23 = *(_DWORD *)(v22 + 0x74);
      v47 = dword_681120 & 0x1CD | 0xF832;
      MiInitializeTbFlushList((int)v55, 1, 33);
      v24 = *(_DWORD **)(v23 + 328);
      v54 = v24;
      if ( !v24 || !*v24 )
      {
        if ( v19 == (unsigned int *)v56 )
          goto LABEL_60;
        goto LABEL_59;
      }
      --*(_WORD *)(v22 + 310);
      v49 = ExAcquireAutoExpandPushLockShared((int)(v24 + 1), 0);
      v25 = (__int64 *)*v24;
      v26 = MiLocatePhysicalViewInTree(v18 >> 12, v54 + 4);
      if ( !v26 )
        goto LABEL_55;
      LODWORD(v27) = v26[3];
      HIDWORD(v27) = *(_DWORD *)(v27 + 12);
      if ( v18 < HIDWORD(v27) << 12 )
        goto LABEL_55;
      HIDWORD(v27) = (*(_DWORD *)(v27 + 16) << 12) | 0xFFF;
      LODWORD(v27) = v50;
      if ( v50 > HIDWORD(v27) )
        goto LABEL_55;
      HIDWORD(v27) = v53;
      if ( v53 )
      {
        v28 = *v25;
        while ( 1 )
        {
          v29 = *v20;
          if ( *v20 >= (unsigned int)v28 )
            break;
          LODWORD(v27) = *v20 & 0x1F;
          HIDWORD(v27) = *(_DWORD *)(HIDWORD(v28) + 4 * (v29 >> 5)) >> (v29 & 0x1F);
          if ( (v27 & 0x100000000i64) == 0 )
            break;
          HIDWORD(v27) = MmPfnDatabase + 24 * v29;
          LODWORD(v27) = HIDWORD(v27) + 4;
          do
          {
            v30 = __ldrex((unsigned int *)v27);
            if ( v30 )
              break;
            HIDWORD(v27) = __strex((unsigned int)v21, (unsigned int *)v27);
          }
          while ( HIDWORD(v27) );
          if ( v30 )
            break;
          ++v20;
          HIDWORD(v27) = &v19[v17];
          ++v21;
          if ( (unsigned int)v20 >= HIDWORD(v27) )
          {
            LOWORD(v31) = v47;
            v32 = &v21[-v17];
            v33 = (int *)v19;
            do
            {
              v34 = *v33++;
              v31 = v31 & 0xFFF | (v34 << 12);
              v48 = v31;
              __dmb(0xBu);
              do
              {
                LODWORD(v27) = __ldrex(v32);
                HIDWORD(v27) = __strex(v31, v32);
              }
              while ( HIDWORD(v27) );
              __dmb(0xBu);
              if ( (v27 & 2) != 0 )
              {
                v35 = MmPfnDatabase + 24 * ((unsigned int)v27 >> 12);
                __dmb(0xBu);
                v36 = (unsigned int *)(v35 + 4);
                do
                  v37 = __ldrex(v36);
                while ( __strex(0, v36) );
                MiInsertTbFlushEntry((int)v55, v18, 1, 0);
                LOWORD(v31) = v48;
              }
              v18 += 4096;
              ++v32;
            }
            while ( v33 < v51 );
            goto LABEL_50;
          }
        }
        while ( v20 > v19 )
        {
          v38 = *--v20;
          HIDWORD(v27) = MmPfnDatabase + 24 * v38;
          __dmb(0xBu);
          LODWORD(v27) = HIDWORD(v27) + 4;
          do
          {
            v39 = __ldrex((unsigned int *)v27);
            HIDWORD(v27) = __strex(0, (unsigned int *)v27);
          }
          while ( HIDWORD(v27) );
        }
LABEL_55:
        v45 = ExReleaseAutoExpandPushLockShared((unsigned int)v49, v27);
        v46 = (__int16)(*(_WORD *)(v22 + 310) + 1);
        *(_WORD *)(v22 + 310) = v46;
        if ( !v46 && *(_DWORD *)(v22 + 100) != v22 + 100 )
          KiCheckForKernelApcDelivery(v45);
LABEL_10:
        if ( v19 == (unsigned int *)v56 )
          goto LABEL_60;
        goto LABEL_59;
      }
      for ( ; v21 < v52; v18 += 4096 )
      {
        __dmb(0xBu);
        do
        {
          LODWORD(v27) = __ldrex(v21);
          HIDWORD(v27) = __strex(0, v21);
        }
        while ( HIDWORD(v27) );
        __dmb(0xBu);
        if ( (v27 & 2) != 0 )
        {
          v40 = MmPfnDatabase + 24 * ((unsigned int)v27 >> 12);
          __dmb(0xBu);
          v41 = (unsigned int *)(v40 + 4);
          do
            v42 = __ldrex(v41);
          while ( __strex(0, v41) );
          MiInsertTbFlushEntry((int)v55, v18, 1, 0);
        }
        ++v21;
      }
LABEL_50:
      v43 = ExReleaseAutoExpandPushLockShared((unsigned int)v49, v27);
      v44 = *(_WORD *)(v22 + 310) + 1;
      *(_WORD *)(v22 + 310) = v44;
      if ( !v44 && *(_DWORD *)(v22 + 100) != v22 + 100 )
        KiCheckForKernelApcDelivery(v43);
      MiFlushTbList((unsigned int)v55, SHIDWORD(v43));
      if ( v19 != (unsigned int *)v56 )
      {
LABEL_59:
        ExFreePoolWithTag((unsigned int)v19);
        goto LABEL_60;
      }
    }
  }
LABEL_60:
  __asm { POP.W           {R4-R11,PC} }
}
