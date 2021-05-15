// PsQueryProcessExceptionFlags 
 
int __fastcall PsQueryProcessExceptionFlags(int a1, int a2, _DWORD *a3)
{
  char v5; // r6
  int v6; // r8
  unsigned int v7; // r5
  unsigned int *v8; // lr
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r1
  __int16 v13; // r3
  unsigned int *v14; // r6
  unsigned int v15; // r4
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19; // [sp+4h] [bp-54h]
  _BYTE v20[56]; // [sp+20h] [bp-38h] BYREF

  v5 = 0;
  if ( a2 )
    return -1073741584;
  if ( !*(_DWORD *)(a1 + 320) )
    return -1073741585;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(v7 + 0x74) == a1 )
  {
    if ( *(_DWORD *)(v7 + 336) != a1 )
      v5 = 2;
  }
  else
  {
    v5 = 3;
  }
  if ( (v5 & 2) != 0 )
  {
    --*(_WORD *)(v7 + 308);
    v8 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v9 = *(_DWORD *)(a1 + 172);
    v10 = 1;
    v11 = v9 & 0xFFFFFFFE;
    do
      v12 = __ldrex(v8);
    while ( v12 == v11 && __strex((v9 & 0xFFFFFFFE) + 2, v8) );
    __dmb(0xBu);
    if ( v12 != v11 )
    {
      if ( !ExfAcquireRundownProtection((_DWORD *)(a1 + 172)) )
      {
        v13 = *(_WORD *)(v7 + 308) + 1;
        *(_WORD *)(v7 + 308) = v13;
        if ( !v13 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
          KiCheckForKernelApcDelivery(0);
        return -1073741558;
      }
      v10 = 1;
    }
  }
  else
  {
    v10 = 1;
  }
  if ( (v5 & 1) != 0 )
  {
    KiStackAttachProcess(a1, 0, (int)v20);
    v10 = 1;
  }
  v19 = *(_DWORD *)(*(_DWORD *)(a1 + 320) + 40);
  v6 = 0;
  if ( (v5 & 1) != 0 )
  {
    KiUnstackDetachProcess((unsigned int)v20, 0);
    v10 = 1;
  }
  if ( (v5 & 2) != 0 )
  {
    v14 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v15 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v16 = __ldrex(v14);
    while ( v16 == v15 && __strex(v15 - 2, v14) );
    if ( v16 != v15 )
      v10 = (int)ExfReleaseRundownProtection((unsigned __int8 *)(a1 + 172));
    v17 = *(_WORD *)(v7 + 308) + 1;
    *(_WORD *)(v7 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
      KiCheckForKernelApcDelivery(v10);
  }
  *a3 = 0;
  if ( (v19 & 4) != 0 )
    *a3 = 1;
  if ( (v19 & 8) != 0 )
    *a3 |= 2u;
  return v6;
}
