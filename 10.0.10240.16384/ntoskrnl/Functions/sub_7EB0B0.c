// sub_7EB0B0 
 
void __fastcall sub_7EB0B0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r7
  int v6; // r9
  int v7; // r8
  unsigned int v8; // r2
  _DWORD *v9; // r6
  unsigned __int8 *v10; // r4
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r2
  int v14; // r2
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3

  v7 = *(_DWORD *)(*(_DWORD *)(v6 - 24 - ObpInfoMaskToOffset[*(_BYTE *)(v6 - 10) & 3]) + 152);
  if ( v7 )
  {
    PsGetMonitorContextServerSilo(ObSiloMonitor, -1, &a5);
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 310);
    v9 = (_DWORD *)a5;
    v10 = (unsigned __int8 *)(a5 + 112);
    v11 = KeAbPreAcquire(a5 + 112, 0, 0);
    v12 = v11;
    do
      v13 = __ldrex(v10);
    while ( __strex(v13 | 1, v10) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v10, v11, (unsigned int)v10);
    if ( v12 )
      *(_BYTE *)(v12 + 14) |= 1u;
    v14 = 1 << (v5 - 1);
    *(_DWORD *)(v7 + 16) &= ~v14;
    *(_BYTE *)(v7 + v5 + 19) = 0;
    if ( v7 == *v9 )
      v9[1] &= ~v14;
    else
      --v9[v5 + 1];
    __pld(v10);
    v15 = *(_DWORD *)v10;
    if ( (*(_DWORD *)v10 & 0xFFFFFFF0) <= 0x10 )
      v16 = 0;
    else
      v16 = v15 - 16;
    if ( (v15 & 2) != 0 )
      goto LABEL_19;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)v10);
    while ( v17 == v15 && __strex(v16, (unsigned int *)v10) );
    if ( v17 != v15 )
LABEL_19:
      ExfReleasePushLock(v10, v15);
    v18 = KeAbPostRelease((unsigned int)v10);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x136) + 1;
    *(_WORD *)(v19 + 310) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
      KiCheckForKernelApcDelivery(v18);
    PsDereferenceMonitorContextServerSilo((int)v9);
  }
  *(_DWORD *)(v6 + 16) = 0;
  JUMPOUT(0x707B4A);
}
