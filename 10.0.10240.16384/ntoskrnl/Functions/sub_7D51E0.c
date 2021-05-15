// sub_7D51E0 
 
void __fastcall sub_7D51E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, unsigned int a13, int a14)
{
  if ( SepScheduleImageVerificationCallbacks(a1, a14) < 0 )
    ExFreePoolWithTag(a13);
  JUMPOUT(0x6D7E8E);
}
