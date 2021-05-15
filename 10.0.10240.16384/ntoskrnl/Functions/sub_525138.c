// sub_525138 
 
void sub_525138()
{
  KeSetEvent((int)&CcLowMemoryEvent, 0, 0);
  JUMPOUT(0x45EC14);
}
