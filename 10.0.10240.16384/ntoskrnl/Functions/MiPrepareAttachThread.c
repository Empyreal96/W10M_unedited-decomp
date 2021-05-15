// MiPrepareAttachThread 
 
int __fastcall MiPrepareAttachThread(int a1, int a2)
{
  int v2; // r0

  if ( (*(_DWORD *)(a1 + 192) & 0xC00u) < 0xC00 )
    return 0;
  if ( *(_DWORD *)(a2 + 4) )
    return 0;
  v2 = *(unsigned __int8 *)(a2 + 113);
  if ( (v2 & 0xFFFFFFF0) == 240 || *(_DWORD *)(a2 + 60) <= 3u )
    return 0;
  *(_BYTE *)(a2 + 113) = v2 & 0xF ^ ((v2 & 0xF0) + 16);
  return 1;
}
