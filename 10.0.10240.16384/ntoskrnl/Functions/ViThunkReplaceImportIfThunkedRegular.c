// ViThunkReplaceImportIfThunkedRegular 
 
int __fastcall ViThunkReplaceImportIfThunkedRegular(_DWORD *a1, _DWORD *a2)
{
  int result; // r0
  int v4; // t1

  result = 0;
  if ( *a2 )
  {
    while ( *a1 != a2[2] )
    {
      v4 = a2[5];
      a2 += 5;
      if ( !v4 )
        return result;
    }
    MmReplaceImportEntry((unsigned int)a1, a2[1]);
    result = 1;
  }
  return result;
}
