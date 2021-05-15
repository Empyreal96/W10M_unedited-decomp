// CmpRmRecover 
 
int __fastcall CmpRmRecover(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // r1
  _DWORD *varg_r0; // [sp+10h] [bp+8h]

  varg_r0 = a1;
  result = CmpRmAnalysisPhase(a1, a2);
  if ( result >= 0 )
  {
    CmpRmReDoPhase((int)a1, v6, a3, a4);
    result = CmpRmUnDoPhase(a1);
  }
  return result;
}
