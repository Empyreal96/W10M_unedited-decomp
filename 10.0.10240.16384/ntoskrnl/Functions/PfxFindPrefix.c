// PfxFindPrefix 
 
int __fastcall PfxFindPrefix(int a1, unsigned __int16 *a2)
{
  __int16 v4; // r0
  int i; // r5
  int v6; // r4
  int v7; // r6
  __int64 v8; // r0
  int v10; // r4

  v4 = ComputeNameLength(a2);
  for ( i = *(_DWORD *)(a1 + 4); *(__int16 *)(i + 2) > v4; i = *(_DWORD *)(i + 4) )
    a1 = i;
  while ( 1 )
  {
    if ( *(__int16 *)(i + 2) <= 0 )
      return 0;
    v6 = i + 8;
    if ( i != -8 )
      break;
LABEL_11:
    a1 = i;
    i = *(_DWORD *)(i + 4);
  }
  while ( 1 )
  {
    v7 = v6 - 8;
    LODWORD(v8) = CompareNamesCaseSensitive(*(unsigned __int16 **)(v6 + 12), a2);
    if ( (_DWORD)v8 != 3 )
      break;
    v6 = *(_DWORD *)(v6 + 4);
LABEL_10:
    if ( !v6 )
      goto LABEL_11;
  }
  if ( !(_DWORD)v8 )
  {
    v6 = *(_DWORD *)(v6 + 8);
    goto LABEL_10;
  }
  if ( *(_WORD *)v7 == 514 )
  {
    v10 = *(_DWORD *)(i + 4);
    LODWORD(v8) = v7 + 8;
    *(_DWORD *)(i + 4) = 0;
    *(_WORD *)i = 514;
    v7 = RtlSplay(v8) - 8;
    *(_WORD *)v7 = 513;
    *(_DWORD *)(a1 + 4) = v7;
    *(_DWORD *)(v7 + 4) = v10;
  }
  return v7;
}
