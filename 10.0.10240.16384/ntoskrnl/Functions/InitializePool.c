// InitializePool 
 
int __fastcall InitializePool(int a1, int a2)
{
  int result; // r0
  unsigned int v4; // r4
  int v5; // r0
  int v6; // r3
  int v7; // r1
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r2
  _BYTE *v12; // r0
  unsigned int v13; // r3
  unsigned int v14; // r4
  int *v15; // r7
  int *v16; // r0
  int *v17; // r6
  int v18[10]; // [sp+8h] [bp-28h] BYREF

  if ( a1 )
  {
    InitializePagedPool(a1);
LABEL_3:
    result = 1;
  }
  else
  {
    KeQuerySystemTime(v18);
    v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v5 = ReadTimeStampCounter();
    v6 = *(_DWORD *)(v4 + 3728);
    v18[3] = v7;
    v8 = v5 ^ v6 ^ *(_DWORD *)(v4 + 2992) ^ v18[1] ^ v18[0];
    v9 = ExGenRandom(0) ^ v8;
    if ( !v9 )
      v9 = 1;
    ExpPoolQuotaCookie = v9;
    ExpPoolFlags |= a2;
    ExpNumberOfNonPagedPools = 1;
    v10 = 1 << (31 - __clz(KeLargestCacheLine));
    ExpCacheLineSize = v10;
    if ( v10 >= 8 )
    {
      if ( v10 > 0x1000 )
        ExpCacheLineSize = 4096;
      if ( PoolTrackTableSize )
      {
        if ( (unsigned int)PoolTrackTableSize >= 0x40 )
          v11 = 1 << (31 - __clz(PoolTrackTableSize));
        else
          v11 = 64;
      }
      else
      {
        v11 = 2048;
      }
      while ( 1 )
      {
        while ( 1 )
        {
          PoolTrackTableSize = v11;
          if ( v11 + 1 <= 0x9249249 )
            break;
          v11 >>= 1;
        }
        v12 = (_BYTE *)MiAllocatePoolPages(512, (28 * v11 + 4123) & 0xFFFFF000, v11, 7 * v11);
        PoolTrackTable = (int)v12;
        if ( v12 )
          break;
        if ( PoolTrackTableSize == 1 )
          goto LABEL_31;
        v11 = (unsigned int)PoolTrackTableSize >> 1;
      }
      PoolTrackTableMask = PoolTrackTableSize++ - 1;
      ExPoolTagTables[0] = (int)v12;
      memset(v12, 0, 28 * PoolTrackTableSize);
      ExpSeedHotTags();
      v13 = (unsigned __int16)KeNumberNodes;
      if ( (unsigned __int16)KeNumberNodes <= 1u )
        goto LABEL_15;
      ExpNumberOfNonPagedPools = (unsigned __int16)KeNumberNodes;
      if ( (unsigned __int16)KeNumberNodes > 0x7Fu )
      {
        v13 = 127;
        ExpNumberOfNonPagedPools = 127;
      }
      if ( v13 > 0x10 )
      {
        v13 = 16;
        ExpNumberOfNonPagedPools = 16;
      }
      v14 = 0;
      if ( !v13 )
      {
LABEL_15:
        ExpTaggedPoolLock = 0;
        PoolVector[0] = (int)NonPagedPoolDescriptor;
        ExInitializePoolDescriptor(NonPagedPoolDescriptor, 512, 0);
        ExInitializePoolDescriptor(dword_644F80, 0, 0);
        goto LABEL_3;
      }
      v15 = ExpNonPagedPoolDescriptor;
      while ( 1 )
      {
        v16 = (int *)MmAllocateIndependentPages(0x2500u, v14);
        v17 = v16;
        if ( !v16 )
          break;
        *v15++ = (int)v16;
        ExInitializePoolDescriptor(v16, 512, v14);
        ExInitializePoolDescriptor(v17 + 1184, 0, v14++);
        if ( v14 >= ExpNumberOfNonPagedPools )
          goto LABEL_15;
      }
LABEL_31:
      result = 0;
    }
    else
    {
      result = sub_96AAAC();
    }
  }
  return result;
}
