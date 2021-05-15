// ObpHandleRevocationBlockRemoveInsertedObject 
 
// local variable allocation has failed, the output may be wrong!
unsigned __int8 *__fastcall ObpHandleRevocationBlockRemoveInsertedObject(unsigned __int8 *result, int a2, unsigned int a3, int a4)
{
  unsigned __int8 *v7; // r6
  unsigned int *v8; // r9
  unsigned int v9; // r5
  unsigned int v10; // r5
  unsigned __int8 *v11; // r5
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r1 OVERLAPPED
  unsigned __int8 **v15; // r2 OVERLAPPED
  unsigned int *v16; // r4
  int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r2
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int v23; // r4
  unsigned int v24; // r1

  v7 = result;
  __dmb(0xBu);
  v8 = (unsigned int *)(result + 8);
  do
    v9 = __ldrex(v8);
  while ( v9 == a2 && __strex(2u, v8) );
  __dmb(0xBu);
  if ( v9 == a2 )
  {
    if ( !a4 )
    {
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v10 + 308);
      v11 = (unsigned __int8 *)(a2 + 8);
      v12 = KeAbPreAcquire(a2 + 8, 0, 0);
      do
        v13 = __ldrex(v11);
      while ( __strex(v13 | 1, v11) );
      __dmb(0xBu);
      if ( (v13 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v11, v12, (unsigned int)v11);
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
    }
    *(_QWORD *)&v14 = *(_QWORD *)v7;
    if ( *(unsigned __int8 **)(*(_DWORD *)v7 + 4) != v7 || *v15 != v7 )
      __fastfail(3u);
    *v15 = (unsigned __int8 *)v14;
    *(_DWORD *)(v14 + 4) = v15;
    if ( !a4 )
    {
      v16 = (unsigned int *)(a2 + 8);
      __pld((void *)(a2 + 8));
      v17 = *(_DWORD *)(a2 + 8);
      v18 = v17 - 16;
      if ( (v17 & 0xFFFFFFF0) <= 0x10 )
        v18 = 0;
      if ( (v17 & 2) != 0 )
        goto LABEL_22;
      __dmb(0xBu);
      do
        v19 = __ldrex(v16);
      while ( v19 == v17 && __strex(v18, v16) );
      if ( v19 != v17 )
LABEL_22:
        ExfReleasePushLock((_DWORD *)(a2 + 8), v17);
      v20 = KeAbPostRelease(a2 + 8);
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v22 = *(_WORD *)(v21 + 0x134) + 1;
      *(_WORD *)(v21 + 308) = v22;
      if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
        KiCheckForKernelApcDelivery(v20);
    }
    result = (unsigned __int8 *)(a2 + 12);
    __pld((void *)(a2 + 12));
    v23 = *(_DWORD *)(a2 + 12) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v24 = __ldrex((unsigned int *)result);
    while ( v24 == v23 && __strex(v23 - 2, (unsigned int *)result) );
    if ( v24 != v23 )
      result = ExfReleaseRundownProtection(result);
    *v8 = a3;
  }
  return result;
}
