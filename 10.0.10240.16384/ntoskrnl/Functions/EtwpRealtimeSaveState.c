// EtwpRealtimeSaveState 
 
int __fastcall EtwpRealtimeSaveState(int a1)
{
  if ( (*(_DWORD *)(a1 + 608) & 1) != 0 )
    return sub_7EBCB4();
  ZwSetInformationFile();
  return -1073741823;
}
