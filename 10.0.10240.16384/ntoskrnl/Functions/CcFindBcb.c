// CcFindBcb 
 
int __fastcall CcFindBcb(int a1, __int64 *a2, unsigned int *a3, int *a4)
{
  __int64 v5; // r4
  int v7; // r7
  int v9; // r4
  unsigned int v10; // r1

  v5 = *a2;
  v7 = 0;
  v9 = *(_DWORD *)CcGetBcbListHead(a1, a2, *(_DWORD *)a2 + 0x80000, (unsigned __int64)(*a2 + 0x80000) >> 32) - 16;
  if ( !HIDWORD(v5) && *(_WORD *)v9 == 765 && !*(_DWORD *)(v9 + 28) )
  {
    while ( *(_DWORD *)a2 < *(_DWORD *)(v9 + 24) )
    {
      v10 = *(_DWORD *)(v9 + 8);
      if ( *(_DWORD *)a2 >= v10 )
      {
        v7 = 1;
        goto LABEL_11;
      }
      if ( *a3 >= v10 )
        *a3 = v10;
      v9 = *(_DWORD *)(v9 + 16) - 16;
      if ( *(_WORD *)v9 != 765 )
      {
        *a4 = v9;
        return 0;
      }
    }
    goto LABEL_11;
  }
  if ( *(_WORD *)v9 != 765 )
  {
LABEL_11:
    *a4 = v9;
    return v7;
  }
  return sub_54A4BC();
}
