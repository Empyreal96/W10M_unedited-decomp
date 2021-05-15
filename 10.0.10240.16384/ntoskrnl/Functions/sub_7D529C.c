// sub_7D529C 
 
void __fastcall sub_7D529C(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r8

  if ( a4 == 1 )
  {
    if ( v4 )
    {
      RtlpRunOnceWaitForInit(a1, v5);
      JUMPOUT(0x6D822A);
    }
  }
  else
  {
    if ( a1 != 3 )
      JUMPOUT(0x6D820C);
    if ( !v4 )
      JUMPOUT(0x6D825A);
  }
  JUMPOUT(0x6D826C);
}
