// sub_555970 
 
void __fastcall sub_555970(int a1)
{
  KeFlushSingleTb(a1 << 10, 1);
  JUMPOUT(0x4F8988);
}
