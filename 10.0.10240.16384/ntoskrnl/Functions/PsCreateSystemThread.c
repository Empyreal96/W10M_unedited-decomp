// PsCreateSystemThread 
 
int __fastcall PsCreateSystemThread(int a1, int a2, int a3)
{
  return PsCreateSystemThreadEx(a1, a2, a3);
}
