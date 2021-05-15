// MiCombiningInProgress 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiCombiningInProgress(int *a1, int a2, int a3)
{
  unsigned int v7; // r1
  int v8; // r5
  unsigned int v9; // r8
  _DWORD *v10; // r2 OVERLAPPED
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r5
  int v13; // r2
  int v14; // r1 OVERLAPPED
  _DWORD *v15; // r2 OVERLAPPED
  int v16; // r2
  unsigned int v17; // r0
  _DWORD *v18; // r3
  int v19; // [sp+0h] [bp-28h]
  int v20; // [sp+4h] [bp-24h]

  v19 = *a1;
  v20 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54EA78();
  do
    v7 = __ldrex((unsigned __int8 *)&dword_634300 + 3);
  while ( __strex(v7 | 0x80, (unsigned __int8 *)&dword_634300 + 3) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634300);
  while ( 1 )
  {
    v8 = dword_634300;
    if ( (dword_634300 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_634300 & 0x40000000) == 0 )
    {
      do
        v17 = __ldrex((unsigned int *)&dword_634300);
      while ( v17 == v8 && __strex(v8 | 0x40000000, (unsigned int *)&dword_634300) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( a3 == 1 )
  {
    ++a1[8];
    ++dword_634304;
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    memset((_BYTE *)a2, 0, 40);
    v10 = (_DWORD *)(v19 + 3284);
    *(_DWORD *)(a2 + 20) = v9;
    v11 = *(_DWORD *)(v19 + 3284);
    *(_QWORD *)a2 = *(_QWORD *)&v11;
    if ( *(_DWORD *)(v11 + 4) != v19 + 3284 )
      __fastfail(3u);
    *(_DWORD *)(v11 + 4) = a2;
    *v10 = a2;
    v12 = (_DWORD *)dword_634308;
    v13 = 0;
    if ( dword_634308 )
    {
      while ( 1 )
      {
        if ( MiCombineCompareThread(v9, v12) < 0 )
        {
          v18 = (_DWORD *)*v12;
          if ( !*v12 )
          {
            v13 = 0;
            break;
          }
        }
        else
        {
          v18 = (_DWORD *)v12[1];
          if ( !v18 )
          {
            v13 = 1;
            break;
          }
        }
        v12 = v18;
      }
    }
    RtlAvlInsertNodeEx((int)&dword_634308, (int)v12, v13, (_DWORD *)(a2 + 8));
  }
  else
  {
    *(_QWORD *)&v14 = *(_QWORD *)a2;
    if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v15 != a2 )
      __fastfail(3u);
    *v15 = v14;
    *(_DWORD *)(v14 + 4) = v15;
    RtlAvlRemoveNode((int)&dword_634308, a2 + 8);
    --a1[8];
    v16 = dword_634304;
    if ( dword_634304 == 1 )
    {
      ++dword_63381C;
      KeFlushTb(3, 2);
      v16 = dword_634304;
    }
    dword_634304 = v16 - 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_634300);
  }
  else
  {
    __dmb(0xBu);
    dword_634300 = 0;
  }
  return KfLowerIrql(v20);
}
