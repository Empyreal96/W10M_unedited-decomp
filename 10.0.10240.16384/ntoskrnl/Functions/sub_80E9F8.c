// sub_80E9F8 
 
void sub_80E9F8()
{
  _DWORD *v0; // r4
  unsigned int v1; // r7
  _DWORD *v2; // r0
  unsigned int v3; // r6
  _DWORD *v4; // r0
  _DWORD *v5; // r8
  int v6; // r9
  unsigned int v7; // r0

  if ( !v0[1601] )
  {
    v1 = MiAllocateMemoryListLocks();
    if ( !v1 )
      JUMPOUT(0x79810E);
    v2 = (_DWORD *)ExAllocatePoolWithTag(
                     512,
                     4 * ((((v0[884] + 1) & 0x1F) != 0) + ((unsigned int)(v0[884] + 1) >> 5) + 2),
                     538996045);
    v3 = (unsigned int)v2;
    if ( !v2 )
      goto LABEL_12;
    *v2 = v0[884] + 1;
    v2[1] = v2 + 2;
    v4 = (_DWORD *)ExAllocatePoolWithTag(
                     512,
                     4 * ((((v0[884] + 1) & 0x1F) != 0) + ((unsigned int)(v0[884] + 1) >> 5) + 2),
                     538996045);
    v5 = v4;
    if ( !v4 )
    {
      v7 = v3;
      goto LABEL_11;
    }
    *v4 = v0[884] + 1;
    v4[1] = v4 + 2;
    v6 = __mrc(15, 0, 13, 0, 3);
    MiLockDynamicMemoryExclusive((int)MiSystemPartition, v6 & 0xFFFFFFC0);
    if ( !v0[1601] )
    {
      v0[1601] = v3;
      v0[1602] = v5;
      v3 = 0;
      v0[1603] = v1;
      v5 = 0;
    }
    MiUnlockDynamicMemoryExclusive((int)MiSystemPartition, v6 & 0xFFFFFFC0);
    if ( v3 )
    {
      ExFreePoolWithTag(v3);
      v7 = (unsigned int)v5;
LABEL_11:
      ExFreePoolWithTag(v7);
LABEL_12:
      ExFreePoolWithTag(v1);
      goto LABEL_13;
    }
  }
LABEL_13:
  JUMPOUT(0x798110);
}
