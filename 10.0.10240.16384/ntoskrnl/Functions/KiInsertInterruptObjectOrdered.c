// KiInsertInterruptObjectOrdered 
 
int **__fastcall KiInsertInterruptObjectOrdered(int a1, int a2)
{
  int *v3; // r1
  int **result; // r0
  int *v5; // r2
  int *v6; // r1
  int *v7; // r2
  int *v8; // r0

  if ( *(_BYTE *)(a2 + 49) && *(_BYTE *)(a1 + 49) )
  {
    if ( *(_BYTE *)(*(_DWORD *)(a1 + 8) + 45) )
    {
      v3 = (int *)(a1 + 4);
      result = *(int ***)(a1 + 8);
      v5 = (int *)(a2 + 4);
      *(_DWORD *)(a2 + 4) = v3;
      *(_DWORD *)(a2 + 8) = result;
      if ( *result != v3 )
        sub_51C25C();
    }
    else
    {
      v6 = (int *)(a1 + 4);
      v7 = (int *)(a1 + 4);
      do
      {
        v8 = v7 - 1;
        if ( !*((_BYTE *)v7 + 45) )
          break;
        v7 = (int *)*v7;
      }
      while ( v7 != v6 );
      v3 = v8 + 1;
      result = (int **)v8[2];
      v5 = (int *)(a2 + 4);
      *(_DWORD *)(a2 + 4) = v3;
      *(_DWORD *)(a2 + 8) = result;
      if ( *result != v3 )
        __fastfail(3u);
    }
  }
  else
  {
    v3 = (int *)(a1 + 4);
    result = *(int ***)(a1 + 8);
    v5 = (int *)(a2 + 4);
    *(_DWORD *)(a2 + 4) = v3;
    *(_DWORD *)(a2 + 8) = result;
    if ( *result != v3 )
      __fastfail(3u);
  }
  *result = v5;
  v3[1] = (int)v5;
  return result;
}
