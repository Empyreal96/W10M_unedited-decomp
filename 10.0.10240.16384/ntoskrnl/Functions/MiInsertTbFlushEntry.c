// MiInsertTbFlushEntry 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall MiInsertTbFlushEntry(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int result; // r0
  unsigned int v8; // r9
  unsigned int v9; // r2
  int v10; // lr
  unsigned int v11; // r3
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r3
  __int64 v15; // kr00_8
  int v16; // r2
  int v17; // r1 OVERLAPPED
  unsigned int v18; // lr
  int v19; // r3

  result = *(_DWORD *)(a1 + 12);
  v8 = a2;
  if ( result )
  {
    v9 = a1 + 4 * result;
    v10 = *(_DWORD *)(v9 + 16);
    if ( (v10 & 0x800) == 0 && !a4 )
    {
      v11 = *(_DWORD *)(v9 + 16) & 0x7FF;
      if ( (v10 & 0xFFFFF000) + ((v11 + 1) << 12) == a2 )
      {
        a2 = v11 + a3;
        if ( v11 + a3 > v11 && a2 <= 0x7FF )
        {
          *(_DWORD *)(a1 + 16) += a3;
          *(_DWORD *)(v9 + 16) = v10 & 0xFFFFF800 | (v10 + a3) & 0x7FF;
          return result;
        }
      }
    }
    if ( (v10 & 0x800) == 0 && !a4 && (v10 & 0xFFFFF000) == v8 + (a3 << 12) )
    {
      v18 = *(_DWORD *)(v9 + 16) & 0x7FF;
      if ( v18 + a3 <= 0x7FF && v18 + a3 > v18 )
        return MiMergeTbFlushEntryBackwards(a1, a2, a3);
    }
  }
  if ( result >= *(_DWORD *)(a1 + 8) )
    return sub_50E60C();
  if ( a3 )
  {
    while ( 1 )
    {
      v12 = (unsigned int)(a3 - 1) > 0x7FF ? 2048 : a3;
      a3 -= v12;
      v13 = v8 & 0xFFFFF000 | ((_WORD)v12 - 1) & 0x7FF | ((a4 & 1) << 11);
      v14 = a4 == 1 ? 0x400000 : 4096;
      v8 += v14 * v12;
      *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 12) + 20) = v13;
      v15 = *(_QWORD *)(a1 + 12);
      v16 = HIDWORD(v15) + v12;
      result = *(_DWORD *)(a1 + 8);
      v17 = v15 + 1;
      *(_QWORD *)(a1 + 12) = *(_QWORD *)&v17;
      if ( (_DWORD)v15 + 1 == result )
      {
        qsort(a1 + 20, v17, 4, MiTbFlushSort);
        result = MiCompressTbFlushList(a1);
        if ( *(_DWORD *)(a1 + 12) == *(_DWORD *)(a1 + 8) )
          break;
      }
      if ( !a3 )
        return result;
    }
    if ( a3 )
    {
      v19 = *(_DWORD *)(a1 + 12);
      *(_BYTE *)(a1 + 5) = 1;
      *(_DWORD *)(a1 + 16) = v19;
    }
  }
  return result;
}
