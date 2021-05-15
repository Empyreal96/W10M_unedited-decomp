// NtUnlockVirtualMemory 
 
int __fastcall NtUnlockVirtualMemory(int a1, unsigned int *a2, _DWORD *a3)
{
  int v4; // r10
  unsigned int v5; // r6
  unsigned int v6; // r9
  unsigned int v7; // r4
  _DWORD *v8; // r8
  unsigned int *v9; // r5
  int v10; // r0
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r6
  int v14; // r2
  unsigned int v15; // r2
  int v16; // r3
  unsigned int *v17; // r5
  int v18; // r6
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  _DWORD *v23; // r8
  _DWORD *v24; // r2
  _DWORD **v25; // r3
  _DWORD *i; // r3
  unsigned int v27; // r2
  int v28; // r3
  _DWORD *v29; // r8
  unsigned int *v30; // r6
  unsigned int v31; // r5
  unsigned int v32; // r0
  int v33; // r4
  unsigned int v34; // r10
  unsigned int v35; // r4
  unsigned int v36; // r5
  _DWORD *k; // r9
  unsigned int v38; // r6
  unsigned int *v39; // r6
  _DWORD *v40; // r2
  _DWORD **v41; // r3
  _DWORD *j; // r3
  int v43; // r8
  unsigned __int8 *v44; // r3
  unsigned int v45; // r1
  unsigned int v46; // r0
  unsigned int v47; // r1
  unsigned int v48; // r1
  int v50; // [sp+10h] [bp-F8h]
  int v51; // [sp+18h] [bp-F0h]
  _DWORD *v52; // [sp+1Ch] [bp-ECh]
  int v53; // [sp+20h] [bp-E8h]
  unsigned int v54; // [sp+24h] [bp-E4h]
  int v55; // [sp+28h] [bp-E0h]
  unsigned int v56; // [sp+2Ch] [bp-DCh]
  int v57; // [sp+30h] [bp-D8h]
  int v58; // [sp+34h] [bp-D4h]
  int v59; // [sp+38h] [bp-D0h]
  unsigned int v62[34]; // [sp+48h] [bp-C0h] BYREF
  _BYTE v63[56]; // [sp+D0h] [bp-38h] BYREF

  v4 = MiLockUnlockCommon(a1);
  v57 = v4;
  if ( v4 < 0 )
    return v4;
  v5 = 0;
  v55 = 0;
  v51 = 0;
  __mrc(15, 0, 13, 0, 3);
  v6 = (v58 + v59 - 1) & 0xFFFFF000;
  v56 = v6;
  v7 = v58 & 0xFFFFF000;
  if ( a1 != -1 )
  {
    KiStackAttachProcess(v50, 0, (int)v63);
    v51 = 2;
  }
  v54 = 0;
  v62[0] = 0;
  v8 = 0;
  v52 = 0;
  if ( !MiLockVadRange(v50, v7) )
  {
    v33 = v50;
LABEL_109:
    MiUnlockVadRange(v33, v58);
    if ( (v51 & 2) != 0 )
      KiUnstackDetachProcess((unsigned int)v63, 0);
    ObfDereferenceObjectWithTag(v33);
    return -1073741782;
  }
  v9 = (unsigned int *)(v50 + 492);
  v53 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9);
  }
  else
  {
    v10 = 0;
    v11 = (unsigned __int8 *)(v50 + 495);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
      v10 = ExpWaitForSpinLockExclusiveAndAcquire(v9);
    while ( 1 )
    {
      v13 = *v9;
      if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v13 & 0x40000000) == 0 )
      {
        do
          v48 = __ldrex(v9);
        while ( v48 == v13 && __strex(v13 | 0x40000000, v9) );
        __dmb(0xBu);
      }
      ++v10;
      __dmb(0xAu);
      __yield();
    }
    v5 = 0;
  }
  if ( v7 <= v6 )
  {
    while ( 1 )
    {
      if ( (((v7 >> 12) + 1) & 0xF) != 0 || !ExSpinLockIsContended((_DWORD *)(v50 + 492)) )
      {
        if ( !KeShouldYieldProcessor() )
          goto LABEL_35;
        v14 = v50;
      }
      if ( v54 )
      {
        MiFreeWsleList(v14 + 492, v62, 0);
        v54 = 0;
        v62[0] = 0;
        v14 = v50;
      }
      v17 = (unsigned int *)(v14 + 492);
      MiUnlockWorkingSetExclusive(v14 + 492, v53);
      v18 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v17);
      }
      else
      {
        v19 = (unsigned __int8 *)v17 + 3;
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 | 0x80, v19) );
        __dmb(0xBu);
        if ( v20 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v17);
        v15 = 0x80000000;
        while ( 1 )
        {
          v21 = *v17;
          v16 = *v17 & 0xBFFFFFFF;
          if ( v16 == 0x80000000 )
            break;
          if ( (v21 & 0x40000000) == 0 )
          {
            do
              v22 = __ldrex(v17);
            while ( v22 == v21 && __strex(v21 | 0x40000000, v17) );
            __dmb(0xBu);
            v15 = 0x80000000;
          }
          __dmb(0xAu);
          __yield();
        }
        v6 = (v58 + v59 - 1) & 0xFFFFF000;
      }
      v53 = v18;
      v5 = v55;
LABEL_35:
      if ( v7 > v5 || !v8 )
      {
        if ( !v8 )
        {
          v23 = MiLocateAddress(v7);
          goto LABEL_46;
        }
        v24 = v8;
        v25 = (_DWORD **)v8[1];
        if ( v25 )
        {
          v23 = (_DWORD *)v8[1];
          v52 = v25;
          for ( i = *v25; i; i = (_DWORD *)*i )
          {
            v23 = i;
            v52 = i;
          }
        }
        else
        {
          v23 = (_DWORD *)(v8[2] & 0xFFFFFFFC);
          v52 = v23;
          if ( v23 )
          {
            do
            {
              if ( (_DWORD *)*v23 == v24 )
                break;
              v24 = v23;
              v23 = (_DWORD *)(v23[2] & 0xFFFFFFFC);
            }
            while ( v23 );
LABEL_46:
            v52 = v23;
          }
        }
        v27 = v51 & 0xFFFFFFFB;
        v51 &= 0xFFFFFFFB;
        v28 = v23[7] & 7;
        if ( v28 == 6 )
        {
          v15 = v27 | 4;
          v51 = v15;
        }
        else
        {
          v15 = 1;
          if ( ((1 << v28) & 0x15) == 0 )
            goto LABEL_62;
        }
        v16 = v23[4] << 12;
        v55 = v16;
      }
      if ( MiIsAddressValid(v7, 1, v15, v16) )
      {
        v29 = (_DWORD *)(((v7 >> 10) & 0x3FFFFC) - 0x40000000);
        v30 = (unsigned int *)(MmPfnDatabase + 24 * (*v29 >> 12));
        v31 = v30[1];
        if ( (v51 & 4) == 0 || MiRotatedToFrameBuffer(((v7 >> 10) & 0x3FFFFC) - 0x40000000) != 1 )
        {
          if ( (v31 & 0x80000000) == 0 )
            MiDemoteCombinedPte((unsigned int)v29, v31 | 0x80000000);
          v32 = MiLocateWsle(v7, v50 + 492, *v30);
          if ( v32 >= MEMORY[0xC0402004] )
          {
            v62[v54 + 1] = v32;
            v54 = ++v62[0];
            if ( v62[0] == 32 )
            {
              MiFreeWsleList(v50 + 492, v62, 0);
              v54 = 0;
              v62[0] = 0;
            }
            v57 = -1073741782;
          }
        }
      }
      else
      {
        v57 = -1073741782;
      }
      v7 += 4096;
      v8 = v52;
      v5 = v55;
      if ( v7 > v6 )
      {
LABEL_62:
        v4 = v57;
        break;
      }
    }
  }
  if ( v4 == -1073741782 )
  {
    v33 = v50;
    if ( v54 )
      MiFreeWsleList(v50 + 492, v62, 0);
    MiUnlockWorkingSetExclusive(v50 + 492, v53);
    goto LABEL_109;
  }
  v34 = v58 & 0xFFFFF000;
  v35 = v58 & 0xFFFFF000;
  v36 = 0;
  k = 0;
  v38 = (v58 + v59 - 1) & 0xFFFFF000;
  if ( (v58 & 0xFFFFF000) > v56 )
    goto LABEL_100;
  v39 = (unsigned int *)(v50 + 492);
  while ( v35 <= v36 && k )
  {
LABEL_82:
    MiUnlockVa((int)v39, v35);
    v35 += 4096;
    if ( (v35 & 0xF000) == 0 && ExSpinLockIsContended(v39) || KeShouldYieldProcessor() )
    {
      MiUnlockWorkingSetExclusive((int)v39, v53);
      v43 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v39);
      }
      else
      {
        v44 = (unsigned __int8 *)(v50 + 495);
        do
          v45 = __ldrex(v44);
        while ( __strex(v45 | 0x80, v44) );
        __dmb(0xBu);
        if ( v45 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v39);
        while ( 1 )
        {
          v46 = *v39;
          if ( (*v39 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v46 & 0x40000000) == 0 )
          {
            do
              v47 = __ldrex(v39);
            while ( v47 == v46 && __strex(v46 | 0x40000000, v39) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v53 = v43;
    }
    if ( v35 > v56 )
      goto LABEL_99;
  }
  if ( k )
  {
    v40 = k;
    v41 = (_DWORD **)k[1];
    if ( v41 )
    {
      k = (_DWORD *)k[1];
      for ( j = *v41; j; j = (_DWORD *)*j )
        k = j;
    }
    else
    {
      for ( k = (_DWORD *)(k[2] & 0xFFFFFFFC); k; k = (_DWORD *)(k[2] & 0xFFFFFFFC) )
      {
        if ( (_DWORD *)*k == v40 )
          break;
        v40 = k;
      }
    }
  }
  else
  {
    k = MiLocateAddress(v35);
  }
  if ( ((1 << (k[7] & 7)) & 0x15) != 0 )
  {
    v36 = k[4] << 12;
    goto LABEL_82;
  }
LABEL_99:
  v34 = v58 & 0xFFFFF000;
  v38 = (v58 + v59 - 1) & 0xFFFFF000;
LABEL_100:
  MiUnlockWorkingSetExclusive(v50 + 492, v53);
  MiUnlockVadRange(v50, v58);
  if ( (v51 & 2) != 0 )
    KiUnstackDetachProcess((unsigned int)v63, 0);
  ObfDereferenceObjectWithTag(v50);
  *a3 = v38 - v34 + 4096;
  *a2 = v58 & 0xFFFFF000;
  return 0;
}
