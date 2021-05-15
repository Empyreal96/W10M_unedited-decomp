// PsPicoSystemCallDispatch 
 
int __fastcall PsPicoSystemCallDispatch(int a1)
{
  int v2[4]; // [sp+0h] [bp-10h] BYREF

  v2[0] = a1;
  dword_61D9C4(v2);
  return *(_DWORD *)(v2[0] + 96);
}
