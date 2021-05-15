// RtlGetCompressionWorkSpaceSize 
 
int __fastcall RtlGetCompressionWorkSpaceSize(__int16 a1)
{
  if ( !(_BYTE)a1 || (unsigned __int8)a1 == 1 )
    return -1073741811;
  if ( (unsigned __int8)a1 > 4u )
    return -1073741217;
  return ((int (__fastcall *)(int))RtlWorkSpaceProcs[(unsigned __int8)a1])(a1 & 0xFF00);
}
