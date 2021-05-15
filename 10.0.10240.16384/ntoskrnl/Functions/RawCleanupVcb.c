// RawCleanupVcb 
 
int __fastcall RawCleanupVcb(_DWORD *a1)
{
  unsigned int v2; // r0
  int result; // r0
  int v4; // r1

  v2 = a1[36];
  if ( !v2 )
    return sub_7CFF34();
  ExFreePoolWithTag(v2);
  a1[36] = 0;
  if ( (a1[18] & 0x10) != 0 )
    FsRtlTeardownPerStreamContexts((int)a1, v4);
  result = a1[39];
  if ( result )
    result = ExFreeCacheAwareRundownProtection(result);
  a1[39] = 0;
  return result;
}
