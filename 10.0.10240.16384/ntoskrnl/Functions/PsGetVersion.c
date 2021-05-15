// PsGetVersion 
 
int __fastcall PsGetVersion(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  if ( a1 )
    *a1 = 10;
  if ( a2 )
    return sub_528CB0();
  if ( a3 )
    *a3 = 10240;
  if ( a4 )
  {
    *a4 = CmCSDVersionString;
    a4[1] = dword_63285C;
  }
  return 0;
}
