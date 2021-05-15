// sub_817F78 
 
void __fastcall sub_817F78(int a1, int a2, int a3, int a4, __int16 a5, int a6)
{
  int v6; // r7

  if ( RtlpLoadPolicyLanguageSpec(a6, v6, &a5, &a5 + 1) < 0 )
  {
    NtClose();
    JUMPOUT(0x7B12A8);
  }
  JUMPOUT(0x7B12E8);
}
