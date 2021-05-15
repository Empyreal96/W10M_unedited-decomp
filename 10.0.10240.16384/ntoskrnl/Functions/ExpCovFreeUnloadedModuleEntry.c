// ExpCovFreeUnloadedModuleEntry 
 
int __fastcall ExpCovFreeUnloadedModuleEntry(_DWORD *a1)
{
  unsigned int v2; // r0

  if ( !a1 )
    return -1073741811;
  if ( a1[3] )
    RtlFreeAnsiString(a1 + 2);
  if ( a1[5] )
    RtlFreeAnsiString(a1 + 4);
  v2 = a1[7];
  if ( v2 )
    ExFreePoolWithTag(v2);
  ExFreePoolWithTag((unsigned int)a1);
  return 0;
}
