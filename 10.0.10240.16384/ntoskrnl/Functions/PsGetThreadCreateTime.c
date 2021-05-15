// PsGetThreadCreateTime 
 
__int64 __fastcall PsGetThreadCreateTime(int a1)
{
  return *(_QWORD *)(a1 + 832);
}
