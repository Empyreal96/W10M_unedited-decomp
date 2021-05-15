// MI_CHECK_KERNEL_NOEXECUTE_FAULT 
 
int __fastcall MI_CHECK_KERNEL_NOEXECUTE_FAULT(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = result;
  if ( (result & 8) != 0 )
    result = sub_514614();
  return result;
}
