// IopBoostThreadCallback 
 
unsigned int __fastcall IopBoostThreadCallback(int a1, unsigned int *a2)
{
  (*(void (__fastcall **)(_DWORD, unsigned int, unsigned int, unsigned int))(a1 + 12))(
    *(_DWORD *)(a1 + 16),
    *a2,
    a2[1],
    a2[2]);
  ObDereferenceObjectDeferDeleteWithTag(*a2);
  return ObDereferenceObjectDeferDeleteWithTag(a2[1]);
}
