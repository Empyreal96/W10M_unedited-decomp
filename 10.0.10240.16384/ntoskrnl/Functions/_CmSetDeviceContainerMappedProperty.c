// _CmSetDeviceContainerMappedProperty 
 
int __fastcall CmSetDeviceContainerMappedProperty(int a1, int a2, int a3, int a4, int a5)
{
  int (**v5)[5]; // r6
  int v6; // r4
  int (*v7)[5]; // t1

  if ( a4 )
    return -1073741802;
  v5 = &off_40B4B8;
  v6 = 0;
  while ( 1 )
  {
    v7 = *v5;
    v5 += 2;
    if ( *(_DWORD *)(a5 + 16) == (*v7)[4] )
      break;
    if ( (unsigned int)++v6 >= 4 )
      return -1073741802;
  }
  return sub_7EEB30();
}
