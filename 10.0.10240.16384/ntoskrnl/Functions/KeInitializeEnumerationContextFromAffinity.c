// KeInitializeEnumerationContextFromAffinity 
 
int __fastcall KeInitializeEnumerationContextFromAffinity(int result, __int16 a2, int a3)
{
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 4) = a3;
  *(_WORD *)(result + 8) = a2;
  return result;
}
