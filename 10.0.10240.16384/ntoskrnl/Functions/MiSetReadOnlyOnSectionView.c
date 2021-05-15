// MiSetReadOnlyOnSectionView 
 
int __fastcall MiSetReadOnlyOnSectionView(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v8; // r7
  unsigned int v9; // r4
  unsigned int v10; // r5
  int v11; // r8
  unsigned int *v12; // r9
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r7
  unsigned int v17; // r2
  unsigned int v18; // r7
  int v19; // r5
  _DWORD *v20; // r0
  int v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r2
  int v24; // r3
  int v25; // r5
  int v26; // r6
  bool v27; // cc
  int v28; // r0
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r0
  unsigned int v32; // [sp+8h] [bp-D8h]
  int v34; // [sp+10h] [bp-D0h]
  int v35; // [sp+14h] [bp-CCh]
  unsigned int v36; // [sp+18h] [bp-C8h]
  int v37; // [sp+1Ch] [bp-C4h]
  char v38[4]; // [sp+24h] [bp-BCh] BYREF
  int v39; // [sp+28h] [bp-B8h] BYREF
  char v40; // [sp+2Ch] [bp-B4h]
  char v41; // [sp+2Dh] [bp-B3h]
  int v42; // [sp+30h] [bp-B0h]
  int v43; // [sp+34h] [bp-ACh]
  int v44; // [sp+38h] [bp-A8h]
  int v45; // [sp+3Ch] [bp-A4h]

  if ( MiVadPureReserve(a2) )
    return sub_52A840();
  v34 = 4;
  v43 = 0;
  v44 = 0;
  v40 = 0;
  v41 = 0;
  v39 = 1;
  v42 = 33;
  v8 = 0;
  v45 = 0;
  v35 = 0;
  v36 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
  v9 = v36;
  v10 = ((a4 >> 10) & 0x3FFFFC) - 0x40000000;
  v32 = v10;
  v11 = 1;
  __mrc(15, 0, 13, 0, 3);
  v12 = (unsigned int *)(a1 + 492);
  v37 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v12);
  }
  else
  {
    v13 = (unsigned __int8 *)(a1 + 495);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v12);
    while ( 1 )
    {
      v15 = *v12;
      if ( (*v12 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v22 = __ldrex(v12);
        while ( v22 == v15 && __strex(v15 | 0x40000000, v12) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MiMakeSystemAddressValid(v36, 0);
  if ( v36 <= v10 )
  {
    while ( 1 )
    {
      v16 = v9 & 0xFFF;
      if ( (v9 & 0xFFF) == 0 )
      {
        MiFlushTbList(&v39);
        MiMakeSystemAddressValid(v9, 0);
      }
      v17 = *(_DWORD *)v9;
      if ( !*(_DWORD *)v9 )
        goto LABEL_25;
      if ( (v17 & 2) != 0 )
      {
        v18 = v17 >> 12;
        v19 = MmPfnDatabase + 24 * (v17 >> 12);
        if ( *(unsigned __int16 *)(v19 + 16) > 1u && (v11 & 7) != 4 )
          goto LABEL_25;
        if ( (*(_DWORD *)(v19 + 20) & 0x8000000) != 0 )
        {
          if ( (*(_DWORD *)(v19 + 4) | 0x80000000) != MiGetProtoPteAddress(a2, v9 << 10 >> 12, 1, v38) )
            goto LABEL_25;
          v20 = (_DWORD *)(MEMORY[0xC0402024] * MiLocateWsle(v9 << 10, v12, *(_DWORD *)v19) - 1069537344);
          v21 = (*v20 >> 4) & 0x1F;
          if ( v21 != v34 )
          {
            if ( v21 )
              goto LABEL_25;
            v23 = *(_DWORD *)(v19 + 8);
            v24 = (v23 & 0x400) != 0 ? (*(unsigned __int16 *)((*(_DWORD *)(v19 + 8) & 0xFFFFF800 | (2
                                                                                                  * (*(_DWORD *)(v19 + 8) & 0x3FC)))
                                                            + 0x10) >> 1) & 0x1F : (v23 >> 5) & 0x1F;
            if ( v24 != v34 )
              goto LABEL_25;
          }
          *v20 ^= ((unsigned __int16)*v20 ^ (unsigned __int16)(16 * v11)) & 0x1F0;
        }
        else
        {
          if ( ((*(_DWORD *)(v19 + 8) >> 5) & 0x1F) != v34 )
            goto LABEL_25;
          v11 = MiUpdatePfnProtection(a2, v19, v11);
        }
        MiRevertValidPte(a2, v9, v11, v18, &v39);
        goto LABEL_20;
      }
      if ( (v17 & 0x400) != 0 )
        break;
      if ( (v17 & 0x800) == 0 )
      {
        if ( ((v17 >> 5) & 0x1F) != v34 )
          goto LABEL_25;
        v25 = (v17 ^ (32 * v11)) & 0x3E0 ^ v17;
        if ( v9 + 0x40000000 <= 0x3FFFFF )
        {
          v26 = 0;
          __dmb(0xBu);
          *(_DWORD *)v9 = v25;
          if ( (v17 & 2) == 0 && (v25 & 2) != 0 )
            v26 = 1;
          v27 = v9 + 1070596096 > 0xFFF;
LABEL_51:
          if ( !v27 )
          {
            v28 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v28, v28 + 4 * v16, v25);
          }
          if ( v26 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
LABEL_20:
          v10 = v32;
LABEL_21:
          v9 += 4;
          goto LABEL_22;
        }
LABEL_69:
        *(_DWORD *)v9 = v25;
        goto LABEL_20;
      }
      v31 = MiSetProtectionOnTransitionPte(a2, v9, v11, (v11 & 7) == 4);
      if ( !v31 )
        goto LABEL_21;
      if ( v31 != 2 )
        goto LABEL_25;
LABEL_22:
      v8 = v35;
LABEL_23:
      if ( v9 > v10 )
        goto LABEL_24;
    }
    if ( (v11 & 7) != 4 )
      goto LABEL_25;
    if ( (v17 & 0xFFFFE000) != -8192 )
    {
      v29 = 32 * (v11 & 0x1F | 0xFFFFFF20);
      if ( v9 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v9 = v29;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v9 = v29;
        if ( v9 + 1070596096 <= 0xFFF )
        {
          v30 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v30, v30 + 4 * v16, v29);
        }
      }
LABEL_25:
      v8 = -1073741755;
      v10 = v9 - 4;
      v9 = v36;
      v34 = 1;
      v35 = -1073741755;
      v32 = v10;
      v11 = 4;
      goto LABEL_23;
    }
    v25 = (v17 ^ (32 * v11)) & 0x3E0 ^ v17;
    if ( v9 + 0x40000000 <= 0x3FFFFF )
    {
      v26 = 0;
      __dmb(0xBu);
      *(_DWORD *)v9 = v25;
      if ( (v17 & 2) == 0 && (v25 & 2) != 0 )
        v26 = 1;
      v27 = v9 + 1070596096 > 0xFFF;
      goto LABEL_51;
    }
    goto LABEL_69;
  }
LABEL_24:
  MiFlushTbList(&v39);
  MiUnlockWorkingSetExclusive(v12, v37);
  return v8;
}
