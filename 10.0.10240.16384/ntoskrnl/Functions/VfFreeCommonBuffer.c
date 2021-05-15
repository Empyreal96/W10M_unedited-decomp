// VfFreeCommonBuffer 
 
int VfFreeCommonBuffer(int a1, int a2, ...)
{
  int (__fastcall *v4)(int, int, int, int); // r6
  int v5; // r4
  int v6; // r0
  int v7; // r5
  int result; // r0
  int varg_r2; // [sp+38h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]
  int v12; // [sp+40h] [bp+18h]
  int v13; // [sp+44h] [bp+1Ch]
  va_list va1; // [sp+48h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v12 = va_arg(va1, _DWORD);
  v13 = va_arg(va1, _DWORD);
  v4 = (int (__fastcall *)(int, int, int, int))ViGetRealDmaOperation(a1, 12);
  v5 = ViGetAdapterInformationInternal(a1, 1);
  v6 = ViHalFreeDomainCommonBuffer((int *)varg_r2a);
  v7 = v6;
  if ( !v5 || v6 || (VF_ASSERT_IRQL(0), (result = ViSpecialFreeCommonBuffer(v4, v5, v12, (unsigned __int8)v13)) == 0) )
  {
    result = v4(a1, a2, varg_r2, varg_r3);
    if ( v5 )
    {
      if ( !v7 )
        result = DECREMENT_COMMON_BUFFERS(v5);
    }
  }
  return result;
}
