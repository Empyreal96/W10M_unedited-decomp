// ObpPushRefDerefInfo 
 
int __fastcall ObpPushRefDerefInfo(int a1, unsigned int a2, int a3, unsigned int a4, unsigned __int16 *a5, int a6)
{
  unsigned int v9; // r5
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r5
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r8
  int i; // r7
  _DWORD *v17; // r2
  _DWORD *v18; // r4
  _DWORD *v19; // r5
  int v20; // r1
  int v21; // r2
  int v22; // r3
  __int16 v23; // r1
  unsigned int v24; // r2
  int result; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  unsigned int v28; // [sp+0h] [bp-28h] BYREF
  int v29; // [sp+4h] [bp-24h]
  unsigned int v30; // [sp+8h] [bp-20h]

  v28 = a2;
  v30 = a4;
  v29 = a3;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 310);
  v10 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
  while ( __strex(v12 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v10, (unsigned int)&ObpStackTraceLock);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  if ( (ObpTraceFlags & 0x73) != 0 )
  {
    v14 = ObpGetObjectRefInfo(a1, &v28);
    if ( v14 >= 0 )
    {
      v15 = v28;
      if ( v28 )
      {
        v14 = ObpGetTraceIndex(a5);
        if ( (unsigned int)v14 >= 0x3FFD )
        {
          v14 = DbgPrintEx(0, 1, (int)"ObpPushRefDerefInfo - ObpStackTable overflow\n", 16381);
        }
        else
        {
          for ( i = *(unsigned __int16 *)(v15 + 24); i; i = (unsigned __int16)(i - 1) )
          {
            v17 = (_DWORD *)(v15 + 12 * i);
            if ( a4 >= v17[4] )
              break;
            v18 = v17 + 4;
            v19 = v17 + 7;
            v20 = v17[4];
            v21 = v17[5];
            v22 = v18[2];
            *v19 = v20;
            v19[1] = v21;
            v19[2] = v22;
          }
          if ( a2 )
            v23 = 0x8000;
          else
            v23 = 0;
          v24 = v15 + 12 * i;
          *(_WORD *)(v24 + 32) = v23 | v14;
          *(_WORD *)(v24 + 34) = v29;
          *(_DWORD *)(v24 + 28) = a4;
          *(_DWORD *)(v24 + 36) = a6;
          ++*(_WORD *)(v15 + 24);
        }
      }
    }
    if ( (unsigned __int16)word_61FE3C < 0x64u )
      ObpRefillWorkItemFreeList(v14);
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&ObpStackTraceLock);
    while ( __strex(v13 - 1, (unsigned int *)&ObpStackTraceLock) );
  }
  else
  {
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&ObpStackTraceLock);
    while ( __strex(v13 - 1, (unsigned int *)&ObpStackTraceLock) );
  }
  if ( (v13 & 2) != 0 && (v13 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
  result = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
  v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v27 = *(_WORD *)(v26 + 0x136) + 1;
  *(_WORD *)(v26 + 310) = v27;
  if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
