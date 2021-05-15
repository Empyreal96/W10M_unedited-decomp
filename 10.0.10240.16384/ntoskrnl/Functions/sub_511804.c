// sub_511804 
 
void sub_511804()
{
  _DWORD *v0; // r4
  int v1; // r5

  if ( !*(_BYTE *)(v1 + 72) )
    ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(v1);
  if ( (*(_WORD *)(*(_DWORD *)(v1 + 304) + 2 * *v0) & 0x1FFF) == 0 )
    ST_STORE<SM_TRAITS>::StReleaseRegion(v1, *v0);
  JUMPOUT(0x42A28A);
}
