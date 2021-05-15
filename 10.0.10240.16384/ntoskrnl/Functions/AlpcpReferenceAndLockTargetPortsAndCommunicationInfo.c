// AlpcpReferenceAndLockTargetPortsAndCommunicationInfo 
 
int __fastcall AlpcpReferenceAndLockTargetPortsAndCommunicationInfo(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r8
  unsigned int *v5; // r7
  int v7; // r6
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r4
  __int64 v11; // r4
  int result; // r0
  unsigned int *v13; // r7
  int v14; // r0
  int v15; // r6
  unsigned int v16; // r2
  unsigned int *v17; // r7
  int v18; // r0
  int v19; // r6
  unsigned int v20; // r2
  unsigned int v21; // r2

  v3 = *(_DWORD *)(a1 + 8);
  v5 = (unsigned int *)(v3 - 4);
  v7 = (*(_DWORD *)(a1 + 244) >> 1) & 3;
  v8 = KeAbPreAcquire(v3 - 4, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v5);
  while ( !v10 && __strex(0x11u, v5) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx((_DWORD *)(v3 - 4), v8, v3 - 4);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( v7 == 2 )
  {
    v11 = *(_QWORD *)v3;
  }
  else if ( v7 == 1 )
  {
    LODWORD(v11) = *(_DWORD *)v3;
    HIDWORD(v11) = *(_DWORD *)v3;
  }
  else
  {
    LODWORD(v11) = *(_DWORD *)(v3 + 8);
    HIDWORD(v11) = v11;
  }
  if ( (_DWORD)v11 && !ObReferenceObjectSafe(v11) )
    return sub_7F8E28();
  if ( HIDWORD(v11) && !ObReferenceObjectSafe(SHIDWORD(v11)) )
    HIDWORD(v11) = 0;
  if ( HIDWORD(v11) && (_DWORD)v11 )
  {
    v13 = (unsigned int *)(v11 + 208);
    v14 = KeAbPreAcquire(v11 + 208, 0, 0);
    v15 = v14;
    do
      v16 = __ldrex(v13);
    while ( !v16 && __strex(0x11u, v13) );
    __dmb(0xBu);
    if ( v16 )
      ExfAcquirePushLockSharedEx((_DWORD *)(v11 + 208), v14, v11 + 208);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    if ( HIDWORD(v11) != (_DWORD)v11 )
    {
      v17 = (unsigned int *)(HIDWORD(v11) + 208);
      v18 = KeAbPreAcquire(HIDWORD(v11) + 208, 0, 0);
      v19 = v18;
      do
        v20 = __ldrex(v17);
      while ( !v20 && __strex(0x11u, v17) );
      __dmb(0xBu);
      if ( v20 )
        ExfAcquirePushLockSharedEx((_DWORD *)(HIDWORD(v11) + 208), v18, HIDWORD(v11) + 208);
      if ( v19 )
        *(_BYTE *)(v19 + 14) |= 1u;
    }
    if ( (*(_DWORD *)(v11 + 244) & 0x20) != 0 || (*(_DWORD *)(HIDWORD(v11) + 244) & 0x20) != 0 )
    {
      AlpcpUnlockAndDereferenceTargetPortsAndCommunicationInfo(v3, v11, SHIDWORD(v11));
      result = -1073741769;
    }
    else
    {
      *a2 = v11;
      *a3 = HIDWORD(v11);
      result = 0;
    }
  }
  else
  {
    __dmb(0xBu);
    do
      v21 = __ldrex(v5);
    while ( v21 == 17 && __strex(0, v5) );
    if ( v21 != 17 )
      ExfReleasePushLockShared((_DWORD *)(v3 - 4));
    KeAbPostRelease(v3 - 4);
    if ( (_DWORD)v11 )
      ObfDereferenceObject(v11);
    if ( HIDWORD(v11) )
      ObfDereferenceObject(SHIDWORD(v11));
    result = -1073741769;
  }
  return result;
}
