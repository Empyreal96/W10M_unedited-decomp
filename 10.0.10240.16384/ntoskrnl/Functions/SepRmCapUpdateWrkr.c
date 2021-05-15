// SepRmCapUpdateWrkr 
 
int __fastcall SepRmCapUpdateWrkr(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v6; // r7
  int result; // r0
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15[6]; // [sp+0h] [bp-18h] BYREF

  v15[0] = a4;
  v4 = *(_DWORD *)(a1 + 28);
  v15[0] = 0;
  v6 = SepBuildCapPolicyTable(v4, v15);
  if ( v6 >= 0 )
    return sub_816AAC();
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire((unsigned int)&SepRmCapTableLock, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)&SepRmCapTableLock);
  while ( __strex(v11 | 1, (unsigned __int8 *)&SepRmCapTableLock) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&SepRmCapTableLock, v9, (unsigned int)&SepRmCapTableLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  __dmb(0xBu);
  SepRmEnforceCap = 1;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&SepRmCapTableLock);
  while ( __strex(v12 - 1, (unsigned int *)&SepRmCapTableLock) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&SepRmCapTableLock);
  result = KeAbPostRelease((unsigned int)&SepRmCapTableLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  *(_DWORD *)(a2 + 24) = v6;
  return result;
}
