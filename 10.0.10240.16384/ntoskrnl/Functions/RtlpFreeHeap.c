// RtlpFreeHeap 
 
int __fastcall RtlpFreeHeap(int a1, int a2, int a3, int a4)
{
  unsigned __int8 *v5; // r5
  int v7; // r8
  int v8; // r10
  int v10; // r6
  int v11; // r1
  int v12; // r3
  _DWORD *v13; // r2
  int v14; // r0
  unsigned __int16 *v15; // r5
  unsigned __int16 v16; // r2
  unsigned int v17; // r9
  _DWORD **v18; // r8
  _DWORD *v19; // r0
  int v20; // r2
  unsigned int v21; // r3
  _DWORD *v22; // r8
  int *v23; // r3
  _DWORD *v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r8
  _DWORD **v27; // r9
  _DWORD *v28; // r0
  int v29; // r2
  unsigned int v30; // r3
  int *v31; // r3
  int v32; // r5
  int v33; // r8
  int v34; // r3
  int *v35; // r2
  int v36; // r0
  char v38; // [sp+10h] [bp-40h]
  unsigned int v39; // [sp+14h] [bp-3Ch] BYREF
  unsigned int v40; // [sp+18h] [bp-38h]
  int v41; // [sp+1Ch] [bp-34h]
  int v42; // [sp+20h] [bp-30h]
  int v43; // [sp+28h] [bp-28h]
  int varg_r0; // [sp+58h] [bp+8h]
  int varg_r1; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v5 = (unsigned __int8 *)a3;
  varg_r2 = a3;
  varg_r0 = a1;
  v7 = 1;
  v8 = 0;
  v38 = 0;
  v41 = 1;
  v40 = 0;
  if ( a1 == a3 )
  {
    RtlpLogHeapFailure(9, a1, a3, 0, 0);
    return 0;
  }
  v10 = *(_DWORD *)(a1 + 68) | a2;
  if ( (v10 & 0x3C010F60) != 0 )
  {
    v7 = 0;
    v11 = 4;
  }
  else
  {
    v11 = 3;
  }
  v12 = dword_682608;
  if ( (dword_682608 & 0x20) != 0 )
  {
    a3 = *(unsigned __int8 *)(a1 + 82) & (*(_DWORD *)(a1 + 76) >> 17);
    v12 = ((v5[2] ^ (unsigned __int8)a3) & 8) != 0;
    if ( ((v5[2] ^ (unsigned __int8)a3) & 8) == 0 )
      RtlpLogHeapFreeEvent(a1, a4, v11);
  }
  if ( (v10 & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 76) )
    {
      *(_DWORD *)v5 ^= *(_DWORD *)(a1 + 80);
      if ( v5[3] != (v5[2] ^ v5[1] ^ *v5) )
        RtlpAnalyzeHeapFailure(a1, v5);
    }
  }
  else
  {
    ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 200), 1, a3, v12);
    v8 = 1;
    v38 = 1;
    if ( *(_DWORD *)(a1 + 76) )
    {
      *(_DWORD *)v5 ^= *(_DWORD *)(a1 + 80);
      if ( v5[3] != (v5[2] ^ v5[1] ^ *v5) )
        RtlpAnalyzeHeapFailure(a1, v5);
    }
    v13 = *(_DWORD **)(a1 + 180);
    do
    {
      if ( (unsigned int)*(unsigned __int16 *)v5 < v13[1] )
        break;
      v13 = (_DWORD *)*v13;
    }
    while ( v13 );
  }
  if ( (v5[2] & 8) != 0 )
    v5[2] &= 0xF7u;
  if ( v5[7] == 4 )
  {
    v32 = (int)(v5 - 24);
    v33 = *(_DWORD *)(v32 + 16);
    v40 = v32 & 0xFFFF0000;
    *(_DWORD *)(a1 + 492) -= v33;
    v34 = *(_DWORD *)v32;
    v35 = *(int **)(v32 + 4);
    v36 = *(_DWORD *)(*(_DWORD *)v32 + 4);
    if ( *v35 == v36 && *v35 == v32 )
    {
      *v35 = v34;
      *(_DWORD *)(v34 + 4) = v35;
    }
    else
    {
      RtlpLogHeapFailure(12, 0, v32, v36, *v35);
    }
    varg_r2 = 0;
    if ( v8 )
    {
      ExpReleaseResourceForThreadLite(*(_DWORD *)(a1 + 200), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v38 = 0;
    }
    if ( (dword_682608 & 0x20) != 0 )
      RtlpHeapLogRangeRelease(a1, v40, *(_DWORD *)(v32 + 20));
    v39 = 0;
    ZwFreeVirtualMemory();
    if ( (dword_682608 & 0x20) != 0 )
      RtlpLogHeapContractEvent(a1, v32, v33, 8 * *(_DWORD *)(a1 + 116), 0, 0);
    goto LABEL_84;
  }
  v39 = *(unsigned __int16 *)v5;
  v14 = RtlpCoalesceFreeBlocks(a1, v5, (int *)&v39);
  v15 = (unsigned __int16 *)v14;
  varg_r2 = v14;
  v16 = v39;
  if ( v39 < *(_DWORD *)(a1 + 108) || *(_DWORD *)(a1 + 116) + v39 < *(_DWORD *)(a1 + 112) )
  {
    if ( v39 > 0xFE00 )
    {
      RtlpInsertFreeBlock(a1, (unsigned __int16 *)v14, v39);
      goto LABEL_73;
    }
    if ( v7 )
    {
      v17 = (unsigned __int16)v39;
      *(_BYTE *)(v14 + 2) = 0;
      *(_BYTE *)(v14 + 7) = 0;
      v18 = (_DWORD **)(a1 + 192);
      if ( *(_DWORD *)(a1 + 180) )
        v19 = (_DWORD *)RtlpFindEntry(a1, v16);
      else
        v19 = *v18;
      while ( v18 != v19 )
      {
        if ( *(_DWORD *)(a1 + 76) )
        {
          v20 = *(v19 - 2);
          v42 = v20;
          if ( (*(_DWORD *)(a1 + 76) & v20) != 0 )
            v42 = *(_DWORD *)(a1 + 80) ^ v20;
          v21 = (unsigned __int16)v42;
        }
        else
        {
          v21 = *((unsigned __int16 *)v19 - 4);
        }
        if ( v17 <= v21 )
          break;
        v19 = (_DWORD *)*v19;
      }
      v22 = v15 + 4;
      v23 = (int *)v19[1];
      if ( (_DWORD *)*v23 == v19 )
      {
        *v22 = v19;
        *((_DWORD *)v15 + 3) = v23;
        *v23 = (int)v22;
        v19[1] = v22;
      }
      else
      {
        RtlpLogHeapFailure(12, 0, (int)v19, 0, *v23);
      }
      *(_DWORD *)(a1 + 116) += *v15;
      v24 = *(_DWORD **)(a1 + 180);
      if ( !v24 )
        goto LABEL_70;
      v25 = *v15;
      while ( v25 >= v24[1] )
      {
        if ( !*v24 )
          goto LABEL_68;
        v24 = (_DWORD *)*v24;
      }
    }
    else
    {
      v26 = (unsigned __int16)v39;
      *(_BYTE *)(v14 + 2) &= 0xF0u;
      *(_BYTE *)(v14 + 7) = 0;
      if ( (*(_DWORD *)(a1 + 64) & 0x40) != 0 )
      {
        RtlFillMemoryUlong((_DWORD *)(v14 + 16), 8 * v16 - 16, -17891602);
        *((_BYTE *)v15 + 2) |= 4u;
      }
      v27 = (_DWORD **)(a1 + 192);
      if ( *(_DWORD *)(a1 + 180) )
        v28 = (_DWORD *)RtlpFindEntry(a1, v26);
      else
        v28 = *v27;
      while ( v27 != v28 )
      {
        if ( *(_DWORD *)(a1 + 76) )
        {
          v29 = *(v28 - 2);
          v43 = v29;
          if ( (*(_DWORD *)(a1 + 76) & v29) != 0 )
            v43 = *(_DWORD *)(a1 + 80) ^ v29;
          v30 = (unsigned __int16)v43;
        }
        else
        {
          v30 = *((unsigned __int16 *)v28 - 4);
        }
        if ( v26 <= v30 )
          break;
        v28 = (_DWORD *)*v28;
      }
      v22 = v15 + 4;
      v31 = (int *)v28[1];
      if ( (_DWORD *)*v31 == v28 )
      {
        *v22 = v28;
        *((_DWORD *)v15 + 3) = v31;
        *v31 = (int)v22;
        v28[1] = v22;
      }
      else
      {
        RtlpLogHeapFailure(12, 0, (int)v28, 0, *v31);
      }
      *(_DWORD *)(a1 + 116) += *v15;
      v24 = *(_DWORD **)(a1 + 180);
      if ( !v24 )
        goto LABEL_70;
      v25 = *v15;
      while ( v25 >= v24[1] )
      {
        if ( !*v24 )
        {
LABEL_68:
          v25 = v24[1] - 1;
          break;
        }
        v24 = (_DWORD *)*v24;
      }
    }
    RtlpHeapAddListEntry(a1, v24, *v15, (int)v22, v25);
LABEL_70:
    if ( *(_DWORD *)(a1 + 76) )
    {
      *((_BYTE *)v15 + 3) = *(_BYTE *)v15 ^ *((_BYTE *)v15 + 2) ^ *((_BYTE *)v15 + 1);
      *(_DWORD *)v15 ^= *(_DWORD *)(a1 + 80);
    }
    goto LABEL_73;
  }
  RtlpDeCommitFreeBlock(a1, (unsigned __int16 *)v14);
LABEL_73:
  varg_r2 = 0;
LABEL_84:
  if ( v38 )
    ExpReleaseResourceForThreadLite(*(_DWORD *)(varg_r0 + 200), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  return v41;
}
