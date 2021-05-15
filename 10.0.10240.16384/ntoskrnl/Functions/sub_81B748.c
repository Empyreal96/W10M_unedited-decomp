// sub_81B748 
 
void sub_81B748(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r4
  __int16 *v11; // r1
  va_list va; // [sp+18h] [bp+18h] BYREF

  va_start(va, a10);
  if ( v10 == 2 )
  {
    v11 = L"CMFStartTime";
  }
  else
  {
    if ( v10 != 4 )
      JUMPOUT(0x7BAA0E);
    v11 = L"CMFStopTime";
  }
  RtlInitUnicodeString((unsigned int)va, (unsigned __int16 *)v11);
  JUMPOUT(0x7BA9F4);
}
