// FsRtlpOpBatchBreakClosePending 
 
int __fastcall FsRtlpOpBatchBreakClosePending(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r5
  unsigned int v8; // r9
  int v9; // r0
  int v10; // r8
  unsigned int v11; // r2
  int v12; // r2
  unsigned int *v13; // r4
  unsigned int v14; // r1
  int v16; // [sp+0h] [bp-28h]
  int v17; // [sp+4h] [bp-24h]
  unsigned int v18; // [sp+4h] [bp-24h]
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v6 = a1;
  v7 = 0;
  v16 = 0;
  if ( a1 )
  {
    v8 = *(_DWORD *)(a1 + 76);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = KeAbPreAcquire(v8, 0, 0);
    v10 = v9;
    do
      v11 = __ldrex((unsigned __int8 *)v8);
    while ( __strex(v11 & 0xFE, (unsigned __int8 *)v8) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
      ExpAcquireFastMutexContended(v8, v9);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    *(_DWORD *)(v8 + 4) = v18;
    if ( *(_DWORD *)(v6 + 4) == *(_DWORD *)(a2 + 28) && (v12 = *(_DWORD *)(v6 + 72), (v12 & 0x700) != 0) )
    {
      if ( (v12 & 0x82) != 0 )
      {
        FsRtlpModifyThreadPriorities((_DWORD *)v6, 0, 0);
        FsRtlpClearOwnerThread(v6, 0);
        *(_BYTE *)(v6 + 16) = 0;
        if ( (*(_DWORD *)(v6 + 72) & 2) != 0 )
          ObfDereferenceObject(*(_DWORD *)(v6 + 4));
        *(_DWORD *)(v6 + 72) = *(_DWORD *)(v6 + 72) & 0x20 | 1;
        *(_DWORD *)(v6 + 4) = 0;
        while ( *(_DWORD *)(v6 + 44) != v6 + 44 )
          FsRtlpRemoveAndCompleteWaitingIrp(*(_DWORD *)(v6 + 44));
      }
      else
      {
        *(_DWORD *)(v6 + 72) = v12 & 0xFE0FF0FF;
        *(_DWORD *)(v6 + 72) = v12 & 0xFE0FF0FF | 0x800;
      }
    }
    else
    {
      v7 = -1073741597;
      v16 = -1073741597;
    }
    *(_DWORD *)(a3 + 24) = v7;
    IofCompleteRequest(a3, 1);
    v13 = *(unsigned int **)(a1 + 76);
    v13[1] = 0;
    __dmb(0xBu);
    do
      v14 = __ldrex(v13);
    while ( !v14 && __strex(1u, v13) );
    if ( v14 )
      ExpReleaseFastMutexContended(v13, v14);
    KeAbPostRelease((unsigned int)v13);
    v17 = v16;
  }
  else
  {
    *(_DWORD *)(a3 + 24) = -1073741597;
    IofCompleteRequest(a3, 1);
    v17 = -1073741597;
  }
  return v17;
}
