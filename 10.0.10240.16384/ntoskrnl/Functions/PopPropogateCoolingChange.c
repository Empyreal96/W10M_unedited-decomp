// PopPropogateCoolingChange 
 
int __fastcall PopPropogateCoolingChange(int result)
{
  int v1; // r4
  int v2; // r7
  unsigned int v3; // r6
  int *i; // r2
  int *v5; // r5
  int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r6
  unsigned int v15; // r2
  int *v16; // r5
  int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r2
  int v20; // r0
  __int16 v21; // r3
  unsigned int v22; // r2
  int v23; // r0
  int v24; // r6
  unsigned int v25; // r2
  int v26; // r0

  v1 = result;
  if ( *(_BYTE *)(result + 35) )
  {
    *(_BYTE *)(result + 35) = 0;
    return result;
  }
  do
  {
    while ( 1 )
    {
      v2 = 0;
      v3 = 100;
      if ( *(_BYTE *)(v1 + 32) )
      {
        for ( i = *(int **)(v1 + 8); i != (int *)(v1 + 8); i = (int *)*i )
        {
          if ( *((_BYTE *)i + 10) )
          {
            if ( *((unsigned __int8 *)i + 8) < v3 )
              v3 = *((unsigned __int8 *)i + 8);
            if ( *((_BYTE *)i + 9) )
              v2 = 1;
          }
        }
      }
      if ( v3 == *(unsigned __int8 *)(v1 + 34) )
        break;
      v5 = (int *)(v1 + 16);
      *(_BYTE *)(v1 + 34) = v3;
      *(_BYTE *)(v1 + 35) = 1;
      if ( *(_DWORD *)(v1 + 20) )
        *(_DWORD *)(v1 + 20) = 0;
      __pld(v5);
      v6 = *v5;
      v7 = *v5 - 16;
      if ( (*v5 & 0xFFFFFFF0) <= 0x10 )
        v7 = 0;
      if ( (v6 & 2) != 0 )
        goto LABEL_22;
      __dmb(0xBu);
      do
        v8 = __ldrex((unsigned int *)v5);
      while ( v8 == v6 && __strex(v7, (unsigned int *)v5) );
      if ( v8 != v6 )
LABEL_22:
        ExfReleasePushLock((_DWORD *)(v1 + 16), v6);
      v9 = KeAbPostRelease(v1 + 16);
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v11 = *(_WORD *)(v10 + 0x134) + 1;
      *(_WORD *)(v10 + 308) = v11;
      if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
        KiCheckForKernelApcDelivery(v9);
      PopDiagTraceCoolingExtensionPassiveUpdate(v1);
      (*(void (__fastcall **)(_DWORD, unsigned int))(v1 + 68))(*(_DWORD *)(v1 + 48), v3);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v12 + 308);
      v13 = KeAbPreAcquire(v1 + 16, 0, 0);
      v14 = v13;
      do
        v15 = __ldrex((unsigned __int8 *)v5);
      while ( __strex(v15 | 1, (unsigned __int8 *)v5) );
      __dmb(0xBu);
      if ( (v15 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v1 + 16), v13, v1 + 16);
      if ( v14 )
        *(_BYTE *)(v14 + 14) |= 1u;
      *(_DWORD *)(v1 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( *(_BYTE *)(v1 + 35) )
      {
        *(_BYTE *)(v1 + 35) = 0;
        break;
      }
    }
    if ( v2 == *(unsigned __int8 *)(v1 + 33) )
      goto LABEL_58;
    v16 = (int *)(v1 + 16);
    *(_BYTE *)(v1 + 33) = v2;
    *(_BYTE *)(v1 + 35) = 1;
    if ( *(_DWORD *)(v1 + 20) )
      *(_DWORD *)(v1 + 20) = 0;
    __pld(v16);
    v17 = *v16;
    v18 = *v16 - 16;
    if ( (*v16 & 0xFFFFFFF0) <= 0x10 )
      v18 = 0;
    if ( (v17 & 2) != 0 )
      goto LABEL_45;
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)v16);
    while ( v19 == v17 && __strex(v18, (unsigned int *)v16) );
    if ( v19 != v17 )
LABEL_45:
      ExfReleasePushLock((_DWORD *)(v1 + 16), v17);
    KeAbPostRelease(v1 + 16);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v20);
    PopDiagTraceCoolingExtensionActiveUpdate(v1);
    (*(void (__fastcall **)(_DWORD, int))(v1 + 64))(*(_DWORD *)(v1 + 48), v2);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v22 + 308);
    v23 = KeAbPreAcquire(v1 + 16, 0, 0);
    v24 = v23;
    do
      v25 = __ldrex((unsigned __int8 *)v16);
    while ( __strex(v25 | 1, (unsigned __int8 *)v16) );
    __dmb(0xBu);
    if ( (v25 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v1 + 16), v23, v1 + 16);
    if ( v24 )
      *(_BYTE *)(v24 + 14) |= 1u;
    *(_DWORD *)(v1 + 20) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  }
  while ( !*(_BYTE *)(v1 + 35) );
  *(_BYTE *)(v1 + 35) = 0;
LABEL_58:
  v26 = *(_DWORD *)(v1 + 40);
  if ( v26 )
    KeSetEvent(v26, 0, 0);
  result = *(_DWORD *)(v1 + 36);
  if ( result )
    result = KeSetEvent(result, 0, 0);
  return result;
}
