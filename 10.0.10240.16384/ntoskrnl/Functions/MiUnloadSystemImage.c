// MiUnloadSystemImage 
 
unsigned int __fastcall MiUnloadSystemImage(unsigned int result, char a2)
{
  int v2; // r6
  char v3; // r9
  int v4; // r10
  unsigned int v5; // r7
  int v6; // r5
  int v7; // r4
  _DWORD *v8; // r8
  int v9; // r0
  int v10; // r1
  int v11; // r1
  int v12; // r1
  __int16 v13; // r2
  char *v14; // r2
  int *v15; // r4
  int v16; // r9
  int v17; // r8
  int v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r0
  int v21; // r2
  unsigned int v22; // r0
  int v23; // r0
  int v24; // r2
  unsigned int v25; // r5
  int v26; // r0
  _DWORD *v27; // r4
  int v28; // r3
  int v29; // r0
  unsigned int v30; // r1
  int v31; // r4
  unsigned int *v32; // r2
  unsigned int v33; // r4
  int v34; // r0
  int v35; // [sp+18h] [bp-98h]
  int v36; // [sp+18h] [bp-98h]
  int v37; // [sp+1Ch] [bp-94h]
  int v39; // [sp+28h] [bp-88h]
  int v40; // [sp+30h] [bp-80h] BYREF
  int v41; // [sp+34h] [bp-7Ch]
  int v42; // [sp+38h] [bp-78h]
  int v43; // [sp+3Ch] [bp-74h]
  unsigned int v44; // [sp+40h] [bp-70h] BYREF
  unsigned int v45; // [sp+44h] [bp-6Ch]
  int v46; // [sp+48h] [bp-68h]
  char v47[4]; // [sp+4Ch] [bp-64h] BYREF
  int *v48; // [sp+50h] [bp-60h] BYREF

  v2 = result;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v3 = a2;
  if ( *(_DWORD *)(result + 76) != 1 )
  {
    if ( (a2 & 4) == 0 )
      return sub_7CE7C4();
    v4 = result + 92;
    v5 = *(_DWORD *)(result + 24);
    v6 = *(_DWORD *)(result + 32) >> 12;
    v7 = *(_DWORD *)(result + 60);
    v37 = v7;
    v8 = 0;
    if ( v5 >= dword_63389C
      && ((v9 = MiGetSystemRegionIndex(v5), *(_BYTE *)(v9 + v10 + 9692) == 1)
       || (result = MiGetSystemRegionIndex(v5), *((_BYTE *)MiState + result + v11) == 11)) )
    {
      v39 = 0;
      result = MiSessionRemoveImage(v2, &v44);
      if ( !result )
        return result;
      result = MiSectionControlArea(v7);
      v8 = (_DWORD *)result;
      if ( *(_DWORD *)v2 )
        result = ExCovReadjustUnloadedModuleEntry(v2, 0);
      v28 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
      v36 = v28;
      if ( (v3 & 1) != 0 )
      {
        MiDeleteSystemPagableVm((int *)(v28 + 3248), (int)v8, ((v5 >> 10) & 0x3FFFFC) - 0x40000000, v6, 3, &v40);
        if ( (v8[7] & 0x4000000) != 0 )
        {
          v29 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
          MiDereferencePerSessionProtos(v8, v29);
        }
        result = ((v5 >> 20) & 0xFFC) - 1070596096;
        if ( v44 && ((v44 >> 20) & 0xFFC) - 1070596096 == result )
          result = ((v5 >> 20) & 0xFFC) - 1070596092;
        v30 = (((*(_DWORD *)(v2 + 32) + v5 - 1) >> 20) & 0xFFC) - 1070596096;
        if ( v45 && ((v45 >> 20) & 0xFFC) - 1070596096 == v30 )
          v30 = (((*(_DWORD *)(v2 + 32) + v5 - 1) >> 20) & 0xFFC) - 1070596100;
        if ( v30 >= result )
          result = MiDeleteSessionPdes(result, v30);
      }
      v31 = v46;
      if ( v46 )
      {
        MiReturnCommit((int)MiSystemPartition, v46 - v41);
        result = -v31;
        v32 = (unsigned int *)(v36 + 32);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 + result, v32) );
      }
      v6 = 0;
      if ( (v3 & 0x10) != 0 )
        result = MiDereferenceImports(*(_DWORD *)(v2 + 76));
      v12 = 0;
    }
    else
    {
      v12 = 1;
      v39 = 1;
    }
    v13 = *(_WORD *)(v2 + 56);
    *(_WORD *)(v2 + 56) = v13 - 1;
    if ( v13 == 1 )
    {
      if ( !v12 )
        MiDeleteSessionDriverProtos(v8);
      if ( (v3 & 2) != 0 )
      {
        VfDriverUnloadImage(v2);
        KseDriverUnloadImage(v2);
      }
      LdrUnloadAlternateResourceModule();
      if ( (*(_DWORD *)(v2 + 52) & 0x100000) != 0 )
        DbgUnLoadImageSymbolsUnicode((unsigned __int16 *)(v2 + 44), v5, -1);
      if ( *(_DWORD *)v2 && v6 )
        ExCovReadjustUnloadedModuleEntry(v2, 0);
      v35 = 0;
      if ( v6 && (v3 & 1) != 0 )
      {
        MiRememberUnloadedDriver(v2 + 44, v5, v6 << 12);
        v15 = 0;
        if ( v37 )
        {
          v15 = (int *)MiSectionControlArea(v37);
          if ( *(_DWORD *)v2 )
          {
            v48 = v15;
            MiManageSubsectionView((int *)&v48, v4, 4);
          }
        }
        if ( (*(_DWORD *)(((v5 >> 20) & 0xFFC) - 1070596096) & 0x400) != 0 )
        {
          if ( (dword_682604 & 1) != 0 )
          {
            v34 = MiInitPerfMemoryFlags(0, 6);
            MiLogPerfMemoryRangeEvent(v5, 0, v34, (v6 + 1023) & 0xFFFFFC00);
          }
          MiUnmapLargeDriver(v5, v6);
          v35 = 1;
          v17 = v6;
        }
        else
        {
          if ( v4 )
            MiUnlockDriverCode(v2);
          v16 = (v5 >> 10) & 0x3FFFFC;
          dword_632F3C = v2;
          MiDeleteSystemPagableVm((int *)dword_634F00, (int)v15, v16 - 0x40000000, v6, 5, &v40);
          v17 = v43;
          if ( v15 )
            MiValidateImagePages(v15, (int)v47, 4, -1);
          dword_632F3C = 0;
          v18 = v40 - v17;
          do
            v19 = __ldrex((unsigned int *)&algn_632F58[4]);
          while ( __strex(v19 + v18, (unsigned int *)&algn_632F58[4]) );
          if ( !v37 )
            MiReleaseDriverPtes(0, v16 - 0x40000000, v6);
          v3 = a2;
        }
        v14 = algn_634DB0;
        do
          v20 = __ldrex((unsigned int *)algn_634DB0);
        while ( __strex(v20 - v17, (unsigned int *)algn_634DB0) );
        if ( *(_DWORD *)v2 )
          MiChargeWsles((int)dword_634F00, -v6, 0);
      }
      if ( v39 == 1 )
      {
        MiReturnSystemImageCommitment(v2, &v40, v14);
        if ( (v3 & 0x10) != 0 )
          MiDereferenceImports(*(_DWORD *)(v2 + 76));
      }
      MiClearImports(v2);
      if ( *(_DWORD *)v2 )
      {
        MiProcessLoaderEntry((int *)v2, 0, v21, *(_DWORD *)v2);
        if ( (PerfGlobalGroupMask & 4) != 0 )
          PerfLogImageUnload(
            v2 + 36,
            0,
            0,
            v5,
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64),
            *(_WORD *)(v2 + 58) & 0xF,
            (*(unsigned __int16 *)(v2 + 58) >> 4) & 7,
            0);
      }
      v22 = *(_DWORD *)(v2 + 40);
      if ( v22 )
        ExFreePoolWithTag(v22);
      if ( v37 )
      {
        if ( v4 )
        {
          v23 = *(_DWORD *)(v4 + 32);
          if ( v23 )
          {
            MiReturnResidentAvailable(v23);
            v24 = *(_DWORD *)(v4 + 32);
            do
              v25 = __ldrex(&dword_634A2C[121]);
            while ( __strex(v25 + v24, &dword_634A2C[121]) );
          }
        }
        v26 = MiSectionControlArea(v37);
        v27 = (_DWORD *)v26;
        if ( !v35 && v5 != *(_DWORD *)(*(_DWORD *)v26 + 24) )
        {
          MiFreePrivateFixupEntryForSystemImage(v5, 1);
          MiReturnSystemImageAddress(v5, *(_DWORD *)(v2 + 32));
        }
        MiDereferenceControlArea(v27);
        ObDereferenceObjectDeferDelete(v37);
      }
      result = ExFreePoolWithTag(v2);
    }
  }
  return result;
}
