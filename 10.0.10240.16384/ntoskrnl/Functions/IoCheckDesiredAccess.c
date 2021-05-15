// IoCheckDesiredAccess 
 
int __fastcall IoCheckDesiredAccess(int *a1, int a2)
{
  int result; // r0

  RtlMapGenericMask(a1, (_DWORD *)IoFileObjectType + 13);
  if ( (*a1 & ~a2) != 0 )
    result = -1073741790;
  else
    result = 0;
  return result;
}
