// CmGetVisibleMaxValueNameLenAndDataLen 
 
int __fastcall CmGetVisibleMaxValueNameLenAndDataLen(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int result; // r0

  *a4 = 0;
  *a5 = 0;
  if ( a2 )
  {
    *a4 = *(_DWORD *)(a2 + 60);
    *a5 = *(_DWORD *)(a2 + 64);
  }
  if ( a1 && (*a4 = *(unsigned __int16 *)(a1 + 98), *a5 = *(_DWORD *)(a1 + 100), a3) )
    result = sub_804BBC();
  else
    result = 0;
  return result;
}
