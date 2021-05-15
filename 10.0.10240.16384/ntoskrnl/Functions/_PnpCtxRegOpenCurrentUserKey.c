// _PnpCtxRegOpenCurrentUserKey 
 
int __fastcall PnpCtxRegOpenCurrentUserKey(int *a1)
{
  int v1; // r4
  int result; // r0
  unsigned __int16 *v3; // r5
  char v4[8]; // [sp+8h] [bp-80h] BYREF
  unsigned __int16 v5[8]; // [sp+18h] [bp-70h] BYREF
  unsigned __int16 *v6; // [sp+28h] [bp-60h]

  v4[0] = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v4[4] = 0;
  v4[5] = 5;
  if ( a1 )
    v1 = *a1;
  else
    v1 = 0;
  result = ZwQueryInformationToken();
  if ( result >= 0 )
  {
    v3 = v6;
    result = RtlInitializeSid((int)v5, (int)v4, 1u);
    if ( result >= 0 )
    {
      *(_DWORD *)RtlSubAuthoritySid((int)v5, 0) = 18;
      if ( RtlEqualSid(v5, v3) )
        result = -1073741637;
      else
        result = SysCtxRegOpenCurrentUserKey(v1);
    }
  }
  return result;
}
