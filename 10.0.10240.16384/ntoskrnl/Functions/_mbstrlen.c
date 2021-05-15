// _mbstrlen 
 
int __fastcall mbstrlen(int a1)
{
  int v3; // [sp+0h] [bp-8h] BYREF

  v3 = a1;
  while ( RtlAnsiCharToUnicodeChar(&v3) )
    ;
  return v3 - a1 - 1;
}
