// FsRtlpOplockStoreKeyForDeleteOperation 
 
int __fastcall FsRtlpOplockStoreKeyForDeleteOperation(int result, int a2, int a3, int a4)
{
  int v4; // r8
  int *v5; // r9
  int v6; // r5
  int v7; // r6
  int v8; // r4
  int v9; // r8
  unsigned int v10; // r9
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  int *v14; // r5
  int *v15; // r4
  int v16; // r1
  int v17; // r2
  int v18; // r3
  unsigned int *v19; // r4
  unsigned int v20; // r1
  char v21; // [sp+0h] [bp-28h]
  int v22; // [sp+4h] [bp-24h]
  int varg_r0; // [sp+30h] [bp+8h]

  varg_r0 = result;
  v4 = a3;
  v5 = (int *)result;
  v6 = *(_DWORD *)(a2 + 96);
  v7 = *(_DWORD *)result;
  v22 = *(_DWORD *)result;
  v21 = 0;
  if ( !*(_BYTE *)v6 && (*(_DWORD *)(v6 + 12) & 0x1000) != 0
    || *(_BYTE *)v6 == 6 && *(_DWORD *)(v6 + 12) == 13 && **(_BYTE **)(a2 + 12) )
  {
    result = IoGetOplockKeyContextEx(*(_DWORD *)(v6 + 28));
    v8 = result;
    if ( result )
    {
      if ( (*(_WORD *)(result + 2) & 1) != 0 )
      {
        if ( !v7 )
        {
          v7 = FsRtlpAllocateOplock();
          v22 = v7;
          *v5 = v7;
        }
        if ( (v4 & 0x20000000) == 0 )
        {
          v9 = *(_DWORD *)(v7 + 76);
          v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v11 = KeAbPreAcquire(v9, 0, 0);
          v12 = v11;
          do
            v13 = __ldrex((unsigned __int8 *)v9);
          while ( __strex(v13 & 0xFE, (unsigned __int8 *)v9) );
          __dmb(0xBu);
          if ( (v13 & 1) == 0 )
            ExpAcquireFastMutexContended(v9, v11);
          if ( v12 )
            *(_BYTE *)(v12 + 14) |= 1u;
          *(_DWORD *)(v9 + 4) = v10;
        }
        v21 = 1;
        if ( !*(_DWORD *)(v7 + 68) )
          *(_DWORD *)(v7 + 68) = ExAllocatePoolWithTag(273, 16, 1869763398);
        v14 = *(int **)(v7 + 68);
        v15 = (int *)(v8 + 4);
        result = *v15;
        v16 = v15[1];
        v17 = v15[2];
        v18 = v15[3];
        *v14 = *v15;
        v14[1] = v16;
        v14[2] = v17;
        v14[3] = v18;
      }
    }
  }
  if ( v21 && (a3 & 0x20000000) == 0 )
  {
    v19 = *(unsigned int **)(v22 + 76);
    v19[1] = 0;
    __dmb(0xBu);
    do
      v20 = __ldrex(v19);
    while ( !v20 && __strex(1u, v19) );
    if ( v20 )
      ExpReleaseFastMutexContended(v19, v20);
    result = KeAbPostRelease(v19);
  }
  return result;
}
