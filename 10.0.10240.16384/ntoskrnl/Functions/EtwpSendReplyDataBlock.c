// EtwpSendReplyDataBlock 
 
int __fastcall EtwpSendReplyDataBlock(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  unsigned int v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  int v10; // r6
  unsigned int *v11; // r2
  int *v12; // r5
  int v13; // r2
  unsigned int v14; // r1
  __int16 v15; // r3
  int result; // r0
  int v17[6]; // [sp+8h] [bp-18h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  v5 = *(_DWORD *)(a1 + 24);
  v6 = *(_DWORD *)(a1 + 16);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = ObReferenceObjectByHandle(v5, 4, EtwpRegistrationObjectType, 1, (int)v17, 0);
  v9 = v8;
  if ( v8 >= 0 )
  {
    v10 = v17[0];
    if ( (*(_BYTE *)(v17[0] + 50) & 2) != 0 )
    {
      if ( v6 >= 4 )
        goto LABEL_16;
      __dmb(0xBu);
      v11 = (unsigned int *)(v10 + 4 * (v6 + 6));
      do
        v12 = (int *)__ldrex(v11);
      while ( __strex(0, v11) );
      __dmb(0xBu);
      if ( v12 )
      {
        v13 = v12[4];
        if ( (*(_BYTE *)(v13 + 50) & 0x40) != 0 )
          v9 = -1073741055;
        else
          v9 = EtwpQueueReply(*(_DWORD *)(v13 + 24), a1);
        EtwpReleaseQueueEntry(v12, 2);
      }
      else
      {
LABEL_16:
        v9 = -1073741811;
      }
    }
    else
    {
      v9 = -1073741816;
    }
    v8 = ObfDereferenceObject(v10);
  }
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( v15 || *(_DWORD *)(v14 + 100) == v14 + 100 )
    result = v9;
  else
    result = sub_7EB3F4(v8);
  return result;
}
