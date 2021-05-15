// IopQueryFlowHistory 
 
int __fastcall IopQueryFlowHistory(_DWORD *a1)
{
  int v2; // r4
  unsigned int *v3; // r0
  unsigned int v4; // r4
  unsigned int v5; // r1

  v2 = ExGetExtensionTable(IopIoQosExtensionHost);
  if ( v2 )
  {
    a1[24] = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(v2 + 16))(a1[10], a1[12], a1[13], a1[14]);
    v3 = (unsigned int *)(IopIoQosExtensionHost + 36);
    __pld((void *)(IopIoQosExtensionHost + 36));
    v4 = *v3 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v5 = __ldrex(v3);
    while ( v5 == v4 && __strex(v4 - 2, v3) );
    if ( v5 != v4 )
      ExfReleaseRundownProtection((unsigned __int8 *)v3);
  }
  else
  {
    a1[24] = -1073741822;
  }
  return KeSetEvent((int)(a1 + 20), 0, 0);
}
