// ViErrorDisplayDescription 
 
int __fastcall ViErrorDisplayDescription(int a1)
{
  int result; // r0
  int v3; // r2
  int *v4; // r1
  int v5; // t1

  result = VfUtilDbgPrint((int)"************************************************************\n"
                               "Driver Verifier detected violation:\n"
                               "\n");
  v3 = 0;
  v4 = &ViErrorDescriptions;
  while ( 1 )
  {
    v5 = *v4;
    v4 += 3;
    if ( v5 == a1 )
      break;
    if ( (unsigned int)++v3 >= 0x3F )
      return result;
  }
  return VfUtilDbgPrint((int)"%s\n\n");
}
