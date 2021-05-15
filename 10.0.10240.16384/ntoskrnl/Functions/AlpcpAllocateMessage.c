// AlpcpAllocateMessage 
 
int __fastcall AlpcpAllocateMessage(int *a1, unsigned int a2, int a3)
{
  int v4; // r1
  int v5; // r0
  int v6; // r5
  int v8; // r6
  unsigned __int8 *v9; // r7
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r1
  int v16; // r4
  unsigned int v17; // r2
  unsigned int v18; // r2

  if ( a2 <= 0x18 )
    v4 = 400;
  else
    v4 = a2 + 120;
  v5 = AlpcpAllocateBlob(AlpcMessageType, v4, a3);
  v6 = v5;
  if ( !v5 )
    return sub_7F457C();
  v8 = v5 - 24;
  v9 = (unsigned __int8 *)(v5 - 4);
  v10 = KeAbPreAcquire(v5 - 4, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 | 1, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v9, v10, (unsigned int)v9);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  *(_BYTE *)(v8 + 8) |= 1u;
  __dmb(0xBu);
  v13 = (unsigned int *)(v8 + 12);
  do
  {
    v14 = __ldrex(v13);
    v15 = v14 + 0x10000;
  }
  while ( __strex(v15, v13) );
  __dmb(0xBu);
  if ( v15 <= 0 )
    KeBugCheckEx(24, 0, v6, 38, v15);
  v16 = *(_DWORD *)(v6 + 136);
  memset((_BYTE *)v6, 0, 144);
  *(_WORD *)(v6 + 122) = 24;
  --*(_WORD *)(v8 + 10);
  *(_DWORD *)(v6 + 136) = v16 & 0x7FFFFFFF;
  do
  {
    __dmb(0xBu);
    do
    {
      v17 = __ldrex(AlpcpNextCallbackId);
      v18 = v17 + 1;
    }
    while ( __strex(v18, AlpcpNextCallbackId) );
    __dmb(0xBu);
  }
  while ( !v18 );
  *(_DWORD *)(v6 + 140) = v18;
  if ( AlpcpMessageLogEnabled )
    AlpcpEnterAllocationEventMessageLog(v6);
  *(_WORD *)(v6 + 122) = 24;
  *a1 = v6;
  return 0;
}
