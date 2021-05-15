// sub_54B6C4 
 
void __fastcall sub_54B6C4(int a1)
{
  int v1; // r7

  if ( ExfAcquireRundownProtection((_DWORD *)(a1 + v1)) )
    JUMPOUT(0x4D3ACC);
  JUMPOUT(0x4D3B54);
}
