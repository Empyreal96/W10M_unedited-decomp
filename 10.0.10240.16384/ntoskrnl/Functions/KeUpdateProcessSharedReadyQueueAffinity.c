// KeUpdateProcessSharedReadyQueueAffinity 
 
int __fastcall KeUpdateProcessSharedReadyQueueAffinity(int a1, int a2, int a3)
{
  int v4; // r7
  unsigned int *v5; // r5
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  _DWORD *v10; // r8
  _DWORD *v11; // r6
  unsigned int *v12; // r9
  unsigned int v13; // r10
  unsigned int v14; // r2
  int v15; // r4
  _DWORD *v16; // r1
  int v17; // r3
  __int64 v18; // kr00_8
  char v19; // lr
  unsigned int v20; // r1
  int v21; // [sp+0h] [bp-28h] BYREF
  _DWORD *v22; // [sp+4h] [bp-24h] BYREF
  int v23; // [sp+8h] [bp-20h]

  v21 = a2;
  v22 = (_DWORD *)a3;
  v4 = KfRaiseIrql(2);
  v23 = v4;
  v5 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_515914();
  v7 = (unsigned __int8 *)(a1 + 51);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(a1 + 48);
  while ( 1 )
  {
    v9 = *v5;
    if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v20 = __ldrex(v5);
      while ( v20 == v9 && __strex(v9 | 0x40000000, v5) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v10 = (_DWORD *)(a1 + 40);
  v11 = *(_DWORD **)(a1 + 40);
  if ( v11 != v10 )
  {
    do
    {
      v12 = v11 - 106;
      v13 = 0;
      while ( 1 )
      {
        do
          v14 = __ldrex(v12);
        while ( __strex(1u, v12) );
        __dmb(0xBu);
        if ( !v14 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v12 );
      }
      v15 = KiAcquireThreadStateLock(v11 - 117, &v21, &v22);
      KeUpdateThreadSchedulingProperties(v11 - 117, v15, v21);
      v16 = v22;
      if ( v15 == 1 && v22 && (*(v11 - 97) & 0x1000) == 0 )
      {
        v18 = *(_QWORD *)(v11 - 81);
        v13 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
        v19 = *((_BYTE *)v11 - 345);
        if ( *(_DWORD **)(v18 + 4) != v11 - 81 || *(_DWORD **)HIDWORD(v18) != v11 - 81 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v18) = v18;
        *(_DWORD *)(v18 + 4) = HIDWORD(v18);
        if ( HIDWORD(v18) == (_DWORD)v18 )
          v16[1] ^= 1 << v19;
        *((_BYTE *)v11 - 336) = 7;
      }
      v17 = v21;
      if ( v21 )
      {
        __dmb(0xBu);
        *(_DWORD *)(v17 + 24) = 0;
      }
      if ( v16 )
      {
        __dmb(0xBu);
        *v16 = 0;
      }
      __dmb(0xBu);
      *v12 = 0;
      if ( v13 )
        KiDeferredReadyThread(v13, v11 - 117);
      v11 = (_DWORD *)*v11;
    }
    while ( v11 != v10 );
    v4 = v23;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5);
  }
  else
  {
    __dmb(0xBu);
    *v5 = 0;
  }
  return KfLowerIrql(v4);
}
