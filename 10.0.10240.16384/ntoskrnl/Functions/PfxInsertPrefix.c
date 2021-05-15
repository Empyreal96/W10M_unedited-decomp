// PfxInsertPrefix 
 
int __fastcall PfxInsertPrefix(int a1, unsigned __int16 *a2, int a3)
{
  __int16 v6; // r0
  _DWORD *v7; // r7
  int i; // r5
  int v9; // r3
  int result; // r0
  int j; // r4
  __int64 v12; // r0
  int v13; // r3
  int v14; // r4
  int v15; // r2

  v6 = ComputeNameLength(a2);
  v7 = (_DWORD *)(a3 + 8);
  *(_WORD *)(a3 + 2) = v6;
  *(_DWORD *)(a3 + 20) = a2;
  *(_DWORD *)(a3 + 8) = a3 + 8;
  *(_DWORD *)(a3 + 12) = 0;
  *(_DWORD *)(a3 + 16) = 0;
  for ( i = *(_DWORD *)(a1 + 4); ; i = *(_DWORD *)(i + 4) )
  {
    v9 = *(__int16 *)(i + 2);
    if ( v9 <= v6 )
      break;
    a1 = i;
  }
  if ( (__int16)v9 == v6 )
  {
    for ( j = i; ; j = v13 - 8 )
    {
      LODWORD(v12) = CompareNamesCaseSensitive(*(unsigned __int16 **)(j + 20), a2);
      if ( (_DWORD)v12 == 2 )
        break;
      if ( (_DWORD)v12 == 3 )
      {
        v13 = *(_DWORD *)(j + 12);
        if ( !v13 )
        {
          LODWORD(v12) = j + 8;
          *(_WORD *)a3 = 514;
          *(_DWORD *)(a3 + 4) = 0;
          *(_DWORD *)(j + 12) = v7;
LABEL_15:
          *v7 = v12;
          v14 = *(_DWORD *)(i + 4);
          *(_DWORD *)(i + 4) = 0;
          *(_WORD *)i = 514;
          v15 = RtlSplay(v12) - 8;
          *(_WORD *)v15 = 513;
          *(_DWORD *)(a1 + 4) = v15;
          *(_DWORD *)(v15 + 4) = v14;
          goto LABEL_6;
        }
      }
      else
      {
        v13 = *(_DWORD *)(j + 16);
        if ( !v13 )
        {
          LODWORD(v12) = j + 8;
          *(_WORD *)a3 = 514;
          *(_DWORD *)(a3 + 4) = 0;
          *(_DWORD *)(j + 16) = v7;
          goto LABEL_15;
        }
      }
    }
    result = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 4) = a3;
    *(_WORD *)a3 = 513;
    *(_DWORD *)(a3 + 4) = i;
LABEL_6:
    result = 1;
  }
  return result;
}
