// RtlStringCbCopyA 
 
int __fastcall RtlStringCbCopyA(int a1)
{
  int v2; // r1
  int v3; // r2
  int result; // r0

  if ( sub_43E028() >= 0 )
    result = sub_4E1E80(a1, v2, 0, v3);
  else
    result = sub_50A20C();
  return result;
}
