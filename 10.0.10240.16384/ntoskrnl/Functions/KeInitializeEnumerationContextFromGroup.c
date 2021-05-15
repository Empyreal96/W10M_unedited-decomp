// KeInitializeEnumerationContextFromGroup 
 
int __fastcall KeInitializeEnumerationContextFromGroup(int result, int *a2)
{
  int v2; // r2

  v2 = *a2;
  *(_WORD *)(result + 8) = *((_WORD *)a2 + 2);
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 4) = v2;
  return result;
}
