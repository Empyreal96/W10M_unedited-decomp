// PopAllocateHiberContext 
 
int PopAllocateHiberContext()
{
  int v0; // r4
  int v1; // r0
  int v2; // r5
  int v3; // r3
  int v4; // r1
  int v5; // r0
  int v6; // r6
  int v7; // r1
  int v8; // r0
  int v9; // r2
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r0
  char *v14; // r1
  int v15; // r1
  unsigned int v16; // r2
  int v17; // r3
  unsigned int v18; // r3
  int v19; // r4
  int v20; // r7
  const void *v21; // r2
  _DWORD *v22; // r0
  int v24; // [sp+8h] [bp-28h] BYREF
  int v25[8]; // [sp+10h] [bp-20h] BYREF

  if ( dword_61EC88 == 5 )
  {
    v25[0] = 0;
    v1 = MmGetHighestPhysicalPage(0);
    v2 = dword_61EED8;
    v3 = PopHiberLoaderScratchPages;
    *(_DWORD *)(v4 + 56) = dword_61EED8;
    PopHiberScratchPages = v3 + (((((unsigned int)(v1 + 32) >> 3) & 0x1FFFFFFC) + 4092) >> 12);
    memset((_BYTE *)v2, 0, 312);
    v5 = MmLockPreChargedPagedPool(*(unsigned int *)algn_61EEDC, dword_61EEE0);
    *(_DWORD *)(v2 + 32) = dword_61EEEC;
    *(_DWORD *)(v2 + 36) = dword_61EEF0;
    *(_DWORD *)(v2 + 128) = dword_61EEE4;
    *(_DWORD *)(v2 + 200) = dword_61EF0C;
    *(_DWORD *)(v2 + 136) = dword_61EEFC;
    *(_DWORD *)(v2 + 144) = dword_61EF14;
    *(_DWORD *)(v2 + 148) = dword_61EF10;
    *(_DWORD *)(v2 + 24) = dword_61EEF4;
    *(_DWORD *)(v2 + 28) = dword_61EEF8;
    *(_DWORD *)(v2 + 40) = v2 + 40;
    *(_DWORD *)(v2 + 44) = v2 + 40;
    PopNumberOfPagesForHibernateProcess = 0;
    if ( dword_61EEA4 )
    {
      v5 = IoGetDumpStack(v5, v2 + 108, 0, PopSimulate & 0x10);
      v0 = v5;
      if ( v5 < 0 )
        goto LABEL_39;
      v6 = *(_DWORD *)(v2 + 108);
      *(_BYTE *)(v2 + 1) = PopGetHiberFlags();
      v7 = dword_61EEE8;
      v8 = *(_DWORD *)(v2 + 136);
      v9 = dword_61EEE8 & 0xFFF;
      *(_WORD *)(v8 + 4) = 4 * (((unsigned int)(v9 + 102399) >> 12) + 7);
      *(_DWORD *)(v8 + 16) = v7 & 0xFFFFF000;
      *(_DWORD *)(v8 + 20) = 98304;
      *(_DWORD *)v8 = 0;
      *(_WORD *)(v8 + 6) = 0;
      *(_DWORD *)(v8 + 24) = v9;
      MmBuildMdlForNonPagedPool(*(_DWORD *)(v2 + 136));
      v10 = *(_DWORD *)(v2 + 144);
      if ( v10 )
      {
        v11 = dword_61EF10;
        *(_DWORD *)v10 = 0;
        v12 = v11 & 0xFFF;
        *(_WORD *)(v10 + 4) = 4 * (((unsigned int)(v12 + 0x1FFF) >> 12) + 7);
        *(_DWORD *)(v10 + 16) = v11 & 0xFFFFF000;
        *(_DWORD *)(v10 + 20) = 4096;
        *(_WORD *)(v10 + 6) = 0;
        *(_DWORD *)(v10 + 24) = v12;
        MmBuildMdlForNonPagedPool(*(_DWORD *)(v2 + 144));
      }
      v5 = PopLoadResumeContext(v2);
      v0 = v5;
      if ( v5 < 0 )
        goto LABEL_39;
      v5 = PopBcdOpen(&v24);
      v0 = v5;
      if ( v5 < 0 )
        goto LABEL_39;
      v0 = PopBcdEstablishResumeObject(v24, v25);
      v13 = v24;
      if ( v0 < 0 || (v0 = PopBcdSetPendingResume(v24), BcdCloseObject(v25[0]), v13 = v24, v0 < 0) )
      {
        v5 = PopBcdClose(v13);
      }
      else
      {
        BcdForciblyUnloadStore(v24);
        RtlClearAllBits(v2 + 24);
        RtlSetAllBits((_DWORD *)(v2 + 32));
        *(_DWORD *)(v2 + 304) = PopGetHwConfigurationSignature();
        PopHiberInitializeResources(v2);
        if ( PopGetBitlockerKeyLocation(v25) >= 0 )
        {
          v14 = (char *)((unsigned int)v25[0] >> 12);
          *(_DWORD *)(v2 + 192) = (unsigned int)v25[0] >> 12;
          PopDiscardRange(v2, v14, 4u, 1802269762);
        }
        if ( !KdPitchDebugger || KdEventLoggingEnabled )
        {
          PoSetHiberRange(v2, 2, &KdTimerDifference, 0, 543646276);
          PoSetHiberRange(v2, 2, &KdDebuggerLock, 0, 543646276);
        }
        MmMarkHiberRange(v2, dword_61EEBC, 53248);
        off_61797C(v2);
        v15 = *(_DWORD *)(v2 + 108);
        if ( v15 )
          IoGetDumpHiberRanges(v2, v15);
        v16 = (unsigned int)(4 * PopHiberScratchPages + 4095) >> 12;
        v17 = *(_DWORD *)(v2 + 152);
        *(_DWORD *)(v2 + 100) = v16;
        if ( v17 )
        {
          v18 = *(_DWORD *)(v2 + 156);
          if ( v18 > v16 )
            *(_DWORD *)(v2 + 100) = v18;
        }
        v5 = (int)PopAllocatePages(*(_DWORD *)(v2 + 100));
        v0 = *(_DWORD *)(v2 + 120);
        *(_DWORD *)(v2 + 96) = v5;
        if ( v0 < 0 )
          goto LABEL_39;
        v5 = (int)PopAllocatePages(0x10u);
        *(_DWORD *)(v6 + 8) = v5;
        if ( v5 )
        {
          PoSetHiberRange(v2, 0x8000, (const void *)(v5 + 0x2000), (const void *)0xE000, 1835363652);
          if ( (*(_DWORD *)(v6 + 76) & 0xFFF) != 0 )
          {
            PopInternalAddToDumpFile(v6, 192, 0);
            PopInternalAddToDumpFile(v2, 312, 0);
            KeBugCheckEx(160, 258, 10, v6, v2);
          }
          v19 = v6;
          v20 = 2;
          do
          {
            v21 = *(const void **)(v19 + 12);
            if ( v21 )
              PoSetHiberRange(v2, 0x8000, v21, *(const void **)(v6 + 76), 1718968931);
            v19 += 4;
            --v20;
          }
          while ( v20 );
          v22 = PopGenerateUnHibernatedMdl(v2, PopHiberScratchPages);
          *(_DWORD *)(v2 + 76) = v22;
          if ( !v22 )
          {
            MmEmptyAllWorkingSets();
            MmFlushAllPages();
            v5 = (int)PopGenerateUnHibernatedMdl(v2, PopHiberScratchPages);
            *(_DWORD *)(v2 + 76) = v5;
            if ( !v5 )
            {
              v0 = -1073741670;
              goto LABEL_39;
            }
          }
          v5 = BgkResumePrepare(v2);
          if ( v5 >= 0 )
            PopBgkResumePrepared = 1;
          *(_DWORD *)(v2 + 124) = *(_DWORD *)(v2 + 160) - 1;
          v0 = 0;
        }
        else
        {
          v0 = *(_DWORD *)(v2 + 120);
        }
      }
      if ( v0 >= 0 )
        return v0;
    }
    else
    {
      v0 = -1073741809;
    }
LABEL_39:
    PopFreeHiberContext(v5);
    return v0;
  }
  return 0;
}
