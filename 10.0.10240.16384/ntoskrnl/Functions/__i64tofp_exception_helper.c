// __i64tofp_exception_helper 
 
__int64 __fastcall _i64tofp_exception_helper(int a1, int a2, int a3, int _R3)
{
  int v4; // s0
  int v5; // s1

  __asm { VMSR            FPSCR, R3 }
  return _fphelper_raise_exception((unsigned __int8)a3, BYTE1(a3), BYTE2(a3), HIBYTE(a3), v4, v5);
}
