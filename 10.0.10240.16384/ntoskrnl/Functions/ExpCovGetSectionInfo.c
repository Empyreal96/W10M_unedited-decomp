// ExpCovGetSectionInfo 
 
int __fastcall ExpCovGetSectionInfo(int a1, _DWORD *a2)
{
  int v2; // r0
  unsigned int v3; // r4
  int v4; // r1
  int *v5; // r0
  int v6; // t1

  *a2 = 0;
  v2 = RtlImageNtHeader(a1);
  if ( !v2 )
    return 0;
  v3 = *(unsigned __int16 *)(v2 + 6);
  v4 = 0;
  if ( !*(_WORD *)(v2 + 6) )
    return 0;
  v5 = (int *)(*(unsigned __int16 *)(v2 + 20) + v2 + 24);
  while ( 1 )
  {
    v6 = *v5;
    v5 += 10;
    if ( v6 == 1987011374 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  return sub_7CDCF0(v5, v4);
}
