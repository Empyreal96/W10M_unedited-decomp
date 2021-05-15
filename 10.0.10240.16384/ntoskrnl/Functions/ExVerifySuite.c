// ExVerifySuite 
 
BOOL __fastcall ExVerifySuite(int a1)
{
  return a1 <= 17 && ((1 << a1) & dword_6416B0) != 0;
}
