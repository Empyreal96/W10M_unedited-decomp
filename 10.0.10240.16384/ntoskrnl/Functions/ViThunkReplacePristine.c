// ViThunkReplacePristine 
 
int __fastcall ViThunkReplacePristine(_DWORD *a1, int a2, _DWORD *a3)
{
  int v3; // r4

  v3 = 0;
  if ( *a1 )
  {
    while ( *a3 != a1[1] )
    {
      a1 = (_DWORD *)((char *)a1 + a2);
      if ( !*a1 )
        return v3;
    }
    v3 = 1;
    *a3 = a1[2];
  }
  return v3;
}
