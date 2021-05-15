// RtlpAllocateHeap 
 
_BYTE *__fastcall RtlpAllocateHeap(_DWORD *a1, unsigned int a2, unsigned int a3, unsigned int a4, int a5, _DWORD *a6)
{
  unsigned int v6; // r6
  char v7; // r10
  _DWORD *v8; // r5
  int v9; // r9
  unsigned int v10; // r8
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r2
  int v16; // r6
  unsigned __int16 **v17; // r9
  _DWORD *v18; // r1
  int v19; // r0
  unsigned __int16 *v20; // r0
  _DWORD *v21; // r1
  unsigned int v22; // r0
  int v23; // r0
  int v24; // r3
  unsigned int v25; // r6
  int v26; // r0
  unsigned int v27; // r6
  unsigned int v28; // r1
  unsigned int v29; // r2
  unsigned int v30; // r2
  BOOL v31; // r0
  unsigned int v32; // r1
  int v33; // r6
  _DWORD *v34; // r2
  _DWORD *v35; // r3
  unsigned int v36; // r2
  char v37; // r3
  _DWORD *v38; // r1
  _DWORD *v39; // r3
  char v41; // [sp+10h] [bp-58h]
  int v42; // [sp+14h] [bp-54h]
  int v43; // [sp+18h] [bp-50h]
  _BYTE *v44; // [sp+1Ch] [bp-4Ch]
  char v45; // [sp+20h] [bp-48h]
  unsigned int v46; // [sp+24h] [bp-44h]
  int v47; // [sp+28h] [bp-40h]
  int v48; // [sp+30h] [bp-38h]
  char v49; // [sp+34h] [bp-34h]
  int v51; // [sp+3Ch] [bp-2Ch]
  unsigned int varg_r2; // [sp+78h] [bp+10h]
  unsigned int varg_r3; // [sp+7Ch] [bp+14h]
  unsigned int varg_r3a; // [sp+7Ch] [bp+14h]

  varg_r2 = a3;
  v6 = a4;
  varg_r3 = a4;
  v46 = a3;
  v7 = a2;
  v49 = a2;
  v8 = a1;
  v43 = 1;
  v48 = 0;
  v41 = 0;
  v44 = 0;
  v42 = 0;
  if ( (a2 & 0x3C010F60) != 0 || a3 >= 0x80000000 )
  {
    v43 = 0;
    *a6 = 4;
    if ( a3 > 0x7FFFFFFF )
      return 0;
    if ( !a3 )
      a3 = 1;
    v11 = a3 + a1[37];
    v6 = v11 & a1[38];
    if ( v6 < 0x10 )
      v6 = 16;
    varg_r3 = v6;
    v9 = (a2 >> 4) & 0xE0 | 1;
    v45 = v9;
    v12 = 1006633216;
    if ( (a2 & 0x3C000100) != 0 || (v12 = a1[47]) != 0 )
    {
      v9 = (a2 >> 4) & 0xE0 | 3;
      v45 = v9;
      v6 += 8;
      varg_r3 = v6;
    }
    v10 = v6 >> 3;
  }
  else
  {
    LOBYTE(v9) = 1;
    v45 = 1;
    v10 = a4 >> 3;
    if ( a4 >> 3 < 2 )
    {
      v6 = a4 + 8;
      varg_r3 = a4 + 8;
      v10 = 2;
    }
    v11 = 3;
    v12 = (int)a6;
    *a6 = 3;
  }
  if ( (a2 & 0x800000) != 0 && (RtlGetNtGlobalFlags() & 0x800) == 0 )
  {
    LOBYTE(v9) = v9 | 8;
    v45 = v9;
  }
  if ( (v7 & 1) == 0 )
  {
    ExAcquireResourceExclusiveLite(v8[50], 1, v11, v12);
    v48 = 1;
    v41 = 1;
    v6 = varg_r3;
  }
  if ( v10 > v8[23] )
  {
    if ( (v8[16] & 2) != 0 )
    {
      varg_r3a = v6 + 24;
      v47 = (ExGenRandom(1) & 0xF) << 12;
      if ( ZwAllocateVirtualMemory() < 0 )
        goto LABEL_107;
      v42 = v47;
      if ( ZwAllocateVirtualMemory() >= 0 )
      {
        *(_WORD *)(v47 + 24) = varg_r3a - v46;
        *(_BYTE *)(v47 + 26) = v9 | 2;
        *(_DWORD *)(v47 + 16) = varg_r3a;
        *(_DWORD *)(v47 + 20) = v6 + 24 + v47 + 4096;
        *(_BYTE *)(v47 + 31) = 4;
        v36 = v6 + 24;
        v8[123] += varg_r3a;
        v37 = dword_682608;
        if ( (dword_682608 & 0x20) != 0 )
        {
          RtlpLogHeapCommit(v8, v47, varg_r3a, 9, 4096, 4);
          v36 = v6 + 24;
          v37 = dword_682608;
        }
        if ( (v37 & 0x20) != 0 )
          RtlpLogHeapExtendEvent(v8, v47, v36, 8 * v8[29]);
        v38 = (_DWORD *)v47;
        if ( v8[19] )
        {
          *(_BYTE *)(v47 + 27) = *(_BYTE *)(v47 + 24) ^ *(_BYTE *)(v47 + 26) ^ *(_BYTE *)(v47 + 25);
          *(_DWORD *)(v47 + 24) ^= v8[20];
          v38 = (_DWORD *)v47;
        }
        v39 = (_DWORD *)v8[40];
        if ( (_DWORD *)*v39 == v8 + 39 )
        {
          *v38 = v8 + 39;
          v38[1] = v39;
          *v39 = v38;
          v8[40] = v38;
        }
        else
        {
          RtlpLogHeapFailure(12, 0);
        }
        v44 = (_BYTE *)(v47 + 32);
        goto LABEL_107;
      }
      ZwFreeVirtualMemory();
      v42 = 0;
      ++v8[132];
    }
    goto LABEL_106;
  }
  v13 = RtlpFindEntry(v8, v10);
  if ( v8 + 48 != (_DWORD *)v13 )
  {
    v14 = v13 - 8;
    if ( v8[19] )
    {
      *(_DWORD *)v14 ^= v8[20];
      if ( *(unsigned __int8 *)(v13 - 5) != (*(unsigned __int8 *)(v13 - 6) ^ *(unsigned __int8 *)(v13 - 7) ^ *(unsigned __int8 *)(v13 - 8)) )
        RtlpAnalyzeHeapFailure(v8, v13 - 8);
    }
    v15 = *(unsigned __int16 *)v14;
    if ( v15 >= v10 )
    {
      v16 = *(_DWORD *)(v14 + 8);
      v17 = *(unsigned __int16 ***)(v14 + 12);
      if ( *v17 == *(unsigned __int16 **)(v16 + 4) && *v17 == (unsigned __int16 *)(v14 + 8) )
      {
        v8[29] -= v15;
        v18 = (_DWORD *)v8[45];
        if ( !v18 )
          goto LABEL_45;
        while ( (unsigned int)*(unsigned __int16 *)v14 >= v18[1] && *v18 )
          v18 = (_DWORD *)*v18;
        goto LABEL_44;
      }
      goto LABEL_33;
    }
    if ( v8[19] )
    {
      *(_BYTE *)(v14 + 3) = *(_BYTE *)v14 ^ *(_BYTE *)(v14 + 2) ^ *(_BYTE *)(v14 + 1);
      *(_DWORD *)v14 ^= v8[20];
    }
  }
  v20 = (unsigned __int16 *)RtlpExtendHeap(v8, varg_r3);
  v14 = (int)v20;
  if ( !v20 )
  {
LABEL_106:
    v44 = 0;
    goto LABEL_107;
  }
  v16 = *((_DWORD *)v20 + 2);
  v17 = (unsigned __int16 **)*((_DWORD *)v20 + 3);
  if ( *v17 == *(unsigned __int16 **)(v16 + 4) && *v17 == v20 + 4 )
  {
    v8[29] -= *v20;
    v21 = (_DWORD *)v8[45];
    if ( !v21 )
      goto LABEL_45;
    v22 = *v20;
    while ( v22 >= v21[1] && *v21 )
      v21 = (_DWORD *)*v21;
LABEL_44:
    RtlpHeapRemoveListEntry(v8);
LABEL_45:
    *v17 = (unsigned __int16 *)v16;
    *(_DWORD *)(v16 + 4) = v17;
    v51 = *(unsigned __int8 *)(v14 + 2);
    v23 = v43;
    if ( !v43 && (*(_BYTE *)(v14 + 2) & 4) != 0 )
    {
      v24 = 8 * *(unsigned __int16 *)v14;
      v25 = v24 - 16;
      if ( (*(_BYTE *)(v14 + 2) & 2) != 0 && v25 > 4 )
        v25 = v24 - 20;
      v26 = RtlCompareMemoryUlong(v14 + 16, v25, -17891602);
      if ( v26 != v25 )
      {
        DbgPrint(
          "HEAP: Free Heap block %p modified at %p after it was freed\n",
          (const void *)v14,
          (const void *)(v26 + v14 + 16));
        if ( KdDebuggerEnabled )
          __debugbreak();
      }
      v23 = 0;
    }
    if ( (*(_BYTE *)(v14 + 2) & 1) == 0 )
    {
      *(_BYTE *)(v14 + 2) = v45;
      v27 = *(unsigned __int16 *)v14 - v10;
      *(_WORD *)v14 = v10;
      v28 = v46;
      v29 = varg_r3 - v46;
      if ( varg_r3 - v46 >= 0x3F )
      {
        *(_DWORD *)(v14 + 8 * v10 - 4) = v29;
        __dmb(0xBu);
        *(_BYTE *)(v14 + 7) = 63;
      }
      else
      {
        *(_BYTE *)(v14 + 7) = v29;
      }
      *(_BYTE *)(v14 + 3) = 0;
      if ( v27 )
      {
        if ( v27 == 1 )
        {
          ++*(_WORD *)v14;
          v30 = varg_r3 - v46 + 8;
          if ( v30 >= 0x3F )
          {
            *(_DWORD *)(v14 + 8 * v10 + 4) = v30;
            __dmb(0xBu);
            *(_BYTE *)(v14 + 7) = 63;
          }
          else
          {
            *(_BYTE *)(v14 + 7) = v30;
          }
        }
        else
        {
          v31 = v23 == 0;
          if ( *(_BYTE *)(v14 + 6) )
            v32 = (v14 & 0xFFFF0000) - (*(unsigned __int8 *)(v14 + 6) << 16) + 0x10000;
          else
            v32 = (unsigned int)v8;
          if ( !RtlpCreateSplitBlock(v8, v32, v14 + 8 * v10, v51, v31, (unsigned __int16)v10, v27) )
            goto LABEL_107;
          v28 = v46;
        }
      }
      v44 = (_BYTE *)(v14 + 8);
      v33 = 8 * *(unsigned __int16 *)v14;
      if ( (*(_BYTE *)(v14 + 7) & 0x3F) == 63 )
        v33 -= 4;
      if ( v43 )
      {
        if ( v8[19] )
        {
          *(_BYTE *)(v14 + 3) = *(_BYTE *)v14 ^ *(_BYTE *)(v14 + 2) ^ *(_BYTE *)(v14 + 1);
          *(_DWORD *)v14 ^= v8[20];
        }
        if ( v48 )
        {
          ExpReleaseResourceForThreadLite(v8[50], __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
          v41 = 0;
        }
        if ( (v49 & 8) != 0 )
          memset((_BYTE *)(v14 + 8), 0, v33 - 8);
      }
      else
      {
        if ( (v49 & 8) != 0 )
        {
          memset((_BYTE *)(v14 + 8), 0, v33 - 8);
        }
        else if ( (v8[16] & 0x40) != 0 )
        {
          RtlFillMemoryUlong((_DWORD *)(v14 + 8), v28 & 0xFFFFFFFC, -1163005939);
        }
        if ( (v8[16] & 0x20) != 0 )
        {
          v34 = (_DWORD *)(v46 + v14 + 8);
          *v34 = -1414812757;
          v34[1] = -1414812757;
          *(_BYTE *)(v14 + 2) |= 4u;
        }
        *(_BYTE *)(v14 + 3) = 0;
        if ( (*(_BYTE *)(v14 + 2) & 2) != 0 )
        {
          if ( *(_BYTE *)(v14 + 7) == 4 )
            v35 = (_DWORD *)(v14 - 16);
          else
            v35 = (_DWORD *)(v14 + 8 * *(unsigned __int16 *)v14 - 8);
          *v35 = 0;
          v35[1] = 0;
        }
        if ( v8[19] )
        {
          *(_BYTE *)(v14 + 3) = *(_BYTE *)v14 ^ *(_BYTE *)(v14 + 2) ^ *(_BYTE *)(v14 + 1);
          *(_DWORD *)v14 ^= v8[20];
        }
      }
      goto LABEL_107;
    }
    v19 = 3;
    goto LABEL_56;
  }
LABEL_33:
  v19 = 12;
LABEL_56:
  RtlpLogHeapFailure(v19, v8);
LABEL_107:
  if ( v41 )
    ExpReleaseResourceForThreadLite(a1[50], __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( (dword_682608 & 0x20) != 0 && v44 && v42 )
    RtlpHeapLogRangeReserve(a1, v42 & 0xFFFF0000, *(_DWORD *)(v42 + 20));
  return v44;
}
