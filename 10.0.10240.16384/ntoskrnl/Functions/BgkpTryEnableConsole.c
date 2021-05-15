// BgkpTryEnableConsole 
 
int BgkpTryEnableConsole()
{
  int result; // r0
  unsigned int v1; // r1

  if ( byte_63761D && dword_637614 )
  {
    __dmb(0xBu);
    result = 0;
    do
      v1 = __ldrex((unsigned int *)&dword_61646C);
    while ( __strex(0, (unsigned int *)&dword_61646C) );
    __dmb(0xBu);
  }
  return result;
}
