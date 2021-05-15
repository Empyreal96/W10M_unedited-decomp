// MmGetSessionId 
 
int __fastcall MmGetSessionId(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 324);
  if ( !v1 || a1 == PsInitialSystemProcess )
    result = -1;
  else
    result = *(_DWORD *)(v1 + 8);
  if ( result == -1 )
    result = 0;
  return result;
}
