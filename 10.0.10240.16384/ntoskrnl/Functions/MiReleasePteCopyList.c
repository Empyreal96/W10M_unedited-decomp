// MiReleasePteCopyList 
 
int __fastcall MiReleasePteCopyList(int result)
{
  int v1; // r2

  v1 = *(_DWORD *)(result + 4);
  if ( v1 )
    result = MiReleasePtes(&dword_634D58, *(_DWORD *)(result + 12), v1);
  return result;
}
