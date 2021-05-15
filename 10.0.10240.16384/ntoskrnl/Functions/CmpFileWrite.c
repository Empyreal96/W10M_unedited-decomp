// CmpFileWrite 
 
int __fastcall CmpFileWrite(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, int a6)
{
  int result; // r0
  int v8; // r2

  if ( CmpNoWrite )
    goto LABEL_7;
  if ( !a2 && (*(_BYTE *)(a1 + 72) & 4) != 0 )
    return CmpDoSystemCacheWrite(a1, a3, a4, a5, a6);
  v8 = *(_DWORD *)(a1 + 4 * a2 + 1776);
  if ( !v8 )
LABEL_7:
    result = 1;
  else
    result = CmpDoFileWrite(a1, a2, v8, a3, a4, a5, a6);
  return result;
}
