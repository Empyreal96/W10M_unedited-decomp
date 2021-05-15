// IoPropagateIrpExtension 
 
int __fastcall IoPropagateIrpExtension(int a1, int a2, char a3)
{
  return IoPropagateIrpExtensionEx(a1, a2, 0, 0, a3);
}
