// VfMajorRegisterHandlers 
 
unsigned int __fastcall VfMajorRegisterHandlers(unsigned int result, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  _DWORD *v14; // r2

  if ( result == 255 || result <= 0x1B )
  {
    if ( result > 0x1B )
      result = 28;
    v14 = &ViMajorVerifierRoutines[48 * result];
    v14[1] = a3;
    v14[2] = a4;
    *v14 = a2;
    v14[3] = a5;
    v14[4] = a6;
    v14[5] = a7;
    v14[6] = a8;
    v14[7] = a9;
    v14[8] = a10;
    v14[9] = a11;
    v14[10] = a12;
    v14[11] = a13;
  }
  return result;
}
