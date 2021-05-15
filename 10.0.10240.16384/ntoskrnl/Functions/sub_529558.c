// sub_529558 
 
void sub_529558()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6

  if ( (PoDebug & 0xD0000) != 0 )
    DbgPrint("PopExecuteProcessorCallback() Cpu %u Failed! rc=0x%x\n", *(_DWORD *)(v2 + 1428), v1);
  *(_DWORD *)(v0 + 20) = v1;
  JUMPOUT(0x466280);
}
