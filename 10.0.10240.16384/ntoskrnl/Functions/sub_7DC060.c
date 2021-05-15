// sub_7DC060 
 
void __fastcall sub_7DC060(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  const char *v5; // r1

  if ( !MmIsSessionInCurrentServerSilo(v4, a2, a3, a4) )
  {
    if ( PsIsCurrentThreadInServerSilo() )
      v5 = "Silo";
    else
      v5 = "Infrastructure";
    DbgPrint("%s doing a Set Token Session Id outside of its range %d\n", v5, v4);
    JUMPOUT(0x6E7134);
  }
  JUMPOUT(0x6E70CC);
}
