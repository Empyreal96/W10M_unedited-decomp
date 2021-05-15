// PsGetProcessCreateTimeQuadPart 
 
__int64 __fastcall PsGetProcessCreateTimeQuadPart(int a1)
{
  return *(_QWORD *)(a1 + 200);
}
