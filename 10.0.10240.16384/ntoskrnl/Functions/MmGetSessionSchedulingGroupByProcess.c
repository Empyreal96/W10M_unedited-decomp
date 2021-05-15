// MmGetSessionSchedulingGroupByProcess 
 
int __fastcall MmGetSessionSchedulingGroupByProcess(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 324);
  if ( !v1 || a1 == PsInitialSystemProcess )
    result = 0;
  else
    result = *(_DWORD *)(*(_DWORD *)(v1 + 44) + 20);
  return result;
}
