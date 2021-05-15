// sub_51B458 
 
void __fastcall sub_51B458(int a1)
{
  __mcr(15, 0, a1 | 0xF00000, 1, 0, 2);
  __isb(0xFu);
  JUMPOUT(0x442DAE);
}
