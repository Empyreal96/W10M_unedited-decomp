// MiReturnNonPagedPoolVa 
 
int __fastcall MiReturnNonPagedPoolVa(unsigned int a1, unsigned int a2)
{
  int v3; // r5
  int v4; // r2
  int v5; // r10
  unsigned int v6; // r7
  unsigned int v7; // r9
  int v8; // r3
  unsigned int v9; // r6
  unsigned int v10; // r8
  int v11; // r5
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r5
  unsigned int v15; // r9
  unsigned int v16; // r8
  int v17; // r2
  int v18; // t1
  int v19; // r2
  int result; // r0
  unsigned int v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r7
  _DWORD *v24; // r3
  _DWORD *v25; // r2
  __int16 i; // r3
  int v28; // t1
  unsigned int v29; // r1
  int v30; // r4
  int v31; // r2
  int v32; // r3
  _DWORD *v33; // r2
  int v34; // r5
  int v35; // r0
  int v36; // lr
  unsigned int *v37; // r7
  unsigned __int8 *v38; // r1
  unsigned int v39; // r2
  int v40; // r3
  unsigned int v41; // r1
  _DWORD *v42; // r3
  int v43; // r0
  _DWORD *v44; // r4
  int v45; // r0
  _DWORD *v46; // r8
  int v47; // r2
  unsigned int v48; // r7
  unsigned int *v49; // r6
  unsigned int v50; // r1
  unsigned int v51; // r0
  unsigned int v52; // r0
  unsigned int v53; // r3
  int v54; // r2
  unsigned int v55; // r0
  unsigned int v56; // [sp+4h] [bp-100h]
  unsigned int v57; // [sp+8h] [bp-FCh]
  _DWORD *v58; // [sp+Ch] [bp-F8h]
  unsigned int v59; // [sp+10h] [bp-F4h]
  int v60; // [sp+14h] [bp-F0h]
  int v61; // [sp+18h] [bp-ECh]
  unsigned int v62; // [sp+1Ch] [bp-E8h]
  unsigned int v63; // [sp+20h] [bp-E4h]
  int v64[3]; // [sp+24h] [bp-E0h] BYREF
  int v65; // [sp+30h] [bp-D4h]
  int v66; // [sp+34h] [bp-D0h]
  unsigned int v67; // [sp+38h] [bp-CCh]
  char v68[16]; // [sp+3Ch] [bp-C8h] BYREF
  int v69; // [sp+4Ch] [bp-B8h] BYREF
  char v70; // [sp+50h] [bp-B4h]
  char v71; // [sp+51h] [bp-B3h]
  int v72; // [sp+54h] [bp-B0h]
  int v73; // [sp+58h] [bp-ACh]
  int v74; // [sp+5Ch] [bp-A8h]
  int v75; // [sp+60h] [bp-A4h]

  v64[0] = 0;
  v64[1] = 0;
  v64[2] = 0;
  v65 = 0;
  v3 = (a1 >> 20) & 0xFFC;
  v4 = *((unsigned __int8 *)&MiState[29] + ((int)(v3 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  if ( v4 == 255 )
    sub_54BED0();
  v5 = dword_6337E8 + 176 * v4;
  v6 = (a1 - *(_DWORD *)(v5 + 136)) >> 12;
  v7 = v6 + a2;
  v59 = v6 & 0xFFFFFC00;
  v62 = v6;
  v63 = (v6 + a2 + 1023) & 0xFFFFFC00;
  v8 = *(_DWORD *)(v5 + 164);
  v67 = v6 + a2;
  v9 = v8 + 4 * (v63 >> 5);
  v58 = 0;
  v73 = 0;
  v74 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v72 = 33;
  v75 = 0;
  v10 = 0;
  v56 = 0;
  v57 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v5 + 128), (unsigned int)v68);
  RtlClearBits((_BYTE *)(v5 + 160), v6, a2);
  if ( (*(_DWORD *)(v3 - 1070596096) & 0x400) != 0 )
  {
    v21 = (v6 + 1023) & 0xFFFFFC00;
    v22 = a2;
    if ( (v7 & 0xFFFFFC00) > v21 )
      v22 = v21 - (v7 & 0xFFFFFC00) + a2;
    *(_DWORD *)(v5 + 120) -= v22;
    v11 = 0;
  }
  else
  {
    v11 = 1;
  }
  *(_DWORD *)(v5 + 112) -= a2;
  MiCountNonPagedPool(a2, 0);
  v12 = (v6 + a2 + 1023) & 0xFFFFFC00;
  v13 = v6 & 0xFFFFFC00;
  v66 = v11 + 42;
  v60 = v5 + 8 * (v11 + 18);
  v14 = -1;
  v15 = v9 & 0xFFFFF000;
  if ( v63 > v59 )
  {
    v16 = v63 - 1024;
    do
    {
      v17 = 0;
      while ( 1 )
      {
        v18 = *(_DWORD *)(v9 - 4);
        v9 -= 4;
        if ( v18 )
          break;
        if ( (unsigned int)++v17 >= 0x20 )
          goto LABEL_14;
      }
      if ( v16 + 1024 == v12 )
      {
        v15 = v9 & 0xFFFFF000;
      }
      else if ( v16 <= v13 )
      {
        v14 = (v9 & 0xFFFFF000) + 4096;
      }
      v9 += 4 * (v17 - 31);
LABEL_14:
      if ( v17 == 32 )
      {
        v56 = *(_DWORD *)(v5 + 136) + (v16 << 12);
        v61 = (v56 >> 20) & 0xFFC;
        v23 = *(_DWORD *)(v61 - 1070596096);
        v24 = (_DWORD *)v9;
        do
          *v24++ = -1;
        while ( v24 != (_DWORD *)(v9 + 128) );
        if ( v16 + 1024 == v12 )
        {
          v25 = (_DWORD *)(v9 + 128);
          for ( i = v9 + 128; (i & 0xFFF) != 0; i = (__int16)v25 )
          {
            if ( *v25++ )
            {
              v15 = (unsigned int)(v25 - 1) & 0xFFFFF000;
              break;
            }
          }
        }
        if ( v16 <= v13 )
        {
          v14 = v9;
          if ( (v9 & 0xFFF) != 0 )
          {
            do
            {
              v28 = *(_DWORD *)(v14 - 4);
              v14 -= 4;
              if ( v28 )
                goto LABEL_38;
            }
            while ( (v14 & 0xFFF) != 0 );
            if ( *(_DWORD *)v14 )
            {
LABEL_38:
              v14 = (v14 & 0xFFFFF000) + 4096;
              goto LABEL_39;
            }
          }
          else
          {
            v14 = v9;
          }
        }
LABEL_39:
        *(_BYTE *)((v16 >> 13) + *(_DWORD *)(v60 + 4)) |= 1 << ((v16 >> 10) & 7);
        v29 = v56;
        if ( !v57 )
          v57 = v56 + 0x400000;
        v30 = MmPfnDatabase + 24 * (v23 >> 12);
        if ( (v23 & 0x400) != 0 )
        {
          v35 = KfRaiseIrql(2);
          v36 = 1024;
          v37 = (unsigned int *)(v30 + 12);
          do
          {
            v38 = (unsigned __int8 *)v37 + 3;
            do
              v39 = __ldrex(v38);
            while ( __strex(v39 | 0x80, v38) );
            while ( 1 )
            {
              __dmb(0xBu);
              if ( !(v39 >> 7) )
                break;
              do
              {
                __dmb(0xAu);
                __yield();
                v40 = *v37;
                __dmb(0xBu);
              }
              while ( v40 < 0 );
              do
                v39 = __ldrex(v38);
              while ( __strex(v39 | 0x80, v38) );
            }
            *(_BYTE *)(v30 + 18) = *(_BYTE *)(v30 + 18) & 0xF8 | 5;
            __dmb(0xBu);
            do
              v41 = __ldrex(v37);
            while ( __strex(v41 & 0x7FFFFFFF, v37) );
            v30 += 24;
            v37 += 6;
            --v36;
          }
          while ( v36 );
          KfLowerIrql(v35);
          v42 = v58;
          v58 = (_DWORD *)(v30 - 24576);
          *(_DWORD *)(v30 - 24576) = v42;
          if ( v16 < v62 || v16 + 1024 > v67 )
            --*(_DWORD *)(v5 + 116);
          if ( (dword_682604 & 1) != 0 )
          {
            v43 = MiInitPerfMemoryFlags(0, 5);
            MiLogPerfMemoryRangeEvent(v56, 0, v43, 1024);
          }
          v44 = (_DWORD *)(v61 - 1070596096);
          __dmb(0xBu);
          *v44 = 0;
          if ( (unsigned int)(v44 + 267649024) <= 0xFFF )
          {
            v45 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v45, (_DWORD *)(v45 + 4 * ((v56 >> 20) & 0xFFC)), 0);
          }
          v29 = v56;
          v32 = 1;
          v31 = 1;
        }
        else
        {
          v31 = 1024;
          v32 = 0;
        }
        MiInsertTbFlushEntry((int)&v69, v29, v31, v32);
        *((_BYTE *)&MiState[29] + ((int)(v61 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) = -1;
      }
      else
      {
        v19 = v66;
        *(_BYTE *)((v16 >> 13) + *(_DWORD *)(v60 + 4)) &= ~(unsigned __int8)(1 << ((v16 >> 10) & 7));
        if ( v16 < *(_DWORD *)(v5 + 4 * v19) )
          *(_DWORD *)(v5 + 4 * v19) = v16;
      }
      v13 = v59;
      v16 -= 1024;
      v12 = v63;
    }
    while ( v16 + 1024 > v59 );
    v10 = v56;
  }
  if ( v15 > v14 )
    MiJoinBitmapPages();
  result = KeReleaseInStackQueuedSpinLock((int)v68);
  if ( v10 )
  {
    result = MiReturnSystemVa(v10, v57, 5, &v69);
    v33 = v58;
    v34 = v64[0];
    if ( !v58 )
    {
LABEL_45:
      if ( v34 )
      {
        v65 = v34;
        result = MiReturnNonPagedPoolCharges(v64);
      }
      return result;
    }
    while ( 1 )
    {
      v46 = (_DWORD *)*v33;
      v47 = (unsigned __int64)(715827883i64 * ((int)v33 - MmPfnDatabase)) >> 32;
      v48 = ((v47 >> 2) + ((unsigned int)v47 >> 31)) >> 10;
      if ( dword_634C94 )
      {
        v49 = (unsigned int *)(dword_634C94 + 4 * (((v47 >> 2) + ((unsigned int)v47 >> 31)) >> 15));
        v50 = (((v47 >> 2) + ((unsigned int)v47 >> 31)) >> 10) & 0x1F;
        LOBYTE(v47) = 1;
        if ( v50 + 1 > 0x20 )
        {
          if ( (v48 & 0x1F) != 0 )
          {
            __dmb(0xBu);
            do
              v52 = __ldrex(v49);
            while ( __strex(v52 & ~(((1 << (32 - v50)) - 1) << v50), v49) );
            __dmb(0xBu);
            v47 = v50 - 31;
            ++v49;
            if ( v50 - 31 >= 0x20 )
            {
              v53 = (unsigned int)v47 >> 5;
              do
              {
                v47 -= 32;
                --v53;
                *v49++ = 0;
              }
              while ( v53 );
            }
            if ( !v47 )
              goto LABEL_86;
          }
          __dmb(0xBu);
          v54 = ~((1 << v47) - 1);
          do
            v55 = __ldrex(v49);
          while ( __strex(v55 & v54, v49) );
        }
        else
        {
          __dmb(0xBu);
          do
            v51 = __ldrex(v49);
          while ( __strex(v51 & ~(1 << v50), v49) );
        }
        __dmb(0xBu);
      }
LABEL_86:
      result = MiFreeLargePageMemory(v48 << 10);
      v34 += 1024;
      v33 = v46;
      if ( !v46 )
      {
        v64[0] = v34;
        goto LABEL_45;
      }
    }
  }
  return result;
}
