// sub_7663CC 
 
int __fastcall sub_7663CC(int a1)
{
  int result; // r0

  result = EtwKernelProvRegHandle;
  if ( EtwKernelProvRegHandle )
    result = EtwWrite(EtwKernelProvRegHandle, SHIDWORD(EtwKernelProvRegHandle), a1, 0);
  return result;
}
