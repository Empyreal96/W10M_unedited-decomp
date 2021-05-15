// SepSqmInformation 
 
int __fastcall SepSqmInformation(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r6
  unsigned int v5; // r2
  unsigned int v6; // r1
  int result; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3

  if ( qword_6534E8 )
    return SepSetSqmObjectName(qword_6534E8, SHIDWORD(qword_6534E8), a1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&dword_6534F0, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&dword_6534F0);
  while ( __strex(v5 | 1, (unsigned __int8 *)&dword_6534F0) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_6534F0, v3, (unsigned int)&dword_6534F0);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( qword_6534E8 || EtwRegister((int)dword_41CF28, 0, 0) >= 0 )
  {
    __dmb(0xBu);
    do
      v10 = __ldrex(&dword_6534F0);
    while ( __strex(v10 - 1, &dword_6534F0) );
    if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
      ExfTryToWakePushLock(&dword_6534F0);
    v11 = KeAbPostRelease((unsigned int)&dword_6534F0);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      KiCheckForKernelApcDelivery(v11);
    return SepSetSqmObjectName(qword_6534E8, SHIDWORD(qword_6534E8), a1);
  }
  __dmb(0xBu);
  do
    v6 = __ldrex(&dword_6534F0);
  while ( __strex(v6 - 1, &dword_6534F0) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock(&dword_6534F0);
  result = KeAbPostRelease((unsigned int)&dword_6534F0);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
