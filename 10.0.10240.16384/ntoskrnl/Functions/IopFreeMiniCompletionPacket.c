// IopFreeMiniCompletionPacket 
 
int __fastcall IopFreeMiniCompletionPacket(int result)
{
  int (*v1)(void); // r3

  if ( *(_BYTE *)(result + 8) != 4 )
    return sub_806DA4();
  v1 = *(int (**)(void))(result + 28);
  if ( v1 )
    return v1();
  if ( *(_BYTE *)(result + 36) )
    result = ExFreePoolWithTag(result);
  return result;
}
