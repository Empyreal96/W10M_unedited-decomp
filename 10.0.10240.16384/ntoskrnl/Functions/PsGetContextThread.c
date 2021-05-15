// PsGetContextThread 
 
int __fastcall PsGetContextThread(int a1, int a2, char a3)
{
  return PspGetContextThreadInternal(a1, a2, a3, a3);
}
