// PiDmListRemoveObject 
 
int __fastcall PiDmListRemoveObject(int a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int v8; // r5
  int v9; // r0
  int v10; // r8
  unsigned int v11; // r5
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r2
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int result; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  void *v28; // [sp+8h] [bp-20h]

  v28 = PiDmGetObjectManagerForObjectType(*(_DWORD *)(a2 + 20));
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire(a2, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)a2);
  while ( __strex(v11 | 1, (unsigned __int8 *)a2) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a2, v9, a2);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = KeAbPreAcquire((unsigned int)a3, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex(a3);
  while ( !v15 && __strex(0x11u, a3) );
  __dmb(0xBu);
  if ( v15 )
    ExfAcquirePushLockSharedEx(a3, v13, (unsigned int)a3);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  PiDmListRemoveObjectWorker(a1, v28, a2, a3, a4);
  __pld(a3);
  v16 = *a3;
  v17 = *a3 - 16;
  if ( (*a3 & 0xFFFFFFF0) <= 0x10 )
    v17 = 0;
  if ( (v16 & 2) != 0 )
    goto LABEL_21;
  __dmb(0xBu);
  do
    v18 = __ldrex(a3);
  while ( v18 == v16 && __strex(v17, a3) );
  if ( v18 != v16 )
LABEL_21:
    ExfReleasePushLock(a3, v16);
  v19 = KeAbPostRelease((unsigned int)a3);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  __pld((void *)a2);
  v22 = *(_DWORD *)a2;
  v23 = *(_DWORD *)a2 - 16;
  if ( (*(_DWORD *)a2 & 0xFFFFFFF0) <= 0x10 )
    v23 = 0;
  if ( (v22 & 2) != 0 )
    goto LABEL_33;
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned int *)a2);
  while ( v24 == v22 && __strex(v23, (unsigned int *)a2) );
  if ( v24 != v22 )
LABEL_33:
    ExfReleasePushLock((_DWORD *)a2, v22);
  result = KeAbPostRelease(a2);
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = *(_WORD *)(v26 + 0x134) + 1;
  *(_WORD *)(v26 + 308) = v27;
  if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
