// IoMakeAssociatedIrp 
 
int __fastcall IoMakeAssociatedIrp(int a1, char a2)
{
  return IoMakeAssociatedIrpPriv(a1, 0, a2);
}
