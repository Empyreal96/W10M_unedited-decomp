// sub_51B568 
 
void __fastcall sub_51B568(int a1, int a2, char a3)
{
  int v3; // r4

  __asm { VMRS            R3, FPINST }
  *(_DWORD *)(v3 + 116) = _R3;
  if ( (a3 & 0x40) != 0 )
  {
    __asm { VMRS            R3, FPINST2 }
    *(_DWORD *)(v3 + 120) = _R3;
  }
  JUMPOUT(0x44315E);
}
