// ViFilterGenericCompletionRoutine 
 
int __fastcall ViFilterGenericCompletionRoutine(int a1, int a2)
{
  if ( *(_BYTE *)(a2 + 33) )
    *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
  IoReleaseRemoveLockEx(*(_DWORD *)(a1 + 40) + 16, a2, 24);
  return 0;
}
