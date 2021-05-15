// FsRtlFindLargeIndex 
 
int __fastcall FsRtlFindLargeIndex(int a1, unsigned int a2, int *a3)
{
  int v3; // r7
  int v4; // r6
  int v5; // r5
  int v6; // r4

  v3 = *(_DWORD *)(a1 + 4);
  v4 = 0;
  v5 = v3 - 1;
  if ( v3 - 1 < 0 )
  {
LABEL_7:
    *a3 = v3;
    return 0;
  }
  while ( 1 )
  {
    v6 = (v5 + v4) / 2;
    if ( v6 && a2 < *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v6 - 8) )
    {
      v5 = v6 - 1;
      goto LABEL_6;
    }
    if ( a2 <= *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v6) - 1 )
      break;
    v4 = v6 + 1;
LABEL_6:
    if ( v4 > v5 )
      goto LABEL_7;
  }
  *a3 = v6;
  return 1;
}
