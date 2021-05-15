// KeInitializeEnumerationContext 
 
int __fastcall KeInitializeEnumerationContext(int result, int a2)
{
  int v2; // r3

  *(_WORD *)(result + 8) = 0;
  v2 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)result = a2;
  *(_DWORD *)(result + 4) = v2;
  return result;
}
