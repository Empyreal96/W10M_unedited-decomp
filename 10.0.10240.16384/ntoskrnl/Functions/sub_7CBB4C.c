// sub_7CBB4C 
 
void __fastcall sub_7CBB4C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, unsigned int a12)
{
  unsigned int v12; // r5

  ExFreePoolWithTag(v12);
  if ( RtlULongLongToULong(2 * a12, (unsigned __int64)a12 >> 31, &a10) >= 0 )
  {
    if ( !ExAllocatePoolWithTag(1, a10, 1380994640) )
      JUMPOUT(0x76E570);
    JUMPOUT(0x76E556);
  }
  JUMPOUT(0x76E5E2);
}
