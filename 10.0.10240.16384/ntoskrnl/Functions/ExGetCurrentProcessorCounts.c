// ExGetCurrentProcessorCounts 
 
int __fastcall ExGetCurrentProcessorCounts(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // r4
  int result; // r0

  v3 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  *a1 = *(_DWORD *)(v3[355] + 404);
  result = v3[930];
  *a2 = v3[929] + result;
  *a3 = v3[357];
  return result;
}
