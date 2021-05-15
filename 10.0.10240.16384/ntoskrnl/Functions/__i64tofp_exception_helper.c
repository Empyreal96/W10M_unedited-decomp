// __i64tofp_exception_helper 
 
int __fastcall _i64tofp_exception_helper(int a1, int a2, int a3, int _R3)
{
  int v4; // s0
  int v5; // s1
  int v11; // [sp+8h] [bp-10h]
  int v12; // [sp+Ch] [bp-Ch]

  __asm { VMSR            FPSCR, R3 }
  return _fphelper_raise_exception((unsigned __int8)a3, BYTE1(a3), SBYTE2(a3), SHIBYTE(a3), v4, v5, v11, v12);
}
