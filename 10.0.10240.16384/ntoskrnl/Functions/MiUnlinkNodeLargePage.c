// MiUnlinkNodeLargePage 
 
int __fastcall MiUnlinkNodeLargePage(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  unsigned __int8 *v6; // r1
  unsigned __int8 *v7; // r0
  int v8; // r6
  bool v9; // zf
  int v10; // r9
  unsigned int *v11; // r0
  __int64 v12; // r4
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  __int64 v16; // r2
  int v17; // r0
  unsigned int *v18; // r1
  int *v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  unsigned int *v22; // r2
  unsigned int v23; // r0
  int v24; // [sp+0h] [bp-28h] BYREF
  unsigned int *v25; // [sp+4h] [bp-24h]
  int v26; // [sp+8h] [bp-20h]

  v24 = a2;
  v25 = (unsigned int *)a3;
  v26 = a4;
  v5 = *(_DWORD *)(a1 + 24) + 104 * a2;
  if ( a3 == 1 )
  {
    v6 = (unsigned __int8 *)(v5 + 98);
    v7 = (unsigned __int8 *)(v5 + 99);
    while ( 1 )
    {
      v8 = *v6;
      if ( *(_DWORD *)(v5 + 8 * (v8 + a4 + 1)) != v5 + 8 * (v8 + a4 + 1)
        || *(_DWORD *)(v5 + 8 * (v8 + a4 + 3)) != v5 + 8 * (v8 + a4 + 3) )
      {
        break;
      }
      if ( ++v6 == v7 )
        goto LABEL_31;
    }
    v9 = v6 == v7;
  }
  else
  {
    v8 = a3;
    if ( *(_DWORD *)(v5 + 8 * (a3 + a4 + 1)) != v5 + 8 * (a3 + a4 + 1) )
    {
LABEL_9:
      v10 = KfRaiseIrql(2);
      v11 = KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)(v5 + 100), &v24);
      HIDWORD(v12) = v5 + 8 * (v8 + a4 + 1);
      if ( *(_DWORD *)HIDWORD(v12) == HIDWORD(v12) )
      {
        HIDWORD(v12) = v5 + 8 * (v8 + a4 + 3);
        if ( *(_DWORD *)HIDWORD(v12) == HIDWORD(v12) )
          return sub_55011C(v11);
      }
      v14 = (unsigned __int8 *)(*(_DWORD *)(HIDWORD(v12) + 4) + 15);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 | 0x80, v14) );
      __dmb(0xBu);
      if ( v15 >> 7 )
      {
        if ( (dword_682604 & 0x10000) == 0 )
        {
          if ( !v24 )
            JUMPOUT(0x550150);
          JUMPOUT(0x550176);
        }
        JUMPOUT(0x550146);
      }
      LODWORD(v12) = *(_DWORD *)(HIDWORD(v12) + 4);
      v16 = *(_QWORD *)v12;
      if ( __PAIR64__(*(_DWORD *)v12, **(_DWORD **)(v12 + 4)) != v12 )
        __fastfail(3u);
      *(_DWORD *)(HIDWORD(v12) + 4) = HIDWORD(v16);
      *(_DWORD *)HIDWORD(v16) = HIDWORD(v12);
      MiUnlinkNodeLargePageHelper(v5, v12, a4, v8);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(&v24);
      }
      else
      {
        v17 = v24;
        if ( !v24 )
        {
          v18 = v25;
          __dmb(0xBu);
          do
            v19 = (int *)__ldrex(v18);
          while ( v19 == &v24 && __strex(0, v18) );
          if ( v19 == &v24 )
            goto LABEL_22;
          v17 = KxWaitForLockChainValid(&v24);
        }
        v24 = 0;
        __dmb(0xBu);
        v22 = (unsigned int *)(v17 + 4);
        do
          v23 = __ldrex(v22);
        while ( __strex(v23 ^ 1, v22) );
      }
LABEL_22:
      __dmb(0xBu);
      v20 = (unsigned int *)(v12 + 12);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 & 0x7FFFFFFF, v20) );
      KfLowerIrql(v10);
      return v12;
    }
    v9 = *(_DWORD *)(v5 + 8 * (a3 + a4 + 3)) == v5 + 8 * (a3 + a4 + 3);
  }
  if ( !v9 )
    goto LABEL_9;
LABEL_31:
  LODWORD(v12) = 0;
  return v12;
}
