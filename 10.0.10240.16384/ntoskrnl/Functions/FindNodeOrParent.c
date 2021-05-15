// FindNodeOrParent 
 
int __fastcall FindNodeOrParent(int a1, int a2, _DWORD *a3)
{
  int i; // r4
  int v7; // r0
  int result; // r0

  if ( !*(_DWORD *)(a1 + 24) )
    return 0;
  for ( i = *(_DWORD *)(a1 + 8); ; i = *(_DWORD *)(i + 4) )
  {
    while ( 1 )
    {
      v7 = (*(int (__fastcall **)(int, int, int))(a1 + 40))(a1, a2, i + 16);
      if ( !v7 )
        break;
      if ( v7 != 1 )
      {
        result = 1;
        *a3 = i;
        return result;
      }
      if ( !*(_DWORD *)(i + 8) )
      {
        result = 3;
        *a3 = i;
        return result;
      }
      i = *(_DWORD *)(i + 8);
    }
    if ( !*(_DWORD *)(i + 4) )
      break;
  }
  result = 2;
  *a3 = i;
  return result;
}
