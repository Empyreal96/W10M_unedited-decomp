// MmProtectSystemCacheView 
 
int __fastcall MmProtectSystemCacheView(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // r8
  int v5; // r7
  unsigned int v6; // r1
  unsigned int v7; // r5
  unsigned int v9; // r9
  int *v10; // lr
  unsigned int v11; // r0
  int v12; // r4
  unsigned int v13; // r6
  int *v14; // r7
  unsigned int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r7
  unsigned int v18; // r3
  int v19; // r4
  int v20; // r4
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r4
  unsigned int *v26; // r2
  unsigned int v27; // r0
  unsigned __int8 *v28; // r1
  int v29; // r3
  unsigned int v30; // r2
  int v31; // r0
  int v32; // r0
  int *v33; // [sp+0h] [bp-C8h]
  int v35; // [sp+Ch] [bp-BCh]
  int v36; // [sp+10h] [bp-B8h] BYREF
  char v37; // [sp+14h] [bp-B4h]
  char v38; // [sp+15h] [bp-B3h]
  int v39; // [sp+18h] [bp-B0h]
  int v40; // [sp+1Ch] [bp-ACh]
  int v41; // [sp+20h] [bp-A8h]
  int v42; // [sp+24h] [bp-A4h]

  v4 = a3;
  if ( a3 == 2 || a3 == 4 )
  {
    v40 = 0;
    v38 = 0;
    v42 = 0;
    v5 = MiMakeProtectionMask(a3);
    v36 = 0;
    v41 = 0;
    v37 = 0;
    v7 = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
    v39 = 33;
    if ( (a2 & 0xFFF) != 0 )
      return sub_549D40();
    v9 = v7 + 4 * (a2 >> 12);
    v35 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634E00);
    }
    else
    {
      v10 = MiState;
      do
        v11 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
      while ( __strex(v11 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
      __dmb(0xBu);
      if ( v11 >> 7 )
      {
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
        v10 = MiState;
      }
      while ( 1 )
      {
        v12 = v10[2272];
        if ( (v12 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v12 & 0x40000000) == 0 )
        {
          v26 = (unsigned int *)(v10 + 2272);
          do
            v27 = __ldrex(v26);
          while ( v27 == v12 && __strex(v12 | 0x40000000, v26) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v4 = a3;
    }
    v13 = v7 + 1070596096;
    v14 = &MmProtectToPteMask[v5];
    v33 = v14;
    while ( 1 )
    {
      v15 = *(_DWORD *)v7;
      if ( (*(_DWORD *)v7 & 2) != 0 )
      {
        if ( v4 == 2 )
        {
          if ( (v15 & 0x80) == 0 )
            goto LABEL_18;
        }
        else if ( v4 != 4 || (v15 & 0x80) != 0 )
        {
          goto LABEL_18;
        }
        v17 = (*v14 & 0x3ED | (v15 >> 12 << 12) | MiDetermineUserGlobalPteMask(v7)) & 0xFFFFF3FF | 0x12;
        if ( (v15 & 0x200) == 0 )
        {
          v20 = MmPfnDatabase + 24 * (v15 >> 12);
          v21 = (unsigned __int8 *)(v20 + 15);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 | 0x80, v21) );
          __dmb(0xBu);
          if ( v22 >> 7 )
          {
            v28 = (unsigned __int8 *)(v20 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v29 = *(_DWORD *)(v20 + 12);
                __dmb(0xBu);
              }
              while ( (v29 & 0x80000000) != 0 );
              do
                v30 = __ldrex(v28);
              while ( __strex(v30 | 0x80, v28) );
              __dmb(0xBu);
            }
            while ( v30 >> 7 );
          }
          v23 = MiCaptureDirtyBitToPfn(v20);
          __dmb(0xBu);
          v24 = (unsigned int *)(v20 + 12);
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 & 0x7FFFFFFF, v24) );
          if ( v23 )
            MiReleasePageFileInfo((int)MiSystemPartition, v23, 1, 0);
        }
        if ( v13 + 3145728 > 0x3FFFFF )
        {
          *(_DWORD *)v7 = v17;
        }
        else
        {
          v18 = *(_DWORD *)v7;
          v19 = 0;
          __dmb(0xBu);
          *(_DWORD *)v7 = v17;
          if ( (v18 & 2) == 0 )
            v19 = 1;
          if ( v13 <= 0xFFF )
          {
            v31 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v31, (_DWORD *)(v31 + 4 * (v7 & 0xFFF)), v17);
          }
          if ( v19 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        MiInsertTbFlushEntry((int)&v36, v7 << 10, 1, 0);
        v4 = a3;
        goto LABEL_17;
      }
      if ( v4 == 2 )
        break;
      if ( (v15 & 0x200) != 0 )
      {
        v16 = v15 & 0xFFFFFDFF;
        if ( v13 + 3145728 > 0x3FFFFF )
          goto LABEL_48;
        __dmb(0xBu);
        *(_DWORD *)v7 = v16;
        if ( v13 > 0xFFF )
          goto LABEL_17;
        goto LABEL_61;
      }
LABEL_18:
      v7 += 4;
      v13 += 4;
      if ( v7 >= v9 )
      {
        MiFlushTbList((unsigned int)&v36, 4095);
        MiUnlockWorkingSetExclusive((int)&dword_634E00, v35);
        return 0;
      }
    }
    if ( (v15 & 0x200) != 0 )
      goto LABEL_18;
    v16 = v15 | 0x200;
    if ( v13 + 3145728 > 0x3FFFFF )
    {
LABEL_48:
      *(_DWORD *)v7 = v16;
      goto LABEL_18;
    }
    __dmb(0xBu);
    *(_DWORD *)v7 = v16;
    if ( v13 > 0xFFF )
      goto LABEL_17;
LABEL_61:
    v32 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
    MiArmWriteConvertedHardwarePde(v32, (_DWORD *)(v32 + 4 * (v7 & 0xFFF)), v16);
LABEL_17:
    v14 = v33;
    goto LABEL_18;
  }
  return -1073741583;
}
