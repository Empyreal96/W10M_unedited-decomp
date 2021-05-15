// VF_MARK_SCATTER_GATHER_LIST 
 
int __fastcall VF_MARK_SCATTER_GATHER_LIST(int result, int a2)
{
  if ( a2 )
  {
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(result + 4);
    *(_DWORD *)(result + 4) = -559026163;
  }
  return result;
}
