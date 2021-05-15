// sub_7D6BA0 
 
void sub_7D6BA0()
{
  int v0; // r5
  int v1; // r6

  EtwpEventWriteTemplateSessAndProv(v1, v0, ETW_EVENT_PROVIDER_UNREGISTERS);
  JUMPOUT(0x6DE9AC);
}
