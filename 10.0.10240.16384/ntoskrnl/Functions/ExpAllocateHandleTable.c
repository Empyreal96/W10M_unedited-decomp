// ExpAllocateHandleTable 
 
int __fastcall ExpAllocateHandleTable(int a1, int a2)
{
  int v4; // r7
  int v5; // r4
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r6

  v4 = 52 * dword_92038C;
  v5 = ExAllocatePoolWithTag(5, 52 * dword_92038C + 40, 1651794511);
  if ( v5 )
  {
    if ( a1 && PsChargeProcessPagedPoolQuota(a1, 92) < 0 )
      return sub_7DE004();
    memset((_BYTE *)v5, 0, v4 + 40);
    *(_DWORD *)(v5 + 12) = a1;
    v7 = __mrc(15, 0, 13, 0, 3);
    v8 = dword_92038C;
    *(_DWORD *)(v5 + 24) = *(_DWORD *)(*(_DWORD *)((v7 & 0xFFFFFFC0) + 0x74) + 176);
    if ( v8 )
    {
      v9 = v5;
      do
      {
        *(_DWORD *)(v9 + 40) = 0;
        v9 += 52;
        --v8;
      }
      while ( v8 );
    }
    v10 = ExpAllocateLowLevelTable(v5, 0);
    if ( v10 )
    {
      ExpInsertLowLevelTableIntoFreeList(v5, v10, v5 + 40, a2);
      *(_DWORD *)(v5 + 8) = v10;
      if ( a1 )
        *(_BYTE *)(v5 + 28) |= 0x10u;
      *(_DWORD *)(v5 + 32) = 0;
      *(_DWORD *)(v5 + 36) = 0;
      return v5;
    }
    ExFreePoolWithTag(v5);
    if ( a1 )
      PsReturnProcessPagedPoolQuota(a1, 0x5Cu);
  }
  return 0;
}
