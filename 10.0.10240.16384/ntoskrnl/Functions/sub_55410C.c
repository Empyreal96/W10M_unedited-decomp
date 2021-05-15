// sub_55410C 
 
void sub_55410C()
{
  int v0; // r4
  int v1; // r0

  if ( ((v0 + 4095) & 0xFFFFF000) != v0 )
  {
    v1 = DbgPrint("(ROUND_UP_TO_POWER2(Size, PAGE_SIZE) == Size)");
    RtlpHeapHandleError(v1);
  }
  JUMPOUT(0x4F5044);
}
