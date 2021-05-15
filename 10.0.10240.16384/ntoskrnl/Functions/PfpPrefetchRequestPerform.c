// PfpPrefetchRequestPerform 
 
int __fastcall PfpPrefetchRequestPerform(int a1)
{
  char v2; // r8
  _BYTE *v3; // r0
  _BYTE *v4; // r5
  int v6; // r2
  int v7; // r4
  int v8; // r2
  int v9; // r4
  int v10; // r4
  _BYTE *v11; // r0
  unsigned int v12; // r7
  int v13; // r5
  int v14; // r4
  int v15; // r4
  int v16; // r3
  int v17; // r0
  int v18; // r2
  unsigned int v19; // r5
  int v20; // r2
  int v21; // r10
  int v22; // r0
  int v23; // r0
  int v24; // r5
  unsigned int v25; // r1
  char *v26; // r2
  int v27; // r3
  unsigned int v28; // r7
  int v29; // r5
  int v30; // r4
  int v31; // r0
  int v32; // r0
  int v33; // r3
  unsigned int v34; // r1
  unsigned int v35; // r7
  int v36; // r6
  int v37; // [sp+8h] [bp-B0h]
  int v38; // [sp+10h] [bp-A8h]
  char v39[16]; // [sp+18h] [bp-A0h] BYREF
  int v40[36]; // [sp+28h] [bp-90h] BYREF

  memset(v40, 0, 112);
  v40[0] = a1;
  KeInitializeEvent((int)v39, 0, 0);
  v2 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) = 0;
  v3 = (_BYTE *)ExAllocatePoolWithTag(512, 80, 1129539152);
  v4 = v3;
  v40[5] = (int)v3;
  if ( !v3 )
    return sub_80EB60();
  memset(v3, 0, 80);
  *((_DWORD *)v4 + 5) = PfpPrefetchSharedConflictNotify;
  *((_DWORD *)v4 + 6) = v4;
  KeInitializeEvent((int)(v4 + 60), 0, 0);
  *(_DWORD *)(v40[5] + 12) = v40;
  if ( (*(_DWORD *)(v40[0] + 56) & 4) != 0 )
  {
    *(_DWORD *)(v40[5] + 32) = 60000;
    v6 = 150;
  }
  else
  {
    *(_DWORD *)(v40[5] + 32) = 250;
    v6 = 15;
  }
  *(_DWORD *)(v40[5] + 28) = v6;
  v7 = PfpPrefetchSharedStart((_DWORD *)v40[5]);
  v8 = v40[0];
  if ( v7 >= 0 )
  {
    v9 = *(unsigned __int8 *)(v40[0] + 57);
    v38 = v9;
    if ( *(_BYTE *)(v40[0] + 57) )
    {
      __dmb(0xBu);
      do
        v25 = __ldrex((unsigned int *)&dword_643B70);
      while ( __strex(v25 + 1, (unsigned int *)&dword_643B70) );
      __dmb(0xBu);
      v26 = *(char **)(v40[0] + 52);
      if ( !v26 )
        v26 = v39;
      v7 = PfpScenCtxPrefetchAbortSet((unsigned int)&unk_637290, v9, (int)v26, 0, 0);
      if ( v7 < 0 )
        goto LABEL_32;
      v8 = v40[0];
      if ( !*(_DWORD *)(v40[0] + 52) )
      {
        *(_DWORD *)(v40[0] + 52) = v39;
        v8 = v40[0];
      }
    }
    v10 = 40 * *(_DWORD *)(a1 + 8);
    if ( v10 )
    {
      v11 = (_BYTE *)ExAllocatePoolWithTag(1, 40 * *(_DWORD *)(a1 + 8), 1213621840);
      v40[2] = (int)v11;
      if ( !v11 )
      {
        v7 = -1073741670;
        goto LABEL_32;
      }
      memset(v11, 0, v10);
      v12 = 0;
      if ( *(_DWORD *)(a1 + 8) )
      {
        v13 = 0;
        do
        {
          v14 = v13 + v40[2];
          memset((_BYTE *)(v13 + v40[2]), 0, 20);
          *(_DWORD *)(v14 + 16) |= 2u;
          v15 = v13 + v40[2];
          memset((_BYTE *)(v13 + v40[2] + 20), 0, 20);
          ++v12;
          v13 += 40;
          *(_DWORD *)(v15 + 36) |= 2u;
        }
        while ( v12 < *(_DWORD *)(a1 + 8) );
      }
      v8 = v40[0];
    }
    if ( (*(_DWORD *)(v8 + 56) & 4) != 0 )
      v16 = 16;
    else
      v16 = 768;
    v40[4] = v16;
    v17 = ExAllocatePoolWithTag(1, 8 * (v16 + 2), 1347249744);
    v8 = v40[0];
    v40[3] = v17;
    if ( !v17 )
    {
      v7 = -1073741670;
      goto LABEL_33;
    }
    if ( (*(_DWORD *)(v40[0] + 56) & 4) == 0 )
    {
      v27 = *(_DWORD *)(v40[0] + 12);
      if ( v27 )
      {
        v23 = ExAllocatePoolWithTag(1, 20 * v27, 1749444176);
        v40[1] = v23;
        if ( !v23 )
        {
          v7 = -1073741670;
          v8 = v40[0];
          goto LABEL_34;
        }
        v28 = 0;
        if ( *(_DWORD *)(v40[0] + 12) )
        {
          v29 = 0;
          while ( 1 )
          {
            v30 = v29 + v23;
            memset((_BYTE *)(v29 + v23), 0, 20);
            ++v28;
            v29 += 20;
            *(_DWORD *)(v30 + 16) |= 2u;
            if ( v28 >= *(_DWORD *)(v40[0] + 12) )
              break;
            v23 = v40[1];
          }
        }
      }
    }
    PfpPrefetchRequestPatchOffsets(a1);
    if ( !*(_WORD *)(a1 + 30) )
    {
      v18 = *(_DWORD *)(a1 + 28);
      if ( (_WORD)v18 )
        *(_WORD *)(a1 + 30) = v18 - 1;
    }
    if ( !*(_DWORD *)(a1 + 20)
      || (v31 = PfpPrefetchPrivatePages(v40), v7 = v31, v31 != -1073741248) && v31 != -1073741670 && v31 != -1073741801 )
    {
      v19 = 0;
      if ( *(_DWORD *)(a1 + 8) )
      {
        v20 = 0;
        v37 = 0;
        v21 = 0;
        do
        {
          if ( PfpVolumeOpenAndVerify(v40[5], v21 + v40[2], v20 + *(_DWORD *)(a1 + 32)) >= 0 )
          {
            v7 = PfpVolumePrefetchMetadata(v40, v19);
            if ( v7 == -1073741248 )
              goto LABEL_32;
          }
          ++v19;
          v20 = v37 + 32;
          v37 += 32;
          v21 += 40;
        }
        while ( v19 < *(_DWORD *)(a1 + 8) );
      }
      if ( (*(_DWORD *)(v40[0] + 56) & 4) != 0 )
      {
        v22 = PfpPrefetchFilesTrickle(v40);
LABEL_28:
        v7 = v22;
        if ( v22 != -1073741248 && v22 != -1073741670 && v22 != -1073741801 )
          v7 = 0;
        goto LABEL_32;
      }
      v32 = PfpPrefetchFiles(v40, 0);
      v7 = v32;
      if ( v32 != -1073741248 && v32 != -1073741670 && v32 != -1073741801 )
      {
        v8 = v40[0];
        v24 = v40[5];
        v33 = *(_DWORD *)(v40[0] + 52);
        if ( v33 && *(_DWORD *)(v33 + 4)
          || (*(_DWORD *)(v40[0] + 56) & 4) != 0 && (*(_DWORD *)(v40[5] + 44) || (*(_DWORD *)(v40[5] + 40) & 4) != 0) )
        {
          v23 = v40[1];
          v7 = -1073741248;
LABEL_35:
          if ( v38 )
          {
            __dmb(0xBu);
            do
              v34 = __ldrex((unsigned int *)&dword_643B70);
            while ( __strex(v34 - 1, (unsigned int *)&dword_643B70) );
            __dmb(0xBu);
            PfpScenCtxPrefetchAbortSet((unsigned int)&unk_637290, v38, 0, 1, 0);
            v24 = v40[5];
            v8 = v40[0];
            v23 = v40[1];
          }
          goto LABEL_36;
        }
        v22 = PfpPrefetchFiles(v40, 1);
        goto LABEL_28;
      }
    }
LABEL_32:
    v8 = v40[0];
LABEL_33:
    v23 = v40[1];
LABEL_34:
    v24 = v40[5];
    goto LABEL_35;
  }
  v24 = v40[5];
  v23 = v40[1];
LABEL_36:
  if ( v23 )
  {
    v35 = 0;
    if ( *(_DWORD *)(v8 + 12) )
    {
      v36 = 0;
      do
      {
        if ( (*(_DWORD *)(v36 + v23 + 16) & 4) != 0 )
        {
          PfpOpenHandleClose((int *)(v36 + v23), v24);
          v24 = v40[5];
          v8 = v40[0];
          v23 = v40[1];
        }
        ++v35;
        v36 += 20;
      }
      while ( v35 < *(_DWORD *)(v8 + 12) );
    }
    ExFreePoolWithTag(v23);
  }
  PfpPrefetchVolumesCleanup(v40);
  if ( v40[3] )
    ExFreePoolWithTag(v40[3]);
  if ( v40[5] )
  {
    PfpPrefetchSharedCleanup((_DWORD *)v40[5]);
    ExFreePoolWithTag(v40[5]);
  }
  *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) = v2;
  return v7;
}
