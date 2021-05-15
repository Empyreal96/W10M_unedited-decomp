// sub_517420 
 
void __fastcall sub_517420(int a1, int a2, int a3, int a4, int a5, int a6)
{
  char v6; // r3

  __dmb(0xBu);
  v6 = PspDebugFlags;
  __dmb(0xBu);
  if ( (v6 & 2) != 0 )
    __debugbreak();
  __asm { POP.W           {R11,PC} }
}
