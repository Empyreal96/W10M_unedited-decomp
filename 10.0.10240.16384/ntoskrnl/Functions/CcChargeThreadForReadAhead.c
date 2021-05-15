// CcChargeThreadForReadAhead 
 
unsigned int __fastcall CcChargeThreadForReadAhead(unsigned int result, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r1
  __int64 v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r6
  unsigned int v9; // r2
  unsigned __int64 *v10; // r3
  unsigned __int64 v11; // kr10_8
  unsigned int v12; // r1
  unsigned __int64 *v13; // r3
  unsigned __int64 v14; // kr18_8

  v5 = *(_DWORD *)(result + 24);
  if ( !*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(result + 20) + 4) + 4) )
    sub_54A95C();
  if ( a4 > 0 )
  {
    if ( a4 > 2 )
    {
      if ( a4 != 3 )
        return result;
      v6 = *(unsigned int *)(v5 + 52);
    }
    else
    {
      v6 = *(unsigned int *)(v5 + 52);
      v7 = *(_DWORD *)(v5 + 76);
      v8 = (unsigned __int64)(v6 + *(_QWORD *)(v5 + 56)) >> 32;
      result = v6 + *(_DWORD *)(v5 + 56);
      v9 = *(_DWORD *)(v5 + 72);
      if ( *(_QWORD *)(v5 + 72) )
      {
        if ( __PAIR64__(v8, result) <= __PAIR64__(v7, v9) )
          return result;
        v6 = __PAIR64__(v8, result) - __PAIR64__(v7, v9);
        __dmb(0xBu);
        v13 = (unsigned __int64 *)(v5 + 72);
        do
          v14 = __ldrexd(v13);
        while ( __strexd(__PAIR64__(v8, result), v13) );
      }
      else
      {
        __dmb(0xBu);
        v10 = (unsigned __int64 *)(v5 + 72);
        do
          v11 = __ldrexd(v10);
        while ( __strexd(__PAIR64__(v8, result), v10) );
      }
      __dmb(0xBu);
    }
    if ( v6 )
    {
      v12 = a5;
      if ( !a5 )
        v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      result = PsUpdateDiskCounters(*(_DWORD *)(v12 + 336), v6, 0i64, 1u, 0, 0);
    }
  }
  return result;
}
