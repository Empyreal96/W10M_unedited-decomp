// MiFillPerSessionProtos 
 
int __fastcall MiFillPerSessionProtos(int a1, unsigned int a2, int a3, int a4, unsigned int a5, int a6, int a7, _DWORD *a8, _DWORD *a9)
{
  int v9; // r7
  __int16 v13; // r1
  int v14; // r0
  __int16 v15; // r3
  int v16; // r4
  int v17; // r8
  int v18; // r5
  int v19; // r10
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned __int8 *v22; // r1
  int v23; // r3
  unsigned int v24; // r2
  int v25; // r2
  int v26; // r0
  int v27; // r2
  unsigned int *v28; // r2
  unsigned int v29; // r4
  int v30; // r4
  int v31; // r0
  char v32[4]; // [sp+8h] [bp-50h] BYREF
  int v33; // [sp+Ch] [bp-4Ch]
  unsigned int v34; // [sp+10h] [bp-48h]
  unsigned int v35; // [sp+14h] [bp-44h]
  int v36; // [sp+18h] [bp-40h]
  int v37; // [sp+1Ch] [bp-3Ch]
  _WORD *v38; // [sp+20h] [bp-38h] BYREF
  __int16 v39; // [sp+24h] [bp-34h]
  unsigned __int16 v40; // [sp+26h] [bp-32h]
  __int64 v41[6]; // [sp+28h] [bp-30h] BYREF

  v9 = a4;
  v37 = a1;
  if ( a8 )
  {
    HIDWORD(v41[0]) = 0;
  }
  else
  {
    MiCreatePteCopyList(3 * a4 + 1, 3 * a4 + 1, (int)v41);
    if ( !HIDWORD(v41[0]) )
      return -1073741670;
    MI_INITIALIZE_COLOR_BASE(0, 0, (int)&v38);
  }
  if ( v9 )
  {
    v35 = a5 & 0x1F;
    v36 = a3 - a2;
    v34 = 0x3FFFFF;
    v33 = a6;
    do
    {
      v13 = v39;
      v14 = v40;
      if ( a8 )
      {
        v17 = MiAllocateDriverPage(v40);
      }
      else
      {
        v15 = *v38 + 1;
        *v38 = v15;
        v16 = (unsigned __int16)(v15 & v13);
        while ( 1 )
        {
          v17 = MiGetPage((int)MiSystemPartition, v16 | v14, 0);
          if ( v17 != -1 )
            break;
          MiWaitForFreePage(MiSystemPartition);
          v14 = v40;
        }
      }
      v18 = MmPfnDatabase + 24 * v17;
      while ( 1 )
      {
        v19 = MiLockProtoPoolPage(a2, v32);
        if ( v19 )
          break;
        MmAccessFault(1, a2, 0, 0);
      }
      v20 = (unsigned __int8 *)(v18 + 15);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 | 0x80, v20) );
      __dmb(0xBu);
      if ( v21 >> 7 )
      {
        v22 = (unsigned __int8 *)(v18 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v18 + 12);
            __dmb(0xBu);
          }
          while ( v23 < 0 );
          do
            v24 = __ldrex(v22);
          while ( __strex(v24 | 0x80, v22) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
      }
      MiInitializePfn(v18, (int *)a2, a5, 23);
      v25 = 32 * (v35 | (v17 << 7) | 0x40);
      if ( a2 + 0x40000000 > v34 )
      {
        *(_DWORD *)a2 = v25;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)a2 = v25;
        if ( a2 + 1070596096 <= 0xFFF )
        {
          v26 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v26, (_DWORD *)(v26 + 4 * (a2 & 0xFFF)), v25);
        }
      }
      ++*(_WORD *)(v18 + 16);
      if ( (*(_BYTE *)(v18 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (v18 - MmPfnDatabase) / 24, *(_BYTE *)(v18 + 18) & 7, *(_DWORD *)(v18 + 12) & 0x3FFFFFFF);
      v27 = *(_DWORD *)(v18 + 12);
      *(_DWORD *)(v18 + 12) = v27 & 0xC0000000 | ((v27 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
      if ( (v27 & 0x3FFFFFFF) == 1 )
        MiPfnShareCountIsZero(v18, 0);
      __dmb(0xBu);
      v28 = (unsigned int *)(v18 + 12);
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 & 0x7FFFFFFF, v28) );
      MiUnlockProtoPoolPage(v19, (unsigned __int8)v32[0]);
      if ( a8 )
      {
        MiMarkPfnVerified(v18, 0);
      }
      else
      {
        MiCopyPage(v17, *(_DWORD *)(v36 + a2), (char *)v41, 8);
        v30 = MiGetPteFromCopyList(v41, v17, -1);
        MiRelocateImagePfn(v37, v30 << 10, v33, v17, a7);
        if ( v30 + 0x40000000 > v34 )
        {
          *(_DWORD *)v30 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v30 = 0;
          if ( (unsigned int)(v30 + 1070596096) <= 0xFFF )
          {
            v31 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v31, (_DWORD *)(v31 + 4 * (v30 & 0xFFF)), 0);
          }
        }
        MiReturnPfnReferenceCount(v18);
      }
      a2 += 4;
      --v9;
      ++v33;
      if ( a8 )
      {
        *a8 += 4096;
        *a9 += 4096;
      }
    }
    while ( v9 );
  }
  MiReleasePteCopyList((int)v41);
  return 0;
}
