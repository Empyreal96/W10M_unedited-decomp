// AlpcpLockCommunicationInfoForReply 
 
int __fastcall AlpcpLockCommunicationInfoForReply(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v6; // r4
  int *v8; // r5
  unsigned int *v9; // r6
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r2
  unsigned int *v15; // r7
  int v16; // r0
  int v17; // r6
  unsigned int v18; // r4

  v6 = (*(_DWORD *)(a1 + 244) >> 1) & 3;
  if ( v6 == 1 )
    return sub_7F7C20();
  v8 = *(int **)(a1 + 8);
  if ( v6 == 2 )
  {
    v9 = (unsigned int *)(v8 - 1);
    v10 = KeAbPreAcquire((unsigned int)(v8 - 1), 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( !v12 && __strex(0x11u, v9) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(v8 - 1, v10, (unsigned int)(v8 - 1));
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v13 = v8[2];
    v14 = v13;
  }
  else
  {
    v15 = (unsigned int *)(v8 - 1);
    v16 = KeAbPreAcquire((unsigned int)(v8 - 1), 0, 0);
    v17 = v16;
    do
      v18 = __ldrex(v15);
    while ( !v18 && __strex(0x11u, v15) );
    __dmb(0xBu);
    if ( v18 )
      ExfAcquirePushLockSharedEx(v8 - 1, v16, (unsigned int)(v8 - 1));
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    v14 = v8[1];
    v13 = *v8;
  }
  *a3 = v13;
  *a4 = v14;
  return (int)v8;
}
