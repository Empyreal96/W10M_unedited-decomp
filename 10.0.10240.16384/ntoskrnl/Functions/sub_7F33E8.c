// sub_7F33E8 
 
void sub_7F33E8()
{
  _BYTE *v0; // r6
  unsigned __int64 v1; // kr00_8

  if ( *v0 )
  {
    __dmb(0xBu);
    do
      v1 = __ldrexd((unsigned __int64 *)&PpmCheckLastExecutionTime);
    while ( __strexd(0i64, (unsigned __int64 *)&PpmCheckLastExecutionTime) );
    __dmb(0xBu);
    *v0 = 0;
  }
  JUMPOUT(0x70C99A);
}
