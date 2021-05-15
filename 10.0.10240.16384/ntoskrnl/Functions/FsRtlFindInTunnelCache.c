// FsRtlFindInTunnelCache 
 
int __fastcall FsRtlFindInTunnelCache(int a1, int a2, int a3, int a4, int a5, unsigned __int16 *a6, int a7, _DWORD *a8, int a9)
{
  int v12; // r5
  unsigned __int8 v13; // r3
  int v14; // r6
  int v15; // r10
  unsigned int v16; // r2
  int v17; // r4
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r0
  __int16 v21; // r3
  unsigned int *v22; // r4
  unsigned int v23; // r5
  unsigned int v24; // r1
  char v26; // [sp+8h] [bp-30h]
  _DWORD _10[11]; // [sp+10h] [bp-28h] BYREF
  unsigned int *varg_r0; // [sp+40h] [bp+8h]
  int varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r0 = (unsigned int *)a1;
  v12 = 0;
  v13 = 0;
  v26 = 0;
  if ( TunnelMaxEntries )
  {
    _10[1] = _10;
    _10[0] = _10;
    v14 = KeAbPreAcquire(a1, 0, 0);
    v15 = KfRaiseIrql(1);
    do
      v16 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v16 & 0xFE, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( (v16 & 1) == 0 )
      ExpAcquireFastMutexContended(a1, v14);
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    *(_DWORD *)(a1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a1 + 28) = v15;
    FsRtlPruneTunnelCache(a1, _10);
    v17 = *(_DWORD *)(a1 + 32);
    while ( v17 )
    {
      v12 = v17;
      v18 = FsRtlCompareNodeAndKey(v17, __PAIR64__(a4, a3), a5);
      if ( v18 <= 0 )
      {
        if ( v18 >= 0 )
          break;
        v17 = *(_DWORD *)(v17 + 8);
      }
      else
      {
        v17 = *(_DWORD *)(v17 + 4);
      }
    }
    if ( v17 )
    {
      RtlCopyUnicodeString(a6, (unsigned __int16 *)(v12 + 52));
      v19 = *(unsigned __int16 *)(v12 + 44);
      if ( *(unsigned __int16 *)(a7 + 2) < v19 )
      {
        v20 = ExAllocatePoolWithTag(17, v19, 879654228);
        *(_DWORD *)(a7 + 4) = v20;
        v21 = *(_WORD *)(v12 + 44);
        *(_WORD *)(a7 + 2) = v21;
        *(_WORD *)a7 = v21;
        memmove(v20, *(_DWORD *)(v12 + 48), *(unsigned __int16 *)(v12 + 44));
      }
      else
      {
        RtlCopyUnicodeString((unsigned __int16 *)a7, (unsigned __int16 *)(v12 + 44));
      }
      memmove(a9, *(_DWORD *)(v12 + 60), *(_DWORD *)(v12 + 64));
      *a8 = *(_DWORD *)(v12 + 64);
      v26 = 1;
    }
    v22 = varg_r0;
    varg_r0[1] = 0;
    v23 = v22[7];
    __dmb(0xBu);
    do
      v24 = __ldrex(v22);
    while ( !v24 && __strex(1u, v22) );
    if ( v24 )
      ExpReleaseFastMutexContended(v22, v24);
    KfLowerIrql((unsigned __int8)v23);
    KeAbPostRelease((unsigned int)v22);
    FsRtlEmptyFreePoolList((int)_10);
    v13 = v26;
  }
  return v13;
}
