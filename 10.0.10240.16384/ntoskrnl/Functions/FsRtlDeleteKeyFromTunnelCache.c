// FsRtlDeleteKeyFromTunnelCache 
 
int __fastcall FsRtlDeleteKeyFromTunnelCache(int a1, int a2, int *a3, unsigned int a4)
{
  _DWORD *v5; // r5
  int v8; // r6
  int v9; // r9
  unsigned int v10; // r2
  int v11; // r3
  unsigned __int64 v12; // kr00_8
  _DWORD *v13; // r0
  __int64 v14; // r2
  _DWORD *v15; // r6
  int v16; // r5
  unsigned int v17; // r1
  int v19; // [sp+0h] [bp-28h] BYREF
  int *v20; // [sp+8h] [bp-20h] BYREF
  int **v21; // [sp+Ch] [bp-1Ch]

  v19 = a1;
  v20 = a3;
  v21 = (int **)a4;
  v5 = 0;
  LOBYTE(v19) = 1;
  if ( !TunnelMaxEntries )
    return v19;
  v21 = &v20;
  v20 = (int *)&v20;
  v8 = KeAbPreAcquire(a1, 0, 0);
  v9 = KfRaiseIrql(1);
  do
    v10 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    ExpAcquireFastMutexContended(a1, v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  *(_DWORD *)(a1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(a1 + 28) = v9;
  v11 = *(_DWORD *)(a1 + 32);
  while ( v11 )
  {
    v12 = *(_QWORD *)(v11 + 32);
    if ( HIDWORD(v12) < a4 )
      goto LABEL_13;
    if ( HIDWORD(v12) > a4 || (unsigned int)v12 > (unsigned int)a3 )
    {
LABEL_16:
      v11 = *(_DWORD *)(v11 + 4);
    }
    else
    {
      if ( v12 >= __PAIR64__(a4, (unsigned int)a3) )
      {
        v5 = (_DWORD *)v11;
        goto LABEL_16;
      }
LABEL_13:
      if ( v5 )
        goto LABEL_19;
      v11 = *(_DWORD *)(v11 + 8);
    }
  }
  if ( !v5 )
    goto LABEL_21;
  do
  {
LABEL_19:
    v13 = RtlRealSuccessor(v5);
    LODWORD(v14) = v5[9];
    HIDWORD(v14) = v5[8];
    v15 = v13;
    if ( v14 != __PAIR64__((unsigned int)a3, a4) )
      break;
    FsRtlRemoveNodeFromTunnel(a1, (unsigned int)v5, (unsigned int)&v20, &v19);
    v5 = v15;
  }
  while ( v15 );
LABEL_21:
  v16 = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 4) = 0;
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)a1);
  while ( !v17 && __strex(1u, (unsigned int *)a1) );
  if ( v17 )
    ExpReleaseFastMutexContended((unsigned int *)a1, v17);
  KfLowerIrql((unsigned __int8)v16);
  KeAbPostRelease(a1);
  FsRtlEmptyFreePoolList((int)&v20);
  return v19;
}
