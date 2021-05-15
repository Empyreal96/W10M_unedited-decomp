// sub_7C1808 
 
int __fastcall sub_7C1808(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r4
  int v10; // r6
  int v11; // r7
  int v13; // [sp+14h] [bp-2Ch]
  int (__fastcall *v14)(int); // [sp+3Ch] [bp-4h]

  ObfDereferenceObject(a1);
  if ( (*(_DWORD *)(v10 + 136) & 0x80000) != 0 )
    EtwTraceJobAssignProcess(v13, a9, v11);
  return v14(v9);
}
