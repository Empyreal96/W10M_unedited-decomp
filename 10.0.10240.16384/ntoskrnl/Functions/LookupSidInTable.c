// LookupSidInTable 
 
char *__fastcall LookupSidInTable(int a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  char *v7; // r5
  char *v9; // r6
  unsigned int i; // r4

  v7 = 0;
  if ( a2 )
  {
    *a7 = 0;
    v9 = byte_60EAA0;
    for ( i = 0; i < 0x3F; ++i )
    {
      if ( RtlEqualSid(a2, *((unsigned __int16 **)v9 + 4)) )
        break;
      v9 += 100;
    }
    if ( i < 0x3F )
      v7 = &byte_60EAA0[100 * i];
  }
  return v7;
}
