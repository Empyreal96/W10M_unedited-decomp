// IopUserRundown 
 
int __fastcall IopUserRundown(int a1)
{
  return IoFreeIrp(a1 - 64);
}
