// VfDevObjPreAddDevice 
 
int __fastcall VfDevObjPreAddDevice(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = MmIsDriverVerifying(a2);
  if ( result && (MmVerifierData & 0x10) != 0 )
  {
    if ( a4 == 4 )
      a4 = 3;
    result = VfFilterAttach(a1, a4);
  }
  return result;
}
