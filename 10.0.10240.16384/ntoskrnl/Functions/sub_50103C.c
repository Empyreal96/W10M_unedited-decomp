// sub_50103C 
 
int __fastcall sub_50103C(__int64 *a1, int a2, int a3, int a4)
{
  __int64 v5; // kr00_8
  int v6; // r6

  v5 = *a1;
  v6 = *((_DWORD *)a1 + 3);
  if ( *((_DWORD *)a1 + 1) )
    MmUnmapReservedMapping(HIDWORD(v5), *((_DWORD *)a1 + 2), v5);
  if ( (_DWORD)v5 )
  {
    MmFreePagesFromMdl(v5, a2, a3, a4);
    ExFreePool(v5);
  }
  *(_DWORD *)a1 = 0;
  *((_DWORD *)a1 + 1) = 0;
  *((_DWORD *)a1 + 2) = 0;
  *((_DWORD *)a1 + 3) = 0;
  return ExFreePool(v6);
}
