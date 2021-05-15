// MmGetSessionGlobalVA 
 
int __fastcall MmGetSessionGlobalVA(int a1)
{
  int result; // r0

  if ( PsIsSystemProcess(a1) )
    result = 0;
  else
    result = *(_DWORD *)(a1 + 324);
  return result;
}
