// VfGetVerifierInformationEx 
 
int __fastcall VfGetVerifierInformationEx(int a1)
{
  int v2; // r3
  int v3; // r2

  memset((_BYTE *)a1, 0, 36);
  *(_DWORD *)a1 = VfVerifyMode;
  v2 = dword_620DE8;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4) = v2;
  v3 = VfWdCancelTimeoutTicks;
  __dmb(0xBu);
  *(_DWORD *)(a1 + 16) = 1000 * v3;
  *(_DWORD *)(a1 + 20) = XdvEnabled;
  return 0;
}
