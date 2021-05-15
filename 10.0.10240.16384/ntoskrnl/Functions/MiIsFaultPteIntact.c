// MiIsFaultPteIntact 
 
BOOL __fastcall MiIsFaultPteIntact(unsigned int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v7; // r0
  BOOL result; // r0
  int v9; // [sp+0h] [bp-18h] BYREF
  _DWORD v10[5]; // [sp+4h] [bp-14h] BYREF

  v9 = a2;
  v10[0] = a3;
  v10[1] = a4;
  v7 = (_DWORD *)MiFindActualFaultingPte();
  result = v7
        && (v7 == (_DWORD *)a2
         || (*v7 & 0x400) != 0
         && ((*v7 & 0xFFFFE000) == -8192 ? (v7 = (_DWORD *)MiCheckVirtualAddress(a1, v10, &v9)) : (v7 = (_DWORD *)((*v7 & 0x1FC | (*v7 >> 2) & 0x3FFFFE00) - 0x40000000)),
             v7 == (_DWORD *)a2))
        && *v7 == *a3;
  return result;
}
