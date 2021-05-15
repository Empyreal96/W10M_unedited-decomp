// sub_51B034 
 
void __fastcall sub_51B034(int a1, int a2, _DWORD *a3)
{
  if ( !*a3 && (KiBugCheckActive & 3) == 0 )
    __debugbreak();
  JUMPOUT(0x442A6A);
}
