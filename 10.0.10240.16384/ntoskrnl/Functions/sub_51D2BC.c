// sub_51D2BC 
 
void __fastcall sub_51D2BC(int a1, int a2, _DWORD *a3)
{
  if ( (*a3 & 0x40000) != 0 )
  {
    EtwTraceMemoryAcg(0x80000000, a2);
    JUMPOUT(0x44A084);
  }
  JUMPOUT(0x44A07C);
}
