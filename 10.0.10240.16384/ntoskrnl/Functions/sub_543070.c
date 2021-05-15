// sub_543070 
 
void __fastcall sub_543070(unsigned int a1)
{
  int v1; // r4
  int v2; // r8

  if ( !a1 )
    __brkdiv0();
  *(_DWORD *)(v2 + 28) = (*(_DWORD *)(v2 + 28) + v1) % a1;
  JUMPOUT(0x4B5F5C);
}
