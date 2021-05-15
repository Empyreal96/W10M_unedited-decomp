// MiIoSpaceIsConstant 
 
int __fastcall MiIoSpaceIsConstant(int a1, int a2)
{
  int result; // r0

  if ( (unsigned int)MiPermanentIoSpace >= MiPermanentIoSpaceEnd )
    result = 0;
  else
    result = sub_513D9C(MiPermanentIoSpace, a2, a1);
  return result;
}
