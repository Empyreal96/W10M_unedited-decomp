// IoGetDumpHiberRanges 
 
int __fastcall IoGetDumpHiberRanges(int result, int a2)
{
  _DWORD *v2; // r4
  int v4; // r6
  unsigned int v5; // r3
  _DWORD *i; // r4
  _DWORD *v7; // r5
  _DWORD *v8; // t1

  v2 = *(_DWORD **)(a2 + 200);
  v4 = result;
  if ( !v2 )
    return result;
  if ( *v2 < 2u || *v2 > 4u || (v5 = v2[1], v5 < 0x20) || v5 > 0x44 )
  {
    if ( v2[3] )
    {
LABEL_9:
      PoSetHiberRange(result, 4);
      goto LABEL_10;
    }
  }
  else if ( v2[3] )
  {
    goto LABEL_9;
  }
LABEL_10:
  result = CrashdmpImageBase;
  if ( CrashdmpImageBase )
  {
    RtlImageNtHeader(CrashdmpImageBase);
    result = PoSetHiberRange(v4, 4);
  }
  v8 = *(_DWORD **)(a2 + 212);
  v7 = (_DWORD *)(a2 + 212);
  for ( i = v8; i != v7; i = (_DWORD *)*i )
    result = PoSetHiberRange(v4, 4);
  return result;
}
