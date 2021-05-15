// MiValidFault 
 
int __fastcall MiValidFault(int a1, unsigned int a2, int *a3, int a4, unsigned __int8 a5, char a6)
{
  unsigned int v6; // lr
  unsigned int v7; // r6
  int v10; // r10
  int v12; // r2
  int v13; // r7
  int v14; // r2
  unsigned int v15; // r7
  int v16; // r5
  int v17; // r1
  int v18; // r0
  unsigned int v19; // r2
  int v20; // r4
  unsigned int v21; // r5
  int v22; // r1
  int v23; // r3
  __int16 *v24; // lr
  unsigned __int8 *v25; // r0
  unsigned int v26; // r2
  unsigned int v27; // r0
  int v28; // r3
  int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r5
  int v32; // r0
  int v33; // r3
  unsigned int v34; // r2
  int v35; // r0
  unsigned int v36; // r3
  int v37; // r1
  unsigned int v38; // r3
  int v39; // r0
  int v40; // r8
  unsigned int v41; // lr
  int v42; // r2
  int v43; // r3
  void **v44; // r4
  int v45; // r2
  int v46; // r1
  int v47; // t1
  int v48; // r2
  int v49; // r4
  unsigned int v51; // [sp+1Ch] [bp-34h] BYREF
  int v52; // [sp+20h] [bp-30h]
  int v53; // [sp+24h] [bp-2Ch]
  int v54; // [sp+28h] [bp-28h]

  v6 = a2;
  v7 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( (a4 & 1) != 0 )
    return sub_534A04();
  v12 = *a3;
  if ( (*a3 & 0x400) != 0 )
  {
    if ( (a4 & 1) != 0 )
    {
      if ( *(_BYTE *)(a4 & 0xFFFFFFFE) == 1 || *(_BYTE *)(a4 & 0xFFFFFFFE) == 3 )
        return -1073741819;
    }
    else
    {
      if ( KeInvalidAccessAllowed(a4) == 1 )
        return -1073741819;
      v6 = a2;
    }
    KeBugCheckEx(80, v6, a1);
  }
  if ( (v12 & 0x20) == 0 && a2 <= MmHighestUserAddress )
    return -1073741819;
  v13 = a1 & 1;
  if ( (a1 & 1) == 0 )
  {
    if ( (a1 & 8) == 0 )
      goto LABEL_7;
    if ( (v12 & 1) == 0 )
    {
      if ( !a6 )
      {
        MI_CHECK_KERNEL_NOEXECUTE_FAULT(a1, a2, a4, *a3);
        v6 = a2;
      }
      goto LABEL_7;
    }
    return -1073741819;
  }
  if ( (v12 & 0x100) != 0 )
  {
    if ( MiCopyOnWriteEx(a2, v7, -1, a5, 0) )
      v20 = 274;
    else
      v20 = -1073740748;
    return v20;
  }
  if ( (v12 & 0x80) == 0 )
    return -1073741819;
LABEL_7:
  if ( *(_DWORD *)(v10 + 328) )
  {
    v32 = MiLocateAddress(v6);
    if ( v32 && (*(_DWORD *)(v32 + 28) & 7) == 3 )
      return 0;
    v6 = a2;
  }
  if ( v13 )
  {
    v21 = (unsigned int)*a3 >> 12;
    if ( MI_IS_PFN(v21) )
    {
      v22 = MmPfnDatabase + 24 * v21;
      v23 = *(_DWORD *)(v22 + 8);
      if ( (v23 & 0x400) == 0 && (v23 & 0x10) != 0 )
      {
        v24 = 0;
        v25 = (unsigned __int8 *)(v22 + 15);
        do
          v26 = __ldrex(v25);
        while ( __strex(v26 | 0x80, v25) );
        __dmb(0xBu);
        if ( v26 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v33 = *(_DWORD *)(v22 + 12);
              __dmb(0xBu);
            }
            while ( v33 < 0 );
            do
              v34 = __ldrex(v25);
            while ( __strex(v34 | 0x80, v25) );
            __dmb(0xBu);
          }
          while ( v34 >> 7 );
        }
        v27 = 0;
        if ( (*(_BYTE *)(v22 + 18) & 0x10) == 0 )
        {
          v28 = *(_DWORD *)(v22 + 8);
          if ( (v28 & 0x400) == 0 && (*(_BYTE *)(v22 + 18) & 8) == 0 )
          {
            v29 = *(_DWORD *)(v22 + 8);
            if ( (v28 & 0x10) != 0 )
            {
              *(_DWORD *)(v22 + 8) = v28 & 0xFFFFFFEF;
              v27 = v29 & 0xFFFFFFF7;
            }
            else
            {
              v27 = 0;
            }
          }
          *(_BYTE *)(v22 + 18) |= 0x10u;
          if ( v27 )
            v24 = MiSystemPartition;
        }
        __dmb(0xBu);
        v30 = (unsigned int *)(v22 + 12);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 & 0x7FFFFFFF, v30) );
        if ( v27 )
          MiReleasePageFileInfo(v24, v27, 1);
      }
    }
    v6 = a2;
  }
  v14 = *(_DWORD *)v7;
  if ( v13 && (v14 & 0x200) != 0 )
  {
    v15 = v14 & 0xFFFFFDFF | 0x10;
  }
  else
  {
    if ( (v14 & 0x10) != 0 )
      goto LABEL_17;
    v15 = v14 | 0x10;
  }
  if ( v7 + 0x40000000 > 0x3FFFFF )
  {
    *(_DWORD *)v7 = v15;
  }
  else
  {
    v16 = 0;
    __dmb(0xBu);
    *(_DWORD *)v7 = v15;
    if ( (v14 & 2) == 0 && (v15 & 2) != 0 )
      v16 = 1;
    if ( v7 >= 0xC0300000 && v7 <= 0xC0300FFF )
    {
      v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v35, v35 + 4 * (v7 & 0xFFF), v15);
      v6 = a2;
    }
    if ( v16 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
LABEL_17:
  if ( (MiFlags & 0x300) == 0 )
  {
    __dsb(0xFu);
    if ( KiTbDisableSingleByAsidBroadcast )
    {
      __mcr(15, 0, v6 & 0xFFFFF000, 8, 3, 3);
      if ( (v6 & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
      {
        v36 = (v6 & 0xFFFFF000) << 10;
        v37 = 4;
        do
        {
          __mcr(15, 0, v36, 8, 3, 3);
          v36 += 0x100000;
          --v37;
        }
        while ( v37 );
      }
    }
    else
    {
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v17 = 0;
      }
      else
      {
        __disable_irq();
        v17 = 1;
      }
      v18 = (unsigned __int8)__mrc(15, 0, 13, 0, 1);
      v19 = v6 & 0xFFFFF000 | v18;
      __mcr(15, 0, v19, 8, 3, 1);
      if ( v19 >= 0xC0000000 && v19 <= 0xC03FFFFF )
      {
        v38 = v18 | ((v19 & 0xFFFFF000) << 10);
        v39 = 4;
        do
        {
          __mcr(15, 0, v38, 8, 3, 1);
          v38 += 0x100000;
          --v39;
        }
        while ( v39 );
      }
      if ( v17 )
        __enable_irq();
    }
    __dsb(0xFu);
    __isb(0xFu);
    if ( !KiTbSendIpiForBroadcastFlushes )
      goto LABEL_25;
    __mcr(15, 0, 0, 8, 3, 1);
    __dsb(0xFu);
    v40 = KfRaiseIrql(12);
    v41 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v42 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v41 + 1412) + 116) + 92);
    v43 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v41 + 1412) + 116) + 96);
    v52 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v41 + 1412) + 116) + 88);
    v53 = v42;
    v54 = v43;
    v44 = &KeNodeBlock;
    if ( KeNodeBlock )
    {
      v45 = (unsigned __int16)KeNumberNodes;
      v46 = 0;
      if ( KeNumberNodes )
      {
        do
        {
          v47 = (int)*v44++;
          v46 |= *(_DWORD *)(v47 + 128);
          --v45;
        }
        while ( v45 );
      }
      v48 = v54 & ~v46;
      v52 = 65537;
      v53 = 0;
      if ( !v48 )
        goto LABEL_99;
    }
    else
    {
      v48 = v54;
    }
    v54 = v48 & ~(1 << *(_DWORD *)(v41 + 1428));
    KiIpiSendRequestEx(v41 + 1408);
    KfLowerIrql(v40);
LABEL_99:
    v6 = a2;
LABEL_25:
    if ( VmTbFlushEnabled )
    {
      v51 = v6 & 0xFFFFF000 | 1;
      VmFlushTb(1, &v51);
      v6 = a2;
    }
    if ( ExTbFlushActive )
    {
      v51 = v6 & 0xFFFFF000 | 1;
      v49 = KfRaiseIrql(15);
      ExFlushTb(1, &v51, 0);
      KfLowerIrql(v49);
    }
  }
  return 0;
}
