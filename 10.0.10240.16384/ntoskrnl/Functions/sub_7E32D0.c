// sub_7E32D0 
 
void __fastcall sub_7E32D0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, unsigned __int16 a19, unsigned __int16 *a20)
{
  int v20; // r3
  unsigned __int16 *i; // r6

  if ( a20 && a19 > 2u )
  {
    v20 = *a20;
    for ( i = a20; v20 && !PipCheckComputerSupported(i); v20 = *i )
      i += wcslen(i) + 1;
    if ( !*i )
      JUMPOUT(0x77C086);
  }
  JUMPOUT(0x77BDDA);
}
