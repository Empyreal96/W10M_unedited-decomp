// SdbpInitializeSearchDBContext 
 
int __fastcall SdbpInitializeSearchDBContext(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int result; // r0
  unsigned __int16 *v7; // r5
  int v8; // r0
  unsigned int v9; // r6
  int v10; // r7
  int v11; // r8
  unsigned __int16 *v12; // r0

  v5 = *(_DWORD *)(a1 + 36);
  if ( v5 )
    return 1;
  v7 = *(unsigned __int16 **)(a1 + 32);
  if ( !v7 )
  {
    if ( (*(_DWORD *)a1 & 2) != 0 || (v8 = *(_DWORD *)(a1 + 28)) == 0 )
    {
      v9 = wcslen(*(unsigned __int16 **)(a1 + 16));
      v10 = wcslen(*(unsigned __int16 **)(a1 + 20));
      v11 = v10 + v9;
      v12 = (unsigned __int16 *)AslAlloc(v10, v11 * 2 + 2);
      v7 = v12;
      if ( !v12 )
      {
        AslLogCallPrintf(1, (int)"SdbpInitializeSearchDBContext", 300, "Failed to allocate process history buffer", a4);
        return 0;
      }
      memmove((int)v12, *(_DWORD *)(a1 + 16), 2 * v9);
      memmove((int)&v7[v9], *(_DWORD *)(a1 + 20), 2 * v10);
      v5 = 0;
      v7[v11] = 0;
    }
    else
    {
      v7 = (unsigned __int16 *)SdbpGetProcessHistory(v8, *(_DWORD *)(a1 + 16), *(_DWORD *)(a1 + 20));
      if ( !v7 )
      {
        AslLogCallPrintf(1, (int)"SdbpInitializeSearchDBContext", 315, "Failed to retrieve process history", a4);
        return 0;
      }
    }
  }
  *(_DWORD *)(a1 + 32) = v7;
  result = SdbpCreateSearchPathPartsFromPath(v7, (_DWORD *)(a1 + 36), a3, v5);
  if ( result )
    *(_DWORD *)a1 |= 1u;
  return result;
}
