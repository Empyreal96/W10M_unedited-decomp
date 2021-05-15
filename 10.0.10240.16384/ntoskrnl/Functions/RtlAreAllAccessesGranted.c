// RtlAreAllAccessesGranted 
 
BOOL __fastcall RtlAreAllAccessesGranted(int a1, int a2)
{
  return (a2 & ~a1) == 0;
}
