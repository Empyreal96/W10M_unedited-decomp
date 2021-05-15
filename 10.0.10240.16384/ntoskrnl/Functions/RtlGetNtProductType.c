// RtlGetNtProductType 
 
int RtlGetNtProductType()
{
  if ( !MEMORY[0xFFFF9268] )
    JUMPOUT(0x7E9BC2);
  return sub_7E9BB8();
}
