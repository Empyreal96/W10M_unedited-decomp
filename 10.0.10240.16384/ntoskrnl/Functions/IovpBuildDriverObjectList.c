// IovpBuildDriverObjectList 
 
int __fastcall IovpBuildDriverObjectList(int a1)
{
  _DWORD *v2; // r4

  if ( PnpIsLegacyDriver(a1) )
  {
    v2 = (_DWORD *)ExAllocatePoolWithTag(512, 8, 7304777);
    if ( !v2 )
      return 0;
    if ( ObReferenceObjectSafe(a1) )
    {
      v2[1] = a1;
      *v2 = IovDriverListHead;
      IovDriverListHead = (int)v2;
    }
    else
    {
      ExFreePoolWithTag((unsigned int)v2);
    }
  }
  return 1;
}
