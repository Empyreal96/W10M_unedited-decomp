// ExCovAddInfoToLoaderEntry 
 
int __fastcall ExCovAddInfoToLoaderEntry(int result, int a2, int a3, int a4)
{
  int v4; // [sp+0h] [bp-8h] BYREF

  v4 = a4;
  *(_DWORD *)(result + 72) = 0;
  if ( ExCovMaxPagedPoolToUse )
  {
    result = ExpCovGetSectionInfo(*(_DWORD *)(result + 24), &v4);
    if ( result )
      result = sub_7CDCCC();
  }
  return result;
}
