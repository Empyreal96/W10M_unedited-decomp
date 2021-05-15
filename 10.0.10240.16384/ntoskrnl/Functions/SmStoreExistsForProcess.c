// SmStoreExistsForProcess 
 
BOOL __fastcall SmStoreExistsForProcess(int a1, int a2, int a3, int a4)
{
  int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[1] = a4;
  v5[0] = a1;
  return ((int (__fastcall *)(void *, int *, _DWORD, _DWORD))SmpKeyedStoreEntryGet)(&byte_636CC4, v5, 0, 0) != 0;
}
