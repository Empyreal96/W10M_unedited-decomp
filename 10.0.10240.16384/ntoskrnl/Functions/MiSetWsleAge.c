// MiSetWsleAge 
 
int __fastcall MiSetWsleAge(int a1, _DWORD *a2, __int16 a3)
{
  int v5; // r0

  v5 = MiRemoveEntryWsle();
  *a2 ^= ((unsigned __int16)*a2 ^ (unsigned __int16)(a3 << 9)) & 0xE00;
  return MiInsertWsle(v5, a2, 0);
}
