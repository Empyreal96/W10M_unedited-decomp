// MmGetSessionObjectByProcess 
 
int __fastcall MmGetSessionObjectByProcess(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 324);
  if ( !v1 || a1 == PsInitialSystemProcess )
    result = 0;
  else
    result = *(_DWORD *)(v1 + 44);
  return result;
}
