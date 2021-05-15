// IoSetStartIoAttributes 
 
int __fastcall IoSetStartIoAttributes(int result, int a2, int a3)
{
  if ( a2 )
    *(_DWORD *)(*(_DWORD *)(result + 176) + 36) |= 0x100u;
  if ( a3 )
    result = sub_555C44();
  return result;
}
