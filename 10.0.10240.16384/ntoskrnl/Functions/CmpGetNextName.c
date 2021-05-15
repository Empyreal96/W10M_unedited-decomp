// CmpGetNextName 
 
int __fastcall CmpGetNextName(__int16 *a1, int a2, _BYTE *a3)
{
  _WORD *v3; // r4
  int v4; // r7
  int result; // r0
  _WORD *v7; // r2
  int v8; // r2
  __int16 v9; // r3
  unsigned int v10; // r3
  _WORD *v11; // r4
  __int16 v12; // r3
  int v13; // r2
  __int16 v14; // r3

  v3 = (_WORD *)*((_DWORD *)a1 + 1);
  v4 = 1;
  if ( v3 && *a1 )
  {
    if ( !*v3 )
      return sub_7FC4E0();
    if ( *v3 == 92 )
    {
      do
      {
        v11 = (_WORD *)(*((_DWORD *)a1 + 1) + 2);
        v12 = *a1;
        *((_DWORD *)a1 + 1) = v11;
        v13 = (unsigned __int16)(v12 - 2);
        v14 = a1[1];
        *a1 = v13;
        a1[1] = v14 - 2;
        if ( !v13 )
          return sub_7FC4E0();
      }
      while ( *v11 == 92 );
    }
    *(_DWORD *)(a2 + 4) = *((_DWORD *)a1 + 1);
    if ( *a1 )
    {
      do
      {
        v7 = (_WORD *)*((_DWORD *)a1 + 1);
        if ( *v7 == 92 )
          break;
        *((_DWORD *)a1 + 1) = v7 + 1;
        v8 = (unsigned __int16)(*a1 - 2);
        v9 = a1[1];
        *a1 = v8;
        a1[1] = v9 - 2;
      }
      while ( v8 );
    }
    v10 = (unsigned __int16)(*((_DWORD *)a1 + 1) - *(_DWORD *)(a2 + 4));
    *(_WORD *)a2 = v10;
    if ( v10 > 0x200 )
      v4 = 0;
    *(_WORD *)(a2 + 2) = v10;
    if ( *a1 )
      *a3 = 0;
    else
      *a3 = 1;
    result = v4;
  }
  else
  {
    *a3 = 1;
    result = 1;
    *(_DWORD *)(a2 + 4) = 0;
    *(_WORD *)a2 = 0;
  }
  return result;
}
