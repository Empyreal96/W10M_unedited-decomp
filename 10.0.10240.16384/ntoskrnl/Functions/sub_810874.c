// sub_810874 
 
// bad sp value at call has been detected, the output may be wrong!
void sub_810874()
{
  _DWORD *v0; // r4

  PsUnregisterMonitorServerSilo(*v0);
  JUMPOUT(0x79E050);
}
