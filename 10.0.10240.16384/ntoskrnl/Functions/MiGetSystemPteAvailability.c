// MiGetSystemPteAvailability 
 
int __fastcall MiGetSystemPteAvailability(int a1, int a2)
{
  unsigned int v2; // r0
  int result; // r0

  if ( a2 == 16 )
    v2 = 2;
  else
    v2 = 1;
  if ( dword_635310 >= 0x4000000 / v2 )
    result = 1;
  else
    result = sub_5214C4();
  return result;
}
