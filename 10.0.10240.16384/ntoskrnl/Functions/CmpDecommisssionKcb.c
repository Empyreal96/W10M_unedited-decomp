// CmpDecommisssionKcb 
 
unsigned int __fastcall CmpDecommisssionKcb(unsigned int a1)
{
  if ( (*(_DWORD *)(a1 + 4) & 0x80000) != 0 )
    a1 = CmpFreeKeyControlBlock(a1);
  return a1;
}
