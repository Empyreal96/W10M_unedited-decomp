// sub_7CDCCC 
 
void __fastcall sub_7CDCCC(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r4

  *(_DWORD *)(v5 + 68) = a5;
  *(_DWORD *)(v5 + 72) = a1;
  DbgPrintEx(126, 2, (int)"COV: Stored coverage section in PsLoadedModuleList at 0x%p\n", v5);
  ExCovReadjustUnloadedModuleEntry(v5);
  JUMPOUT(0x772B92);
}
