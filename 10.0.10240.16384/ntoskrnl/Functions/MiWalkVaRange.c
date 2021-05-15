// MiWalkVaRange 
 
int __fastcall MiWalkVaRange(unsigned int a1, unsigned int a2, _DWORD *a3, int a4, int a5)
{
  unsigned int v5; // r9
  int v6; // r6
  int v7; // r7
  unsigned int v8; // r5
  unsigned int *v9; // r8
  int v10; // lr
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  int v15; // r4
  _DWORD *v16; // lr
  int v17; // r10
  unsigned int v18; // r6
  int v19; // r8
  unsigned int v20; // r4
  _DWORD *v21; // r4
  int v22; // r0
  int v23; // r4
  int v24; // r4
  int v25; // r6
  int v26; // r0
  int v27; // r4
  unsigned __int8 *v28; // r3
  unsigned int v29; // r1
  unsigned int v30; // r2
  unsigned int v31; // r0
  unsigned int v32; // r1
  unsigned int v33; // r1
  int v34; // r0
  unsigned int v35; // r3
  int v36; // r3
  int v37; // r4
  unsigned __int8 *v38; // r3
  unsigned int v39; // r1
  unsigned int v40; // r2
  unsigned int v41; // r0
  unsigned int v42; // r1
  char v43[4]; // [sp+10h] [bp-F8h] BYREF
  int v44; // [sp+14h] [bp-F4h]
  int v45; // [sp+18h] [bp-F0h]
  int v46; // [sp+1Ch] [bp-ECh]
  _DWORD *v47; // [sp+20h] [bp-E8h]
  int v48; // [sp+24h] [bp-E4h]
  unsigned int v49; // [sp+28h] [bp-E0h]
  int v50; // [sp+2Ch] [bp-DCh]
  unsigned int *v51; // [sp+30h] [bp-D8h]
  unsigned int v52; // [sp+34h] [bp-D4h]
  int v53; // [sp+38h] [bp-D0h] BYREF
  unsigned int *v54; // [sp+3Ch] [bp-CCh] BYREF
  int v55; // [sp+40h] [bp-C8h]
  int v56; // [sp+44h] [bp-C4h]
  int v57; // [sp+48h] [bp-C0h] BYREF
  int v58; // [sp+4Ch] [bp-BCh] BYREF
  int v59; // [sp+50h] [bp-B8h] BYREF
  char v60; // [sp+54h] [bp-B4h]
  char v61; // [sp+55h] [bp-B3h]
  int v62; // [sp+58h] [bp-B0h]
  int v63; // [sp+5Ch] [bp-ACh]
  int v64; // [sp+60h] [bp-A8h]
  int v65; // [sp+64h] [bp-A4h]

  v47 = a3;
  v50 = a4;
  v5 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v49 = 0;
  v60 = 0;
  v48 = 17;
  v43[0] = 17;
  v59 = 1;
  v6 = 0;
  v7 = 0;
  v62 = 33;
  v63 = 0;
  v44 = 0;
  v45 = 0;
  v8 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v61 = 0;
  v64 = 0;
  v65 = 0;
  v56 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v9 = (unsigned int *)(v56 + 492);
  v51 = (unsigned int *)(v56 + 492);
  v10 = KfRaiseIrql(2);
  v46 = v10;
  v52 = 0x80000000;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5391A8();
  v12 = (unsigned __int8 *)(v56 + 495);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 | 0x80, v12) );
  __dmb(0xBu);
  if ( v13 >> 7 )
  {
    ExpWaitForSpinLockExclusiveAndAcquire(v9);
    v10 = v46;
  }
  while ( 1 )
  {
    v14 = *v9;
    if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v14 & 0x40000000) == 0 )
    {
      do
        v33 = __ldrex(v9);
      while ( v33 == v14 && __strex(v14 | 0x40000000, v9) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( v8 > v5 )
    goto LABEL_55;
  v55 = 0x7FFFF;
  do
  {
    v15 = MiGetNextPageTable(v8, v5, &v59, v10, 1, &v53);
    v16 = v47;
    v17 = 1;
    if ( v15 != v8 )
    {
      if ( (v47[7] & 0x8000) == 0
        && v47[12]
        && (v34 = MiGetProtoPteAddress(v47, (v8 >> 2) & 0xFFFFF, 1, &v54), v16 = v47, v34) )
      {
        v17 = 0;
      }
      else
      {
        v6 = -1073740748;
        v45 = -1073740748;
        if ( !v15 )
          break;
        v8 = v15;
      }
    }
    if ( v53 == 1 )
    {
      v8 += 4096;
LABEL_53:
      v10 = v46;
      continue;
    }
    while ( 1 )
    {
      v18 = 0;
      v19 = 0;
      if ( v17 && (v20 = *(_DWORD *)v8) != 0 )
      {
        if ( (v20 & 2) != 0 || (v20 & 0x400) == 0 )
        {
          v21 = v47;
          goto LABEL_15;
        }
        v25 = v50;
        if ( v50 == 2 && (v20 & 0xFFFFE000) != -8192 )
        {
          v18 = (*(_DWORD *)v8 & 0x1FC | (*(_DWORD *)v8 >> 2) & 0x3FFFFE00) - 0x40000000;
          if ( v18 >= dword_640484 && v18 < dword_640488 )
            goto LABEL_43;
          v25 = v50;
        }
        if ( v20 >> 13 == v55
          || (v35 = (*(_DWORD *)v8 & 0x1FC | (*(_DWORD *)v8 >> 2) & 0x3FFFFE00) - 0x40000000, v35 < dword_640484)
          || v35 >= dword_640488 )
        {
          if ( v8 == -1071644800 && (*(_DWORD *)(v56 + 736) & 1) == 0 )
          {
            v6 = -1073740748;
            v7 = v44;
            v45 = -1073740748;
            goto LABEL_23;
          }
          if ( (v16[7] & 0x8000) == 0
            && v16[12]
            && ((v26 = MiGetProtoPteAddress(v16, (v8 >> 2) & 0xFFFFF, 1, &v54), v18 = v26, v20 >> 13 == v55)
             || v26 == (v20 & 0x1FC | (v20 >> 2) & 0x3FFFFE00) - 0x40000000) )
          {
            v7 = v44;
          }
          else
          {
            v7 = v44;
            v18 = (v20 & 0x1FC | (v20 >> 2) & 0x3FFFFE00) - 0x40000000;
            if ( v50 != 2 )
            {
              v6 = -1073740748;
              v45 = -1073740748;
              goto LABEL_23;
            }
          }
LABEL_43:
          v21 = v47;
          if ( v18 )
          {
LABEL_44:
            if ( ((v49 ^ v18) & 0xFFFFF000) != 0 )
            {
              if ( v7 )
              {
                MiUnlockProtoPoolPage(v7, v48);
                v49 = 0;
              }
              v7 = MiLockProtoPoolPage(v18, v43);
              v44 = v7;
              if ( !v7 )
              {
                MiFlushTbList(&v59);
                v9 = v51;
                MiUnlockWorkingSetExclusive(v51, v46);
                MmAccessFault(1, v18, 0, 0);
                v37 = KfRaiseIrql(2);
                if ( (dword_682604 & 0x210000) != 0 )
                {
                  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
                }
                else
                {
                  v38 = (unsigned __int8 *)v9 + 3;
                  do
                    v39 = __ldrex(v38);
                  while ( __strex(v39 | 0x80, v38) );
                  __dmb(0xBu);
                  if ( v39 >> 7 )
                    ExpWaitForSpinLockExclusiveAndAcquire(v9);
                  v40 = v52;
                  while ( 1 )
                  {
                    v41 = *v9;
                    if ( (*v9 & 0xBFFFFFFF) == v40 )
                      break;
                    if ( (v41 & 0x40000000) == 0 )
                    {
                      do
                        v42 = __ldrex(v9);
                      while ( v42 == v41 && __strex(v41 | 0x40000000, v9) );
                      __dmb(0xBu);
                      v40 = 0x80000000;
                    }
                    __dmb(0xAu);
                    __yield();
                  }
                  v7 = v44;
                }
                v6 = v45;
                v10 = v37;
                v48 = (unsigned __int8)v43[0];
                v46 = v37;
                goto LABEL_54;
              }
              v48 = (unsigned __int8)v43[0];
              v49 = v18;
            }
            goto LABEL_17;
          }
LABEL_15:
          if ( v7 )
          {
            MiUnlockProtoPoolPage(v7, v48);
            v7 = 0;
            v49 = 0;
            v44 = 0;
          }
LABEL_17:
          v22 = MiActOnPte(v21, v8, v18, v50, a5, &v58, &v57);
          if ( v22 )
          {
            if ( v22 == 274 )
            {
              MiInsertTbFlushEntry(&v59, v8 << 10, 1);
              MiFlushTbList(&v59);
              MiCopyOnWriteEx(v8 << 10, v8, -1, v46, 0);
              v19 = 1;
              v8 -= 4;
            }
            else if ( v22 == -1073741791 )
            {
              MiInsertTbFlushEntry(&v59, v8 << 10, 1);
            }
            else
            {
              v45 = v22;
            }
          }
          v23 = v57;
          if ( v57 )
          {
            if ( v7 )
            {
              MiUnlockProtoPoolPage(v7, v48);
              v7 = 0;
              v49 = 0;
              v44 = 0;
            }
            MiReleasePageFileInfo(v58, v23, 1);
          }
          goto LABEL_22;
        }
        v7 = v44;
        if ( v25 == 1 )
        {
          v6 = -1073740748;
          v45 = -1073740748;
          goto LABEL_23;
        }
        if ( v44 )
        {
          MiUnlockProtoPoolPage(v44, v48);
          v7 = 0;
          v49 = 0;
          v44 = 0;
        }
        MiFlushTbList(&v59);
        if ( MiMakeProtoLeafValid((_DWORD *)v8, 24, v46, v36) != (_DWORD *)v8 )
        {
          v6 = -1073740748;
          v45 = -1073740748;
          goto LABEL_23;
        }
      }
      else
      {
        v21 = v47;
        if ( (v47[7] & 0x8000) != 0 || !v47[12] )
          goto LABEL_15;
        v18 = MiGetProtoPteAddress(v47, (v8 >> 2) & 0xFFFFF, 1, &v54);
        if ( v18 )
          goto LABEL_44;
        if ( v17 )
          goto LABEL_15;
        v19 = 1;
      }
      v8 -= 4;
LABEL_22:
      v6 = v45;
LABEL_23:
      v8 += 4;
      v24 = 0;
      if ( v8 > v5 || v19 == 1 || (v8 & 0xFFF) == 0 )
        v24 = 1;
      if ( (v8 & 0x3C) == 0 && ExSpinLockIsContended(v56 + 492) || KeShouldYieldProcessor() )
        v24 |= 2u;
      if ( v24 )
        break;
      v16 = v47;
    }
    if ( v7 )
    {
      MiUnlockProtoPoolPage(v7, v48);
      v7 = 0;
      v49 = 0;
      v44 = 0;
    }
    if ( (v24 & 2) == 0 )
    {
      v9 = v51;
      goto LABEL_53;
    }
    MiFlushTbList(&v59);
    v9 = v51;
    MiUnlockWorkingSetExclusive(v51, v46);
    v27 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
    }
    else
    {
      v28 = (unsigned __int8 *)v9 + 3;
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 | 0x80, v28) );
      __dmb(0xBu);
      if ( v29 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v9);
      v30 = v52;
      while ( 1 )
      {
        v31 = *v9;
        if ( (*v9 & 0xBFFFFFFF) == v30 )
          break;
        if ( (v31 & 0x40000000) == 0 )
        {
          do
            v32 = __ldrex(v9);
          while ( v32 == v31 && __strex(v31 | 0x40000000, v9) );
          __dmb(0xBu);
          v30 = 0x80000000;
        }
        __dmb(0xAu);
        __yield();
      }
      v6 = v45;
    }
    v10 = v27;
    v46 = v27;
LABEL_54:
    ;
  }
  while ( v8 <= v5 );
LABEL_55:
  MiFlushTbList(&v59);
  MiUnlockWorkingSetExclusive(v9, v46);
  return v6;
}
