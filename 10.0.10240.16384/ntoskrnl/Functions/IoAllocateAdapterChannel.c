// IoAllocateAdapterChannel 
 
int __fastcall IoAllocateAdapterChannel(int a1)
{
  return (*(int (**)(void))(*(_DWORD *)(a1 + 4) + 16))();
}
