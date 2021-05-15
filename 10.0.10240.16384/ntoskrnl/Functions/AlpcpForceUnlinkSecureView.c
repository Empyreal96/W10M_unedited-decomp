// AlpcpForceUnlinkSecureView 
 
int __fastcall AlpcpForceUnlinkSecureView(int a1)
{
  int v1; // r4
  int v2; // r7
  int v3; // r9
  unsigned __int8 *v4; // r8
  int v5; // r0
  int v6; // r6
  unsigned int v7; // r2
  unsigned int *v8; // r1
  unsigned int v9; // r2
  int v10; // r2
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  char v15; // r2
  int v16; // r8
  int v17; // r3
  unsigned int *v18; // r6
  unsigned int v19; // r1
  int result; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r1
  int v25; // r1
  char v26[56]; // [sp+8h] [bp-38h] BYREF

  v1 = a1;
  v2 = *(_DWORD *)(a1 + 8);
  v3 = *(_DWORD *)(a1 + 16);
  v4 = (unsigned __int8 *)(v2 - 4);
  v5 = KeAbPreAcquire(v2 - 4, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(v4);
  while ( __strex(v7 | 1, v4) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 - 4), v5, v2 - 4);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  *(_BYTE *)(v2 - 16) |= 1u;
  __dmb(0xBu);
  v8 = (unsigned int *)(v2 - 12);
  do
  {
    v9 = __ldrex(v8);
    v10 = v9 + 0x10000;
  }
  while ( __strex(v10, v8) );
  __dmb(0xBu);
  if ( v10 <= 0 )
    KeBugCheckEx(24, 0, v2, 38, v10);
  if ( v1 == *(_DWORD *)(v2 + 40) )
  {
    KiStackAttachProcess(v3, 0, (int)v26);
    MmUnsecureVirtualMemory(*(_DWORD **)(v1 + 32), v11, v12, v13);
    KiUnstackDetachProcess((unsigned int)v26, 0);
    v14 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 36) = v14 | 1;
    *(_DWORD *)(v2 + 40) = 0;
    *(_DWORD *)(v1 + 36) |= 4u;
  }
  else
  {
    v1 = 0;
  }
  v15 = *(_BYTE *)(v2 - 16);
  v16 = 0;
  if ( (v15 & 1) != 0 )
  {
    v17 = *(__int16 *)(v2 - 14);
    *(_WORD *)(v2 - 14) = 0;
    v16 = 0x10000 - v17;
    *(_BYTE *)(v2 - 16) = v15 & 0xFE;
  }
  v18 = (unsigned int *)(v2 - 4);
  __dmb(0xBu);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 - 1, v18) );
  if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v2 - 4));
  result = KeAbPostRelease(v2 - 4);
  if ( v16 > 0 )
  {
    __dmb(0xBu);
    v21 = (unsigned int *)(v2 - 12);
    do
    {
      v22 = __ldrex(v21);
      result = v22 - v16;
    }
    while ( __strex(result, v21) );
    __dmb(0xBu);
    if ( result <= 0 )
    {
      if ( result )
        KeBugCheckEx(24, 0, v2, 40, result);
      result = AlpcpDestroyBlob(v2);
    }
  }
  if ( v1 )
  {
    __dmb(0xBu);
    v23 = (unsigned int *)(v1 - 12);
    do
    {
      v24 = __ldrex(v23);
      v25 = v24 - 1;
    }
    while ( __strex(v25, v23) );
    __dmb(0xBu);
    if ( v25 <= 0 )
    {
      if ( v25 )
        KeBugCheckEx(24, 0, v1, 33, v25);
      result = AlpcpDestroyBlob(v1);
    }
  }
  return result;
}
