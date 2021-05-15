// ObDestroyHandleRevocationBlock 
 
unsigned int *__fastcall ObDestroyHandleRevocationBlock(_DWORD **a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r4
  int v4; // r0
  unsigned int v5; // r2
  unsigned int *result; // r0
  _DWORD *v7; // r5
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  unsigned int v14; // r1
  _DWORD *v15; // r0

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 + 2);
  v4 = KeAbPreAcquire((unsigned int)(a1 + 2), 0, 0);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 | 1, v3) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return (unsigned int *)sub_80A688(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v7 = *a1;
  while ( v7 != a1 )
  {
    v15 = v7;
    v7 = (_DWORD *)*v7;
    ObpHandleRevocationBlockRemoveInsertedObject(v15, a1, 0, 1);
  }
  __pld(v3);
  v8 = *(_DWORD *)v3;
  if ( (*(_DWORD *)v3 & 0xFFFFFFF0) > 0x10 )
    v9 = v8 - 16;
  else
    v9 = 0;
  if ( (v8 & 2) != 0 )
    goto LABEL_26;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v3);
  while ( v10 == v8 && __strex(v9, (unsigned int *)v3) );
  if ( v10 != v8 )
LABEL_26:
    ExfReleasePushLock(v3, v8);
  v11 = KeAbPostRelease((unsigned int)v3);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  result = (unsigned int *)(a1 + 3);
  do
    v14 = __ldrex(result);
  while ( !v14 && __strex(1u, result) );
  __dmb(0xBu);
  if ( v14 )
  {
    if ( v14 != 1 )
      result = ExfWaitForRundownProtectionRelease(result, v14);
  }
  return result;
}
