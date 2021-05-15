// sub_553BEC 
 
void __fastcall sub_553BEC(int a1)
{
  int v1; // r4

  if ( (unsigned int)(a1 - 2048) < 0x400 )
  {
    if ( *(_DWORD *)(v1 + 1324) )
      JUMPOUT(0x4F49FC);
  }
  JUMPOUT(0x4F4A0A);
}
