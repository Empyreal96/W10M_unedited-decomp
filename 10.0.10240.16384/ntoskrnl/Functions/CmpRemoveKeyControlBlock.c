// CmpRemoveKeyControlBlock 
 
int __fastcall CmpRemoveKeyControlBlock(int a1)
{
  return CmpRemoveKeyHash(*(_DWORD *)(a1 + 20), (_DWORD *)(a1 + 12));
}
