// RtlFindUnicodePrefix 
 
int __fastcall RtlFindUnicodePrefix(int a1, int a2, int a3)
{
  __int16 v6; // r0
  int i; // r5
  _DWORD *v8; // r4
  int v9; // r6
  __int64 v10; // r0
  int v11; // r4
  _DWORD *v12; // r4
  int result; // r0
  int v14; // r0

  v6 = ComputeUnicodeNameLength(a2);
  for ( i = *(_DWORD *)(a1 + 4); *(__int16 *)(i + 2) > v6; i = *(_DWORD *)(i + 4) )
    a1 = i;
  while ( 1 )
  {
    if ( *(__int16 *)(i + 2) <= 0 )
    {
      v12 = 0;
      goto LABEL_16;
    }
    v8 = (_DWORD *)(i + 12);
    if ( i != -12 )
      break;
LABEL_10:
    a1 = i;
    i = *(_DWORD *)(i + 4);
  }
  while ( 1 )
  {
    v9 = (int)(v8 - 3);
    LODWORD(v10) = CompareUnicodeStrings(v8[3], a2, 0);
    if ( (_DWORD)v10 == 3 )
    {
      v8 = (_DWORD *)v8[1];
      goto LABEL_9;
    }
    if ( (_DWORD)v10 )
      break;
    v8 = (_DWORD *)v8[2];
LABEL_9:
    if ( !v8 )
      goto LABEL_10;
  }
  if ( a3 )
  {
    v12 = v8 - 3;
    v14 = CompareUnicodeStrings(*(_DWORD *)(v9 + 24), a2, a3);
    if ( v14 == 1 || v14 == 2 )
      goto LABEL_16;
    result = sub_7DD404();
  }
  else
  {
    if ( *(_WORD *)v9 == 2050 )
    {
      v11 = *(_DWORD *)(i + 4);
      LODWORD(v10) = v9 + 12;
      *(_DWORD *)(i + 4) = 0;
      *(_WORD *)i = 2050;
      v9 = RtlSplay(v10) - 12;
      *(_WORD *)v9 = 2049;
      *(_DWORD *)(a1 + 4) = v9;
      *(_DWORD *)(v9 + 4) = v11;
    }
    v12 = (_DWORD *)v9;
LABEL_16:
    result = (int)v12;
  }
  return result;
}
