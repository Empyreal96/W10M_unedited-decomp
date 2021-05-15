// sub_7F5370 
 
void __fastcall sub_7F5370(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v12; // r4
  int v13; // r5

  if ( !v12 )
  {
    a9 = 0;
    a10 = 0;
    a11 = 0;
    a12 = 0;
    SeCaptureSubjectContext(&a9, a2, a3, 0);
  }
  SepAdtIncorporatePerUserPolicy(v13, 1, 0);
  if ( !v12 )
    SeReleaseSubjectContext((int)&a9);
  JUMPOUT(0x715D9E);
}
