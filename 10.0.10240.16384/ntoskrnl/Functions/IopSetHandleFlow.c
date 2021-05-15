// IopSetHandleFlow 
 
int __fastcall IopSetHandleFlow(int a1)
{
  int v2; // r4
  unsigned int *v3; // r0
  unsigned int v4; // r4
  unsigned int v5; // r1

  v2 = ExGetExtensionTable(IopIoQosExtensionHost);
  if ( v2 )
  {
    *(_DWORD *)(a1 + 96) = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(v2 + 8))(
                             *(_DWORD *)(a1 + 44),
                             *(_DWORD *)(a1 + 40),
                             *(unsigned __int8 *)(a1 + 104),
                             *(_DWORD *)(a1 + 100));
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
    *(_DWORD *)(a1 + 96) = -1073741822;
  }
  return KeSetEvent(a1 + 80, 0, 0);
}
