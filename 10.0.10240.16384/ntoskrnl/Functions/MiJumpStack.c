// MiJumpStack 
 
int __fastcall MiJumpStack(int a1)
{
  return KeGenericCallDpc((int)MiDoStackCopy, a1);
}
