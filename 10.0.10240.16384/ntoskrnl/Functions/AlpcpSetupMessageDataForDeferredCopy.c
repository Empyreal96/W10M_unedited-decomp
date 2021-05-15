// AlpcpSetupMessageDataForDeferredCopy 
 
int __fastcall AlpcpSetupMessageDataForDeferredCopy(int a1, int a2, int a3, unsigned int a4, char a5, char a6)
{
  int result; // r0

  result = 0;
  if ( !a5 )
    a2 += 24;
  if ( a6 && a4 + a2 > MmUserProbeAddress )
    return -1073741819;
  *(_DWORD *)(a1 + 88) = a2;
  if ( a4 > 0x100 )
    result = sub_7F43A0(0);
  return result;
}
