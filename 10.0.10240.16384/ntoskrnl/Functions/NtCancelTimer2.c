// NtCancelTimer2 
 
int __fastcall NtCancelTimer2(int a1)
{
  return ExpSetTimer2(a1, 0, 0);
}
