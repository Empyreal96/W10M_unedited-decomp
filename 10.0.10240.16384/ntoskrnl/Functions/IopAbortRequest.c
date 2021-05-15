// IopAbortRequest 
 
int __fastcall IopAbortRequest(int a1)
{
  return IopCompleteRequest(a1, a1 + 28, (_DWORD *)(a1 + 32), (_DWORD **)(a1 + 36), (_DWORD *)(a1 + 40));
}
