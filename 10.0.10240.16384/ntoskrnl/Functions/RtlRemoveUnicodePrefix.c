// RtlRemoveUnicodePrefix 
 
int __fastcall RtlRemoveUnicodePrefix(int result, __int16 *a2)
{
  int v2; // r2
  int v4; // r2
  __int16 *v5; // r3
  __int16 *i; // r2
  __int16 *v7; // r4
  int v8; // r2
  _WORD *v9; // r1
  __int16 *v10; // r3
  int v11; // r5
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r2
  int j; // r1
  _DWORD *v17; // r3
  _DWORD *v18; // r3
  int v19; // r1
  __int16 *v20; // r3
  int v21; // r2

  *(_DWORD *)(result + 8) = 0;
  v2 = *a2;
  if ( v2 >= 2049 )
  {
    if ( v2 <= 2050 )
    {
      v4 = *((_DWORD *)a2 + 2);
      if ( (__int16 *)v4 == a2 )
      {
        v5 = (__int16 *)*((_DWORD *)a2 + 3);
        for ( i = a2 + 6; v5 != i; v5 = *(__int16 **)v5 )
          i = v5;
        v7 = i - 6;
        result = RtlDelete((_DWORD *)a2 + 3);
        if ( result )
        {
          if ( v7 + 6 != (__int16 *)result )
          {
            v8 = *((_DWORD *)v7 + 1);
            v9 = (_WORD *)(result - 12);
            while ( *(__int16 **)(v8 + 4) != v7 )
              v8 = *(_DWORD *)(v8 + 4);
            *v9 = 2049;
            *(_DWORD *)(v8 + 4) = v9;
            *(_DWORD *)(result - 8) = *((_DWORD *)v7 + 1);
            *v7 = 2050;
            *((_DWORD *)v7 + 1) = 0;
          }
        }
        else
        {
          v19 = *((_DWORD *)v7 + 1);
          v20 = *(__int16 **)(v19 + 4);
          v21 = v19;
          while ( v20 != v7 )
          {
            v21 = *(_DWORD *)(v21 + 4);
            v20 = *(__int16 **)(v21 + 4);
          }
          *(_DWORD *)(v21 + 4) = v19;
        }
      }
      else
      {
        v10 = *(__int16 **)(v4 + 8);
        v11 = *((_DWORD *)a2 + 2);
        while ( v10 != a2 )
        {
          v11 = *(_DWORD *)(v11 + 8);
          v10 = *(__int16 **)(v11 + 8);
        }
        *(_DWORD *)(v11 + 8) = v4;
        *(_WORD *)v11 = *a2;
        *(_DWORD *)(v11 + 4) = *((_DWORD *)a2 + 1);
        v12 = *((_DWORD *)a2 + 4);
        v13 = *((_DWORD *)a2 + 5);
        result = (int)(a2 + 12);
        *(_DWORD *)(v11 + 12) = *((_DWORD *)a2 + 3);
        *(_DWORD *)(v11 + 16) = v12;
        *(_DWORD *)(v11 + 20) = v13;
        v14 = *((_DWORD *)a2 + 3);
        if ( (__int16 *)v14 == a2 + 6 )
        {
          v15 = v11 + 12;
          *(_DWORD *)(v11 + 12) = v11 + 12;
          for ( j = *((_DWORD *)a2 + 1); *(__int16 **)(j + 4) != a2; j = *(_DWORD *)(j + 4) )
            ;
          *(_DWORD *)(j + 4) = v11;
        }
        else
        {
          v15 = v11 + 12;
          if ( *(__int16 **)(v14 + 4) == a2 + 6 )
            *(_DWORD *)(v14 + 4) = v15;
          else
            *(_DWORD *)(v14 + 8) = v15;
        }
        v17 = *(_DWORD **)(v11 + 16);
        if ( v17 )
          *v17 = v15;
        v18 = *(_DWORD **)(v11 + 20);
        if ( v18 )
          *v18 = v15;
      }
    }
    else
    {
      result = sub_7DD348();
    }
  }
  return result;
}
