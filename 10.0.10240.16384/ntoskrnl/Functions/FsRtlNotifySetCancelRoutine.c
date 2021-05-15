// FsRtlNotifySetCancelRoutine 
 
int __fastcall FsRtlNotifySetCancelRoutine(int a1, int a2)
{
  int v4; // r6
  unsigned int *v6; // r1
  unsigned int v7; // r4
  unsigned int *v8; // r2
  unsigned int v9; // r4
  int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r1

  v4 = 0;
  *(_BYTE *)(a1 + 37) = KeAcquireQueuedSpinLock(7);
  if ( a2 )
  {
    __dmb(0xBu);
    v8 = (unsigned int *)(a1 + 56);
    do
      v9 = __ldrex(v8);
    while ( __strex(0, v8) );
    __dmb(0xBu);
    v10 = *(unsigned __int8 *)(a1 + 37);
    *(_DWORD *)(a1 + 28) = 0;
    KeReleaseQueuedSpinLock(7, v10);
    if ( v9 )
    {
      __dmb(0xBu);
      v11 = (unsigned int *)(a2 + 68);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 - 1, v11) );
      __dmb(0xBu);
      v4 = 1;
    }
  }
  else
  {
    if ( *(_BYTE *)(a1 + 36) )
      return sub_520430();
    __dmb(0xBu);
    v6 = (unsigned int *)(a1 + 56);
    do
      v7 = __ldrex(v6);
    while ( __strex((unsigned int)FsRtlCancelNotify, v6) );
    __dmb(0xBu);
    KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a1 + 37));
  }
  return v4;
}
