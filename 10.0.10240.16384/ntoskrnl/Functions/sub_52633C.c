// sub_52633C 
 
void __fastcall sub_52633C(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5

  MiLockVad(a4 & 0xFFFFFFC0, v4);
  MiUnlockAndDereferenceVad(v4);
  *(_DWORD *)(v5 + 8) = 0;
  JUMPOUT(0x4613AA);
}
