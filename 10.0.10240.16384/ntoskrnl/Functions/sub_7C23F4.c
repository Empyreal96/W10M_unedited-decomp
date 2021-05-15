// sub_7C23F4 
 
void __fastcall sub_7C23F4(int a1, int a2, int a3, int a4, char a5)
{
  if ( RtlCheckTokenMembership(0, SeAliasAdminsSid, (int)&a5) >= 0 )
  {
    if ( a5 )
      JUMPOUT(0x6ACADE);
  }
  JUMPOUT(0x6ACAE4);
}
