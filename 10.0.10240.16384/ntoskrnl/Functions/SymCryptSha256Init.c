// SymCryptSha256Init 
 
int __fastcall SymCryptSha256Init(_DWORD *a1)
{
  _DWORD *v1; // r4
  int result; // r0

  a1[2] = 0;
  a1[3] = 0;
  *a1 = 0;
  a1[22] = 1779033703;
  a1[23] = -1150833019;
  a1[24] = 1013904242;
  a1[25] = -1521486534;
  v1 = a1 + 26;
  result = 1359893119;
  *v1 = 1359893119;
  v1[1] = -1694144372;
  v1[2] = 528734635;
  v1[3] = 1541459225;
  return result;
}
