// sub_54B104 
 
void sub_54B104(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, ...)
{
  int v18; // r4
  int *v19; // r5
  unsigned __int16 *v20; // r4
  va_list va; // [sp+38h] [bp+38h] BYREF

  va_start(va, a18);
  if ( PopDiagGetDriverName(v18, (char *)va, 64) < 0 )
    v20 = (unsigned __int16 *)&word_5CB8A8;
  else
    va_copy((va_list)v20, va);
  wcslen(v20);
  EtwWrite(*v19, v19[1], (int)POP_ETW_EVENT_IRP_DRIVERACQUIRE, 0);
  JUMPOUT(0x4D25D0);
}
