// RtlpOpenImageFileOptionsKey 
 
int RtlpOpenImageFileOptionsKey()
{
  int result; // r0
  int v1; // [sp+0h] [bp-30h] BYREF

  result = RtlpOpenBaseImageFileOptionsKey(&v1);
  if ( result >= 0 )
    result = sub_7E87A0();
  return result;
}
