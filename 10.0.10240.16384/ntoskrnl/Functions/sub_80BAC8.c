// sub_80BAC8 
 
void sub_80BAC8()
{
  __int16 *v0; // r6
  _QWORD *v1; // r8

  if ( !RtlTimeFieldsToTime(v0, v1) )
    JUMPOUT(0x790276);
  JUMPOUT(0x79026E);
}
