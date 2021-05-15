// sub_96C11C 
 
void sub_96C11C()
{
  int v0; // r4

  if ( (PoDebug & 1) != 0 )
    DbgPrint("%s: ZwAlpcCreatePort failed: 0x%x\n", "PopUmpoInitializeMonitorChannel", v0);
  JUMPOUT(0x959126);
}
