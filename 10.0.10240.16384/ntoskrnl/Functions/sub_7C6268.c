// sub_7C6268 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7C6268(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v12; // r3
  BOOL v13; // r5
  int v14; // r1
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3
  _DWORD *v19; // r4
  int v20; // r5
  int v21; // r6
  int v22; // r7
  int v23; // r8
  unsigned int v24; // r0

  ExfAcquirePushLockExclusiveEx(v19, v20, (unsigned int)v19);
  if ( v20 )
    *(_BYTE *)(v20 + 14) |= v23;
  v12 = v19[6];
  v13 = (v12 & v23) != 0;
  __pld(v19);
  v19[6] = v12 | v23;
  v14 = *v19;
  if ( (*v19 & 0xFFFFFFF0) > 0x10 )
    v24 = v14 - 16;
  else
    v24 = 0;
  if ( (v14 & 2) != 0 )
    goto LABEL_3;
  __dmb(0xBu);
  do
    v15 = __ldrex(v19);
  while ( v15 == v14 && __strex(v24, v19) );
  if ( v15 != v14 )
LABEL_3:
    ExfReleasePushLock(v19, v14);
  v16 = KeAbPostRelease((unsigned int)v19);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  if ( v13 )
    PiDmRemoveCacheReferenceForObject(v21, v22);
  PiDmObjectRelease((int)v19);
  __asm { POP.W           {R4-R9,R11,PC} }
}
