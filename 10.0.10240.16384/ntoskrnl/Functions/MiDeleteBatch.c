// MiDeleteBatch 
 
int __fastcall MiDeleteBatch(int *a1, _DWORD *a2, unsigned int a3, int a4, int a5)
{
  int v5; // r7
  unsigned int v8; // r5
  int v9; // r10
  unsigned int v10; // r6
  int v11; // r7
  int v12; // t1
  unsigned int v13; // r2
  unsigned int *v15; // r2
  unsigned int v16; // r0
  int v17; // r0
  unsigned int *v18; // r1
  int *v19; // r0
  unsigned __int8 *v20; // r1
  unsigned int v21; // r2
  int v22; // r2
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int *v26; // r2
  unsigned int v27; // r0
  unsigned int v28; // r2
  unsigned int v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r0
  int v32; // r3
  unsigned int v33; // r2
  int v34; // r3
  unsigned int v35; // r2
  int var28[11]; // [sp+10h] [bp-28h] BYREF

  v5 = a4;
  v8 = a3;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(algn_640690, var28, a3, MiSystemPartition);
  v9 = a5;
  v10 = 0;
  if ( v8 )
  {
    do
    {
      v12 = *a1++;
      v11 = v12;
      if ( (*(_BYTE *)(v12 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (v11 - MmPfnDatabase) / 24);
      v13 = *(_DWORD *)(v11 + 12) & 0xC0000000 | (*(_DWORD *)(v11 + 12) - 1) & 0x3FFFFFFF;
      *(_DWORD *)(v11 + 12) = v13;
      if ( (v13 & 0x3FFFFFFF) == 0 && MiPfnShareCountIsZero(v11, 1u) == 3 )
        return sub_53852C();
      if ( v10 != v8 - 1 || a5 == 1 )
      {
        __dmb(0xBu);
        v15 = (unsigned int *)(v11 + 12);
        do
          v16 = __ldrex(v15);
        while ( __strex(v16 & 0x7FFFFFFF, v15) );
      }
      else
      {
        __dmb(0xBu);
        v26 = (unsigned int *)(v11 + 12);
        do
          v27 = __ldrex(v26);
        while ( __strex(v27 & 0x7FFFFFFF, v26) );
      }
      ++v10;
    }
    while ( v10 < v8 );
    v5 = a4;
    v9 = a5;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(var28);
  }
  else
  {
    v17 = var28[0];
    if ( !var28[0] )
    {
      v18 = (unsigned int *)var28[1];
      __dmb(0xBu);
      do
        v19 = (int *)__ldrex(v18);
      while ( v19 == var28 && __strex(0, v18) );
      if ( v19 == var28 )
        goto LABEL_17;
      v17 = KxWaitForLockChainValid(var28);
    }
    var28[0] = 0;
    __dmb(0xBu);
    v30 = (unsigned int *)(v17 + 4);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 ^ 1, v30) );
  }
LABEL_17:
  v20 = (unsigned __int8 *)(v5 + 15);
  if ( v9 == 1 )
  {
    do
      v28 = __ldrex(v20);
    while ( __strex(v28 | 0x80, v20) );
    __dmb(0xBu);
    if ( v28 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v32 = *(_DWORD *)(v5 + 12);
          __dmb(0xBu);
        }
        while ( (v32 & 0x80000000) != 0 );
        do
          v33 = __ldrex(v20);
        while ( __strex(v33 | 0x80, v20) );
        __dmb(0xBu);
      }
      while ( v33 >> 7 );
    }
  }
  else
  {
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 | 0x80, v20) );
    __dmb(0xBu);
    if ( v21 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v34 = *(_DWORD *)(v5 + 12);
          __dmb(0xBu);
        }
        while ( (v34 & 0x80000000) != 0 );
        do
          v35 = __ldrex(v20);
        while ( __strex(v35 | 0x80, v20) );
        __dmb(0xBu);
      }
      while ( v35 >> 7 );
    }
  }
  v22 = *(_DWORD *)(v5 + 12);
  if ( (*(_BYTE *)(v5 + 18) & 7) != 6 )
    KeBugCheckEx(78, 153, (v5 - MmPfnDatabase) / 24);
  if ( (v22 & 0x3FFFFFFFu) < v8 )
    KeBugCheckEx(78, 153, (v5 - MmPfnDatabase) / 24);
  *(_DWORD *)(v5 + 12) = v22 & 0xC0000000 | (v22 - v8) & 0x3FFFFFFF;
  __dmb(0xBu);
  v23 = (unsigned int *)(v5 + 12);
  if ( v9 == 1 )
  {
    do
      v29 = __ldrex(v23);
    while ( __strex(v29 & 0x7FFFFFFF, v23) );
  }
  else
  {
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 & 0x7FFFFFFF, v23) );
  }
  for ( ; v8; --v8 )
  {
    if ( *a2++ )
      MiReleasePageFileInfo(MiSystemPartition, *(a2 - 1), 1);
  }
  return 0;
}
