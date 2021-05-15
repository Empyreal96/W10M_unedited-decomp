// IopCancelIrpsInCurrentThreadListApcRoutine 
 
int __fastcall IopCancelIrpsInCurrentThreadListApcRoutine(int a1)
{
  *(_DWORD *)(a1 + 76) |= IopCancelIrpsInCurrentThreadList(
                            *(_DWORD *)(a1 + 48),
                            __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
                            *(_DWORD *)(a1 + 52),
                            *(unsigned __int8 *)(a1 + 72));
  return KeSetEvent(a1 + 56, 0, 0);
}
