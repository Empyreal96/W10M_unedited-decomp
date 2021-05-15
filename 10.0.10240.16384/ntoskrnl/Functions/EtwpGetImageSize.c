// EtwpGetImageSize 
 
int __fastcall EtwpGetImageSize(int a1, _DWORD *a2)
{
  int v2; // r2
  int v4; // r4

  v2 = 0;
  if ( !a1 )
    return -1073741811;
  *a2 = 0;
  v4 = *(unsigned __int16 *)(a1 + 24);
  if ( v4 == 267 || v4 == 523 )
    *a2 = *(_DWORD *)(a1 + 80);
  else
    *a2 = 0;
  if ( !*a2 )
    v2 = -1073741701;
  return v2;
}
