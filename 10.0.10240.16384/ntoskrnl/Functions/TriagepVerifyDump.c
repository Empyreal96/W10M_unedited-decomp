// TriagepVerifyDump 
 
int __fastcall TriagepVerifyDump(_DWORD *a1)
{
  int v2; // r0
  int v3; // r1

  if ( !a1 )
    return 0;
  if ( a1[1] == 1347245380 && *a1 == 1162297680 )
  {
    v2 = TriagepGetPageSize(a1[8]);
    if ( v2 != -1 )
    {
      TriageImagePageSize = v2;
      if ( *(_DWORD *)(v3 + 3976) == 4 && *(_DWORD *)(*(_DWORD *)(v3 + 4100) + v3 - 4) == 1145524820 )
        return 1;
    }
  }
  return 0;
}
