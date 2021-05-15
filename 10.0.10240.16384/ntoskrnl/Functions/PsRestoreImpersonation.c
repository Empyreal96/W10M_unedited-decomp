// PsRestoreImpersonation 
 
int __fastcall PsRestoreImpersonation(_DWORD *a1, int a2)
{
  int v2; // r10
  int v5; // r3
  int v6; // r6
  unsigned int v7; // r5
  char v8; // r2
  unsigned int v9; // r9
  unsigned __int8 *v10; // r8
  int v11; // r0
  int v12; // r6
  unsigned int v13; // r2
  unsigned int *v14; // r0
  int v15; // r6
  int v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r1
  int v19; // r4
  unsigned int v20; // r1
  int result; // r0
  __int16 v22; // r3
  unsigned int v23; // r1
  unsigned int v24; // r2
  int v25; // [sp+0h] [bp-20h]

  v25 = 0;
  v2 = 0;
  v5 = __mrc(15, 0, 13, 0, 3);
  v6 = *(_DWORD *)a2;
  v7 = v5 & 0xFFFFFFC0;
  if ( !*(_DWORD *)a2 )
    return sub_7C52D4(a1);
  if ( SeQueryTokenTrustLink(*(_DWORD *)a2) )
  {
    v6 = SeQueryTokenTrustLink(v6);
    ObfReferenceObject(v6);
    v2 = *(_DWORD *)a2;
    v8 = 1;
  }
  v9 = *(_DWORD *)(a2 + 8) & 3 | (4 * ((unsigned __int8)v8 & (*(_BYTE *)(a2 + 5) != 0))) | v6 & 0xFFFFFFF8;
  --*(_WORD *)(v7 + 308);
  v10 = (unsigned __int8 *)(a1 + 236);
  v11 = KeAbPreAcquire((unsigned int)(a1 + 236), 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(v10);
  while ( __strex(v13 | 1, v10) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1 + 236, v11, (unsigned int)(a1 + 236));
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v14 = a1 + 240;
  if ( (a1[240] & 8) != 0 )
  {
    v15 = a1[226] & 0xFFFFFFF8;
    v25 = a1[263];
  }
  else
  {
    v15 = 0;
  }
  if ( *(_DWORD *)a2 )
  {
    a1[226] = v9;
    a1[263] = v2;
    v16 = *(unsigned __int8 *)(a2 + 4);
    __dmb(0xBu);
    if ( v16 )
    {
      do
        v17 = __ldrex(v14);
      while ( __strex(v17 | 0x100, v14) );
    }
    else
    {
      do
        v23 = __ldrex(v14);
      while ( __strex(v23 & 0xFFFFFEFF, v14) );
    }
    __dmb(0xBu);
    __dmb(0xBu);
    do
      v18 = __ldrex(v14);
    while ( __strex(v18 | 8, v14) );
    __dmb(0xBu);
    goto LABEL_18;
  }
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned __int8 *)v14);
  while ( __strex(v24 & 0xF7, (unsigned __int8 *)v14) );
  __dmb(0xBu);
  if ( !((unsigned __int8)(v24 & 8) >> 3) )
  {
LABEL_18:
    v19 = 0;
    goto LABEL_19;
  }
  v19 = 1;
LABEL_19:
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)v10);
  while ( __strex(v20 - 1, (unsigned int *)v10) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock(a1 + 236);
  result = KeAbPostRelease((unsigned int)(a1 + 236));
  v22 = *(_WORD *)(v7 + 308) + 1;
  *(_WORD *)(v7 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v15 )
  {
    result = ObfDereferenceObject(v15);
    if ( v25 )
      result = ObfDereferenceObject(v25);
    if ( v19 )
      result = PspWriteTebImpersonationInfo(a1, v7);
  }
  return result;
}
