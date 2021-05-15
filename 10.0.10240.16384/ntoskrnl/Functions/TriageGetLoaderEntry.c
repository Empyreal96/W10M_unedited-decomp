// TriageGetLoaderEntry 
 
int __fastcall TriageGetLoaderEntry(int a1, unsigned int a2)
{
  int v5; // r1
  _DWORD *v6; // r2
  int v7; // r3

  if ( !TriagepVerifyDump() || a2 >= *(_DWORD *)(TriageImagePageSize + a1 + 52) )
    return 0;
  v5 = *(_DWORD *)(TriageImagePageSize + a1 + 48) + a1 + 76 * a2;
  v6 = (_DWORD *)(*(_DWORD *)v5 + a1);
  v7 = 2 * *v6;
  *(_WORD *)(v5 + 48) = v7;
  *(_WORD *)(v5 + 50) = v7;
  *(_DWORD *)(v5 + 52) = v6 + 1;
  return v5 + 4;
}
