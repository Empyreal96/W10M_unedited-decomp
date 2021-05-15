// sub_7EB23C 
 
void __fastcall sub_7EB23C(int a1, _DWORD *a2)
{
  if ( *a2 != a1 )
    PspApplyWorkingSetLimits(a1);
  JUMPOUT(0x707E14);
}
