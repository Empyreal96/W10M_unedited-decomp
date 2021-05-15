// ObQueryRefTraceInformation 
 
int __fastcall ObQueryRefTraceInformation(unsigned int a1, int a2, unsigned int *a3, int a4)
{
  unsigned int v4; // r10
  unsigned int v5; // r6
  int v6; // r5
  unsigned int v7; // r8
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r4
  unsigned int v13; // r10
  char v14; // r3
  unsigned int i; // r1
  unsigned int j; // r0
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned int *v22; // [sp+4h] [bp-34h]
  char v23; // [sp+Ch] [bp-2Ch]
  int v24; // [sp+10h] [bp-28h]

  v22 = a3;
  v4 = a2;
  v5 = a1;
  v6 = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    ProbeForWrite(a1, a2, 4);
  v7 = 20;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 310);
  v9 = KeAbPreAcquire((unsigned int)&ObpStackTraceLock, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)&ObpStackTraceLock);
  while ( __strex(v11 | 1, (unsigned __int8 *)&ObpStackTraceLock) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ObpStackTraceLock, v9, (unsigned int)&ObpStackTraceLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v23 = ObpTraceFlags;
  if ( (ObpTraceFlags & 2) == 0 )
  {
    if ( v4 >= 0x14 )
    {
      *(_BYTE *)v5 = 0;
      goto LABEL_32;
    }
LABEL_21:
    v6 = -1073741820;
    goto LABEL_32;
  }
  v12 = 0;
  v24 = ObpTraceFlags & 0x20;
  if ( (ObpTraceFlags & 0x20) != 0 )
    v7 = (unsigned __int16)ObpRuntimeTraceProcessName + 22;
  if ( (ObpTraceFlags & 0x10) != 0 )
  {
    while ( v12 < 0x10 && ObpRuntimeTracePoolTags[v12] )
      v12 = (unsigned __int16)(v12 + 1);
    if ( v12 )
      v7 += 10 * v12;
  }
  if ( v7 > v4 )
    goto LABEL_21;
  v13 = v5 + 20;
  memset((_BYTE *)v5, 0, 20);
  *(_BYTE *)v5 = 1;
  v14 = v23;
  *(_BYTE *)(v5 + 1) = (v23 & 0x40) != 0;
  if ( v24 )
  {
    *(_DWORD *)(v5 + 4) = ObpRuntimeTraceProcessName;
    *(_DWORD *)(v5 + 8) = v13;
    memmove(v5 + 20, dword_61FDE4, HIWORD(ObpRuntimeTraceProcessName));
    v13 += 2 * (HIWORD(ObpRuntimeTraceProcessName) >> 1);
    v14 = ObpTraceFlags;
  }
  if ( (v14 & 0x10) != 0 )
  {
    *(_WORD *)(v5 + 12) = 2 * (5 * v12 - 1);
    *(_WORD *)(v5 + 14) = 2 * (5 * v12 - 1) + 2;
    *(_DWORD *)(v5 + 16) = v13;
    for ( i = 0; i < v12; ++i )
    {
      for ( j = 0; j < 4; ++j )
        *(_WORD *)(v13 + 2 * (5 * i + j)) = (unsigned __int8)(ObpRuntimeTracePoolTags[i] >> (8 * j));
      *(_WORD *)(v13 + 2 * (5 * i + j)) = 59;
    }
    *(_WORD *)(v13 + 10 * v12 - 2) = 0;
  }
LABEL_32:
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)&ObpStackTraceLock);
  while ( __strex(v17 - 1, (unsigned int *)&ObpStackTraceLock) );
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ObpStackTraceLock);
  v18 = KeAbPostRelease((unsigned int)&ObpStackTraceLock);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x136) + 1;
  *(_WORD *)(v19 + 310) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
    KiCheckForKernelApcDelivery(v18);
  if ( v22 )
    *v22 = v7;
  return v6;
}
