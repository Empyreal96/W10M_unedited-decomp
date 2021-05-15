// IopPnPCompleteRequest 
 
int __fastcall IopPnPCompleteRequest(int a1, __int64 a2)
{
  *(_QWORD *)(a1 + 24) = a2;
  return pIofCompleteRequest(a1, 0);
}
