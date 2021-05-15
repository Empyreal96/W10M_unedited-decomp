// SeCreateAccessStateEx 
 
int __fastcall SeCreateAccessStateEx(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  SeCaptureSubjectContextEx(a1, a2, v9);
  return SepCreateAccessStateFromSubjectContext(v9, a3, a4, a5, a6);
}
