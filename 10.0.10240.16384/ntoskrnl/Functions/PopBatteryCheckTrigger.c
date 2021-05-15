// PopBatteryCheckTrigger 
 
int PopBatteryCheckTrigger()
{
  int v1; // r3

  if ( dword_61EDA4 || dword_61EDA8 )
  {
    if ( dword_61EC0C != 1 )
      return sub_7F3778();
    v1 = 1;
  }
  else
  {
    v1 = 0;
  }
  return v1 && PopBatteryCheckTriggerAllBatteries();
}
