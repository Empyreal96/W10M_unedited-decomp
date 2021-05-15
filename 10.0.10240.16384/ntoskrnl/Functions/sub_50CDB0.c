// sub_50CDB0 
 
void __fastcall sub_50CDB0(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  __int64 v5; // kr00_8

  v5 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(v4 + 8) = v5;
  *(_DWORD *)(v5 + 4) = a4;
  *(_DWORD *)HIDWORD(v5) = a4;
  JUMPOUT(0x481DF6);
}
