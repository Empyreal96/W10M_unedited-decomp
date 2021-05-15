// sub_818DAC 
 
void __fastcall sub_818DAC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, char a19)
{
  char *v19; // r4
  int v20; // r6

  if ( v19 != &a19 )
    ExFreePoolWithTag((unsigned int)v19);
  if ( ExAllocatePoolWithTag(1, v20 + 256, 1265530196) )
  {
    ZwQueryValueKey();
    JUMPOUT(0x7B4128);
  }
  JUMPOUT(0x7B414E);
}
