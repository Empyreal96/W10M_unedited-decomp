// KiIntSteerSetDestination 
 
int __fastcall KiIntSteerSetDestination(int a1, int a2)
{
  int v4; // r3
  int result; // r0

  if ( KiIntSteerVerifyDestination() < 0 )
    sub_51FCE4();
  v4 = *(_DWORD *)(a1 + 96);
  if ( v4 != 1 && v4 != 3 || (result = off_617ADC(*(_DWORD *)(a1 + 16), a1 + 24, a2), result < 0) )
    KeBugCheckEx(160, 16385, 258);
  return result;
}
