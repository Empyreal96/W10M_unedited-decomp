// IoGetFsTrackOffsetState 
 
int __fastcall IoGetFsTrackOffsetState(int a1)
{
  int v1; // r4
  int v2; // r3
  int result; // r0

  v1 = *(_DWORD *)(a1 + 104);
  if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 || (v1 && (*(_WORD *)(v1 + 2) & 0x20) != 0 ? (v2 = 1) : (v2 = 0), !v2) )
    result = -1073741275;
  else
    result = sub_520810();
  return result;
}
