// KiCacheInitialize 
 
// local variable allocation has failed, the output may be wrong!
int KiCacheInitialize()
{
  unsigned int v0; // r8
  int result; // r0
  unsigned int v2; // r9
  unsigned int v3; // r6
  unsigned int v4; // r5
  unsigned int v5; // r7
  int v6; // r2
  int v7; // r1
  unsigned int v8; // r4
  int v9; // r10
  int v10; // lr
  int v11; // r4 OVERLAPPED
  int v12; // r1
  int v13; // r3
  unsigned int v14; // r0
  int v15; // r2
  unsigned int v16; // r3
  int v17; // r3
  int v18; // [sp+8h] [bp-28h]
  int v19; // [sp+10h] [bp-20h]

  v0 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  result = 0;
  v18 = 0;
  v2 = 0;
  v3 = -1;
  *(_BYTE *)(v0 + 3576) = 0;
  v4 = v0 + 3504;
  v19 = __mrc(15, 0, 0, 0, 1);
  v5 = __mrc(15, 1, 0, 0, 1);
  v6 = 1;
  v7 = 2;
  v8 = 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = v5 & 7;
    if ( v10 == 2 )
    {
      *(_DWORD *)(v4 + 8) = 2;
LABEL_12:
      v13 = 2 * (v9 & 7);
      goto LABEL_13;
    }
    if ( v10 != 3 && v10 != 1 )
    {
      if ( v10 != 4 )
        goto LABEL_6;
      *(_DWORD *)(v4 + 8) = 0;
      goto LABEL_12;
    }
    *(_DWORD *)(v4 + 8) = 1;
    v13 = (2 * (v9 & 7)) | 1;
LABEL_13:
    __mcr(15, 2, v13, 0, 0, 0);
    __isb(0xFu);
    v14 = __mrc(15, 1, 0, 0, 0);
    *(_BYTE *)v4 = v9 + 1;
    v7 = (unsigned __int8)((v14 >> 3) + 1);
    v15 = (unsigned __int16)(1 << ((v14 & 7) + 4));
    *(_BYTE *)(v4 + 1) = v7;
    *(_WORD *)(v4 + 2) = v15;
    *(_DWORD *)(v4 + 4) = (((v14 >> 13) & 0x7FFF) + 1) * v15 * v7;
    ++*(_BYTE *)(v0 + 3576);
    if ( v10 == 3 )
    {
      v5 = v5 & 0xFFFFFFF8 | 2;
    }
    else
    {
      ++v9;
      v5 >>= 3;
    }
    if ( v2 <= *(unsigned __int16 *)(v4 + 2) )
      v2 = *(unsigned __int16 *)(v4 + 2);
    v16 = *(_DWORD *)(v4 + 4);
    if ( v8 <= v16 )
      v8 = *(_DWORD *)(v4 + 4);
    if ( v3 >= v16 )
      v3 = *(_DWORD *)(v4 + 4);
    v4 += 12;
    v6 = v18 + 1;
    v18 = v6;
    if ( v6 == 6 )
      break;
    result = 0;
    v6 = 1;
    v7 = 2;
    if ( (unsigned int)(v9 + 1) > 8 )
      goto LABEL_6;
  }
  result = 0;
LABEL_6:
  v11 = v19;
  if ( *(_DWORD *)(v0 + 20) )
  {
    v12 = KiCacheType;
    if ( ((KiCacheType ^ v19) & 0xC000) != 0 )
    {
      v12 = KiCacheType & 0xFFFF3FFF | 0x8000;
      KiCacheType = v12;
      v11 = v19 & 0xFFFF3FFF | 0x8000;
    }
    if ( v12 != v11 )
      KeBugCheckEx(62, v12, v11, 0, 0);
    result = KiExternalCacheAddDescriptor();
  }
  else if ( (unsigned __int16)v19 >> 14 == 2 )
  {
    v17 = 1 << ((v19 & 0xF) + 2);
    *(_QWORD *)&KiMinimumIcacheLine = *(_QWORD *)(&v11 - 1);
    KiMinimumDcacheLine = 1 << ((BYTE2(v19) & 0xF) + 2);
    if ( v2 )
      KeLargestCacheLine = v2;
    if ( v3 <= 0x4000 )
      v3 = 0x4000;
    KiICacheFlushPromoteThreshold = v3 >> 1;
  }
  else
  {
    result = sub_694148(0, v7, v6);
  }
  return result;
}
