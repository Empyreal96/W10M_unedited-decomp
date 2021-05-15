// FsRtlpWaitOnIrp 
 
int __fastcall FsRtlpWaitOnIrp(int a1, int a2, int a3, int a4, void (__fastcall *a5)(int, int), unsigned int a6, char a7, _BYTE *a8)
{
  _BYTE *v12; // r10
  int v13; // r0
  _DWORD *v14; // r4
  int v15; // r3
  unsigned int v16; // r6
  _DWORD *v17; // r9
  _DWORD *v18; // r2
  int v19; // r3
  unsigned int *v20; // r1
  unsigned int v21; // r0
  unsigned int *v22; // r8
  unsigned int v23; // r1
  int v24; // r0
  unsigned int v25; // r8
  int v26; // r5
  int v27; // r1
  int v28; // r0
  unsigned int v29; // r2
  _DWORD *i; // r0
  unsigned int *v31; // r4
  unsigned int v32; // r5
  unsigned int v33; // r1
  unsigned int *v34; // r4
  unsigned int v35; // r1
  char v37; // [sp+8h] [bp-30h]
  _BYTE v38[3]; // [sp+9h] [bp-2Fh] BYREF
  int v39; // [sp+Ch] [bp-2Ch]
  int v40; // [sp+10h] [bp-28h]
  int v41; // [sp+14h] [bp-24h]
  int varg_r0; // [sp+40h] [bp+8h]
  int varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v41 = a3;
  v40 = a1;
  varg_r0 = a1;
  v39 = -1073741670;
  v37 = 1;
  v12 = a8;
  if ( !a8 )
    v12 = v38;
  *v12 = 0;
  v13 = ExAllocatePoolWithTag(17, 32);
  v14 = (_DWORD *)v13;
  *(_DWORD *)(v13 + 8) = a2;
  if ( a2 )
    v15 = *(_DWORD *)(a2 + 28);
  else
    v15 = 0;
  *(_DWORD *)(v13 + 24) = v15;
  *(_BYTE *)(v13 + 28) = a7;
  if ( a4 )
  {
    *(_DWORD *)(v13 + 12) = a4;
    *(_DWORD *)(v13 + 16) = a3;
    v16 = a6;
  }
  else
  {
    *(_DWORD *)(v13 + 12) = FsRtlpOplockWaitCompleteRoutine;
    v16 = a6;
    *(_DWORD *)(v13 + 16) = a6;
    *(_BYTE *)a6 = 0;
    *(_BYTE *)(a6 + 1) = 0;
    *(_BYTE *)(a6 + 2) = 4;
    *(_DWORD *)(a6 + 4) = 0;
    *(_DWORD *)(a6 + 12) = a6 + 8;
    *(_DWORD *)(a6 + 8) = a6 + 8;
  }
  if ( a5 )
    a5(v41, a2);
  v17 = (_DWORD *)(a1 + 44);
  v18 = (_DWORD *)v17[1];
  *v14 = v17;
  v14[1] = v18;
  if ( (_DWORD *)*v18 != v17 )
    __fastfail(3u);
  *v18 = v14;
  v17[1] = v14;
  if ( a2 )
  {
    *(_DWORD *)(a2 + 24) = 0;
    *(_BYTE *)(a2 + 37) = KeAcquireQueuedSpinLock(7);
    *(_DWORD *)(a2 + 28) = v40;
    if ( *(_BYTE *)(a2 + 36) )
    {
      if ( a4 )
      {
        *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
        v19 = 259;
      }
      else
      {
        v19 = -1073741536;
      }
      v39 = v19;
      FsRtlpCancelWaitingIrp(a2, 1);
      goto LABEL_56;
    }
    __dmb(0xBu);
    v20 = (unsigned int *)(a2 + 56);
    do
      v21 = __ldrex(v20);
    while ( __strex((unsigned int)FsRtlpWaitingIrpCancelRoutine, v20) );
    __dmb(0xBu);
    KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
  }
  if ( a4 )
  {
    if ( a2 )
      *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
    v39 = 259;
  }
  else
  {
    v22 = *(unsigned int **)(v40 + 76);
    v22[1] = 0;
    __dmb(0xBu);
    do
      v23 = __ldrex(v22);
    while ( !v23 && __strex(1u, v22) );
    if ( v23 )
      ExpReleaseFastMutexContended(v22, v23);
    KeAbPostRelease((unsigned int)v22);
    v37 = 0;
    v24 = FsRtlCancellableWaitForSingleObject(v16, 0, a2);
    v39 = v24;
    if ( v24 == -1073741749 || v24 == -1073741536 )
    {
      if ( a2 )
      {
        IoCancelIrp(a2);
      }
      else
      {
        v25 = v40;
        v40 = *(_DWORD *)(v40 + 76);
        v26 = KeAbPreAcquire(v40, 0, 0);
        v27 = KfRaiseIrql(1);
        v41 = v27;
        v28 = v40;
        do
          v29 = __ldrex((unsigned __int8 *)v28);
        while ( __strex(v29 & 0xFE, (unsigned __int8 *)v28) );
        __dmb(0xBu);
        if ( (v29 & 1) == 0 )
        {
          ExpAcquireFastMutexContended(v28, v26);
          v28 = v40;
          v27 = v41;
        }
        if ( v26 )
          *(_BYTE *)(v26 + 14) |= 1u;
        *(_DWORD *)(v28 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v28 + 28) = v27;
        for ( i = *(_DWORD **)(v25 + 44); i != v17; i = (_DWORD *)*i )
        {
          if ( v14 == i )
          {
            FsRtlpRemoveAndCompleteWaitingIrp((int)i);
            break;
          }
        }
        v31 = *(unsigned int **)(v25 + 76);
        v31[1] = 0;
        v32 = v31[7];
        __dmb(0xBu);
        do
          v33 = __ldrex(v31);
        while ( !v33 && __strex(1u, v31) );
        if ( v33 )
          ExpReleaseFastMutexContended(v31, v33);
        KfLowerIrql((unsigned __int8)v32);
        KeAbPostRelease((unsigned int)v31);
        v37 = 0;
      }
      KeWaitForSingleObject(v16, 0, 0, 0, 0);
      *v12 = 0;
    }
    else
    {
      if ( a2 )
        v39 = *(_DWORD *)(a2 + 24);
      *v12 = 1;
    }
  }
LABEL_56:
  if ( v37 )
  {
    v34 = *(unsigned int **)(varg_r0 + 76);
    v34[1] = 0;
    __dmb(0xBu);
    do
      v35 = __ldrex(v34);
    while ( !v35 && __strex(1u, v34) );
    if ( v35 )
      ExpReleaseFastMutexContended(v34, v35);
    KeAbPostRelease((unsigned int)v34);
  }
  return v39;
}
