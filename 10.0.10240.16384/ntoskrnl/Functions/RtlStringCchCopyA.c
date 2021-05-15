// RtlStringCchCopyA 
 
int __fastcall RtlStringCchCopyA(int a1, unsigned int a2)
{
  int v3; // r1
  int v4; // r2
  int result; // r0

  if ( sub_43E028(a1, a2) >= 0 )
    result = sub_455C10(a1, v3, v4, v4);
  else
    result = sub_50AB88();
  return result;
}
