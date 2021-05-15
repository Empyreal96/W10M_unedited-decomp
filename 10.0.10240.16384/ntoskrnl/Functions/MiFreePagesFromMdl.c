// MiFreePagesFromMdl 
 
int __fastcall MiFreePagesFromMdl(__int16 *a1, int a2, int a3)
{
  __int16 *v4; // r9
  int result; // r0
  int v6; // r6
  unsigned int *v7; // r7
  unsigned int v8; // r10
  int v9; // r4
  int v10; // r8
  int v11; // r9
  unsigned int v12; // r2
  unsigned int v13; // r0
  int v14; // r3
  int v15; // r0
  unsigned int v16; // r0
  int v17; // lr
  unsigned __int8 *v18; // r3
  unsigned int v19; // r1
  unsigned __int8 *v20; // r1
  int v21; // r3
  unsigned int v22; // r2
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r8
  unsigned int *v26; // lr
  int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r0
  unsigned int v30; // r3
  int v31; // r2
  unsigned int v32; // r0
  unsigned int *v33; // r8
  int v34; // t1
  unsigned int *v35; // r7
  int v36; // t1
  unsigned int *v37; // r2
  unsigned int v38; // r4
  int v39; // [sp+8h] [bp-30h]
  __int16 *v41; // [sp+10h] [bp-28h]
  unsigned int v42; // [sp+14h] [bp-24h]

  v41 = a1;
  v4 = a1;
  if ( (*(_WORD *)(a2 + 6) & 0x200) != 0 )
    return sub_514934();
  if ( (*(_WORD *)(a2 + 6) & 1) != 0 )
    MmUnmapLockedPages(*(_DWORD *)(a2 + 12), a2);
  if ( (*(_WORD *)(a2 + 6) & 0x801) != 0 )
    KeBugCheckEx(26, 4664, a2);
  v6 = 0;
  v7 = (unsigned int *)(a2 + 28);
  v8 = (*(_DWORD *)(a2 + 20)
      + (((unsigned __int16)*(_DWORD *)(a2 + 24) + (unsigned __int16)*(_DWORD *)(a2 + 16)) & 0xFFFu)
      + 4095) >> 12;
  v42 = v8;
  if ( (dword_682604 & 1) != 0 )
    MiLogMdlRangeEvent(a2 + 28, 633, v8);
  v9 = 0;
  result = 1;
  v39 = 1;
  v10 = -1;
  if ( v8 )
  {
    while ( 1 )
    {
      v11 = MmPfnDatabase + 24 * *v7;
      if ( (*(_DWORD *)(v11 + 20) & 0xFFFFF) != 1048573 )
        KeBugCheckEx(26, 4662, a2);
      if ( (*(_DWORD *)(v11 + 20) & 0x7000000) == 50331648 )
      {
        v17 = KfRaiseIrql(2);
        v18 = (unsigned __int8 *)(v11 + 15);
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 | 0x80, v18) );
        __dmb(0xBu);
        if ( v19 >> 7 )
        {
          v20 = (unsigned __int8 *)(v11 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v21 = *(_DWORD *)(v11 + 12);
              __dmb(0xBu);
            }
            while ( v21 < 0 );
            do
              v22 = __ldrex(v20);
            while ( __strex(v22 | 0x80, v20) );
            __dmb(0xBu);
          }
          while ( v22 >> 7 );
        }
        *(_DWORD *)(v11 + 20) &= 0xF8FFFFFF;
        __dmb(0xBu);
        v23 = (unsigned int *)(v11 + 12);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 & 0x7FFFFFFF, v23) );
        KfLowerIrql(v17);
        result = v39;
      }
      v12 = *v7;
      if ( *v7 != v10 )
      {
        if ( v9 )
        {
          v33 = &v7[-v9];
          do
          {
            v34 = *v33++;
            v6 += MiFreeSmallPageFromMdl(v34, a3);
            --v9;
          }
          while ( v9 );
        }
        v13 = *v7;
        v14 = *v7 & 0x3FF;
        if ( v8 >= __PAIR64__(v14, 1024) )
        {
          v10 = v13 + 1;
          result = 1;
LABEL_65:
          v39 = result;
          v9 = 1;
          goto LABEL_17;
        }
        if ( v14 == 1023 && v8 >= 0x400 )
        {
          v10 = v13 - 1;
          result = 0;
          goto LABEL_65;
        }
        v15 = MiFreeSmallPageFromMdl(v13, a3);
        goto LABEL_16;
      }
      if ( result == 1 )
      {
        if ( (*v7 & 0x3FF) != 1023 )
        {
          v10 = v12 + 1;
LABEL_42:
          ++v9;
          goto LABEL_17;
        }
      }
      else if ( (v12 & 0x3FF) != 0 )
      {
        v10 = v12 - 1;
        goto LABEL_42;
      }
      v25 = v12 >> 10;
      if ( ((*(char *)((v12 >> 13) + dword_634C94) >> ((v12 >> 10) & 7)) & 1) != 0 )
      {
        v26 = (unsigned int *)(dword_634C94 + 4 * (v12 >> 15));
        v27 = (v12 >> 10) & 0x1F;
        LOBYTE(v12) = 1;
        if ( (unsigned int)(v27 + 1) > 0x20 )
        {
          if ( (v25 & 0x1F) != 0 )
          {
            __dmb(0xBu);
            do
              v29 = __ldrex(v26);
            while ( __strex(v29 & ~(((1 << (32 - v27)) - 1) << v27), v26) );
            __dmb(0xBu);
            v12 = v27 - 31;
            ++v26;
            if ( (unsigned int)(v27 - 31) >= 0x20 )
            {
              v30 = v12 >> 5;
              do
              {
                v12 -= 32;
                --v30;
                *v26++ = 0;
              }
              while ( v30 );
            }
            if ( !v12 )
              goto LABEL_59;
          }
          __dmb(0xBu);
          v31 = ~((1 << v12) - 1);
          do
            v32 = __ldrex(v26);
          while ( __strex(v32 & v31, v26) );
        }
        else
        {
          __dmb(0xBu);
          do
            v28 = __ldrex(v26);
          while ( __strex(v28 & ~(1 << v27), v26) );
        }
        __dmb(0xBu);
      }
LABEL_59:
      v15 = MiFreeLargePageMemory(v25 << 10);
LABEL_16:
      v6 += v15;
      result = v39;
      v9 = 0;
      v10 = -1;
LABEL_17:
      --v8;
      ++v7;
      if ( !v8 )
      {
        if ( v9 )
        {
          v35 = &v7[-v9];
          do
          {
            v36 = *v35++;
            result = MiFreeSmallPageFromMdl(v36, a3);
            v6 += result;
            --v9;
          }
          while ( v9 );
        }
        v4 = v41;
        if ( v6 )
        {
          if ( v41 == MiSystemPartition )
          {
            MiReturnResidentAvailable(v6);
            do
              v16 = __ldrex(&dword_634A2C[28]);
            while ( __strex(v16 + v6, &dword_634A2C[28]) );
          }
          else
          {
            v37 = (unsigned int *)(v41 + 1920);
            do
              v38 = __ldrex(v37);
            while ( __strex(v38 + v6, v37) );
          }
          result = MiReturnCommit(v41, v6);
        }
        break;
      }
    }
  }
  if ( v4 == MiSystemPartition )
  {
    do
      result = __ldrex((unsigned int *)&dword_634D94);
    while ( __strex(result - v42, (unsigned int *)&dword_634D94) );
  }
  *(_WORD *)(a2 + 6) &= 0xFFFDu;
  return result;
}
