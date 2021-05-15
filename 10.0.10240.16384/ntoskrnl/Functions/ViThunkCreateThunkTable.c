// ViThunkCreateThunkTable 
 
int __fastcall ViThunkCreateThunkTable(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // r5
  int v6; // r0
  int v7; // r4

  v3 = a2 >> 3;
  v6 = ExAllocatePoolWithTag(1, 8 * ((a2 >> 3) + 2), 1951821133);
  v7 = v6;
  if ( !v6 )
    return 0;
  memmove(v6 + 16, a1, 8 * v3);
  *(_DWORD *)(v7 + 8) = a3;
  *(_DWORD *)(v7 + 12) = v3;
  return v7;
}
