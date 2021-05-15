// ObHandleRevocationBlockAddObject 
 
int __fastcall ObHandleRevocationBlockAddObject(_DWORD *a1, int a2)
{
  int v2; // r1
  int v4; // r8
  _DWORD *v5; // r4
  unsigned int *v6; // r5
  unsigned int v7; // r0
  unsigned int v8; // r1
  int v9; // r10
  unsigned int v10; // r2
  unsigned __int8 *v11; // r6
  int v12; // r0
  int v13; // r9
  unsigned int v14; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r1
  _DWORD *v17; // r2
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int v24; // r4
  unsigned int v25; // r1

  v2 = a2 - 24;
  v4 = 0;
  if ( (*(_BYTE *)(v2 + 14) & 0x40) != 0 )
    v5 = (_DWORD *)(v2 - ObpInfoMaskToOffset[*(_BYTE *)(v2 + 14) & 0x7F]);
  else
    v5 = 0;
  if ( !v5 )
    return -1073741637;
  v6 = a1 + 3;
  __pld(a1 + 3);
  v7 = a1[3] & 0xFFFFFFFE;
  do
    v8 = __ldrex(v6);
  while ( v8 == v7 && __strex(v7 + 2, v6) );
  __dmb(0xBu);
  if ( v8 == v7 )
    v9 = 1;
  else
    v9 = ExfAcquireRundownProtection(a1 + 3);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  v11 = (unsigned __int8 *)(a1 + 2);
  v12 = KeAbPreAcquire((unsigned int)(a1 + 2), 0, 0);
  v13 = v12;
  do
    v14 = __ldrex(v11);
  while ( __strex(v14 | 1, v11) );
  __dmb(0xBu);
  if ( (v14 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 2, v12, (unsigned int)(a1 + 2));
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  __dmb(0xBu);
  v15 = v5 + 2;
  do
    v16 = __ldrex(v15);
  while ( !v16 && __strex((unsigned int)a1, v15) );
  __dmb(0xBu);
  if ( v16 )
  {
    v4 = -1073741823;
  }
  else
  {
    v17 = (_DWORD *)a1[1];
    *v5 = a1;
    v5[1] = v17;
    if ( (_DWORD *)*v17 != a1 )
      __fastfail(3u);
    *v17 = v5;
    a1[1] = v5;
  }
  __pld(v11);
  v18 = *(_DWORD *)v11;
  v19 = *(_DWORD *)v11 - 16;
  if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
    v19 = 0;
  if ( (v18 & 2) != 0 )
    goto LABEL_33;
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)v11);
  while ( v20 == v18 && __strex(v19, (unsigned int *)v11) );
  if ( v20 != v18 )
LABEL_33:
    ExfReleasePushLock(a1 + 2, v18);
  v21 = KeAbPostRelease((unsigned int)(a1 + 2));
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v23 = *(_WORD *)(v22 + 0x134) + 1;
  *(_WORD *)(v22 + 308) = v23;
  if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
    KiCheckForKernelApcDelivery(v21);
  if ( v4 < 0 && v9 )
  {
    __pld(v6);
    v24 = *v6 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v25 = __ldrex(v6);
    while ( v25 == v24 && __strex(v24 - 2, v6) );
    if ( v25 != v24 )
      ExfReleaseRundownProtection((unsigned __int8 *)a1 + 12);
  }
  return v4;
}
