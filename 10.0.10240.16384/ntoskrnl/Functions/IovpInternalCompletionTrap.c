// IovpInternalCompletionTrap 
 
int __fastcall IovpInternalCompletionTrap(int a1, int a2)
{
  if ( *(_BYTE *)(a2 + 33) )
    *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
  return 0;
}
