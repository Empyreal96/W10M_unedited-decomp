// _flsbuf 
 
int __fastcall flsbuf(int a1, int a2)
{
  int result; // r0

  result = -1;
  *(_DWORD *)(a2 + 12) |= 0x20u;
  return result;
}
