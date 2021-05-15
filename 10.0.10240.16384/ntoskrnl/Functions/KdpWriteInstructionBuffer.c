// KdpWriteInstructionBuffer 
 
_BYTE *__fastcall KdpWriteInstructionBuffer(_BYTE *result, __int64 a2, char a3)
{
  switch ( a3 )
  {
    case 1:
      *result = a2;
      break;
    case 2:
      *(_WORD *)result = a2;
      break;
    case 4:
      *(_DWORD *)result = a2;
      break;
    case 8:
      *(_QWORD *)result = a2;
      break;
  }
  return result;
}
