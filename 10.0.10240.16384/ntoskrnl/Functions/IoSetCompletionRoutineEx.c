// IoSetCompletionRoutineEx 
 
int __fastcall IoSetCompletionRoutineEx(int a1, int a2, int a3, int a4, char a5, char a6, char a7)
{
  int result; // r0
  int v12; // r0
  int v13; // r2

  if ( !a6 )
    return sub_5206CC();
  v12 = ExAllocatePoolWithTag(512, 16, 1934978889);
  if ( !v12 )
    return -1073741670;
  *(_DWORD *)v12 = a1;
  *(_DWORD *)(v12 + 4) = a4;
  *(_DWORD *)(v12 + 8) = a3;
  *(_BYTE *)(v12 + 12) = a6;
  *(_BYTE *)(v12 + 13) = a5;
  *(_BYTE *)(v12 + 14) = a7;
  v13 = *(_DWORD *)(a2 + 96);
  *(_DWORD *)(v13 - 8) = IopUnloadSafeCompletion;
  *(_DWORD *)(v13 - 4) = v12;
  result = 0;
  *(_BYTE *)(v13 - 37) = -32;
  return result;
}
