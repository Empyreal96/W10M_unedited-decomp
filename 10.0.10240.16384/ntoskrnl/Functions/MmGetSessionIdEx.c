// MmGetSessionIdEx 
 
int __fastcall MmGetSessionIdEx(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 324);
  if ( !v1 || a1 == PsInitialSystemProcess )
    result = -1;
  else
    result = *(_DWORD *)(v1 + 8);
  return result;
}
