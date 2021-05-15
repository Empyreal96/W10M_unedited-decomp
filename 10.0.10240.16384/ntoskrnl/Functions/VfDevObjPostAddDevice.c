// VfDevObjPostAddDevice 
 
int __fastcall VfDevObjPostAddDevice(int result, int a2, int a3, int a4, int a5)
{
  int v6; // r5

  v6 = result;
  if ( a5 >= 0 && (MmVerifierData & 0x10) != 0 )
  {
    result = MmIsDriverVerifying(a2);
    if ( result )
    {
      if ( a4 == 4 )
        a4 = 5;
      result = VfFilterAttach(v6, a4);
    }
  }
  return result;
}
