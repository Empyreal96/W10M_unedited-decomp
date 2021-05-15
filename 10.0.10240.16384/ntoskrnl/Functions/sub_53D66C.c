// sub_53D66C 
 
void __fastcall sub_53D66C(int a1, _DWORD *a2)
{
  unsigned int v2; // r3

  if ( a2[992] < (unsigned int)(a2[1030] + 800) )
  {
    v2 = a2[928];
    __dmb(0xBu);
    if ( v2 > 0x50 )
      JUMPOUT(0x4A2E76);
  }
  JUMPOUT(0x4A2E78);
}
