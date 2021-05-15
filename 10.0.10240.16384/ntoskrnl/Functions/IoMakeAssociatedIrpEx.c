// IoMakeAssociatedIrpEx 
 
int __fastcall IoMakeAssociatedIrpEx(int a1, int a2, char a3)
{
  return IoMakeAssociatedIrpPriv(a1, a2, a3);
}
