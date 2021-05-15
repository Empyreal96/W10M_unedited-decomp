// EtwpAddProviderToSession 
 
unsigned int __fastcall EtwpAddProviderToSession(_DWORD *a1, int a2, unsigned int a3)
{
  unsigned __int8 *v4; // r6
  int v7; // r0
  unsigned int v8; // r4
  unsigned __int8 *v10; // r4
  int *v11; // r7
  unsigned int v12; // r1
  int v13; // r0
  int v14; // r4
  int v15; // r2
  unsigned int *v16; // r2
  unsigned int v17; // r4

  v4 = (unsigned __int8 *)(a1 + 126);
  v7 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
  do
    v8 = __ldrex(v4);
  while ( __strex(v8 | 1, v4) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_7E77E0(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( a3 <= 0x8000 && a1[63] + a3 <= a1[1] )
  {
    v10 = (unsigned __int8 *)a1[20];
    v11 = a1 + 20;
    while ( v10 != (unsigned __int8 *)v11 )
    {
      if ( *((_DWORD *)v10 + 3) == a3 && RtlCompareMemory(v10 + 16, a2, a3) == a3 )
        goto LABEL_14;
      v10 = *(unsigned __int8 **)v10;
    }
    v13 = ExAllocatePoolWithTag(512, a3 + 16, 1651995717);
    v14 = v13;
    if ( v13 )
    {
      a1[63] += a3;
      *(_DWORD *)(v13 + 12) = a3;
      memmove(v13 + 16, a2, a3);
      v15 = *v11;
      *(_DWORD *)v14 = *v11;
      *(_DWORD *)(v14 + 4) = v11;
      if ( *(int **)(v15 + 4) != v11 )
        __fastfail(3u);
      *(_DWORD *)(v15 + 4) = v14;
      *v11 = v14;
      *(_BYTE *)(v14 + 8) = 0;
      __dmb(0xBu);
      v16 = a1 + 153;
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 | 0x8C0, v16) );
      __dmb(0xBu);
    }
  }
LABEL_14:
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v4);
  while ( __strex(v12 - 1, (unsigned int *)v4) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v4);
  return KeAbPostRelease((unsigned int)v4);
}
