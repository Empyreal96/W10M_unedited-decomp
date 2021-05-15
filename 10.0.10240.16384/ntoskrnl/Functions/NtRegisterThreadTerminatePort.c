// NtRegisterThreadTerminatePort 
 
int __fastcall NtRegisterThreadTerminatePort(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  int result; // r0
  _DWORD *v6; // r0
  int v7; // [sp+8h] [bp-8h] BYREF

  v7 = a4;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = ObReferenceObjectByHandle(a1, 1, LpcPortObjectType, *(char *)(v4 + 0x15A), &v7);
  if ( result >= 0 )
  {
    v6 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, 8u, 1884582736);
    if ( v6 )
    {
      v6[1] = v7;
      *v6 = *(_DWORD *)(v4 + 860);
      *(_DWORD *)(v4 + 860) = v6;
      result = 0;
    }
    else
    {
      result = sub_7EB22C();
    }
  }
  return result;
}
