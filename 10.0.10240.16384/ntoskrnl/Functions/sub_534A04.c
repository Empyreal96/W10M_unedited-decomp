// sub_534A04 
 
void __fastcall sub_534A04(int a1)
{
  int v1; // r8
  int v2; // r4

  v2 = *(unsigned __int8 *)(v1 & ~a1);
  if ( v2 == 1 )
  {
    MiUpdatePrefetchPriority();
  }
  else if ( v2 != 3 )
  {
    JUMPOUT(0x48ED44);
  }
  JUMPOUT(0x48EE48);
}
