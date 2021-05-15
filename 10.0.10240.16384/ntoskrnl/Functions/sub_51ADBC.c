// sub_51ADBC 
 
void __fastcall sub_51ADBC(int a1)
{
  int v1; // r5

  if ( !ExAllocatePoolWithTag(a1, 8 * v1) )
    RtlRaiseStatus(-1073741670);
  JUMPOUT(0x441DF8);
}
