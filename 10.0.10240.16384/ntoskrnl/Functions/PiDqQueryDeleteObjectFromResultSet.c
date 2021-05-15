// PiDqQueryDeleteObjectFromResultSet 
 
int __fastcall PiDqQueryDeleteObjectFromResultSet(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // [sp+Ch] [bp-4h] BYREF

  v5 = a2;
  result = RtlDeleteElementGenericTableAvl(a1 + 36, (int)&v5, a3, a4);
  if ( result )
    result = PiDmObjectRelease(v5);
  return result;
}
