// CcDereferenceFileOffset 
 
unsigned int __fastcall CcDereferenceFileOffset(unsigned int result, int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // r7
  unsigned __int8 *v5; // r5
  int v6; // r4
  int v7; // r6
  unsigned int v8; // r2
  unsigned __int8 *v9; // r4
  int v10; // r0
  int v11; // r1
  int v12; // r6
  unsigned int v13; // r2
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r4
  unsigned int v18; // r1
  unsigned int varg_r0; // [sp+28h] [bp+8h]

  varg_r0 = result;
  v4 = (_DWORD *)result;
  if ( *(__int64 *)(result + 24) > 0x2000000 )
  {
    v5 = (unsigned __int8 *)(result + 180);
    v6 = KeAbPreAcquire(result + 180, 0, 0);
    v7 = KfRaiseIrql(1);
    do
      v8 = __ldrex(v5);
    while ( __strex(v8 & 0xFE, v5) );
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      ExpAcquireFastMutexContended((int)(v4 + 45), v6);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    v9 = (unsigned __int8 *)(v4 + 18);
    v4[46] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4[52] = v7;
    v10 = KeAbPreAcquire((unsigned int)(v4 + 18), 0, 0);
    v12 = v10;
    do
      v13 = __ldrex(v9);
    while ( __strex(v13 | 1, v9) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4 + 18, v10, (unsigned int)(v4 + 18));
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    SetVacb((int)v4, v11, a3, a4, 0xFFFFFFFE);
    __pld(v9);
    v14 = *(_DWORD *)v9;
    v15 = *(_DWORD *)v9 - 16;
    if ( (*(_DWORD *)v9 & 0xFFFFFFF0) <= 0x10 )
      v15 = 0;
    if ( (v14 & 2) != 0 )
      goto LABEL_21;
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)v9);
    while ( v16 == v14 && __strex(v15, (unsigned int *)v9) );
    if ( v16 != v14 )
LABEL_21:
      ExfReleasePushLock(v4 + 18, v14);
    KeAbPostRelease((unsigned int)(v4 + 18));
    v17 = v4[52];
    v4[46] = 0;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v5);
    while ( !v18 && __strex(1u, (unsigned int *)v5) );
    if ( v18 )
      ExpReleaseFastMutexContended(v4 + 45, v18);
    KfLowerIrql((unsigned __int8)v17);
    result = KeAbPostRelease((unsigned int)(v4 + 45));
  }
  return result;
}
