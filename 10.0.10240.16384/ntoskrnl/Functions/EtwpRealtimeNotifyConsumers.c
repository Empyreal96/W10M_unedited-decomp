// EtwpRealtimeNotifyConsumers 
 
int __fastcall EtwpRealtimeNotifyConsumers(_DWORD *a1)
{
  unsigned __int8 *v1; // r7
  int v3; // r0
  unsigned int v4; // r2
  int v6; // r0
  int v7; // r8
  unsigned int v8; // r5
  int v9; // r4
  unsigned int v10; // r1
  int v11; // r0
  int i; // r4
  int *j; // r3

  v1 = (unsigned __int8 *)(a1 + 126);
  v3 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
  do
    v4 = __ldrex(v1);
  while ( __strex(v4 | 1, v1) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7F0DB4(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v6 = EtwpGetMaxDebugIdBufferSize(a1);
  v7 = v6;
  if ( v6 )
  {
    v11 = ExAllocatePoolWithTag(1, v6, 1651995717);
    v8 = v11;
    if ( v11 )
    {
      EtwpInitializeProviderInfoBuffer(a1, v11, v7);
      for ( i = a1[64]; (_DWORD *)i != a1 + 64; i = *(_DWORD *)i )
      {
        EtwpAddDebugInfoEvents(a1, v8, v7, 0);
        *(_BYTE *)(i + 50) |= 8u;
        if ( *(_DWORD *)(v8 + 48) > 0x48u )
        {
          EtwpRealtimeInjectEtwBuffer(a1, i, v8);
          *(_DWORD *)(v8 + 48) = 72;
        }
      }
      for ( j = (int *)a1[20]; j != a1 + 20; j = (int *)*j )
        *((_BYTE *)j + 8) = 1;
      v9 = 0;
    }
    else
    {
      v9 = -1073741801;
    }
  }
  else
  {
    v8 = 0;
    v9 = -2147483622;
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v1);
  while ( __strex(v10 - 1, (unsigned int *)v1) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v1);
  KeAbPostRelease((unsigned int)v1);
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v9;
}
