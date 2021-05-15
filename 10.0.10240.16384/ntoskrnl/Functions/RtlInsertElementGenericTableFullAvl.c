// RtlInsertElementGenericTableFullAvl 
 
int __fastcall RtlInsertElementGenericTableFullAvl(int a1, int a2, unsigned int a3, bool *a4, _DWORD *a5, int a6)
{
  _DWORD *v11; // r0
  _DWORD *v12; // r4
  _DWORD *v13; // r1
  _DWORD *v14; // r0
  int v15; // r2

  if ( a6 == 1 )
  {
    v12 = a5;
  }
  else
  {
    if ( a3 + 16 < a3 )
      return sub_51872C();
    v11 = (_DWORD *)(*(int (**)(void))(a1 + 44))();
    v12 = v11;
    if ( !v11 )
      return sub_51872C();
    *v11 = 0;
    v11[1] = 0;
    v11[2] = 0;
    v11[3] = 0;
    ++*(_DWORD *)(a1 + 24);
    if ( a6 )
    {
      v13 = v11;
      v14 = a5;
      if ( a6 == 2 )
        a5[1] = v12;
      else
        a5[2] = v12;
      *v12 = a5;
      *(_BYTE *)(a1 + 12) = -1;
      while ( 1 )
      {
        v15 = 1;
        if ( *(_DWORD **)(*v13 + 4) == v13 )
          v15 = -1;
        if ( *((_BYTE *)v14 + 12) )
          break;
        *((_BYTE *)v14 + 12) = v15;
        v13 = v14;
        v14 = (_DWORD *)*v14;
      }
      if ( *((char *)v14 + 12) == v15 )
      {
        RebalanceNode();
      }
      else
      {
        *((_BYTE *)v14 + 12) = 0;
        if ( !*(_BYTE *)(a1 + 12) )
          ++*(_DWORD *)(a1 + 28);
      }
    }
    else
    {
      *(_DWORD *)(a1 + 8) = v11;
      *v11 = a1;
      *(_DWORD *)(a1 + 28) = 1;
    }
    memmove((int)(v12 + 4), a2, a3);
  }
  if ( a4 )
    *a4 = a6 != 1;
  return (int)(v12 + 4);
}
