// CcSaveNVContext 
 
int __fastcall CcSaveNVContext(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r7
  int v9; // r8
  int v10; // r9
  int v11; // r10
  int v12; // r11

  *(_DWORD *)(a1 + 20) = v5;
  *(_DWORD *)(a1 + 24) = v6;
  *(_DWORD *)(a1 + 28) = v7;
  *(_DWORD *)(a1 + 32) = v8;
  *(_DWORD *)(a1 + 36) = v9;
  *(_DWORD *)(a1 + 40) = v10;
  *(_DWORD *)(a1 + 44) = v11;
  *(_DWORD *)(a1 + 48) = v12;
  *(_DWORD *)(a1 + 56) = &a5;
  *(_DWORD *)a1 = 2097159;
  return (*(int (**)(void))(a1 + 64))();
}
