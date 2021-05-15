// MmChangeImageProtection 
 
int __fastcall MmChangeImageProtection(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r10
  unsigned int v7; // r9
  int v8; // r5
  int v9; // r3
  int v10; // r2
  int *v11; // r0
  unsigned int v12; // r7
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r4
  int v16; // r3
  int v17; // r4
  unsigned int v18; // r1
  int v19; // r0
  __int16 v20; // r3
  int v21; // r0
  int v22; // r2
  int *v23; // r1
  int v24; // t1
  int v25; // r0
  int v26; // r2
  unsigned int v27; // r0
  int v28; // r0
  int *v29; // r4
  int v30; // t1
  int *v31; // r6
  int v32; // t1
  int v33; // r3
  int v34; // r2
  int v35; // r0
  __int16 v36; // r3
  __int16 v37; // r3
  unsigned int v40; // [sp+Ch] [bp-24h]

  v40 = a2;
  v4 = a3;
  if ( a4 != 1 && a4 != 2
    || (*(_WORD *)(a1 + 6) & 7) != 2
    || *(_DWORD *)(a1 + 24)
    || (*(_DWORD *)(a1 + 20) & 0xFFF) != 0 )
  {
    return -1073741811;
  }
  v7 = *(_DWORD *)(a1 + 20) >> 12;
  v8 = MmAcquireLoadLock();
  v9 = (__int16)--*(_WORD *)(v8 + 308) - 1;
  *(_WORD *)(v8 + 308) = v9;
  ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, v10, v9);
  v11 = MiLookupDataTableEntry(*(_DWORD *)(a1 + 16), 1);
  v12 = (unsigned int)v11;
  if ( v11 )
  {
    v13 = v11[6];
    v14 = a2 + v4;
    v15 = *(_DWORD *)(v12 + 32) + v13;
    if ( *(_DWORD *)(a1 + 16) + *(_DWORD *)(a1 + 20) > v15 || a2 < v13 || v14 > v15 || v14 - 1 < a2 )
    {
      v17 = -1073741800;
    }
    else
    {
      v16 = *(_DWORD *)(v12 + 52);
      if ( (v16 & 0x80000) != 0 )
      {
        v17 = -1073741757;
      }
      else
      {
        *(_DWORD *)(v12 + 52) = v16 | 0x80000;
        v17 = 0;
        if ( v13 >= dword_63389C
          && (*((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v13)) == 1
           || *((_BYTE *)&MiState[2423] + MiGetSystemRegionIndex(v18)) == 11) )
        {
          MiSessionReferenceImage(v18);
        }
        else
        {
          ++*(_WORD *)(v12 + 56);
        }
      }
    }
  }
  else
  {
    v17 = -1073741275;
  }
  v19 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v20 = *(_WORD *)(v8 + 308) + 1;
  *(_WORD *)(v8 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v19);
  v21 = MmReleaseLoadLock(v8);
  if ( v17 >= 0 )
  {
    if ( (*(_DWORD *)(((*(_DWORD *)(v12 + 24) >> 20) & 0xFFC) - 1070596096) & 0x400) == 0 )
    {
      v22 = 0;
      if ( !v7 )
      {
LABEL_31:
        MiSetImageProtection(v12, *(_DWORD *)(a1 + 16), *(_DWORD *)(a1 + 20));
        if ( a4 == 1 )
        {
          v25 = *(_DWORD *)(v12 + 60);
          if ( v25 && (v26 = *(_DWORD *)(*(_DWORD *)(MiSectionControlArea(v25) + 56) + 4), (v26 & 0xFFFFFFF8) > 8) )
            v27 = v26 & 0xFFFFFFF8;
          else
            v27 = 0;
          if ( dword_61D8C8 )
          {
            v28 = dword_61D8C8(v27, a1, v40, a3, v40 - *(_DWORD *)(v12 + 24));
            v17 = v28;
            if ( v28 >= 0 )
            {
              if ( (MiFlags & 0x30000) != 0 && v28 == 300 && v7 )
              {
                v29 = (int *)(a1 + 28);
                do
                {
                  v30 = *v29++;
                  MiMarkPfnVerified(MmPfnDatabase + 24 * v30, 0);
                  --v7;
                }
                while ( v7 );
              }
              MiSetImageProtection(v12, *(_DWORD *)(a1 + 16), *(_DWORD *)(a1 + 20));
              v17 = 0;
            }
          }
          else
          {
            v17 = -1073741822;
          }
        }
        else if ( (MiFlags & 0x30000) != 0 && v7 )
        {
          v31 = (int *)(a1 + 28);
          do
          {
            v32 = *v31++;
            MiClearPfnImageVerified(MmPfnDatabase + 24 * v32, 24, 3 * v32, MmPfnDatabase);
            --v7;
          }
          while ( v7 );
        }
        goto LABEL_49;
      }
      v23 = (int *)(a1 + 28);
      while ( 1 )
      {
        v24 = *v23++;
        if ( (*(_DWORD *)(MmPfnDatabase + 24 * v24 + 20) & 0x8000000) != 0 )
          break;
        if ( ++v22 >= v7 )
          goto LABEL_31;
      }
    }
    v17 = -1073741800;
LABEL_49:
    MmAcquireLoadLock();
    v33 = *(__int16 *)(v8 + 308) - 1;
    *(_WORD *)(v8 + 308) = v33;
    ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, v34, v33);
    *(_DWORD *)(v12 + 52) &= 0xFFF7FFFF;
    v35 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
    v36 = *(_WORD *)(v8 + 308) + 1;
    *(_WORD *)(v8 + 308) = v36;
    if ( !v36 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(v35);
    MiUnloadSystemImage(v12, -1);
    v21 = MmReleaseLoadLock(v8);
  }
  v37 = *(_WORD *)(v8 + 308) + 1;
  *(_WORD *)(v8 + 308) = v37;
  if ( !v37 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v21);
  return v17;
}
