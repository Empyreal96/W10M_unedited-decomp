// HvpMarkCellDirty 
 
int __fastcall HvpMarkCellDirty(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  unsigned int v9; // r10
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r4
  int v13; // r0
  int *v14; // r4
  int v15; // r4
  int v16; // r6
  unsigned int *v17; // r4
  unsigned int v18; // r1
  unsigned int *v20; // r4
  unsigned int v21; // r1
  int v22; // [sp+8h] [bp-28h] BYREF
  unsigned int v23; // [sp+Ch] [bp-24h]

  v5 = *(_DWORD *)(a1 + 92);
  v22 = -1;
  if ( (v5 & 1) != 0 || a2 < 0 )
    return 1;
  if ( !a3 )
  {
    v9 = *(_DWORD *)(a1 + 1868);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = KeAbPreAcquire(v9, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex((unsigned __int8 *)v9);
    while ( __strex(v12 & 0xFE, (unsigned __int8 *)v9) );
    __dmb(0xBu);
    if ( (v12 & 1) == 0 )
      ExpAcquireFastMutexContended(v9, v10);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    *(_DWORD *)(v9 + 4) = v23;
  }
  v13 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v22);
  if ( !v13 || (v14 = (int *)(v13 - 4), v13 == 4) )
  {
    if ( !a3 )
    {
      v20 = *(unsigned int **)(a1 + 1868);
      v20[1] = 0;
      __dmb(0xBu);
      do
        v21 = __ldrex(v20);
      while ( !v21 && __strex(1u, v20) );
      if ( v21 )
        ExpReleaseFastMutexContended(v20, v21);
      KeAbPostRelease((unsigned int)v20);
    }
  }
  else
  {
    if ( !HvpGetCellMap(a1, a2) )
      sub_804354();
    v15 = *v14;
    if ( v15 < 0 )
      v15 = -v15;
    HvpReleaseHCell(a1);
    v16 = HvpMarkDirty(a1, a2 - 4, v15, a4);
    if ( !a3 )
    {
      v17 = *(unsigned int **)(a1 + 1868);
      v17[1] = 0;
      __dmb(0xBu);
      do
        v18 = __ldrex(v17);
      while ( !v18 && __strex(1u, v17) );
      if ( v18 )
        ExpReleaseFastMutexContended(v17, v18);
      KeAbPostRelease((unsigned int)v17);
    }
    if ( v16 )
    {
      *(_BYTE *)(a1 + 73) = 1;
      return 1;
    }
  }
  return 0;
}
