// PspDereferenceQuotaBlock 
 
int __fastcall PspDereferenceQuotaBlock(int result)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int v3; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(result + 1024);
  do
  {
    v2 = __ldrex(v1);
    v3 = v2 - 1;
  }
  while ( __strex(v3, v1) );
  __dmb(0xBu);
  if ( !v3 )
    result = sub_7C04D8();
  return result;
}
