// sub_52799C 
 
void __fastcall sub_52799C(int a1, unsigned int a2)
{
  int v2; // lr
  int v3[3]; // [sp+8h] [bp-60h] BYREF

  if ( a2 <= *(_DWORD *)(v2 + 3604) )
  {
    MiAdvanceFaultList(v3);
    JUMPOUT(0x4DC232);
  }
  JUMPOUT(0x4DC26E);
}
