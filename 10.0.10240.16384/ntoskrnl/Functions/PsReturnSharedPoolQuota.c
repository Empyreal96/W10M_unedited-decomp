// PsReturnSharedPoolQuota 
 
int __fastcall PsReturnSharedPoolQuota(int result, unsigned int a2, int a3)
{
  int v3; // r4

  v3 = result;
  if ( result != 1 )
  {
    if ( a2 )
      result = PspReturnQuota(result, 0, 1, a2);
    if ( a3 )
      result = sub_7C03B8(result);
    else
      result = PspDereferenceQuotaBlock(v3);
  }
  return result;
}
