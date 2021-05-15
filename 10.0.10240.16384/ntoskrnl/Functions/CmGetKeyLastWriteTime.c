// CmGetKeyLastWriteTime 
 
int __fastcall CmGetKeyLastWriteTime(int result, int a2, int a3, int a4)
{
  if ( a3 )
  {
    *(_QWORD *)result = *(_QWORD *)(a3 + 4);
    if ( !a2 )
      return result;
  }
  else
  {
    *(_DWORD *)result = *(_DWORD *)(a2 + 88);
    *(_DWORD *)(result + 4) = *(_DWORD *)(a2 + 92);
  }
  if ( a4 )
    result = sub_804B64();
  return result;
}
