// MiFlushTbList 
 
unsigned int __fastcall MiFlushTbList(unsigned int result, int a2)
{
  int v2; // r8
  unsigned int v3; // r6
  int v4; // r9
  unsigned int v5; // r2
  unsigned int v6; // r7
  int v7; // lr
  int v8; // r1
  int v9; // t1
  unsigned int v10; // r3
  int v11; // r2
  int v12; // r4
  unsigned int v13; // r3
  int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r7
  int v17; // r2
  int v18; // t1
  unsigned int v19; // r3
  int v20; // r3
  int v21; // r4
  int v22; // r0
  unsigned int v23; // r3
  int v24; // r1
  unsigned int v25; // r1
  int v26; // r5
  unsigned int v27; // r3
  int v28; // r5
  unsigned int v29; // r5
  int *v30; // r1
  int v31; // r2
  int v32; // t1
  unsigned int v33; // r3
  int v34; // r3
  unsigned int v35; // r3
  int v36; // r0
  unsigned int v37; // r4
  int v38; // r7
  int v39; // r8
  unsigned int v40; // lr
  void **v41; // r2
  int v42; // r1
  int v43; // t1
  int v44; // r4
  int v45; // [sp+Ch] [bp-40h]
  int v46; // [sp+10h] [bp-3Ch]
  unsigned int v47; // [sp+14h] [bp-38h]
  BOOL v48; // [sp+18h] [bp-34h]
  int v49; // [sp+24h] [bp-28h]

  v2 = *(_DWORD *)(result + 12);
  v3 = result;
  v45 = v2;
  v47 = result;
  if ( v2 )
  {
    if ( *(_BYTE *)(result + 5) || *(_DWORD *)(result + 16) > (unsigned int)dword_63382C )
    {
      if ( (*(_BYTE *)(result + 4) & 1) != 0 )
      {
        __dsb(0xFu);
        __mcr(15, 0, 0, 8, 7, 0);
        __dsb(0xFu);
        __isb(0xFu);
        *(_BYTE *)(result + 5) = 0;
      }
      else
      {
        v22 = *(_DWORD *)result;
        if ( *(_DWORD *)v3 == 1 )
          result = KeFlushTb(1, 0);
        else
          result = KeFlushTb(v22, 1);
        *(_BYTE *)(v3 + 5) = 0;
      }
LABEL_24:
      *(_DWORD *)(v3 + 12) = 0;
      *(_DWORD *)(v3 + 16) = 0;
      return result;
    }
    if ( (*(_BYTE *)(result + 4) & 1) != 0 )
    {
      result = KeFlushMultipleRangeCurrentTb(v2, (_DWORD *)(result + 20), *(_DWORD *)result);
      *(_DWORD *)(v3 + 12) = 0;
      *(_DWORD *)(v3 + 16) = 0;
      return result;
    }
    v4 = *(_DWORD *)result;
    v48 = *(_DWORD *)result != 1;
    v5 = result + 20;
    __dsb(0xFu);
    if ( v4 == 1 )
    {
      if ( KiTbDisableSingleByAsidBroadcast )
        return sub_50E448(result, a2, v5);
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v46 = 0;
      }
      else
      {
        v46 = 1;
        __disable_irq();
      }
      v6 = v5 + 4 * v2;
      v7 = (unsigned __int8)__mrc(15, 0, 13, 0, 1);
      result += 20;
      do
      {
        v9 = *(_DWORD *)result;
        result += 4;
        v8 = v9;
        v10 = v9 & 0xFFFFF000 | v7;
        __mcr(15, 0, v10, 8, 3, 1);
        if ( v10 >= 0xC0000000 && v10 <= 0xC03FFFFF )
        {
          v13 = v7 | ((v10 & 0xFFFFF000) << 10);
          v14 = 4;
          do
          {
            __mcr(15, 0, v13, 8, 3, 1);
            v13 += 0x100000;
            --v14;
          }
          while ( v14 );
        }
        v11 = v8 & 0x7FF;
        if ( (v8 & 0x800) != 0 )
          v12 = 0x400000;
        else
          v12 = 4096;
        if ( (v8 & 0x7FF) != 0 )
        {
          do
          {
            v8 += v12;
            v15 = v8 & 0xFFFFF000 | v7;
            __mcr(15, 0, v15, 8, 3, 1);
            if ( v15 >= 0xC0000000 && v15 <= 0xC03FFFFF )
            {
              v27 = v7 | ((v15 & 0xFFFFF000) << 10);
              v28 = 4;
              do
              {
                __mcr(15, 0, v27, 8, 3, 1);
                v27 += 0x100000;
                --v28;
              }
              while ( v28 );
            }
            --v11;
          }
          while ( v11 );
        }
      }
      while ( result < v6 );
      v3 = v47;
      if ( v46 )
        __enable_irq();
    }
    else if ( v4 )
    {
      if ( v4 != 2 )
        goto LABEL_19;
      v29 = v5 + 4 * v2;
      v30 = (int *)(result + 20);
      do
      {
        v32 = *v30++;
        v31 = v32;
        v33 = v32 & 0xFFFFF000;
        __mcr(15, 0, v32 & 0xFFFFF000, 8, 3, 3);
        if ( (v32 & 0xFFFFF000) >= 0xC0000000 && v33 <= 0xC03FFFFF )
        {
          v35 = (v33 & 0xFFFFF000) << 10;
          v36 = 4;
          do
          {
            __mcr(15, 0, v35, 8, 3, 3);
            v35 += 0x100000;
            --v36;
          }
          while ( v36 );
        }
        v34 = v31 & 0x7FF;
        if ( (v31 & 0x800) != 0 )
          result = 0x400000;
        else
          result = 4096;
        if ( (v31 & 0x7FF) != 0 )
        {
          do
          {
            v31 += result;
            __mcr(15, 0, v31 & 0xFFFFF000, 8, 3, 3);
            if ( (v31 & 0xFFFFF000) >= 0xC0000000 && (v31 & 0xFFFFF000) <= 0xC03FFFFF )
            {
              v37 = (v31 & 0xFFFFF000) << 10;
              v38 = 4;
              do
              {
                __mcr(15, 0, v37, 8, 3, 3);
                v37 += 0x100000;
                --v38;
              }
              while ( v38 );
            }
            --v34;
          }
          while ( v34 );
        }
      }
      while ( (unsigned int)v30 < v29 );
    }
    else
    {
      v16 = v5 + 4 * v2;
      result += 20;
      do
      {
        v18 = *(_DWORD *)result;
        result += 4;
        v17 = v18;
        v19 = v18 & 0xFFFFF000;
        __mcr(15, 0, v18 & 0xFFFFF000, 8, 3, 3);
        if ( (v18 & 0xFFFFF000) >= 0xC0000000 && v19 <= 0xC03FFFFF )
        {
          v23 = (v19 & 0xFFFFF000) << 10;
          v24 = 4;
          do
          {
            __mcr(15, 0, v23, 8, 3, 3);
            v23 += 0x100000;
            --v24;
          }
          while ( v24 );
        }
        v20 = v17 & 0x7FF;
        if ( (v17 & 0x800) != 0 )
          v21 = 0x400000;
        else
          v21 = 4096;
        if ( (v17 & 0x7FF) != 0 )
        {
          do
          {
            v17 += v21;
            __mcr(15, 0, v17 & 0xFFFFF000, 8, 3, 3);
            if ( (v17 & 0xFFFFF000) >= 0xC0000000 && (v17 & 0xFFFFF000) <= 0xC03FFFFF )
            {
              v25 = (v17 & 0xFFFFF000) << 10;
              v26 = 4;
              do
              {
                __mcr(15, 0, v25, 8, 3, 3);
                v25 += 0x100000;
                --v26;
              }
              while ( v26 );
            }
            --v20;
          }
          while ( v20 );
        }
      }
      while ( result < v16 );
      v3 = v47;
    }
    v5 = v3 + 20;
LABEL_19:
    __dsb(0xFu);
    __isb(0xFu);
    if ( KiTbSendIpiForBroadcastFlushes )
    {
      __mcr(15, 0, 0, 8, 3, 1);
      __dsb(0xFu);
      v39 = KfRaiseIrql(12);
      v40 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      if ( v48 )
        v49 = dword_681D78[0];
      else
        v49 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v40 + 1412) + 116) + 96);
      v41 = &KeNodeBlock;
      if ( !KeNodeBlock )
        goto LABEL_93;
      v42 = (unsigned __int16)KeNumberNodes;
      result = 0;
      if ( KeNumberNodes )
      {
        do
        {
          v43 = (int)*v41++;
          result |= *(_DWORD *)(v43 + 128);
          --v42;
        }
        while ( v42 );
      }
      if ( (v49 & ~result) != 0 )
      {
LABEL_93:
        KiIpiSendRequestEx(v40 + 1408);
        result = KfLowerIrql(v39);
      }
      v2 = v45;
      v5 = v3 + 20;
    }
    if ( VmTbFlushEnabled )
      result = VmFlushTb(v2, v5);
    if ( ExTbFlushActive )
    {
      v44 = KfRaiseIrql(15);
      ExFlushTb(v2, v3 + 20, v4);
      result = KfLowerIrql(v44);
    }
    goto LABEL_24;
  }
  return result;
}
