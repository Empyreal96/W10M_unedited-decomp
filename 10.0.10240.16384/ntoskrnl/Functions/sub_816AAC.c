// sub_816AAC 
 
void __fastcall sub_816AAC(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r5
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r0

  if ( a5 )
    *(_DWORD *)(a5 + 36) = 1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = KeAbPreAcquire((unsigned int)&SepRmCapTableLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&SepRmCapTableLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&SepRmCapTableLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&SepRmCapTableLock, v6, (unsigned int)&SepRmCapTableLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = SepRmCapTable;
  __dmb(0xBu);
  SepRmCapTable = a5;
  __dmb(0xBu);
  __dmb(0xBu);
  SepRmEnforceCap = a5 != 0;
  __dmb(0xBu);
  if ( a5 && InitSafeBootMode == 1 )
  {
    v14 = SepRmCapTable;
    __dmb(0xBu);
    SepRmDereferenceCapTable(v14);
    __dmb(0xBu);
    SepRmCapTable = 0;
    *(_DWORD *)(*((_DWORD *)SepRmDefaultCap + 9) + 16) = SeDefaultRecoveryCapeSd;
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&SepRmCapTableLock);
  while ( __strex(v10 - 1, (unsigned int *)&SepRmCapTableLock) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&SepRmCapTableLock);
  v11 = KeAbPostRelease((unsigned int)&SepRmCapTableLock);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  if ( v9 )
    SepRmDereferenceCapTable(v9);
  JUMPOUT(0x816BDC);
}
