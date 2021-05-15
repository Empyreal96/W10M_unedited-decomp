// MiDrainControlAreaWrites 
 
int __fastcall MiDrainControlAreaWrites(int result)
{
  if ( *(_DWORD *)(result + 40) )
    result = sub_53E5B8();
  return result;
}
