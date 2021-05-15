// MiReleasePageFileInfo 
 
int __fastcall MiReleasePageFileInfo(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r6
  char v6; // r7
  int v7; // r9
  int v8; // r10
  int v9; // r8
  unsigned int *v10; // r5
  int result; // r0
  unsigned int v12; // r1
  int v13; // r5
  int v14; // r3
  unsigned int v15; // r7
  unsigned int v16; // lr
  unsigned int v17; // r1
  unsigned int v18; // r1
  int v19; // r5
  int v20; // r1
  unsigned int v21; // r3
  BOOL v22; // r7
  unsigned int v23; // r3
  int v24; // r0
  unsigned int v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // r0
  unsigned int *v29; // r1
  unsigned int *v30; // r2
  int v31; // r7
  int v32; // r2
  int v33; // r0
  int v34; // r0
  int v35; // r3
  int v36; // r0
  int v37; // r0
  int v38; // [sp+0h] [bp-40h]
  int v39; // [sp+0h] [bp-40h]
  int v40; // [sp+4h] [bp-3Ch]
  _DWORD *v41; // [sp+Ch] [bp-34h]
  int v42; // [sp+10h] [bp-30h]
  int v44; // [sp+18h] [bp-28h] BYREF
  unsigned int *v45; // [sp+1Ch] [bp-24h]
  int varg_r0; // [sp+48h] [bp+8h]
  unsigned int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = *(_DWORD *)(a1 + 4 * ((a2 >> 2) & 1) + 3600);
  v5 = a2 >> 13;
  v42 = a3 & 1;
  v6 = a3;
  varg_r1 = a2;
  v7 = (a2 >> 3) & 1;
  v8 = (a2 >> 4) & 1;
  v9 = 0;
  if ( (a3 & 1) != 0 )
  {
    v10 = (unsigned int *)(v4 + 116);
    v44 = 0;
    v45 = (unsigned int *)(v4 + 116);
    __dmb(0xBu);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_5399C0(&MmPfnDatabase);
    do
      v12 = __ldrex(v10);
    while ( __strex((unsigned int)&v44, v10) );
    __dmb(0xBu);
    if ( v12 )
      KxWaitForLockOwnerShip(&v44);
  }
  else
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v4 + 116), (unsigned int)&v44);
  }
  v13 = *(_DWORD *)(v4 + 64);
  v40 = v13;
  if ( v7 )
  {
    *(_BYTE *)((v5 >> 3) + *(_DWORD *)(v13 + 16)) &= ~(unsigned __int8)(1 << (v5 & 7));
    ++*(_DWORD *)(v4 + 24);
    if ( v5 < *(_DWORD *)(v4 + 72) )
      *(_DWORD *)(v4 + 72) = v5;
  }
  if ( !v8 )
    goto LABEL_20;
  if ( (v6 & 2) == 0 )
  {
    v14 = *(_DWORD *)(v4 + 108);
    if ( v14 )
    {
      v15 = v14 + 4 * v5;
      v16 = ((v15 >> 10) & 0x3FFFFC) - 0x40000000;
      v17 = *(_DWORD *)v16;
      if ( (*(_DWORD *)v16 & 2) != 0 )
      {
        *(_DWORD *)v15 = 1;
        v41 = (_DWORD *)(MmPfnDatabase + 24 * (v17 >> 12));
        v18 = (unsigned int)(v41 + 2);
        v19 = v41[2] & 0x1FFF | (((v41[2] >> 13) - 1) << 13);
        if ( (unsigned int)(v41 + 2) < 0xC0000000 || v18 > 0xC03FFFFF )
        {
          *(_DWORD *)v18 = v19;
        }
        else
        {
          v34 = 0;
          v35 = *(_DWORD *)v18;
          v39 = 0;
          __dmb(0xBu);
          *(_DWORD *)v18 = v19;
          if ( (v35 & 2) == 0 && (v19 & 2) != 0 )
          {
            v34 = 1;
            v39 = 1;
          }
          if ( (unsigned int)(v41 + 267649026) <= 0xFFF )
          {
            v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v36, v36 + 4 * (v18 & 0xFFF), v19);
            v16 = ((v15 >> 10) & 0x3FFFFC) - 0x40000000;
            v34 = v39;
          }
          if ( v34 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        if ( (v19 & 0xFFFFE000) == 0 )
        {
          --*(_DWORD *)(v4 + 100);
          if ( v16 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v16 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v16 = 0;
            if ( v16 >= 0xC0300000 && v16 <= 0xC0300FFF )
            {
              v37 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v37, v37 + 4 * (v16 & 0xFFF), 0);
            }
          }
          KeFlushSingleTb(v15, 1);
          RtlpInterlockedPushEntrySList((unsigned __int64 *)(v4 + 48), v41);
        }
        v13 = v40;
      }
      else
      {
        v31 = *(_DWORD *)v16 & 0x1FFF | (((*(_DWORD *)v16 >> 13) - 1) << 13);
        if ( v16 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v16 = v31;
        }
        else
        {
          v32 = 0;
          v38 = 0;
          __dmb(0xBu);
          *(_DWORD *)v16 = v31;
          if ( (v17 & 2) == 0 && (v31 & 2) != 0 )
          {
            v32 = 1;
            v38 = 1;
          }
          if ( v16 + 1070596096 <= 0xFFF )
          {
            v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v33, v33 + 4 * (v16 & 0xFFF), v31);
            v32 = v38;
          }
          if ( v32 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
      }
    }
  }
  if ( (*(_WORD *)(v4 + 96) & 0x40) != 0 )
  {
    MiStoreSetEvictPageFile(v4, v5);
    v22 = 0;
    goto LABEL_30;
  }
  *(_BYTE *)((v5 >> 3) + *(_DWORD *)(v13 + 8)) &= ~(unsigned __int8)(1 << (v5 & 7));
  v20 = *(_DWORD *)(v4 + 12);
  v21 = *(_DWORD *)(v4 + 68);
  *(_DWORD *)(v4 + 12) = v20 + 1;
  if ( v5 < v21 )
    *(_DWORD *)(v4 + 68) = v5;
  if ( !v20 )
    v22 = (*(_BYTE *)(v4 + 98) & 1) != 0;
  else
LABEL_20:
    v22 = 0;
  if ( (v7 || ((*(int *)(*(_DWORD *)(v13 + 16) + 4 * (v5 >> 5)) >> (v5 & 0x1F)) & 1) == 0)
    && (v8 || ((*(int *)(*(_DWORD *)(v13 + 8) + 4 * (v5 >> 5)) >> (v5 & 0x1F)) & 1) == 0) )
  {
    v23 = *(_DWORD *)(v4 + 12);
    if ( v23 >= *(_DWORD *)(v4 + 24) )
      v23 = *(_DWORD *)(v4 + 24);
    *(_DWORD *)(v4 + 28) = v23;
    v9 = 1;
  }
  ++*(_DWORD *)(v4 + 80);
  if ( v9 )
  {
    v24 = *(_DWORD *)(v4 + 128);
    v25 = (*(_DWORD *)(v24 + 512) & 0xFFFFF800 | 0x400) & 0x7FF ^ (((*(_DWORD *)(v24 + 512) & 0xFFFFF800 | 0x400) & 0xFFFFF800)
                                                                 + 2048);
    v26 = (unsigned int *)(v24 + 512);
    do
      v27 = __ldrex(v26);
    while ( __strex(v25, v26) );
  }
LABEL_30:
  if ( v42 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = KiReleaseQueuedSpinLockInstrumented(&v44);
    }
    else
    {
      v28 = v44;
      if ( !v44 )
      {
        v29 = v45;
        __dmb(0xBu);
        do
          result = __ldrex(v29);
        while ( (int *)result == &v44 && __strex(0, v29) );
        if ( (int *)result == &v44 )
          goto LABEL_37;
        v28 = KxWaitForLockChainValid(&v44);
      }
      v44 = 0;
      __dmb(0xBu);
      v30 = (unsigned int *)(v28 + 4);
      do
        result = __ldrex(v30);
      while ( __strex(result ^ 1, v30) );
    }
  }
  else
  {
    result = KeReleaseInStackQueuedSpinLock((int)&v44);
  }
LABEL_37:
  if ( v22 )
    result = KeSetEvent(a1 + 520, 0, 0);
  return result;
}
