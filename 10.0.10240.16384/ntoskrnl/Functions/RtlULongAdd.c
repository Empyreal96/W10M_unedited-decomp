// RtlULongAdd 
 
int __fastcall RtlULongAdd(unsigned int a1, int a2, _DWORD *a3)
{
  int v3; // r3
  int result; // r0

  v3 = a1 + a2;
  if ( a1 + a2 < a1 )
    return sub_50CF28();
  result = 0;
  *a3 = v3;
  return result;
}
