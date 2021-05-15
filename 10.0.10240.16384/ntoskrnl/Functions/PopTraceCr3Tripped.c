// PopTraceCr3Tripped 
 
void PopTraceCr3Tripped()
{
  int v0[10]; // [sp+8h] [bp-28h] BYREF

  if ( (unsigned int)dword_6163C8 > 5 )
  {
    if ( TlgKeywordOn((int)&dword_6163C8, 0x400000000000i64) )
      TlgWrite(&dword_6163C8, (unsigned __int8 *)dword_414478 + 1, 0, 0, 2, v0);
  }
}
