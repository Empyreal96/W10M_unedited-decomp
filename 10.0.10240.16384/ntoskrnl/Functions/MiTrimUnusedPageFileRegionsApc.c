// MiTrimUnusedPageFileRegionsApc 
 
int __fastcall MiTrimUnusedPageFileRegionsApc(_DWORD *a1)
{
  int v2; // r3
  int v3; // r0
  int v4; // r8
  int i; // r3
  __int64 v6; // r4
  unsigned int v7; // r9
  _DWORD *v8; // r7
  unsigned int v9; // r6
  BOOL v10; // r3
  int v11; // r2
  int *v12; // r1
  int *v13; // r0
  unsigned int v14; // r2
  int v15; // t1
  bool j; // zf
  int v17; // t1
  unsigned int v18; // r6
  bool v19; // zf
  int v20; // r2
  int *v21; // r1
  int *v22; // r0
  unsigned int v23; // r2
  int v24; // t1
  bool k; // zf
  int v26; // t1
  unsigned int v28; // r1
  unsigned int v29; // r0
  unsigned int v31; // [sp+8h] [bp-30h] BYREF
  int v32; // [sp+Ch] [bp-2Ch] BYREF
  char v33[40]; // [sp+10h] [bp-28h] BYREF

  v2 = a1[5];
  v3 = a1[4];
  v4 = *(_DWORD *)(v3 + 4 * v2 + 3600);
  v32 = v3;
  for ( i = 4 * (*(_WORD *)(v4 + 96) & 1 | (a1[7] << 11)); ; i = v31 & 0x1FFF | (v7 << 13) )
  {
    v31 = i;
    HIDWORD(v6) = MiFindFreePageFileSpace(v3, &v31, a1[6], 0, 4);
    if ( HIDWORD(v6) < a1[6] )
      break;
    LODWORD(v6) = v31 >> 13;
    v7 = (v31 >> 13) + HIDWORD(v6);
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v4 + 116), (unsigned int)v33);
    v8 = *(_DWORD **)(v4 + 64);
    v9 = v6 + HIDWORD(v6) - 1;
    if ( v9 >= v8[3] )
      goto LABEL_32;
    if ( HIDWORD(v6) > 1 )
    {
      v11 = v8[4];
      v12 = (int *)(v11 + 4 * ((unsigned int)v6 >> 5));
      v13 = (int *)(v11 + 4 * (v9 >> 5));
      if ( v12 != v13 )
      {
        v15 = *v12++;
        for ( j = (v15 & (-1 << (v6 & 0x1F))) == 0; j; j = v17 == 0 )
        {
          if ( v12 == v13 )
          {
            v14 = 0xFFFFFFFF >> (31 - (v9 & 0x1F));
            goto LABEL_14;
          }
          v17 = *v12++;
        }
        goto LABEL_32;
      }
      v14 = 0xFFFFFFFF >> (32 - BYTE4(v6)) << (v6 & 0x1F);
LABEL_14:
      v10 = (*v12 & v14) == 0;
    }
    else
    {
      if ( HIDWORD(v6) != 1 )
        goto LABEL_32;
      v10 = ((*(unsigned __int8 *)(((int)v6 >> 3) + v8[4]) >> (v6 & 7)) & 1) == 0;
    }
    if ( !v10 )
      goto LABEL_32;
    v18 = v6 + HIDWORD(v6) - 1;
    if ( v18 >= v8[1] )
      goto LABEL_32;
    if ( HIDWORD(v6) > 1 )
    {
      v20 = v8[2];
      v21 = (int *)(v20 + 4 * ((unsigned int)v6 >> 5));
      v22 = (int *)(v20 + 4 * (v18 >> 5));
      if ( v21 != v22 )
      {
        v24 = *v21++;
        for ( k = ((-1 << (v6 & 0x1F)) & v24) == 0; k; k = v26 == 0 )
        {
          if ( v21 == v22 )
          {
            v23 = 0xFFFFFFFF >> (31 - (v18 & 0x1F));
            goto LABEL_27;
          }
          v26 = *v21++;
        }
        goto LABEL_32;
      }
      v23 = 0xFFFFFFFF >> (32 - BYTE4(v6)) << (v6 & 0x1F);
LABEL_27:
      v19 = (v23 & *v21) == 0;
    }
    else
    {
      v19 = ((*(unsigned __int8 *)(((int)v6 >> 3) + v8[2]) >> (v6 & 7)) & 1) == 0;
    }
    if ( v19 )
    {
      v28 = RtlFindNextForwardRunClearCapped(
              (unsigned int *)(*(_DWORD *)(v4 + 64) + 12),
              v7 - 1,
              0xFFFFFFFF,
              (unsigned int *)&v32);
      if ( v28 > 1 )
      {
        v29 = RtlFindNextForwardRunClearCapped(
                (unsigned int *)(*(_DWORD *)(v4 + 64) + 4),
                v7 - 1,
                v28,
                (unsigned int *)&v32);
        if ( v29 > 1 )
          HIDWORD(v6) = v29 + HIDWORD(v6) - 1;
      }
      LODWORD(v6) = v31 >> 13;
      RtlSetBits((_BYTE *)(*(_DWORD *)(v4 + 64) + 12), v31 >> 13, HIDWORD(v6));
      RtlSetBits((_BYTE *)(*(_DWORD *)(v4 + 64) + 4), v6, HIDWORD(v6));
      *(_DWORD *)(v4 + 24) -= HIDWORD(v6);
      *(_DWORD *)(v4 + 12) -= HIDWORD(v6);
      KeReleaseInStackQueuedSpinLock((int)v33);
      *(_QWORD *)(a1 + 7) = v6;
      MiMapPageFileHash(v4, 0, 0, v6, HIDWORD(v6));
      return KeSetEvent((int)a1, 0, 0);
    }
LABEL_32:
    KeReleaseInStackQueuedSpinLock((int)v33);
    v3 = v32;
  }
  return KeSetEvent((int)a1, 0, 0);
}
