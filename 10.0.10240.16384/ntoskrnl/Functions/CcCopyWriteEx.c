// CcCopyWriteEx 
 
int __fastcall CcCopyWriteEx(_DWORD *a1, __int64 *a2, unsigned int a3, int a4, int a5, int a6)
{
  _DWORD *v8; // r6
  int v9; // r0
  __int64 v10; // kr00_8
  int v11; // r10
  int v12; // r3
  int v13; // r7
  int v15; // r6
  int v16; // r1
  unsigned __int8 *v17; // r0
  unsigned int v18; // r2
  int v19; // r1
  unsigned int *v20; // r6
  unsigned int v21; // r7
  int v22; // r3
  unsigned int v23; // r1
  signed __int64 v24; // kr08_8
  unsigned __int8 *v25; // [sp+18h] [bp-40h]
  int v26; // [sp+18h] [bp-40h]
  int v27; // [sp+1Ch] [bp-3Ch]
  int v28; // [sp+1Ch] [bp-3Ch]
  int v29; // [sp+20h] [bp-38h]
  int v31[2]; // [sp+28h] [bp-30h] BYREF
  __int64 v32[5]; // [sp+30h] [bp-28h] BYREF

  v8 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v9 = (v8[240] >> 9) & 7;
  if ( (*(_DWORD *)(v8[84] + 192) & 0x100000) != 0 )
  {
    v9 = 0;
  }
  else if ( ((v8[240] >> 9) & 7u) >= 2 )
  {
    goto LABEL_3;
  }
  if ( v8 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v8[250] )
  {
LABEL_4:
    if ( (a1[11] & 0x10) == 0 )
      goto LABEL_5;
    goto LABEL_30;
  }
LABEL_3:
  if ( v9 > 0 )
    goto LABEL_4;
LABEL_30:
  if ( !a4 )
    return 0;
LABEL_5:
  v10 = *a2;
  v11 = 2;
  v12 = *a2 & 0xFFF;
  v29 = *(_DWORD *)(a1[5] + 4);
  v32[0] = *a2;
  if ( !v12 && a3 >= 0x1000 )
    v11 = 3;
  if ( (((_WORD)v10 + (_WORD)a3) & 0xFFF) == 0 )
    v11 |= 4u;
  v13 = a1[3];
  v31[0] = v10;
  if ( (*(_BYTE *)(v13 + 4) & 0x40) == 0 )
    return sub_53D468();
  v25 = *(unsigned __int8 **)(v13 + 40);
  v15 = KeAbPreAcquire((unsigned int)v25, 0, 0);
  v16 = KfRaiseIrql(1);
  v27 = v16;
  v17 = v25;
  do
    v18 = __ldrex(v25);
  while ( __strex(v18 & 0xFE, v25) );
  __dmb(0xBu);
  if ( (v18 & 1) == 0 )
  {
    ExpAcquireFastMutexContended(v25, v15);
    v17 = v25;
    v16 = v27;
  }
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  *((_DWORD *)v17 + 1) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *((_DWORD *)v17 + 7) = v16;
  v19 = a1[3];
  v20 = *(unsigned int **)(v13 + 40);
  v21 = v20[7];
  v28 = *(_DWORD *)(v19 + 32);
  v31[0] = v28;
  v22 = *(_DWORD *)(v19 + 36);
  v20[1] = 0;
  v26 = v22;
  v31[1] = v22;
  __dmb(0xBu);
  do
    v23 = __ldrex(v20);
  while ( !v23 && __strex(1u, v20) );
  if ( v23 )
    ExpReleaseFastMutexContended(v20, v23);
  KfLowerIrql((unsigned __int8)v21);
  KeAbPostRelease((unsigned int)v20);
  v24 = __PAIR64__(v26, v28) - v10;
  if ( (int)((__PAIR64__(v26, v28) - v10) >> 32) <= 0 )
  {
    if ( v24 >= 0 && (_DWORD)v24 )
    {
      if ( (unsigned int)v24 <= 0x1000 && !HIDWORD(v24) )
        v11 |= 6u;
    }
    else
    {
      v11 = 7;
    }
  }
  return CcMapAndCopyInToCache(v29, a5, v32, a3, v11, a1, v31, a4, a6);
}
