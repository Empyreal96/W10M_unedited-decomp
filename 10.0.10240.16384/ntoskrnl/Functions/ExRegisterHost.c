// ExRegisterHost 
 
int __fastcall ExRegisterHost(void ***a1, int a2, unsigned __int16 *a3)
{
  int v5; // r0
  void **v6; // r6
  int v7; // r5
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  char v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r3
  unsigned int *v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r2
  int v21; // r0
  unsigned int v22; // r2
  int v23; // r7
  void ***v24; // r1

  v5 = ExAllocatePoolWithTag(*((_DWORD *)a3 + 2), 52, 1212512325);
  v6 = (void **)v5;
  if ( !v5 )
    return -1073741670;
  __dmb(0xBu);
  *(_DWORD *)(v5 + 8) = 1;
  v13 = *(_BYTE *)(v5 + 48);
  *(_DWORD *)(v5 + 44) = 0;
  *(_BYTE *)(v5 + 48) = v13 & 0xFE;
  v14 = *((_DWORD *)a3 + 1);
  v15 = *((_DWORD *)a3 + 2);
  v16 = *((_DWORD *)a3 + 3);
  *(_DWORD *)(v5 + 12) = *(_DWORD *)a3;
  *(_DWORD *)(v5 + 16) = v14;
  *(_DWORD *)(v5 + 20) = v15;
  *(_DWORD *)(v5 + 24) = v16;
  v17 = *((_DWORD *)a3 + 5);
  *(_DWORD *)(v5 + 28) = *((_DWORD *)a3 + 4);
  *(_DWORD *)(v5 + 32) = v17;
  *(_DWORD *)(v5 + 36) = 0;
  *(_DWORD *)(v5 + 40) = 0;
  v18 = (unsigned int *)(v5 + 36);
  do
    v19 = __ldrex(v18);
  while ( !v19 && __strex(1u, v18) );
  __dmb(0xBu);
  if ( v19 != 1 && v19 )
    ExfWaitForRundownProtectionRelease(v18, v19);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v20 + 308);
  v21 = KeAbPreAcquire((unsigned int)&ExpHostListLock, 0, 0);
  do
    v22 = __ldrex((unsigned __int8 *)&ExpHostListLock);
  while ( __strex(v22 | 1, (unsigned __int8 *)&ExpHostListLock) );
  __dmb(0xBu);
  if ( (v22 & 1) == 0 )
  {
    if ( v21 )
      *(_BYTE *)(v21 + 14) |= 1u;
    v23 = ExpFindHost(*a3, a3[1]);
    if ( v23 )
    {
      v7 = -1073741771;
      ExpDereferenceHost(v6);
      ExpDereferenceHost(v23);
    }
    else
    {
      v24 = (void ***)off_9203A8;
      *v6 = &ExpHostList;
      v6[1] = v24;
      v7 = 0;
      if ( *v24 != &ExpHostList )
        __fastfail(3u);
      *v24 = v6;
      off_9203A8 = v6;
      *a1 = v6;
    }
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)&ExpHostListLock);
    while ( __strex(v8 - 1, (unsigned int *)&ExpHostListLock) );
    if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&ExpHostListLock);
    v9 = KeAbPostRelease((unsigned int)&ExpHostListLock);
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(v9);
    return v7;
  }
  return sub_811370(v21);
}
