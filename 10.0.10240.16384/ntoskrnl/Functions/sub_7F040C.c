// sub_7F040C 
 
void __fastcall sub_7F040C(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7)
{
  _DWORD *v7; // r6

  if ( RtlULongLongToULong(2 * *v7, (unsigned __int64)(unsigned int)*v7 >> 31, &a7) >= 0 )
  {
    if ( a7 + 16 >= a7 )
      JUMPOUT(0x78554A);
    JUMPOUT(0x7855DA);
  }
  JUMPOUT(0x7855CE);
}
