// IoIsOperationSynchronous 
 
BOOL __fastcall IoIsOperationSynchronous(int a1)
{
  int v1; // r3
  BOOL result; // r0
  int v3; // r3

  result = 0;
  if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 96) + 28) + 44) & 2) != 0
    || (v3 = *(_DWORD *)(a1 + 8), (v3 & 4) != 0)
    || (v3 & 2) != 0 && (v3 & 0x40) != 0 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( (v1 & 2) == 0 || (v1 & 0x40) != 0 )
      result = 1;
  }
  return result;
}
