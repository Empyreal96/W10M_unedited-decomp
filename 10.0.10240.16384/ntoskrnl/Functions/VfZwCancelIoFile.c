// VfZwCancelIoFile 
 
int __fastcall VfZwCancelIoFile(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckVirtualAddress(a2);
  return pXdvZwCancelIoFile(a1, a2);
}
