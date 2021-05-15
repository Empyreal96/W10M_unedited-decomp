// sub_7DFACC 
 
void sub_7DFACC(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( PipGrowDeviceObjectList((int *)va) < 0 )
    JUMPOUT(0x775B66);
  JUMPOUT(0x775B40);
}
