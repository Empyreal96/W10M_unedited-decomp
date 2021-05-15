// VF_UNMARK_SCATTER_GATHER_LIST 
 
int __fastcall VF_UNMARK_SCATTER_GATHER_LIST(int result, int a2)
{
  if ( *(_DWORD *)(result + 4) == -559026163 )
  {
    if ( a2 )
      *(_DWORD *)(result + 4) = *(_DWORD *)(a2 + 28);
  }
  return result;
}
