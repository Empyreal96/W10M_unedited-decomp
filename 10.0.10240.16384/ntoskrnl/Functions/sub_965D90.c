// sub_965D90 
 
void __fastcall sub_965D90(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r4
  _DWORD *v5; // r8
  int v6; // lr

  *(_DWORD *)(v4 + 4) = a4 >> 1;
  *(_DWORD *)(v4 + 8) = *(_DWORD *)(*(_DWORD *)a1 + 3592) >> 3;
  CcMaxLazyWritePages = 0x2000;
  *v5 = v6 - 1;
  CcExtraWBThreadDelay = 5000000;
  JUMPOUT(0x949368);
}
