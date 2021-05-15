// ObpDeleteDirectoryObject 
 
int __fastcall ObpDeleteDirectoryObject(int result)
{
  if ( (*(_DWORD *)(result + 168) & 4) != 0 )
    result = ObDereferenceObjectDeferDelete(*(_DWORD *)(result + 156));
  return result;
}
