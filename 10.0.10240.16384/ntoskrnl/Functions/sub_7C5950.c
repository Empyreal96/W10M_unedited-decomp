// sub_7C5950 
 
void __fastcall sub_7C5950(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  unsigned __int8 *v4; // r5
  unsigned int v5; // r3

  v5 = *v4;
  if ( v5 >= 5 && v5 <= 8 )
  {
    RtlpCompareKnownObjectAces(v3, v4);
    JUMPOUT(0x6C4046);
  }
  if ( a3 >= 5 )
    JUMPOUT(0x6C404A);
  JUMPOUT(0x6C4038);
}
