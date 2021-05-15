// sub_7E7554 
 
void sub_7E7554(int a1, int a2, int a3, int a4, ...)
{
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( ExpWnfAllocateNextPersistentNameSequence((char *)va) < 0 )
    JUMPOUT(0x6F4FBE);
  JUMPOUT(0x6F4F58);
}
