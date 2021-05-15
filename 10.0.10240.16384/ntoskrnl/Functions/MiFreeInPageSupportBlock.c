// MiFreeInPageSupportBlock 
 
int __fastcall MiFreeInPageSupportBlock(int result)
{
  int v1; // r4
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r1
  int v5; // r0
  BOOL v6; // r0

  v1 = result;
  if ( *(_DWORD *)(result + 88) == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(result + 124) )
    result = KeAbPostRelease(result);
  __dmb(0xBu);
  v2 = (unsigned int *)(v1 + 100);
  do
  {
    v3 = __ldrex(v2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, v2) );
  if ( !v4 )
  {
    v5 = *(_DWORD *)(v1 + 144);
    if ( v5 && v5 != v1 + 152 )
      ExFreePoolWithTag(v5, 0);
    v6 = (*(_BYTE *)(v1 + 113) & 0x20) == 0;
    if ( LOWORD(MiState[2 * v6 + 1939]) >= (unsigned int)*((unsigned __int8 *)&MiState[1942] + v6) )
      result = ExFreePoolWithTag(v1, 0);
    else
      result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_6348C8 + v6, (_DWORD *)v1);
  }
  return result;
}
