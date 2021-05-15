// FstubWriteEntryEFI 
 
int __fastcall FstubWriteEntryEFI(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int *a7)
{
  __int64 v9; // r6
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // r4
  int v13; // r9
  int v14; // r1
  int result; // r0

  if ( a5 )
    v9 = *(_QWORD *)(a1 + 48) - a2 - 1i64;
  else
    v9 = 2i64;
  v10 = *(_DWORD *)(a1 + 4);
  v11 = a3 << 7;
  if ( !v10 )
    __brkdiv0();
  v12 = v11 % v10;
  v13 = v11 / v10;
  memmove(*(_DWORD *)(a1 + 40) + v11 % v10, a4, 0x80u);
  v14 = *(_DWORD *)(a1 + 4);
  if ( v12 + 128 == v14 )
  {
    result = FstubWriteSector(*(_DWORD *)a1, v14, v9 + v13, (v9 + (unsigned __int64)(unsigned int)v13) >> 32);
    if ( result < 0 )
      return result;
    memset(*(_BYTE **)(a1 + 40), 0, *(_DWORD *)(a1 + 4));
  }
  if ( a7 )
    *a7 = RtlComputeCrc32(*a7, a4, 0x80u);
  return 0;
}
