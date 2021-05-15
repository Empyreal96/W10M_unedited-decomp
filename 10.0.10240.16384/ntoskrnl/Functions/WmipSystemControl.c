// WmipSystemControl 
 
int __fastcall WmipSystemControl(int a1, int a2)
{
  return IoWMISystemControl(a1, a1, a2);
}
