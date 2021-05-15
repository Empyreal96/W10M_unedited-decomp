// IoClearIrpExtraCreateParameter 
 
int __fastcall IoClearIrpExtraCreateParameter(int result)
{
  if ( (*(_DWORD *)(result + 8) & 0x80) != 0 )
    *(_DWORD *)(result + 60) = 0;
  return result;
}
