// PspReleaseProcessQuota 
 
int __fastcall PspReleaseProcessQuota(int a1)
{
  int result; // r0
  unsigned int *v2; // r2
  unsigned int v3; // r1

  result = *(_DWORD *)(a1 + 332);
  if ( result )
  {
    __dmb(0xBu);
    v2 = (unsigned int *)(result + 1028);
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 - 1, v2) );
    __dmb(0xBu);
    result = PspDereferenceQuotaBlock(result);
  }
  return result;
}
