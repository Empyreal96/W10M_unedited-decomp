// NtDeleteAtom 
 
int __fastcall NtDeleteAtom(unsigned int a1)
{
  int result; // r0
  _DWORD *v3; // [sp+0h] [bp-8h] BYREF

  v3 = 0;
  PsInvokeWin32Callout(2, (int)&v3, 0, 0);
  if ( v3 )
    result = RtlDeleteAtomFromAtomTable(v3, a1);
  else
    result = -1073741790;
  return result;
}
