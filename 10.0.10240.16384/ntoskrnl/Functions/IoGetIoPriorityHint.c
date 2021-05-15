// IoGetIoPriorityHint 
 
int __fastcall IoGetIoPriorityHint(int a1)
{
  int v1; // r3
  int v2; // r2
  int result; // r0
  int v4; // r3

  v1 = (*(_DWORD *)(a1 + 8) >> 17) & 7;
  if ( !v1 )
    return 2;
  v2 = v1 - 1;
  if ( v1 - 1 < 2 && (v4 = *(_DWORD *)(a1 + 80)) != 0 && *(_DWORD *)(v4 + 1000) )
    result = 2;
  else
    result = v2;
  return result;
}
