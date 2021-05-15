// PiDmListAddObject 
 
int __fastcall PiDmListAddObject(int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v6; // r5
  int v7; // r0
  unsigned int v8; // r5
  int result; // r0
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r2
  int v17; // r0
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  unsigned int v23; // r1
  __int16 v24; // r3
  void *v25; // [sp+8h] [bp-20h]

  v25 = PiDmGetObjectManagerForObjectType(*(_DWORD *)(a2 + 20));
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire(a2, 0, 0);
  do
    v8 = __ldrex((unsigned __int8 *)a2);
  while ( __strex(v8 | 1, (unsigned __int8 *)a2) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_7C8E90(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  v11 = KeAbPreAcquire((unsigned int)a3, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(a3);
  while ( !v13 && __strex(0x11u, a3) );
  __dmb(0xBu);
  if ( v13 )
    ExfAcquirePushLockSharedEx(a3, v11, (unsigned int)a3);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  PiDmListAddObjectWorker(a1, v25, a2, a3);
  __pld(a3);
  v14 = *a3;
  if ( (*a3 & 0xFFFFFFF0) > 0x10 )
    v15 = v14 - 16;
  else
    v15 = 0;
  if ( (v14 & 2) != 0 )
    goto LABEL_35;
  __dmb(0xBu);
  do
    v16 = __ldrex(a3);
  while ( v16 == v14 && __strex(v15, a3) );
  if ( v16 != v14 )
LABEL_35:
    ExfReleasePushLock(a3, v14);
  v17 = KeAbPostRelease((unsigned int)a3);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = (__int16)(*(_WORD *)(v18 + 0x134) + 1);
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  __pld((void *)a2);
  v20 = *(_DWORD *)a2;
  if ( (*(_DWORD *)a2 & 0xFFFFFFF0) > 0x10 )
    v21 = v20 - 16;
  else
    v21 = 0;
  if ( (v20 & 2) != 0 )
    goto LABEL_33;
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)a2);
  while ( v22 == v20 && __strex(v21, (unsigned int *)a2) );
  if ( v22 != v20 )
LABEL_33:
    ExfReleasePushLock((_DWORD *)a2, v20);
  result = KeAbPostRelease(a2);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = *(_WORD *)(v23 + 0x134) + 1;
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
