// CmGetVisibleMaxNameLenAndClassLen 
 
int __fastcall CmGetVisibleMaxNameLenAndClassLen(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int result; // r0

  *a4 = 0;
  if ( a5 )
    *a5 = 0;
  if ( a2 )
  {
    *a4 = *(unsigned __int16 *)(a2 + 52);
    if ( a5 )
      *a5 = *(_DWORD *)(a2 + 56);
  }
  if ( a1 && (*a4 = *(unsigned __int16 *)(a1 + 96), a3) )
    result = sub_804C6C();
  else
    result = 0;
  return result;
}
