// ObpCreateTypeArray 
 
_DWORD *__fastcall ObpCreateTypeArray(_DWORD **a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r5
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  _DWORD *v7; // r3
  _DWORD *v8; // r7
  int v9; // r4
  _DWORD *v10; // r0
  _DWORD *v11; // r4
  _DWORD *v12; // r8
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 310);
  v3 = (unsigned __int8 *)(a1 + 32);
  v4 = KeAbPreAcquire((unsigned int)(a1 + 32), 0, 0);
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
  v8 = 0;
  v9 = 0;
  if ( *a1 != a1 )
  {
    do
    {
      v7 = (_DWORD *)*v7;
      ++v9;
    }
    while ( v7 != a1 );
    if ( v9 )
    {
      v10 = (_DWORD *)ExAllocatePoolWithTag(1, 4 * (v9 + 1), 1916887631);
      v8 = v10;
      if ( v10 )
      {
        *v10 = v9;
        v11 = *a1;
        if ( *a1 != a1 )
        {
          v12 = v10;
          do
          {
            v12[1] = v11;
            ++v12;
            if ( !ObReferenceObjectSafe((int)(v11 + 10)) )
              *v12 = 0;
            v11 = (_DWORD *)*v11;
          }
          while ( v11 != a1 );
        }
      }
    }
  }
  __pld(v3);
  v13 = *(_DWORD *)v3;
  v14 = *(_DWORD *)v3 - 16;
  if ( (*(_DWORD *)v3 & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  if ( (v13 & 2) != 0 )
    goto LABEL_23;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v3);
  while ( v15 == v13 && __strex(v14, (unsigned int *)v3) );
  if ( v15 != v13 )
LABEL_23:
    ExfReleasePushLock(v3, v13);
  v16 = KeAbPostRelease((unsigned int)v3);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x136) + 1;
  *(_WORD *)(v17 + 310) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 )
    KiCheckForKernelApcDelivery(v16);
  return v8;
}
