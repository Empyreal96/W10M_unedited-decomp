// AslFileMappingEnsureMappedAs 
 
int __fastcall AslFileMappingEnsureMappedAs(int a1)
{
  int v2; // r4
  int v3; // r0
  int v4; // r3

  if ( *(_DWORD *)(a1 + 552) == 1 )
    return -1073741538;
  v3 = RtlFileMapMapView(a1 + 520, 0);
  v2 = v3;
  if ( v3 >= 0 )
  {
    if ( *(_BYTE *)(a1 + 551) )
    {
      v4 = 6;
    }
    else
    {
      v2 = AslpFileMappingGetFileKind((_DWORD *)(a1 + 520), (int *)(a1 + 552));
      if ( v2 >= 0 )
        return v2;
      AslLogCallPrintf(
        1,
        (int)"AslFileMappingEnsureMappedAs",
        345,
        "AslpFileMappingGetFileKind failed %S [%x]",
        (const void *)a1,
        v2);
      v4 = 3;
    }
    *(_DWORD *)(a1 + 552) = v4;
    return v2;
  }
  if ( v3 == -1073741554 && !*(_BYTE *)(a1 + 551) )
    v2 = 0;
  return v2;
}
