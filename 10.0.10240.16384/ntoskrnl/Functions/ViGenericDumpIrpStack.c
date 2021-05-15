// ViGenericDumpIrpStack 
 
int __fastcall ViGenericDumpIrpStack(unsigned __int8 *a1)
{
  unsigned int v1; // r2

  v1 = *a1;
  if ( v1 == 15 && a1[1] == 1 )
    return VfUtilDbgPrint((int)"IRP_MJ_SCSI");
  if ( v1 <= 0x1B )
    return VfUtilDbgPrint((int)IrpMajorNames[v1]);
  if ( v1 == 255 )
    return VfUtilDbgPrint((int)"IRP_MJ_BOGUS");
  return VfUtilDbgPrint((int)"IRP_MJ_??");
}
