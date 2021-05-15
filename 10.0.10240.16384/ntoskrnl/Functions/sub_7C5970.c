// sub_7C5970 
 
void __fastcall sub_7C5970(int a1)
{
  int v1; // r5

  if ( ((*(_BYTE *)(v1 + 1) ^ *(_BYTE *)(a1 + 1)) & 0xC0) == 0 )
    JUMPOUT(0x6C40DA);
  JUMPOUT(0x6C40F6);
}
