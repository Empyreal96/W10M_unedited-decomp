// sub_8086F8 
 
void sub_8086F8()
{
  char v0; // [sp+20h] [bp-68h] BYREF

  PfSnLogScenarioDecision((int)&v0, 0, 0, 15);
  JUMPOUT(0x75B672);
}
