// _swinput_s 
 
int __fastcall swinput_s(int a1, unsigned int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v5[10]; // [sp+8h] [bp-28h] BYREF

  if ( a1 && a3 && a2 <= 0x3FFFFFFF )
  {
    v5[2] = a1;
    v5[3] = 73;
    v5[0] = a1;
    v5[1] = 2 * a2;
    result = winput_s(v5, a3, a4);
  }
  else
  {
    PopPoCoalescinCallback();
    result = -1;
  }
  return result;
}
