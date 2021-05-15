// AslFileMappingEnsure 
 
int __fastcall AslFileMappingEnsure(int a1)
{
  int v2; // r5
  int v3; // r3

  if ( *(_DWORD *)(a1 + 536) )
    return 0;
  if ( *(_DWORD *)(a1 + 552) == 1 )
    return -1073741538;
  v2 = RtlFileMapMapView(a1 + 520, 0);
  if ( v2 >= 0 )
  {
    if ( *(_BYTE *)(a1 + 551) )
    {
      v3 = 6;
    }
    else
    {
      v2 = AslpFileMappingGetFileKind((_DWORD *)(a1 + 520), (int *)(a1 + 552));
      if ( v2 >= 0 )
        return v2;
      AslLogCallPrintf(
        1,
        (int)"AslFileMappingEnsure",
        413,
        "AslpFileMappingGetFileKind failed %S [%x]",
        (const void *)a1,
        v2);
      v3 = 3;
    }
    *(_DWORD *)(a1 + 552) = v3;
  }
  return v2;
}
