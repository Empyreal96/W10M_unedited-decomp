// RtlInsertUnicodePrefix 
 
int __fastcall RtlInsertUnicodePrefix(int a1, int a2, int a3)
{
  __int16 v6; // r0
  _DWORD *v7; // r7
  int i; // r6
  int v9; // r3
  _DWORD *v10; // r5
  __int64 v11; // r0
  int v12; // r3
  _DWORD *v13; // r3
  int v14; // r4
  int v15; // r2
  int result; // r0

  v6 = ComputeUnicodeNameLength(a2);
  v7 = (_DWORD *)(a3 + 12);
  *(_WORD *)(a3 + 2) = v6;
  *(_DWORD *)(a3 + 24) = a2;
  *(_DWORD *)(a3 + 12) = a3 + 12;
  *(_DWORD *)(a3 + 16) = 0;
  *(_DWORD *)(a3 + 20) = 0;
  for ( i = *(_DWORD *)(a1 + 4); ; i = *(_DWORD *)(i + 4) )
  {
    v9 = *(__int16 *)(i + 2);
    if ( v9 <= v6 )
      break;
    a1 = i;
  }
  if ( (__int16)v9 == v6 )
  {
    v10 = (_DWORD *)i;
    LODWORD(v11) = CompareUnicodeStrings(*(_DWORD *)(i + 24), a2, 0);
    while ( (_DWORD)v11 != 2 )
    {
      if ( (_DWORD)v11 == 3 )
      {
        v12 = v10[4];
        if ( !v12 )
        {
          v13 = v10 + 3;
          *(_DWORD *)(a3 + 4) = 0;
          *(_DWORD *)(a3 + 8) = a3;
          *(_WORD *)a3 = 2050;
          v10[4] = v7;
LABEL_12:
          *v7 = v13;
          v14 = *(_DWORD *)(i + 4);
          LODWORD(v11) = v10 + 3;
          *(_DWORD *)(i + 4) = 0;
          *(_WORD *)i = 2050;
          v15 = RtlSplay(v11) - 12;
          *(_WORD *)v15 = 2049;
          *(_DWORD *)(a1 + 4) = v15;
          *(_DWORD *)(v15 + 4) = v14;
          goto LABEL_13;
        }
      }
      else
      {
        v12 = v10[5];
        if ( !v12 )
        {
          v13 = v10 + 3;
          *(_DWORD *)(a3 + 4) = 0;
          *(_DWORD *)(a3 + 8) = a3;
          *(_WORD *)a3 = 2050;
          v10[5] = v7;
          goto LABEL_12;
        }
      }
      v10 = (_DWORD *)(v12 - 12);
      LODWORD(v11) = CompareUnicodeStrings(*(_DWORD *)(v12 + 12), a2, 0);
    }
    if ( CompareUnicodeStrings(v10[6], a2, -1) == 2 )
      result = 0;
    else
      result = sub_7DD3E8();
  }
  else
  {
    *(_DWORD *)(a1 + 4) = a3;
    *(_WORD *)a3 = 2049;
    *(_DWORD *)(a3 + 4) = i;
    *(_DWORD *)(a3 + 8) = a3;
LABEL_13:
    result = 1;
  }
  return result;
}
