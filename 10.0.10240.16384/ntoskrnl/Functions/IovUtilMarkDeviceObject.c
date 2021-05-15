// IovUtilMarkDeviceObject 
 
int __fastcall IovUtilMarkDeviceObject(int result, int a2)
{
  if ( IovUtilVerifierEnabled )
    result = IovpUtilMarkDeviceObject(result, a2);
  return result;
}
