// PfTTraceListTrim 
 
int *__fastcall PfTTraceListTrim(int a1, unsigned int a2, int a3)
{
  int *result; // r0
  int *v6; // r4
  int *v7; // r6
  int v8; // r2
  __int64 v9; // kr00_8
  int v10; // r1
  int *v11; // r1

  if ( a1 == 1 )
  {
    result = &dword_643A64;
    v6 = &dword_643A74;
    v7 = &dword_643B1C;
  }
  else
  {
    result = &dword_643A5C;
    v6 = &dword_643A6C;
    v7 = &dword_643B18;
  }
  while ( *v6 > a2 )
  {
    v8 = *result;
    if ( (int *)*result == result )
      break;
    v9 = *(_QWORD *)v8;
    if ( *(int **)(v8 + 4) != result || *(_DWORD *)(v9 + 4) != v8 )
      __fastfail(3u);
    *result = v9;
    *(_DWORD *)(v9 + 4) = result;
    if ( *(_DWORD *)(v8 + 20) )
      v10 = *(_DWORD *)(v8 + 40);
    else
      v10 = *(_DWORD *)(v8 + 28);
    --*v6;
    *v7 += v10;
    v11 = *(int **)(a3 + 4);
    *(_DWORD *)v8 = a3;
    *(_DWORD *)(v8 + 4) = v11;
    if ( *v11 != a3 )
      __fastfail(3u);
    *v11 = v8;
    *(_DWORD *)(a3 + 4) = v8;
  }
  return result;
}
