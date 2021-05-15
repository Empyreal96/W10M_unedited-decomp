// SeCreateAccessState 
 
int __fastcall SeCreateAccessState(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD v9[10]; // [sp+8h] [bp-28h] BYREF

  SeCaptureSubjectContextEx(
    __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
    v9);
  return SepCreateAccessStateFromSubjectContext(v9, a1, a2, a3, a4);
}
