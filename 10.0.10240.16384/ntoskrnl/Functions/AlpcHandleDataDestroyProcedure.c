// AlpcHandleDataDestroyProcedure 
 
int __fastcall AlpcHandleDataDestroyProcedure(int a1)
{
  int v2; // r3

  v2 = *(_DWORD *)(a1 + 16);
  if ( v2 )
  {
    ObpDecrementHandleCount(*(_DWORD *)(a1 + 8), v2 - 24);
    ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 16));
    ObfDereferenceObjectWithTag(*(_DWORD *)(a1 + 8));
    *(_DWORD *)(a1 + 16) = 0;
  }
  return 0;
}
