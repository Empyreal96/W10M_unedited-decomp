// SmWdProcessStore 
 
void __fastcall SmWdProcessStore(int *a1)
{
  unsigned int *v1; // r5
  int v3; // r7
  unsigned int v4; // r4
  unsigned int v5; // r1
  int v6; // r9
  int v7; // r8
  int v8; // r3
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r3
  int v14; // r3
  unsigned int *v15; // r1
  int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r4
  unsigned int v19; // r1
  union _LARGE_INTEGER v20; // [sp+8h] [bp-38h] BYREF
  _DWORD v21[12]; // [sp+10h] [bp-30h] BYREF

  v1 = (unsigned int *)(a1 + 2);
  __pld(a1 + 2);
  v21[0] = 0;
  v21[1] = v21;
  v3 = 0;
  v4 = a1[2] & 0xFFFFFFFE;
  do
    v5 = __ldrex(v1);
  while ( v5 == v4 && __strex(v4 + 2, v1) );
  __dmb(0xBu);
  if ( v5 == v4 )
    v6 = 1;
  else
    v6 = ExfAcquireRundownProtection(a1 + 2);
  if ( v6 )
  {
    v7 = *a1;
    v8 = *(_DWORD *)(*a1 + 3568);
    __dmb(0xBu);
    if ( v8 || (v9 = *(_DWORD *)(v7 + 3572), __dmb(0xBu), v9) )
    {
      KeQueryTickCount((int *)&v20);
      v10 = KeMaximumIncrement;
      v11 = ((v20.LowPart - *(_DWORD *)(v7 + 3584)) * (unsigned __int64)(unsigned int)KeMaximumIncrement) >> 32;
      v20.QuadPart = (v20.QuadPart - *(_QWORD *)(v7 + 3584)) * (unsigned int)KeMaximumIncrement;
      v12 = *(_DWORD *)(v7 + 3568);
      __dmb(0xBu);
      if ( v12 )
      {
        v11 = v20.HighPart;
        v10 = v20.LowPart;
        if ( v20.QuadPart >= WatchdogReadsQueueTimeout.QuadPart )
        {
          v3 = 4;
          SmWdRemoveWorkItems((struct _SMKM_STORE_QUEUE *)(v7 + 3536), (struct _PF_QUEUE *)v21, 2u);
          SmWdCompleteWorkItems((struct _PF_QUEUE *)v21, (void *)v7, -1073741643, v13);
        }
      }
      v14 = *(_DWORD *)(v7 + 3572);
      __dmb(0xBu);
      if ( v14 )
      {
        v11 = v20.HighPart;
        v10 = v20.LowPart;
        if ( v20.QuadPart >= WatchdogWritesQueueTimeout.QuadPart )
          v3 |= 1u;
      }
      if ( v3 )
        StEtaIoTimeout(*(_DWORD *)(*a1 + 1592), v10, v11, *a1, (unsigned int)dword_989680);
      if ( (v3 & 1) != 0 )
      {
        v15 = (unsigned int *)(a1 + 22);
        v16 = a1[22];
        __dmb(0xBu);
        if ( !v16 )
        {
          __dmb(0xBu);
          do
            v17 = __ldrex(v15);
          while ( !v17 && __strex(1u, v15) );
          __dmb(0xBu);
          if ( !v17 )
          {
            KeInsertQueueApc((int)(a1 + 10), (int)a1, 0, 0);
            v6 = 0;
          }
        }
      }
    }
    if ( v6 )
    {
      __pld(v1);
      v18 = *v1 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v19 = __ldrex(v1);
      while ( v19 == v18 && __strex(v18 - 2, v1) );
      if ( v19 != v18 )
        ExfReleaseRundownProtection((unsigned __int8 *)v1);
    }
  }
}
