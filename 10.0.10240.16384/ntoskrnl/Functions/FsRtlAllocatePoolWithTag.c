// FsRtlAllocatePoolWithTag 
 
int __fastcall FsRtlAllocatePoolWithTag(int a1, int a2)
{
  int result; // r0

  result = ExAllocatePoolWithTag(a1, a2);
  if ( !result )
    RtlRaiseStatus(-1073741670);
  return result;
}
