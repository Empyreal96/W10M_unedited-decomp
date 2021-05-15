// MmDeleteKernelStack 
 
int __fastcall MmDeleteKernelStack(unsigned int a1, int a2)
{
  int v4; // r7
  int v5; // r1
  int v6; // r5
  int v7; // r6
  _DWORD *v8; // r8
  int v9; // lr
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  int v12; // r4
  unsigned int *v13; // r2
  unsigned int v14; // r0
  int v15; // r8
  int v16; // r6
  int v17; // r4
  unsigned __int8 *v18; // r1
  int v19; // r3
  unsigned int v20; // r2
  unsigned int *v21; // r2
  unsigned int v22; // r0
  int v23; // [sp+0h] [bp-20h]
  int v24; // [sp+0h] [bp-20h]

  if ( (dword_682604 & 1) != 0 )
    return sub_5481F0();
  v4 = ((a1 >> 10) & 0x3FFFFC) - 1073741828;
  if ( (a2 & 1) == 0 )
  {
    v5 = MmPfnDatabase;
    v6 = 0;
    v7 = *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)v4 >> 12) + 20) >> 28;
    if ( (a2 & 8) != 0 )
    {
      while ( 1 )
      {
        v23 = *(_DWORD *)v4;
        v8 = (_DWORD *)(v5 + 24 * (*(_DWORD *)v4 >> 12));
        v9 = KfRaiseIrql(2);
        v10 = (unsigned __int8 *)v8 + 15;
        do
          v11 = __ldrex(v10);
        while ( __strex(v11 | 0x80, v10) );
        __dmb(0xBu);
        if ( v11 >> 7 )
        {
          v18 = (unsigned __int8 *)v8 + 15;
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v19 = v8[3];
              __dmb(0xBu);
            }
            while ( v19 < 0 );
            do
              v20 = __ldrex(v18);
            while ( __strex(v20 | 0x80, v18) );
            __dmb(0xBu);
          }
          while ( v20 >> 7 );
        }
        if ( v23 == *(_DWORD *)v4 )
          break;
        __dmb(0xBu);
        v21 = v8 + 3;
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 & 0x7FFFFFFF, v21) );
        KfLowerIrql(v9);
        v5 = MmPfnDatabase;
      }
      v12 = *v8;
      __dmb(0xBu);
      v13 = v8 + 3;
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 & 0x7FFFFFFF, v13) );
      KfLowerIrql(v9);
      if ( v12 == -5 )
        v6 = 1;
    }
    v15 = 176 * v7;
    while ( 1 )
    {
      v16 = v15 + 24 * v6 + dword_6337E8;
      if ( *(unsigned __int16 *)(v16 + 60) < *(int *)(v16 + 64) )
      {
        v17 = v4 << 10;
        *(_DWORD *)((v4 << 10) + 0xFF0) = dword_634C80 ^ (v4 << 10);
        if ( v6 == 1 )
          return RtlpInterlockedPushEntrySList((unsigned __int64 *)(v16 + 56), (_DWORD *)(v17 + 4088));
        v24 = KfRaiseIrql(2);
        if ( MiClearStackOwners(v4, a2) == 1 )
        {
          RtlpInterlockedPushEntrySList((unsigned __int64 *)(v16 + 56), (_DWORD *)(v17 + 4088));
          return KfLowerIrql(v24);
        }
        KfLowerIrql(v24);
      }
      if ( v6 != 1 )
        return MiDeleteKernelStack(v4, a2);
      v6 = 0;
    }
  }
  return MiDeleteKernelStack(v4, a2);
}
