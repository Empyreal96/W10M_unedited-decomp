// PsSetContextThread 
 
int __fastcall PsSetContextThread(int a1, int a2, char a3)
{
  return PspSetContextThreadInternal(a1, a2, a3, a3);
}
