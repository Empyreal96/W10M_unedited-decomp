// WheapFillOutErrorRecord 
 
int __fastcall WheapFillOutErrorRecord(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v4)(int, int, int, int); // r4

  v4 = (int (__fastcall *)(int, int, int, int))dword_649F64[7 * *(_DWORD *)(a3 + 32)];
  __dmb(0xBu);
  return v4(a3 + 73, a2, a4, a1);
}
