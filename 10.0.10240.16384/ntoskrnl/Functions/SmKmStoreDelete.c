// SmKmStoreDelete 
 
int __fastcall SmKmStoreDelete(int a1, unsigned int a2, char a3)
{
  _DWORD **v3; // r7
  unsigned __int8 *v4; // r6
  int v5; // r8
  unsigned int v7; // r9
  unsigned int v8; // r1
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r9
  int v13; // r4
  unsigned int *v14; // r0
  unsigned int v15; // r1
  unsigned int *v16; // r0
  unsigned int v17; // r1
  unsigned __int8 *v18; // r8
  unsigned int v19; // r2
  int v20; // r0
  int v21; // r4
  unsigned int v22; // r2
  int v23; // r3
  int v24; // r3
  unsigned int v25; // r1
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r1
  int v30; // r0
  __int16 v31; // r3
  unsigned int v32; // r1
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  int v37; // [sp+0h] [bp-20h]

  v37 = a2 & 0x1F;
  v3 = (_DWORD **)(a1 + 96 * v37);
  v4 = (unsigned __int8 *)(v3 + 23);
  v5 = a3;
  v7 = a2 >> 5;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire((unsigned int)(v3 + 23), 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v4);
  while ( __strex(v11 | 1, v4) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3 + 23, v9, (unsigned int)(v3 + 23));
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( v7 != ((_WORD)v3[3] & 0x7FF) )
    goto LABEL_61;
  v12 = (unsigned int)*v3;
  if ( !*v3 || v12 == -1 )
    goto LABEL_61;
  if ( !v5 )
    goto LABEL_14;
  if ( ((_WORD)v3[3] & 0x800) != 0 )
  {
LABEL_61:
    v13 = -1073741735;
LABEL_62:
    __dmb(0xBu);
    do
      v32 = __ldrex((unsigned int *)v4);
    while ( __strex(v32 - 1, (unsigned int *)v4) );
    if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v3 + 23);
    v33 = KeAbPostRelease((unsigned int)(v3 + 23));
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v35 = *(_WORD *)(v34 + 0x134) + 1;
    *(_WORD *)(v34 + 308) = v35;
    if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
      KiCheckForKernelApcDelivery(v33);
    return v13;
  }
  if ( ((_WORD)v3[3] & 0x1000) != 0 )
  {
    v13 = -1073741790;
    goto LABEL_62;
  }
LABEL_14:
  (*(void (__fastcall **)(int, _DWORD, int))(a1 + 3072))(a1, *v3, 7);
  v14 = (unsigned int *)(v3 + 1);
  do
    v15 = __ldrex(v14);
  while ( !v15 && __strex(1u, v14) );
  __dmb(0xBu);
  if ( v15 && v15 != 1 )
    ExfWaitForRundownProtectionRelease(v14, v15);
  if ( ((_WORD)v3[3] & 0x800) != 0 )
  {
    v16 = (unsigned int *)(v3 + 2);
    do
      v17 = __ldrex(v16);
    while ( !v17 && __strex(1u, v16) );
    __dmb(0xBu);
    if ( v17 )
    {
      if ( v17 != 1 )
        ExfWaitForRundownProtectionRelease(v16, v17);
    }
  }
  if ( (dword_636E9C & 0x10) != 0 )
  {
    SmKmEtwLogStoreStats((int *)&qword_636E90, *v3);
    SmKmEtwLogStoreChange((int *)&qword_636E90, (int)*v3, SmEventStoreDelete);
  }
  (*(void (__fastcall **)(int, unsigned int, int))(a1 + 3072))(a1, v12, 2);
  *v3 = 0;
  v18 = (unsigned __int8 *)(a1 + 3176);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v19 + 308);
  v20 = KeAbPreAcquire(a1 + 3176, 0, 0);
  v21 = v20;
  do
    v22 = __ldrex(v18);
  while ( __strex(v22 | 1, v18) );
  __dmb(0xBu);
  if ( (v22 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 3176), v20, a1 + 3176);
  if ( v21 )
    *(_BYTE *)(v21 + 14) |= 1u;
  if ( *(_DWORD *)(a1 + 3188) == v37 )
    *(_DWORD *)(a1 + 3188) = -1;
  if ( ((_WORD)v3[3] & 0x800) != 0 )
  {
    v23 = *(_DWORD *)(a1 + 3184) - 1;
    *(_DWORD *)(a1 + 3184) = v23;
    if ( !v23 )
    {
      SmWdStopMonitoring(a1 + 3080);
      (*(void (__fastcall **)(int, _DWORD, int))(a1 + 3072))(a1, 0, 3);
    }
  }
  v24 = *(_DWORD *)(a1 + 3180) - 1;
  *(_DWORD *)(a1 + 3180) = v24;
  if ( !v24 )
    (*(void (__fastcall **)(int, _DWORD, int))(a1 + 3072))(a1, 0, 4);
  __dmb(0xBu);
  do
    v25 = __ldrex((unsigned int *)v18);
  while ( __strex(v25 - 1, (unsigned int *)v18) );
  if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 3176));
  v26 = KeAbPostRelease(a1 + 3176);
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x134) + 1;
  *(_WORD *)(v27 + 308) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
    KiCheckForKernelApcDelivery(v26);
  __dmb(0xBu);
  do
    v29 = __ldrex((unsigned int *)v4);
  while ( __strex(v29 - 1, (unsigned int *)v4) );
  if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v4);
  KeAbPostRelease((unsigned int)v4);
  v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v31 = *(_WORD *)(v30 + 0x134) + 1;
  *(_WORD *)(v30 + 308) = v31;
  if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
    KiCheckForKernelApcDelivery(v30);
  (*(void (__fastcall **)(int, unsigned int, int))(a1 + 3072))(a1, v12, 1);
  return 0;
}
