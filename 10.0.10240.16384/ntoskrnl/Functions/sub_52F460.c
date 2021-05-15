// sub_52F460 
 
void __fastcall sub_52F460(int a1, int a2)
{
  if ( a1 != PsInitialSystemProcess && a1 != PsIdleProcess )
  {
    if ( *(_DWORD *)(a1 + 804) != a2 )
      PsIsSiloInSilo();
    JUMPOUT(0x48331A);
  }
  JUMPOUT(0x483318);
}
