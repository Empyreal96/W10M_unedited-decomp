// EtwpQueueReply 
 
int __fastcall EtwpQueueReply(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r0
  int v6; // r4
  _BYTE *v7; // r0
  int v8; // r6
  unsigned int *v10; // r2
  unsigned int v11; // r1
  int v12[4]; // [sp+0h] [bp-10h] BYREF

  v12[0] = a4;
  v5 = *(_DWORD *)(a2 + 4);
  v12[0] = 0;
  v6 = EtwpAllocDataBlock(v5, a2, v12);
  if ( v6 < 0 )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(a1 + 40);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
    __dmb(0xBu);
  }
  else
  {
    v7 = (_BYTE *)ExAllocatePoolWithTag(512, 32, 1920431173);
    v8 = (int)v7;
    if ( !v7 )
      return sub_7EB408();
    memset(v7, 0, 32);
    *(_DWORD *)(v8 + 8) = v12[0];
    KiInsertQueue(a1, v8, 0, 0);
  }
  return v6;
}
