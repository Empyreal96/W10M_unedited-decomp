// sub_50A2F0 
 
void __fastcall sub_50A2F0(int a1, int a2, int a3)
{
  if ( (PoDebug & 1) != 0 )
    DbgPrint("%s: ZwAlpcSendWaitReceivePort failed: 0x%x\n", "PopUmpoProcessMessages", a3);
  JUMPOUT(0x435D72);
}
