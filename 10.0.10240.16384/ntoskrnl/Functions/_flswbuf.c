// _flswbuf 
 
int __fastcall flswbuf(int a1, int a2)
{
  int result; // r0

  result = 0xFFFF;
  *(_DWORD *)(a2 + 12) |= 0x20u;
  return result;
}
