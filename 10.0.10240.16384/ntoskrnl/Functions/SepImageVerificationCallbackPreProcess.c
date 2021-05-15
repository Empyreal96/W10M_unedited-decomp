// SepImageVerificationCallbackPreProcess 
 
int __fastcall SepImageVerificationCallbackPreProcess(int a1, int a2, _DWORD *a3, _DWORD *a4, unsigned int a5)
{
  int result; // r0

  result = memmove((int)a3, (int)a4, a5);
  a3[3] = (char *)a3 + a4[3] - (_DWORD)a4;
  a3[7] = (char *)a3 + a4[7] - (_DWORD)a4;
  a3[9] = (char *)a3 + a4[9] - (_DWORD)a4;
  a3[10] = (char *)a3 + a4[10] - (_DWORD)a4;
  a3[11] = (char *)a3 + a4[11] - (_DWORD)a4;
  return result;
}
