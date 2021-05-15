// AlpcpReferenceConnectedPort 
 
int __fastcall AlpcpReferenceConnectedPort(int a1)
{
  int v1; // r4
  int v4; // r6
  unsigned int *v5; // r8
  int v6; // r0
  int v7; // r7
  unsigned int v8; // r2
  int v9; // r3
  unsigned int v10; // r2

  v1 = 0;
  if ( (*(_DWORD *)(a1 + 244) & 6) == 2 )
    return sub_80AE50();
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 )
  {
    v5 = (unsigned int *)(v4 - 4);
    v6 = KeAbPreAcquire(v4 - 4, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex(v5);
    while ( !v8 && __strex(0x11u, v5) );
    __dmb(0xBu);
    if ( v8 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v4 - 4), v6, v4 - 4);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = (*(_DWORD *)(a1 + 244) >> 1) & 3;
    if ( v9 == 2 )
    {
      v1 = *(_DWORD *)(v4 + 4);
    }
    else
    {
      if ( v9 != 3 )
      {
LABEL_17:
        __dmb(0xBu);
        do
          v10 = __ldrex(v5);
        while ( v10 == 17 && __strex(0, v5) );
        if ( v10 != 17 )
          ExfReleasePushLockShared((_DWORD *)(v4 - 4));
        KeAbPostRelease(v4 - 4);
        return v1;
      }
      v1 = *(_DWORD *)(v4 + 8);
    }
    if ( v1 && !ObReferenceObjectSafe(v1) )
      v1 = 0;
    goto LABEL_17;
  }
  return v1;
}
