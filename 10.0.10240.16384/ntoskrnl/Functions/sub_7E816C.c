// sub_7E816C 
 
void sub_7E816C(int a1, int a2, int a3, int a4, ...)
{
  unsigned int *v4; // r6
  int v5; // r7
  unsigned int v6; // r8
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( !v5 || !RtlIsValidOemCharacter((__int16 *)va) )
  {
    if ( *v4 >= v6 >> 1 )
      JUMPOUT(0x6FA15A);
    JUMPOUT(0x6FA10A);
  }
  JUMPOUT(0x6FA124);
}
