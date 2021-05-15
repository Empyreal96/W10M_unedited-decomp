// AlpcpFlushMessagesPort 
 
int __fastcall AlpcpFlushMessagesPort(int a1)
{
  int result; // r0
  int *v3; // r5
  unsigned int *v4; // r6
  int v5; // r0
  unsigned int v6; // r2
  int v7; // r4
  int v8; // r5
  unsigned int v9; // r2

  ((void (*)(void))AlpcpFlushQueue)();
  AlpcpFlushQueue(a1, a1 + 104, 2);
  AlpcpFlushQueue(a1, a1 + 116, 3);
  AlpcpFlushQueue(a1, a1 + 128, 4);
  result = AlpcpFlushCancelQueue(a1, 0);
  if ( (*(_DWORD *)(a1 + 244) & 6) == 6 )
  {
    v3 = *(int **)(a1 + 8);
    v4 = (unsigned int *)(v3 - 1);
    v5 = KeAbPreAcquire((unsigned int)(v3 - 1), 0, 0);
    do
      v6 = __ldrex(v4);
    while ( !v6 && __strex(0x11u, v4) );
    __dmb(0xBu);
    if ( v6 )
    {
      result = sub_806F84(v5, 17);
    }
    else
    {
      if ( v5 )
        *(_BYTE *)(v5 + 14) |= 1u;
      v7 = *v3;
      v8 = v3[2];
      if ( v7 && !ObReferenceObjectSafe(v7) )
        v7 = 0;
      if ( v8 && !ObReferenceObjectSafe(v8) )
        v8 = 0;
      __dmb(0xBu);
      do
        v9 = __ldrex(v4);
      while ( v9 == 17 && __strex(0, v4) );
      if ( v9 != 17 )
        ExfReleasePushLockShared(v4);
      result = KeAbPostRelease((unsigned int)v4);
      if ( v7 )
      {
        if ( (*(_DWORD *)(v7 + 244) & 0x40) == 0 && v8 && (*(_DWORD *)(v8 + 244) & 8) == 0 )
        {
          AlpcpFlushMessagesByRequestor(v8, v7, v7 + 96, 1);
          AlpcpFlushMessagesByRequestor(v8, v7, v7 + 104, 2);
          if ( (*(_DWORD *)(a1 + 244) & 0x80) == 0 )
            AlpcpFlushMessagesByRequestor(v8, v7, v7 + 116, 3);
          AlpcpFlushMessagesByRequestor(v8, v7, v7 + 128, 4);
          AlpcpFlushCancelQueue(v7, a1);
        }
        result = ObfDereferenceObject(v7);
      }
      if ( v8 )
        result = ObfDereferenceObject(v8);
    }
  }
  return result;
}
