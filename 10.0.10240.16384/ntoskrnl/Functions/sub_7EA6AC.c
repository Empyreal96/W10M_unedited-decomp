// sub_7EA6AC 
 
void sub_7EA6AC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  unsigned int v10; // r5
  int v11; // r5
  int v12; // [sp+18h] [bp+18h] BYREF
  va_list va; // [sp+18h] [bp+18h]
  void *v14; // [sp+1Ch] [bp+1Ch] BYREF
  va_list va1; // [sp+1Ch] [bp+1Ch]
  va_list va2; // [sp+20h] [bp+20h] BYREF

  va_start(va2, a10);
  va_start(va1, a10);
  va_start(va, a10);
  v12 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v14 = va_arg(va2, void *);
  ExFreePoolWithTag(v10);
  v11 = ExAllocatePoolWithTag(1, v12, 538987843);
  if ( v11 )
  {
    SeQuerySecurityDescriptorInfo((int *)va2, v11, (unsigned int *)va, (int *)va1);
    JUMPOUT(0x7056BE);
  }
  JUMPOUT(0x705714);
}
