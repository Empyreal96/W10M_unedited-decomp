// ObRevokeHandles 
 
int __fastcall ObRevokeHandles(_DWORD **a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r4
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  _DWORD *v7; // r5
  _DWORD *v8; // r0
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int result; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 + 2);
  v4 = KeAbPreAcquire((unsigned int)(a1 + 2), 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = *a1;
  while ( v7 != a1 )
  {
    v8 = v7;
    v7 = (_DWORD *)*v7;
    ObpHandleRevocationBlockRemoveInsertedObject(v8, a1, 1, 1);
  }
  __pld(v3);
  v9 = *(_DWORD *)v3;
  v10 = *(_DWORD *)v3 - 16;
  if ( (*(_DWORD *)v3 & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  if ( (v9 & 2) != 0 )
    goto LABEL_17;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v3);
  while ( v11 == v9 && __strex(v10, (unsigned int *)v3) );
  if ( v11 != v9 )
LABEL_17:
    ExfReleasePushLock(v3, v9);
  result = KeAbPostRelease((unsigned int)v3);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
