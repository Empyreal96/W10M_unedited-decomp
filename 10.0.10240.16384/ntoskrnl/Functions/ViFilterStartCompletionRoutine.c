// ViFilterStartCompletionRoutine 
 
int __fastcall ViFilterStartCompletionRoutine(int a1, int a2)
{
  int v2; // r2

  if ( *(_BYTE *)(a2 + 33) )
    *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
  v2 = *(_DWORD *)(a1 + 40);
  if ( (*(_DWORD *)(*(_DWORD *)(v2 + 4) + 32) & 1) != 0 )
    *(_DWORD *)(a1 + 32) |= 1u;
  IoReleaseRemoveLockEx(v2 + 16, a2, 24);
  return 0;
}
