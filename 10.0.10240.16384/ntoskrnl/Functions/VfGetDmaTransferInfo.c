// VfGetDmaTransferInfo 
 
int __fastcall VfGetDmaTransferInfo(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7)
{
  int (__fastcall *v11)(int, int, int, int, int, _DWORD, int, int); // r0
  int v13; // [sp+Ch] [bp-1Ch]

  v13 = a4;
  v11 = (int (__fastcall *)(int, int, int, int, int, _DWORD, int, int))ViGetRealDmaOperation(a1, 68);
  return v11(a1, a2, a3, a4, a5, a6, a7, v13);
}
