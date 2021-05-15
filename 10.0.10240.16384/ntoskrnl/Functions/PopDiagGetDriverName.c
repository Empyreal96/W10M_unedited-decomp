// PopDiagGetDriverName 
 
int __fastcall PopDiagGetDriverName(int a1, _WORD *a2, unsigned int a3)
{
  int v4; // r3
  int v5; // r2
  unsigned int v6; // r3
  int result; // r0

  if ( a1 && (v4 = *(_DWORD *)(a1 + 8), (v5 = *(_DWORD *)(v4 + 32)) != 0) && (v6 = *(unsigned __int16 *)(v4 + 28)) != 0 )
    result = RtlStringCbCopyNW(a2, a3, v5, v6);
  else
    result = -1073741823;
  return result;
}
