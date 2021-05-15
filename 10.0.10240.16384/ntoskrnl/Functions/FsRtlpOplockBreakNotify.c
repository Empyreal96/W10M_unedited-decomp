// FsRtlpOplockBreakNotify 
 
int __fastcall FsRtlpOplockBreakNotify(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r6
  unsigned int v7; // r8
  unsigned int v8; // r9
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int *v15; // r4
  unsigned int v16; // r1
  char v18; // [sp+10h] [bp-28h]
  int v19; // [sp+14h] [bp-24h]
  int varg_r2; // [sp+48h] [bp+10h]

  varg_r2 = a3;
  v5 = a1;
  if ( !a1 )
  {
    *(_DWORD *)(a3 + 24) = 0;
    IofCompleteRequest(a3, 1);
    return 0;
  }
  v7 = a1[19];
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = KeAbPreAcquire(v7, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)v7);
  while ( __strex(v11 & 0xFE, (unsigned __int8 *)v7) );
  __dmb(0xBu);
  if ( (v11 & 1) == 0 )
    ExpAcquireFastMutexContended(v7, v9);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  *(_DWORD *)(v7 + 4) = v8;
  v18 = 1;
  v12 = v5[18];
  if ( (v12 & 0x1F00F00) != 0 || (_DWORD *)v5[9] != v5 + 9 || (v12 & 0x20000) != 0 )
  {
    if ( (v12 & 0x80) == 0 )
    {
      v18 = 0;
      *(_DWORD *)(a3 + 24) = 0;
      FsRtlpModifyThreadPriorities(v5, 0, 1);
      FsRtlpOplockSendModernAppTermination((int)v5, 0, v13, v14);
      v19 = FsRtlpWaitOnIrp((int)v5, a3, 0, (int)FsRtlpNotifyOplockBreakComplete, 0, 0, 0, 0);
      goto LABEL_16;
    }
    v5[18] = v5[18] & 0x20 | 1;
    v5[1] = 0;
  }
  *(_DWORD *)(a3 + 24) = 0;
  IofCompleteRequest(a3, 1);
  v19 = 0;
LABEL_16:
  if ( v18 )
  {
    v15 = (unsigned int *)a1[19];
    v15[1] = 0;
    __dmb(0xBu);
    do
      v16 = __ldrex(v15);
    while ( !v16 && __strex(1u, v15) );
    if ( v16 )
      ExpReleaseFastMutexContended(v15, v16);
    KeAbPostRelease((unsigned int)v15);
  }
  return v19;
}
