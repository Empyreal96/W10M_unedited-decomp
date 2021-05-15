// MiOutSwapWorkingSetCallback 
 
unsigned int __fastcall MiOutSwapWorkingSetCallback(unsigned int result, unsigned int a2, unsigned int a3)
{
  int v3; // r4
  unsigned int v4; // r10
  int v5; // r8
  unsigned int v6; // r7
  unsigned int v7; // r3
  unsigned int v8; // r6
  int v9; // r4
  char v10; // r9
  unsigned int v11; // r5
  int v12; // r2
  unsigned int v13; // r2
  unsigned int v14; // r3
  int v15; // r5
  int v16; // r0
  _DWORD *v17; // r5
  unsigned int v18; // r6
  unsigned int *v19; // r3
  unsigned int *v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r4
  unsigned __int8 *v23; // r3
  unsigned int v24; // r1
  unsigned __int8 *v25; // r1
  int v26; // r3
  unsigned int v27; // r2
  int v28; // r3
  unsigned int v29; // r0
  unsigned int v30; // r3
  unsigned int v31; // r3
  int *v32; // r5
  int v33; // r2
  int v34; // r3
  int v35; // r6
  int v36; // r0
  unsigned int *v37; // r2
  unsigned int v38; // r2
  unsigned int *v39; // r6
  int v40; // r3
  unsigned __int8 *v41; // r3
  unsigned int v42; // r1
  unsigned int v43; // r1
  unsigned int v44; // [sp+8h] [bp-38h]
  int v45; // [sp+Ch] [bp-34h] BYREF
  unsigned int v46; // [sp+10h] [bp-30h]
  unsigned int v47; // [sp+14h] [bp-2Ch]
  int v48; // [sp+18h] [bp-28h]
  unsigned int v49; // [sp+1Ch] [bp-24h]

  v3 = 0x40000000;
  v4 = a2;
  v5 = *(_DWORD *)(result + 8);
  v48 = 0x40000000;
  v49 = a3;
  v6 = result;
  if ( a2 <= a3 )
  {
    v7 = 1;
    v46 = 0x3FFFFF;
    do
    {
      v8 = 0;
      result = 0;
      v9 = 0;
      v10 = 0;
      v44 = 0;
      v47 = 0;
      while ( 1 )
      {
        v11 = *(_DWORD *)v4;
        v45 = v11;
        if ( (v11 & 2) != 0 )
          break;
        if ( (v11 & 0x400) != 0 )
          goto LABEL_37;
        if ( (v11 & 0x800) == 0 )
        {
          if ( (v11 & 8) != 0 )
          {
            result = v46;
            v13 = v11 & 0xFFFFFFF7;
            v7 = v4 + 0x40000000;
            v8 = v11;
            if ( v4 + 0x40000000 > v46 )
            {
              *(_DWORD *)v4 = v13;
            }
            else
            {
              v14 = *(_DWORD *)v4;
              v15 = 0;
              __dmb(0xBu);
              result = 2;
              *(_DWORD *)v4 = v13;
              if ( (v14 & 2) == 0 && (v13 & 2) != 0 )
                v15 = 1;
              v7 = 4095;
              if ( v4 + 1070596096 <= 0xFFF )
              {
                v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                result = MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * (v4 & 0xFFF)), v13);
              }
              if ( v15 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
            }
          }
          goto LABEL_37;
        }
        result = MiLockTransitionLeafPage((unsigned int *)v4, 0);
        v9 = result;
        if ( result )
        {
          v10 = 1;
          if ( (*(_BYTE *)(result + 18) & 8) == 0 && (*(_BYTE *)(result + 18) & 0x20) == 0 )
          {
            v7 = *(_DWORD *)(result + 8);
            if ( (v7 & 8) != 0 )
            {
              v8 = *(_DWORD *)(result + 8);
              if ( *(_WORD *)(result + 16) || (*(_BYTE *)(result + 18) & 7) != 3 )
              {
                v7 = *(_DWORD *)(result + 8) & 0xFFFFFFF7;
                *(_DWORD *)(result + 8) = v7;
              }
              else
              {
                MiUnlinkPageFromList(result, 0);
                *(_DWORD *)(v9 + 8) &= 0xFFFFFFF7;
                result = MiInsertPageInList(v9, 8, v12);
              }
            }
          }
          goto LABEL_37;
        }
      }
      result = MI_IS_PFN(v11 >> 12);
      if ( !result )
        goto LABEL_36;
      v9 = MmPfnDatabase + 24 * (v11 >> 12);
      v7 = *(_DWORD *)(v9 + 20);
      if ( (v7 & 0x8000000) != 0 )
      {
        v17 = *(_DWORD **)(v6 + 4);
        if ( !v17 )
          goto LABEL_36;
      }
      else
      {
        result = 0x80000000;
        v7 = *(_DWORD *)(v9 + 4) | 0x80000000;
        if ( v7 != v4 )
          goto LABEL_36;
        v10 = 1;
        v23 = (unsigned __int8 *)(v9 + 15);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 | 0x80, v23) );
        __dmb(0xBu);
        if ( v24 >> 7 )
        {
          v25 = (unsigned __int8 *)(v9 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v26 = *(_DWORD *)(v9 + 12);
              __dmb(0xBu);
            }
            while ( (v26 & 0x80000000) != 0 );
            do
              v27 = __ldrex(v25);
            while ( __strex(v27 | 0x80, v25) );
            __dmb(0xBu);
          }
          while ( v27 >> 7 );
        }
        v7 = *(unsigned __int8 *)(v9 + 18);
        if ( (v7 & 8) != 0 )
          goto LABEL_36;
        v28 = *(_DWORD *)(v9 + 8);
        if ( (v28 & 8) != 0 )
        {
          v8 = *(_DWORD *)(v9 + 8);
          *(_DWORD *)(v9 + 8) = v28 & 0xFFFFFFF7;
          v44 = v8;
        }
        else
        {
          v8 = 0;
        }
        if ( (*(_BYTE *)(v5 + 112) & 7) == 0 )
        {
          v7 = *(_DWORD *)(*(_DWORD *)(v5 + 92) + 4);
          if ( *(_DWORD *)v9 < v7 )
            goto LABEL_37;
        }
        v7 = *(unsigned __int16 *)(v9 + 16);
        if ( v7 != 1 )
          goto LABEL_37;
        if ( (v11 & 0x200) != 0 && (*(_BYTE *)(v9 + 18) & 0x10) == 0 )
        {
          v7 = *(_DWORD *)(v9 + 8);
          if ( (v7 & 0x10) == 0 )
            goto LABEL_37;
          v10 = 3;
        }
        v29 = MiCaptureDirtyBitToPfn(v9);
        v30 = *(unsigned __int8 *)(v9 + 18);
        v47 = v29;
        v31 = v30 >> 6;
        if ( v31 != 1 )
        {
          if ( v31 == 2 )
          {
            v10 |= 4u;
          }
          else if ( !v31 )
          {
            v10 |= 8u;
          }
        }
        if ( *(_DWORD *)(v6 + 56) == -1 )
        {
          v32 = (int *)(v9 + 8);
          MI_SET_PAGING_FILE_INFO(
            &v45,
            (_DWORD *)(v9 + 8),
            *(_DWORD *)&MiSystemPartition[2 * dword_63F99C + 1800],
            0x7FFFF,
            0);
          v33 = v45;
          if ( v48 + v9 + 8 > v46 )
          {
            *v32 = v45;
          }
          else
          {
            v34 = *v32;
            v35 = 0;
            __dmb(0xBu);
            *v32 = v33;
            if ( (v34 & 2) == 0 && (v33 & 2) != 0 )
              v35 = 1;
            if ( (unsigned int)(v9 + 1070596104) <= 0xFFF )
            {
              v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v36, (_DWORD *)(v36 + 4 * ((unsigned __int16)v32 & 0xFFF)), v33);
            }
            if ( v35 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
        __dmb(0xBu);
        v37 = (unsigned int *)(v9 + 12);
        do
          result = __ldrex(v37);
        while ( __strex(result & 0x7FFFFFFF, v37) );
        v38 = *(_DWORD *)(v6 + 56);
        v17 = *(_DWORD **)v6;
        v10 &= 0xFEu;
        if ( v38 != -1 )
        {
          v7 = v38 + 2;
          v39 = (unsigned int *)(v6 + 8 * (v38 + 2));
          if ( v38 >= 5 )
            goto LABEL_36;
          v7 = v39[1];
          if ( !v7 )
            goto LABEL_36;
          MiReservePageFileSpaceForPage(MiSystemPartition, v4, 128, v39);
          *v39 = ((*v39 & 0xFFFFE000) + 0x2000) ^ *v39 & 0x1FFF;
          v40 = v39[1] - 1;
          v39[1] = v40;
          if ( !v40 )
            ++*(_DWORD *)(v6 + 56);
          v10 |= 0x10u;
        }
      }
      result = v17[2];
      v7 = v17[1];
      if ( result >= v7 )
      {
        v8 = v44;
        goto LABEL_37;
      }
      v18 = v4 << 10;
      v19 = (unsigned int *)(*v17 + 8 * result);
      v20 = v19 - 2;
      if ( !result || *(v19 - 2) + *(v19 - 1) != v18 )
      {
        v17[2] = result + 1;
        v20 = v19;
        *v19 = v18;
        v19[1] = 0;
      }
      v20[1] += 4096;
      v7 = v17[3] + 1;
      v17[3] = v7;
      if ( (v10 & 2) != 0 )
      {
        v7 = *(_DWORD *)(v6 + 68) + 1;
        *(_DWORD *)(v6 + 68) = v7;
      }
      if ( (v10 & 4) != 0 )
      {
        v7 = *(_DWORD *)(v6 + 60) + 1;
        *(_DWORD *)(v6 + 60) = v7;
LABEL_36:
        v8 = v44;
        goto LABEL_37;
      }
      v8 = v44;
      if ( (v10 & 8) != 0 )
      {
        v7 = *(_DWORD *)(v6 + 64) + 1;
        *(_DWORD *)(v6 + 64) = v7;
      }
LABEL_37:
      if ( (v10 & 1) != 0 )
      {
        __dmb(0xBu);
        v21 = (unsigned int *)(v9 + 12);
        do
        {
          v22 = __ldrex(v21);
          result = v22 & 0x7FFFFFFF;
          v7 = __strex(v22 & 0x7FFFFFFF, v21);
        }
        while ( v7 );
      }
      if ( v8 )
      {
        if ( (v8 & 0x10) != 0 )
          v8 &= 0xFFFFFFEF;
        result = MiReleasePageFileInfo((int)MiSystemPartition, v8, 0, v7);
      }
      if ( v47 )
        result = MiReleasePageFileInfo((int)MiSystemPartition, v47, 0, v47);
      v7 = v49;
      v4 += 4;
    }
    while ( v4 <= v49 );
    v3 = v48;
  }
  if ( *(_BYTE *)(v6 + 12) != 17 && (ExSpinLockIsContended((_DWORD *)v5) || (result = KeShouldYieldProcessor()) != 0) )
  {
    MiUnlockWorkingSetExclusive(v5, *(unsigned __int8 *)(v6 + 12));
    KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)v5);
    }
    else
    {
      v41 = (unsigned __int8 *)(v5 + 3);
      do
        v42 = __ldrex(v41);
      while ( __strex(v42 | 0x80, v41) );
      __dmb(0xBu);
      if ( v42 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v5);
      while ( 1 )
      {
        result = *(_DWORD *)v5;
        if ( (*(_DWORD *)v5 & ~v3) == 0x80000000 )
          break;
        if ( (result & v3) == 0 )
        {
          do
            v43 = __ldrex((unsigned int *)v5);
          while ( v43 == result && __strex(result | v3, (unsigned int *)v5) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  return result;
}
