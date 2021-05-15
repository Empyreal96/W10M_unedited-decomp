// FsRtlOplockBreakToNoneEx 
 
int __fastcall FsRtlOplockBreakToNoneEx(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r10
  int v9; // r8
  int v10; // r0
  int v11; // r4
  int v12; // r5
  unsigned int v13; // r5
  unsigned int v14; // r10
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  unsigned int *v18; // r4
  unsigned int v19; // r1
  unsigned __int8 v21; // [sp+18h] [bp-30h] BYREF
  _BYTE v22[3]; // [sp+19h] [bp-2Fh] BYREF
  int v23; // [sp+1Ch] [bp-2Ch]
  int v24; // [sp+20h] [bp-28h]
  int v25; // [sp+24h] [bp-24h]

  v6 = a4;
  v25 = a4;
  v9 = *a1;
  v24 = *a1;
  v23 = 0;
  v10 = 0;
  v21 = 0;
  if ( (a3 & 0x10) != 0 )
  {
    v23 = -1073741811;
  }
  else
  {
    v11 = a6;
    v12 = a5;
    while ( 1 )
    {
      v22[0] = 0;
      if ( !v10 )
      {
        v13 = *(_DWORD *)(v9 + 76);
        v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v15 = KeAbPreAcquire(v13, 0, 0);
        v16 = v15;
        do
          v17 = __ldrex((unsigned __int8 *)v13);
        while ( __strex(v17 & 0xFE, (unsigned __int8 *)v13) );
        __dmb(0xBu);
        if ( (v17 & 1) == 0 )
          ExpAcquireFastMutexContended(v13, v15);
        if ( v16 )
          *(_BYTE *)(v16 + 14) |= 1u;
        *(_DWORD *)(v13 + 4) = v14;
        v21 = 1;
        v11 = a6;
        v12 = a5;
        v6 = v25;
      }
      v23 = FsRtlpOplockBreakToNone(v9, *(_DWORD *)(a2 + 96), a2, a3 | 8, v6, v12, v11, &v21, v22);
      if ( !v23 )
        v23 = FsRtlpOplockBreakByCacheFlags(v9, *(_DWORD *)(a2 + 96), a2, a3 | 8, 28672, v6, v12, v11, &v21, v22);
      if ( !v22[0] )
        break;
      v10 = v21;
    }
  }
  if ( v21 )
  {
    v18 = *(unsigned int **)(v24 + 76);
    v18[1] = 0;
    __dmb(0xBu);
    do
      v19 = __ldrex(v18);
    while ( !v19 && __strex(1u, v18) );
    if ( v19 )
      ExpReleaseFastMutexContended(v18, v19);
    KeAbPostRelease((unsigned int)v18);
  }
  return v23;
}
